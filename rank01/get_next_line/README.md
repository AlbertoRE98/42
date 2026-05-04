*Este proyecto ha sido creado como parte del currículo de 42 por aramos-e.*
-----

## 💡 Descripcion

El objetivo de este proyecto es programar una función que devuelva una línea leída desde un descriptor de archivo (file descriptor). Este reto introduce el concepto de **variables estáticas** en C y requiere una gestión de memoria impecable para evitar fugas (memory leaks) y errores de segmentación.


-----

## 🛠️ Especificaciones Técnicas

| Característica | Detalle |
| :--- | :--- |
| **Lenguaje** | C (Estándar C99) |
| **Funciones Autorizadas** | `read`, `malloc`, `free` |
| **Variable Estática** | Utilizada para preservar el contenido entre llamadas |
| **Robustez** | Pasa tests de `Invalid FD`, `Empty File` y `NULL_CHECK` |

-----

## 📂 Estructura del Código

Tu implementación se divide en las siguientes funciones clave para mantener la claridad y cumplir con la **Norma**:

  * **`get_next_line.c`**: Contiene la lógica principal, la lectura (`read_and_store`), la extracción de la línea (`extract_line`) y la actualización del remanente (`update_storage`).
  * **`get_next_line_utils.c`**: Funciones auxiliares necesarias (`ft_strlen`, `ft_strchr`, `ft_strjoin`, `ft_strdup`, `ft_substr`).
  * **`get_next_line.h`**: Prototipos y definición del `BUFFER_SIZE`.

-----

## 🚀 Instrucciones

### 1\. Compilación

Puedes compilar la función junto con tu código principal definiendo el tamaño del buffer:

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
```

### 2\. Ejemplo de uso en C

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int     fd;
    char    *line;

    fd = open("test.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

-----

## 🧪 Testing

Este código ha sido testeado y validado contra:

1.  **Francinette**: Pasa todos los tests de funcionalidad y leaks.
2.  **gnlTester (Tripouille)**: OK en Mandatory y Bonus.
3.  **Valgrind**: 0 errores de memoria y 0 bytes perdidos incluso en fallos de lectura.

### Casos Críticos Cubiertos:

  * **Archivos Vacíos**: Retorna `NULL` correctamente sin crashear.
  * **Líneas Largas**: Maneja buffers de cualquier tamaño (desde 1 hasta 1,000,000+) sin TIMEOUT.
  * **Múltiples FD**: Estructura preparada para la parte de Bonus.
  * **Errores de Malloc**: Implementa `free_and_return` para limpiar la memoria estática si falla una asignación intermedia.


### Recursos
* **Manuales de Sistema (man):** Utilizados para replicar prototipos y comportamientos originales.
* **Aprendizaje entre pares (Peer Learning):** Intercambio de lógica y resolución de problemas mediante el diálogo constante con otros estudiantes.

-----
### USO DE IA
Usada para tareas pedagogicas, explicaciones y debug complejo
