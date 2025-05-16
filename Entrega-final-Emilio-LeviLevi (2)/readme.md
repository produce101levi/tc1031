# Proyecto: Melodica
Una aplicación similar a Spotify o Apple Music, pero con la opción de guardar y descargar una cantidad limitada de canciones con la versión gratis, seleccionar canciones en las que no quieres tener un anuncio (con un límite diario) a no ser que tengas el servicio premium.

## Descripción del avance 1
Este avance contiene una base de datos de 10 canciones (las que se utilizarán para correr este programa por ahora, posteriormente se agregarán más, y el usuario podrá agregar las que desee) las cuales organizará de más antigua a más reciente, utilizando el método mer

## Descripción del avance 2
En este avance, las canciones se almacenan en una estructura de árbol de búsqueda binario, el cual es conveniente para éste caso porque al tratarse de una estructura basada en qué elemento es mayor o menor que el nodo anterior, ordenarlos es mucho más fácil. Con ésta estructura, el método "mergeSort" ya no es necesario, y podemos simplificar el proceso de programación. 

### Cambios sobre el primer avance
1. Cambié de entrada vector a entrada BST: Los árboles de búsqueda binaria se basan en la organización ascendiente y descendiente de las canciones, cosa que es esencial dentro de la aplicación.
2. Cambié de algoritmo de ordenación; de MergeSort a inorden: El algoritmo inorden funciona mejor con los árboles de búsqueda binaria porque toman menos memoria, no cambian la estructura del árbol y hace más fácil la búsqueda de elementos. 
3. Agregué opciones de ordenación: Anteriormente sólo se organizaban las canciones por año de lanzamiento. Ahora el usuario puede elegir ordenarlas por título, año de lanzamiento o artista (en nombre alfabético/descendiente).

## Descripción del avance 3
Éste avance le da al usuario la capacidad de eliminar canciones de y visualizar su playlist. Se utilizan funciones nuevas tales como eliminarCanciones(), agregarCanciones(), y también existen más comandos condicionales. Ahora incluye un menú inicial para que el usuario pueda seleccionar qué acción quiere tomar. 

### Cambios sobre el segundo avance
1. Agregué la opción de eliminar canciones de la lista de reproducción, ya que los usuarios no van a tener el deseo de mantener sus canciones permanentemente en sus listas.
2. Agregué la opción de "mostrar playlist" para que el usuario tenga acceso a ella sin antes necesitar insertar canciones.
3. Agregué un menú para que el usuario pueda elegir entre ver su playlist, agregar canciones o eliminar canciones.
4. En el segundo avance, no se compiló el avance proyecto porque la sintaxis estaba incorrecta (me faltaron algunos corchetes.). Fueron corregidos en este avance.


## Entrega final
La entrega final es un proyecto de ordenar canciones dentro de playlists por orden alfabético y numérico. Le da la oportunidad al usuario de ingresar y buscar canciones dentro de la playlist, además de salir del programa cuando lo desee. Tiene dos menús; uno principal y otro que da la opción al usuario de cómo quiere visualizar las canciones ordenadas en la playlist que crea. Se basa en archivos de texto como bases de datos, de donde se extraen los datos y se meten en una pila. El usuario también puede ingresar canciones que se guardan a los archivos. 

### Cambios sobre el tercer avance avance
1. Cambio de BST a pilas: Es más fácil de programar y más flexible.
2. Cambio de inorden a quickSort: Eficiencia, complejidad no muy extrema a comparación de otros métodos.
3. Agregar otro menú: Hay más funciones necesarias dentro de la entrega final que se muestran en el nuevo menú
4. Agregar función buscarCanción: Se solicita en el proyecto una función en la que el usuario pueda consultar de las estructuras de datos
5. Agregar más archivos de texto: Para hacer más fácil la programación de ordenación de datos y que se puedan ordenar desde los archivos de texto como lo desee el usuario.


## Instrucciones para compilar el proyecto
Ejecuta el siguiente comando en la terminal:

`g++ main.cpp -o primer_avance` 

## Instrucciones para ejecutar el proyecto
Ejecuta el siguiente comando en la terminal:

`./primer_avance` 

## Descripción de las entradas del avance de proyecto
CIN:
El usuario ingresa los datos cuando se le solicitan
ARCHIVOS DE TEXTO:

artist.txt, title.txt, year.txt: De éstos archivos de texto se obtienen los datos que ingresa el usuario y se almacenan en una pila. 


## Descripción de las salidas del avance de proyecto


ARCHIVOS DE TEXTO:

Cada archivo guarda los mismos datos, sin embargo, el orden es diferente.
En el archivo artist.txt, se guarda primero el nombre del artista.
En el archivo title.txt, se guarda primero el título de la canción
En el archivo year.txt, se guarda primero el año de lanzamiento de la canción

## Desarrollo de competencias

### SICT0301: Evalúa los componentes
#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
En la sección de funciones quickSort podemos observar la complejidad del alogoritmo de ordenamiento utilizado; quickSort. 
Las líneas 63, 64, 69 y 73 son de complejidad O(1). No dependen de ninguna entrada para su

Todos los ciclos son de complejidad O(n), ya que ninguno tiene un ciclo dentro del otro y por tanto no son O(n^2).

Considero que desarrollé éste criterio porque ahora tengo claro cómo hacer un análisis de algoritmos de funcionamiento y como sacar la complejidad final de una función, cosa que hice con el algoritmo en la sección del código FUNCIONES QUICKSORT.

#### Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.
Considero que mi desarrollo de la competencia se observa en el análisis que hice tanto en el archivo readme como en el código en la estructura de Stack. Aprendí a tomar el peor de los casos para un análisis de éste tipo, y así tomar en cuenta lo más conveniente para un programa.

La estructura de datos STACK o PILA tiene tres funciones básicas relacionadas con ella; push, pop y isEmpty. Todas éstas se encuentran en la estructura Stack, en la línea 9.

En las tres funciones se puede observar una compeljidad O(1). Ninguna de las funciones tiene ciclos, recursiones, ni llama a funciones que no sean constantes. Por lo tanto, podemos argumentar que la complejidad de la estructura pila es O(1).

#### Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.
En todo el programa se pueden ver las notas en las que se hace el análisis de cada parte del código. Aprendí cómo tomar en cuenta los componentes de cada función y cada línea para hacer un análisis de complejidad de mi programa, lo que se puede observar en las notas que puse dentro del main.cpp.

### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
Uno de los retos principales en la creación de éste proyecto fue elegir un algoritmo de ordenamiendo adecuado. Primeramente elegí el algoritmo MergeSort, luego un árbol de búsqueda binario (BST) con un método inorden y finalmente me decidí por QuickSort.
Me decidí por el método quickSort para la entrega final, basándome en todos los aprendizajes que adquirí al hacer éste proyecto, los cuales detallaré a continuación. Aquí también se puede ver mi desarrollo de la competencia. 
Mi motivo principal para ésto es que el código para un árbol de búsqueda binario era muy difícil de entender y modificar para agregar funciones nuevas al programa. El método inorden no daba la libertad que necesitaba de modificar las partes del código.
Además, la complejidad de quickSort (en éste programa) O(n log n) es muy eficiente. En el peor de los casos no tiene una complejidad extrema (a diferencia de métodos como el bubbleSort en el cual la complejidad puede llegar a ser O(n^2), al tratarse de un ciclo doble). 
Otros métodos como mergeSort tienen una complejidad similar pero quickSort tiene mejor rendimiento en la memoria y utiliza menos memoria a comparación de otros métodos.


#### Selecciona una estructura de datos adecuada al problema y la usa correctamente.
Ahora utilizando una pila en lugar de un árbol de búsqueda binario, el funcionamiento del código es mucho más fácil de explicar, seguir y organizar para mi. Las funciones son más flexibles, y ahora el código está mucho más claro no sólo para mi sino también para cualquier otra persona que quiera ver y evaluar el código.

Si bien la pila no posee la cualidad intrínsica de un árbol de búsqueda binario de organizar los datos, la complejidad de la misma es O(1) ya que la complejidad de las funciones básicas relacionadas a ella (siendo éstas push(), pop() y isEmpty()) son de complejidad O(1). Así que en el peor de los casos, ésta estructura es mucho menos compleja que un árbol de estructura binario. 

Además, es mucho más complicado programar un BST para que pueda ordenar los datos en forma alfabética o numérica, especialmente considerando que el método de ordenamiento con archivos que yo opté por utilizar requeriría de tres estructuras de datos; cosa que es fácil implementar con una pila pero no con un BST.

### SICT0303: Implementa acciones científicas
#### Implementa mecanismos para consultar información de las estructras correctos.
En el código se implementa la función buscarCancion() en la que el usuario puede ingresar el título de una canción y el programa consulta la pila para regresar el título de la canción que el usuario desea buscar. 
Con esto aprendí cómo utilizar las funciones de C++ y librerías como algorithm para comparar un input del usuario con los datos que se encuentran en los archivos, los cuales posteriormente serían metidos dentro de la pila para que se puedan consultar. Ahora ya desarrollé éste criterio, y se puede observar también en los detalles que agregué a la función. Por ejemplo, agregué también la línea de código 

transform(searchTitle.begin(), searchTitle.end(), searchTitle.begin(), ::tolower);
y
transform(currentTitle.begin(), currentTitle.end(), currentTitle.begin(), ::tolower);

para convertir los datos de las pilas y las entradas de búsqueda del usuario a minúsculas para que sin importar si el usuario ingresa una búsqueda en todo minúsculas o todo mayúsculas, mezclado o normal, el sistema pueda regresar la búsqueda de manera satisfactoria. 

#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.
La base de datos principal que maneja éste programa es a base de textos. De éstos, se obtienen los datos anteriormente cargados por el usuario para que así, no tenga que volver a ingresarlos todos al momento de reiniciar el programa. 
La función en la que se observa todo el mecanismo de carga de datos a la pila es readFileAndPushToStack(const string& filename, Stack& stack) en la que se toman el nombre del archivo y el nombre de la pila para que del archivo se carguen los datos a la pila.
Existen tres archivos; artist.txt, title.txt, y year.txt. En cada uno de los archivos, se encuentran todos los datos de las canciones, sin embargo, el dato "artista" está primero en artist.txt, el título en title.txt, y el año en year.txt. Son hechos de ésta manera con el fin de que el orden por tipo de dato sea más fácil. 
Cada archivo tiene su pila correspondiente, y la función readFileAndPushToStack se encarga de cargar desde los archivos los datos a la pilas. Posteriormente, las pilas son utilizadas en las funciones. 
Lo principal que aprendí de la implementación de mecanismos de carga de datos es que no tiene que ser tan complejo el mecanismo. Sólo tuve que crear la función y posteriormente utilizar las pilas dentro de las funciones que las requerían. Considero que ésta función es donde más se puede observar el desarrollo de ésta competencia.


### Implementa mecanismos de escritura de archivos para guardar los datos  de las estructuras de manera correcta
En el programa, hay una función ingresarCancion() en la que el usuario puede ingresar una canción al sistema y el mismo guarda los datos dentro de los archivos artist, title y year, en su orden correspondiente. 
El usuario ingresa el título, artista y año de lanzamiento de la canción y éstos utilizan la función getline para guardar las líneas de texto dentro de los archivos. Posteriormente, se cierra el archivo.
Tuve pocos aprendizajes en ésta área pero sí existieron. Aprendí que utilizar ios:app como indicador para abrir el archivo sirve para que el archivo no borre los datos ya almacenados en él cuando se reinicia el programa. También aprendí la funcionalidad de "cerr" (aunque por ahora no sea necesario, puede ser útil en el futuro). Todos éstos desarrollos pueden verse dentro de la función ingresarCancion(). 