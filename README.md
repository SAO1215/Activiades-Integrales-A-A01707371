# Libreria Personal 
Olivia Araceli Morales Quezada (A01707371)

Este proyecto fue creado con el proposito de implementar  metodos de ordenamiento y estructuras lineales, consiste en un programa que permita llevar un registro de tus lecturas, mediante un menu te da la opcion de poder ver los libros registrados en un archivo "libros.txt", ordenarlos alfabéticamente por titulo, agregar libros, elimminarlos, verificar que ya existen en tu lista y generar un reporte nuevo con las actualizaciones.

## Integral A Avance 1 

### Competencias a evaluar
### SICT0302B: Toma decisiones

Hace un análisis de complejidad correcto y completo para todo el programa y sus compenetes. 

**Análisis de complejidad temporal**

*ordenaMerge()*: Para ordenar se utilizó el método _mergesort_ el cual tiene una complejidad O(nlog(n)) ya que consiste en dividir a la mitad el arreglo hasta obtener solo un valor [O(log(n)], despues combinar y juntar las mitades [O(n)].

*size()*: Esta funcion cuenta la cantidad de nodos que hay en tu lista, por lo que su complejidad es de O(n) poruqe depende del tamaño de la lista.

*update()*: Es un metodo que nos ayuda a sustituir un valor de la lista se gun su posición, su complejidad es de O(n) ya que tinene que recorrerla.

*add()*: Al tratarse de una lista ligada simple para añadir un elemento al final debe recorrerla entera. Complejidad de O(n).

*get()*: Para obtener un valor de la lista y verificar que este existe se consulta elementopor elemento, asi que su complejidad corresponde a O(n).

*remove()*: Esta funcion elimina el elemento de la lista que le indiques, pero primero necesita encontrarlo, su complejidad corresponde a O(n).

*display()*: Es una función que muestra el contenido de la lista, hace uso de un ciclo que solo se detiene cuando llega al final de la lista por lo que su complejidad es de O(n).
 

### SICT0301B: Toma decisiones
Selecciona un algoritmo de ordenamiento adecuado al problema el ordenamiento puede ser antes o después agregarlos los datos a la estructura lineal o para reordenar los datos de diferentes formas para presentar reportes.

**Algoritmo de ordenamiento**

En el archivo "sortmerge.h" esta el metodo, y su implementación dentro de "main.cpp" esta en la linea 64.

### SICT0303B: Implementa acciones científicas

**Implementa mecanismos de lectura de archivos correctos y útiles dentro de un programa.** 
Para poder leer los datos primero se accede a un archivo "libros.txt", este proceso se encuentra en la funcion _leer()_, implementada en la linea 44 de "main.cpp".

**Implementa mecanismos de escritura de archivos correctos y útiles dentro de un programa.**
Desde el menu puedes encontar un opcion para escribir un reporte, apartir de la linea 69, este gener un archivo "reporte.txt".


## Integral A Avance 2

### Competencias a evaluar
### SICT0302B: Toma decisiones

Selecciona y usa una estructura lineal adecuada al problema dentro de tu programa usa una estructura lineal para hacer manejo de los datos (agregar, consultar y eliminar).

**Estructura lineal**
Se hace uso del archivo "list.h" donde se encuentra una estructura para crear listas y varios metodos para manejarlas, y su implementación se encuentara dentro de "main.cpp".

## Integral A Avance 3
### Competencias a evaluar
### SICT0302B: Toma decisiones

Usa un árbol adecuado para resolver un problema, puede ser cualquiera de los árboles vistos en el curso, lo lo importante es que se demuestre que se usa forma útil el árbol para extraer y guardar información.

**Estructura arbol**
Se cambio el programa para que por medio de la estructura de arbol binario que se encuentra en el archivo "bst.h" para su implementacion, ahora podemos almacenar, agregar, eliminar, consultar y mostrar nuestros datos ordenados.

### SICT0302B: Toma decisiones

Hace un análisis de complejidad correcto y completo para todo el programa y sus compenetes. 

**Análisis de complejidad temporal**

*add()*: Esta funcion añade un elemento en el arbol, no necesita recorrer todo el arbol sino que divide este proceso por niveles. su complejidad es de O(log(n)).

*remove()*: Esta funcion elimina un elemento de la estructura, para esto no recorre uno a uno sino que se va dividiendo el trabajo por lo que su complejidad es de O(log(n)).

*removeAll()*: Esta funcion vacia todo el arbol, se apoya de otra funcion llamada *removeChild()* que elimina los nodos hijos, su complejidad es O(log(n)).

*visit()*: Esta función nos ayuda a darle el formato deseado a la funcion *inorder()* la cual nos muestra el contenido de los datos en orden, su complejidad es de O(log(n)).

*find()*: Con esta funcion verificarmos que un dato se encuentre en la estructura, su complejidad es de O(log(n)).

## Consideraciones
- Para el avance 3, todo lo que se estaba implementado con listas y sorts se cambio a arboles.
- Para eliminar o agregar datos es necesario escribir todos los datos respetando los espacios. Ejemplo: "Un_mundo_feliz Aldous_Huxley 374" 


**Referencias**

- Fundación Aquae. (2020, 3 noviembre). Los 100 mejores libros de la historia - Fundación Aquae. https://www.fundacionaquae.org/los-100-mejores-libros-de-todos-los-tiempos/