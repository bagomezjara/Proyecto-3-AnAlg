En este archivo se podran encontrar 3 codigos fuentes, los cuales corresponden al codigo de comparacion de secuencias de forma bottom-up con tabulacion y
top-down con memorization, tambien se encontrara el codigo fuente de nuestra implementacion de VertexCover de 2 aproximado.

1)	Primero revisaremos el codigo de comparacion de secuencias bottom-up con tabulacion.
	Nuestra implementacion lo que haces es usa usar una matriz de enteros como tabla para guardar los puntajes acumulados de las comparaciones de las
	secuencias. Para nuestra implementacion utilizamos 2 funciones, la primera llamada reglas llena la tabla de los valores optimos acumulados y entra
	la ultima casilla, que contendra el puntaje optimo de las secuencias, la segunda funcion llamada optimo usa un stack y compara los valores de la matriz
	y hace push de los caracteres de los strings si es que conviene que hagan match o mismatch y hace push al caracter '-' en el caso donde la mejor solucion,
	basandose en la matriz, indica que es mejor añadir el caracter.
	
 	°Para compilar el codigo se necesitan hacer 2 simples pasos
	1-$ g++ bottomup.cpp -o *nombre ejecutable*
	1-$./*nombre ejecutable*
	
	°Para usar el codigo se pide entregar por terminal la primera secuendia, presionar enter y entregar la segunda secuencia, luego el codigo
	entregara el score maximo de las secuencias optimas y luego 2 string separados por un salto de linea indicando las secuencias optimas
	
2)	Ahora se revisara el codigo de comparacion de secuencias top-down con memorization.
	Nuestra implementacion lo que hace es utilizar una matriz que guarda los valores de los score asignados, luego usamos la matriz para revisar
	si ese subproblema fue resuelto antes, si no es el caso la funcion se llama recursivamente y compara los 3 casos posibles en las 2 direcciones posibles,
	este proceso ocurre hasta que se llegue al caso base, en cual caso entre el valor de la casilla. Luego se usa la funcion optimo que utiliza stacks para 
	encontrar y crear el par de strings optimo que tenga el score optimo dado por la funcion reglasrec.
	
	°Para compilar el codigo se necesitan hacer 2 simples pasos
	1-$ g++ topdown.cpp -o *nombre ejecutable*
	1-$./*nombre ejecutable*
	
	°Para usar el codigo se pide entregar por terminal la primera secuendia, presionar enter y entregar la segunda secuencia, luego el codigo
	entregara el score maximo de las secuencias optimas.
		
3)	Finalmente se revisar nuestra implmentacion de VertexCover 2 aproximado.
	Nuestra implementacion usa una estrucutra de grafo que nos ayuda a guardar los vertices y aristas, asi mismo culaes esta cubiertas, tambien usamos
	distintas funciones para obtener las aristas y vectores del grafo, para el algoritmo de vertex cover, basicamente almacena las aristas y vertices
	cubiertos del grafo y los compara, eliminando acquellos que se encuentran repetidos.
	
	°Para compilar el codigo se necesitan hacer 2 simples pasos
	1-$ g++ VC.cpp -o *nombre ejecutable*
	1-$./*nombre ejecutable*
	
	°Para utilizar el codigo primero se pedira ingresar el numero de nodos que va a tener el grafo.
	Luego se pedia ingresar las aristas del grafo, estas deben ser ingresadas de la siguiente forma:
	si se quiere ingresar la arista que conecta el nodo 1 y 2 se ingresara "1 2" en la terminañ, luego se presiona enter, si se quiere terminar de ingresar
	las aristas se debera escribir en la terminal "0 0".
	Finalmente se imprimira por pantalla los vectores que representa el vertex cover 2 aproximado del grafo.