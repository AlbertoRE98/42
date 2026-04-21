*Este proyecto ha sido creado como parte del currículo de 42 por <aramos-e>.*

---

## Descripción

Reimplementación de la función `printf()` de la librería estándar de C como librería estática.
El objetivo principal es comprender el funcionamiento de las **funciones variádicas** en C —
funciones que aceptan un número variable de argumentos — y construir un sistema de formateo
extensible y bien estructurado desde cero.

La librería expone una única función pública:

```c
int ft_printf(char const *format, ...);
```

Se comporta igual que `printf()` de la libc para las conversiones implementadas, incluyendo
el valor de retorno (número total de caracteres escritos).

---

## Conversiones soportadas

| Especificador | Descripción |
|---|---|
| `%c` | Imprime un único carácter |
| `%s` | Imprime una cadena de caracteres (`NULL` → `"(null)"`) |
| `%p` | Imprime un puntero en formato hexadecimal (`NULL` → `"(nil)"`) |
| `%d` | Imprime un entero con signo en base 10 |
| `%i` | Imprime un entero con signo en base 10 |
| `%u` | Imprime un entero sin signo en base 10 |
| `%x` | Imprime un entero en hexadecimal minúsculas |
| `%X` | Imprime un entero en hexadecimal mayúsculas |
| `%%` | Imprime el carácter `%` literal |

---

## Instrucciones

**Compilación de la librería:**
```bash
make
```
Genera `libftprintf.a` en la raíz del repositorio.

**Uso en tu proyecto:**
```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o programa
```

**Reglas del Makefile:**

| Regla | Efecto |
|---|---|
| `make` / `make all` | Compila y genera `libftprintf.a` |
| `make clean` | Elimina los ficheros objeto `.o` |
| `make fclean` | Elimina los `.o` y `libftprintf.a` |
| `make re` | Recompila todo desde cero |


### Arquitectura: dispatcher

`ft_printf` no gestiona las conversiones directamente. El flujo es:

```
ft_printf → ft_parse → ft_dispatch → ft_print_*
```

- **`ft_parse`** recorre la cadena de formato carácter a carácter. Al encontrar `%`,
  extrae el especificador y delega en el dispatcher.
- **`ft_dispatch`** actúa como router: recibe el carácter de conversión y llama a la
  función correspondiente.
- **Cada `ft_print_*`** gestiona una conversión concreta y devuelve el número de
  caracteres escritos.
- **`ft_printf`** acumula todos esos valores y los devuelve como total.

Esta separación garantiza que ninguna función supera las 25 líneas que impone la Norma
de 42, y hace el sistema extensible — añadir una nueva conversión es añadir una función
y una rama en el dispatcher.

### `ft_putnbr_base`: conversión numérica genérica

En lugar de funciones separadas para decimal y hexadecimal, una única función recursiva
acepta la base como string:

```
"0123456789"        → base 10 (para %d, %u)
"0123456789abcdef"  → base 16 minúsculas (para %x, %p)
"0123456789ABCDEF"  → base 16 mayúsculas (para %X)
```

La recursividad genera los dígitos en el orden correcto sin necesitar un buffer auxiliar
para invertirlos.

### `va_list` por puntero

Todas las funciones de conversión reciben `va_list *` (puntero) en lugar de `va_list`
(valor). Esto garantiza que el iterador de argumentos variádicos es compartido — cada
`va_arg` consume el argumento correcto en orden, independientemente de la arquitectura.
Pasar `va_list` por valor crearía una copia local y el iterador original no avanzaría,
provocando que argumentos consecutivos se lean incorrectamente.

### Gestión de casos borde

| Situación | Comportamiento |
|---|---|
| `%s` con `NULL` | Imprime `(null)` — 6 caracteres |
| `%p` con `NULL` | Imprime `(nil)` — 5 caracteres |
| `%d` con `INT_MIN` | El argumento se guarda en `long` antes de negar para evitar overflow |
| `%u` con `-1` | Extraído como `unsigned int` → imprime `4294967295` |
| `%x` con `-1` | Extraído como `unsigned int` → imprime `ffffffff` |
| `format` es `NULL` | `ft_printf` devuelve `-1` sin crashear |
| `%` al final de cadena | Se ignora, no crashea |

### Promoción de tipos en funciones variádicas

El estándar C define que ciertos tipos se promueven automáticamente al pasarse como
argumentos variádicos. Ignorar estas reglas produce comportamiento indefinido:

| Tipo pasado | Tipo a usar en `va_arg` |
|---|---|
| `char` | `int` (luego castear a `char`) |
| `short` | `int` (luego castear a `short`) |
| `float` | `double` (luego castear a `float`) |
| `int` | `int` |
| `unsigned int` | `unsigned int` |
| `char *` | `char *` |
| `void *` | `void *` |

---

## Cómo funcionan las funciones variádicas

Las funciones variádicas permiten aceptar un número indefinido de argumentos usando
el operador `...` (ellipsis). El mecanismo completo se gestiona con cuatro macros de
`<stdarg.h>`:

**`va_list`** — Tipo opaco que actúa como iterador sobre los argumentos variádicos.
Internamente es un puntero a la zona de la pila o registros donde el compilador
colocó los argumentos.

**`va_start(ap, last)`** — Inicializa el iterador `ap` para que apunte al primer
argumento variádico. `last` debe ser el nombre del último parámetro nombrado antes
del `...`.

**`va_arg(ap, type)`** — Lee el siguiente argumento interpretándolo como `type` y
avanza el iterador. El tipo debe coincidir exactamente con lo que se pasó (respetando
las reglas de promoción), o el comportamiento es indefinido.

**`va_end(ap)`** — Cierra y limpia el iterador. Obligatorio después de cada
`va_start` o `va_copy`. En algunas arquitecturas libera recursos; omitirlo es
comportamiento indefinido según el estándar.

Ejemplo del flujo para `ft_printf("%d %s", 42, "hola")`:

```
va_start  → iterador apunta a 42
va_arg(int)   → lee 42,    iterador avanza → apunta a "hola"
va_arg(char*) → lee "hola", iterador avanza → no hay más args
va_end    → limpieza
ft_printf devuelve 6  (2 dígitos + 1 espacio + 4 letras = 7...
                       con el espacio entre %d y %s son 7 total)
```

---

## Recursos

- [`man 3 printf`](https://man7.org/linux/man-pages/man3/printf.3.html) — Especificación oficial de printf
- [`man 3 stdarg`](https://man7.org/linux/man-pages/man3/stdarg.3.html) — Documentación de va_list y macros variádicas
- [`man 2 write`](https://man7.org/linux/man-pages/man2/write.2.html) — Syscall de escritura
- [Variadic Functions — cppreference](https://en.cppreference.com/w/c/variadic) — Referencia del estándar C


### USO DE IA
Usada para tareas pedagogicas, explicaciones y debug complejo