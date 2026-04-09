
## 📝 Descripción
Este proyecto consiste en crear una librería en **C** que contiene una serie de funciones de propósito general. El objetivo es comprender el funcionamiento interno de las funciones estándar de C, implementarlas desde cero y construir una base sólida para los próximos proyectos del cursus.

---

## 🏗️ La Librería: Detalles Técnicos

La librería `libft.a` se genera en la raíz del repositorio utilizando el comando `ar`. El contenido se divide en tres bloques estratégicos:

* **Funciones de libc (Parte 1):** Reimplementaciones de funciones estándar con el prefijo `ft_` (como `ft_strlen`, `ft_memset`, `ft_atoi`) que siguen fielmente las definiciones del `man`.
* **Funciones Adicionales (Parte 2):** Funciones que no pertenecen a la librería estándar o tienen un enfoque distinto, orientadas a la manipulación de strings y escritura en descriptores de archivo (como `ft_substr`, `ft_strjoin`, `ft_split`).
* **Listas enlazadas (Parte 3):** Funciones para manejar estructuras de datos dinámicas utilizando una estructura de nodos definida en el header.

---

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

### Referencias
* **Manuales de Sistema (man):** Utilizados para replicar prototipos y comportamientos originales.
* **Aprendizaje entre pares (Peer Learning):** Intercambio de lógica y resolución de problemas mediante el diálogo constante con otros estudiantes.

### Uso de IA (Declaración de Transparencia)
En cumplimiento con las normativas académicas, el uso de IA en este proyecto se ha limitado a un enfoque de apoyo al aprendizaje:
* **Tareas:** Uso de Gemini 3 Flash para la explicación de conceptos técnicos abstractos y apoyo en la depuración de errores de segmentación.
* **Lógica:** Apoyo en la estructura del Makefile y en el análisis de casos críticos de desbordamiento (*overflow*) en conversiones numéricas.
* **Compromiso:** Se ha priorizado el desarrollo del razonamiento intelectual propio, utilizando la IA como un tutor y no como un generador de código directo.
