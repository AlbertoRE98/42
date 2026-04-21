*Este proyecto ha sido creado como parte del currículo de 42 por <aramos-e>.*

## 📝 Descripción
Este proyecto consiste en crear una librería en **C** que contiene una serie de funciones de propósito general. El objetivo es comprender el funcionamiento interno de las funciones estándar de C, implementarlas desde cero y construir una base sólida para los próximos proyectos del cursus.

## 🚀 Instrucciones

### Compilación y Makefile
El proyecto se compila mediante un **Makefile** que incluye las flags `-Wall -Werror -Wextra`.

| Comando | Acción |
| :--- | :--- |
| `make` | Compila la parte obligatoria y genera `libft.a`. |
| `make clean` | Elimina los archivos objeto (`.o`). |
| `make fclean` | Elimina los objetos y el archivo de la librería `libft.a`. |
| `make re` | Realiza una recompilación completa (`fclean` + `all`). |

### Uso
Para integrar la librería en otros proyectos en C, incluye el header en tu código:
```c
#include "libft.h"
```
Y enlaza el archivo `.a` durante la compilación:
```bash
cc main.c -L. -lft
```

---

## 📖 Recursos y Aprendizaje

### Recursos
* **Manuales de Sistema (man):** Utilizados para replicar prototipos y comportamientos originales.
* **Aprendizaje entre pares (Peer Learning):** Intercambio de lógica y resolución de problemas mediante el diálogo constante con otros estudiantes.

### USO DE IA
Usada para tareas pedagogicas, explicaciones y debug complejo
