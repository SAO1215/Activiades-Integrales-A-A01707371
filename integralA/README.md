# Integral A Avance 1 
Olivia Araceli Morales Quezada (A01707371)

## Libreria Personal
Este proyecto fue creado con el proposito de implementar  metodos de ordenamiento, consiste en un programa que permita llevar un registro de tus lecturas, mediante un menu te da la opcion de poder ver los libros registrados en un archivo "libros.txt", ordenarlos alfabéticamente por titulo y generar un reporte nuevo ya ordenado.

## Competencias a evaluar
### SICT0302B: Toma decisiones

Hace un análisis de complejidad correcto y completo para todo el programa y sus compenetes 

**Análisis de complejidad temporal**

*ordenaMerge*: Para ordenar se utilizó el método _mergesort_ el cual tiene una complejidad O(nlog(n)) ya que consiste en dividir a la mitad el arreglo hasta obtener solo un valor [O(log(n)], despues combinar y juntar las mitades [O(n)].

### SICT0301B: Toma decisiones
Selecciona un algoritmo de ordenamiento adecuado al problema el ordenamiento puede ser antes o después agregarlos los datos a la estructura lineal o para reordenar los datos de diferentes formas para presentar reportes.

**Algoritmo de ordenamiento**

En el archivo "sortmerge.h" esta el metodo, y su implementación dentro de "main.cpp" esta en la linea 64.

### SICT0303B: Implementa acciones científicas

**Implementa mecanismos de lectura de archivos correctos y útiles dentro de un programa.** 
Para poder leer los datos primero se accede a un archivo "libros.txt", este proceso se encuentra en la funcion _leer()_, implementada en la linea 44 de "main.cpp".

**Implementa mecanismos de escritura de archivos correctos y útiles dentro de un programa.**
Desde el menu puedes encontar un opcion para escribir un reporte, apartir de la linea 69, este gener un archivo "reporte.txt".

**Referencias**

- Fundación Aquae. (2020, 3 noviembre). Los 100 mejores libros de la historia - Fundación Aquae. https://www.fundacionaquae.org/los-100-mejores-libros-de-todos-los-tiempos/