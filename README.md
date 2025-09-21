# push_swap

**push_swap** es un proyecto de 42 cuyo objetivo es ordenar una pila de números utilizando un conjunto limitado de operaciones y el menor número de movimientos posible. El desafío consiste en implementar un programa que, dado un conjunto de números enteros, genere una lista óptima de instrucciones para ordenar los datos, empleando únicamente las operaciones permitidas sobre dos pilas (stack A y stack B).

## 📚 Descripción

El proyecto se compone de dos programas:

- **push_swap:** recibe una lista de números por argumentos y muestra por salida estándar la secuencia de operaciones mínimas para ordenarlos.
- **checker:** (opcional) permite comprobar si una secuencia de operaciones efectivamente ordena la pila.

El algoritmo se enfrenta a restricciones importantes:
- Solo puedes utilizar ciertas operaciones (swap, push, rotate y reverse rotate) sobre las pilas.
- El objetivo es escribir el algoritmo más eficiente posible, minimizando la cantidad de operaciones.

## ⚙️ Operaciones Permitidas

- `sa`, `sb` : intercambia los dos primeros elementos de la pila A o B.
- `ss` : `sa` y `sb` al mismo tiempo.
- `pa`, `pb` : mueve el primer elemento de la pila B a la A o viceversa.
- `ra`, `rb` : rota todos los elementos de la pila A o B hacia arriba.
- `rr` : `ra` y `rb` al mismo tiempo.
- `rra`, `rrb` : rota todos los elementos de la pila A o B hacia abajo.
- `rrr` : `rra` y `rrb` al mismo tiempo.

## 🛠️ Compilación

Asegúrate de tener `make` y un compilador de C instalados.

```bash
git clone https://github.com/Juansito19/push_swap.git
cd push_swap
make
```

Esto generará un ejecutable llamado `push_swap` en el directorio raíz.

## 🚀 Uso

Ejecuta el programa pasando una lista de números a ordenar:

```bash
./push_swap 4 67 3 87 23
```

La salida será la secuencia de operaciones que ordenan la pila.

### Ejemplo

```bash
$ ./push_swap 3 2 1
sa
rra
```

Esto indica que, para ordenar `3 2 1`, primero se debe hacer un swap sobre la pila A y luego una rotación inversa.

## 🧪 Checker (opcional)

Algunos proyectos incluyen un programa `checker` para verificar que la secuencia de operaciones efectivamente ordena la pila:

```bash
./push_swap 4 3 2 1 | ./checker 4 3 2 1
```

Si la secuencia es correcta, `checker` imprimirá `OK`. Si no, imprimirá `KO`.

## 📝 Notas sobre la implementación

- El manejo de errores y validación de argumentos está implementado para evitar comportamientos indeseados.
- Se usaron distintas estrategias de ordenación según el tamaño de la pila para optimizar el número de movimientos.

## 📂 Estructura del proyecto

- `src/` : Archivos fuente del proyecto.
- `includes/` : Archivos de cabecera.
- `Makefile` : Automatización de la compilación.

## 🧑‍💻 Autor

- Juan ([@Juansito19](https://github.com/Juansito19))
