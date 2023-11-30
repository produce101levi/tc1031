# tc1031
DESCRIPCIÓN DE CADA EJERCICIO:

EEJERCICIO 1
En éste código iniciamos con las librerías iostream y vector, y luego nos vamos a definir la clase Solution. Abrimos un método público llamado sortColors de tipo void porque no nos va a regresar ningún valor. Éste método toma un vector de enteros por referencia.  Inicializamos una variable de tipo entero n y a ésta le asignamos el tamaño del vector. 
Empezamos con la parte de los ciclos for e if, en donde primero verificamos el rango del tamaño del vector, luego abrimos un ciclo for de iteración sobre cada elemento del vector. Verificamos si el elemento tiene un valor de 0 1 o 2 para después poner el proceso de ordenamiento burbuja. De lo contrario, aquí imprimimos un mensaje de Error.

——————————————————————————————————————————————-
EJERCICIO 2
Ésta función se trata de construir un array utilizando operaciones de pila. Primero definimos la clase Solution, para luego poner un vector de tipo string llamado buildArray que toma un vector y un entero. 
Definimos un vector de string ans para almacenar la secuencia de operaciones, y luego aquí tenemos una función reserve, que viene de la librería vector. Ésto es para reservar el doble del espacio necesario en el vector. Luego definimos la variable input y le asignamos el valor 1. 

El bucle for la variable x recorre cada elemento del vector target, y le agrega "push" y "pop" a la secuencia. La función retorna el vector que representa la secuencia de las operaciones.

—————————————————————————————————————————————-
EJERCICIO 3
Primeramente el código ya nos da la definición de la estructura del árbol binario, y luego nos toca la parte de la definición de la clase Solution, y también está la función height de tipo entero que nos regresa la altura del árbol. Si el nodo es nulo, la altura es 0. Si no, la altura es 1 más la máxima altura entre el subárbol izquierdo y el subárbol derecho. 

Ahora en la funcion de tipo bool, isBalanced, si el árbol es nulo está balanceado, se regresa "true. Se calcula la diferencia de altura entre el subárbol izquierdo y el derecho. La función if balance > 1 o balance < -1 dice que si la diferencia de altura es mayor que 1 o menor que -1 el árbol no está balanceado, por lo tanto regresa un valor de false.

Se verifica entonces el balance de los subárboles con la condicional if(!isBalanced(root->left || !isBalanced(root->right)), recursivamente. Se regresa de ésto un valor de false

Si los dos subárboles son balanceados, el árbol completo está balanceado. Si el programa cumple con todas las condiciones apropiadas, el programa regresa un valor de true para indicar que el árbol está balanceado.


https://leetcode.com/problems/sort-colors/
https://leetcode.com/problems/build-an-array-with-stack-operations/
https://leetcode.com/problems/balanced-binary-tree/solutions/4346948/solution-using-c/

https://leetcode.com/a01620887/

