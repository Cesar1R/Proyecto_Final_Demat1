
Proyecto: "Asistente en batallas Pokemon"

Importante: Se usan algunas funciones que estan definidas para ejecutarse en entornos basados en unix, tales como las contenias en screen.h entre otras. 

El codigo esta comentado parcialmente, considero que lo mas importante se describe claramente en este archivo y los pocos comentarios junto con el nombre de las variables hacen legible el codigo 


Sinapsis: El asistente se muestra en consola y presenta 4 opciones. A lo largo del reporte se profundizara en el codigo que alimenta a cada funcion, asi como de los demas archivos que se muestran en la carpeta comprimida. 

Comencemos por los archivos .txt
-Datos.txt
	El primero es datos.txt donde se presentan dos tablas,representan el multiplicador de cada tipo de las filas hacia los tipos de las cabeceras de las columnas. 

	Despues sigue una lista donde en la primera columna se muestra un tipo y se sigue en la fila de los nombres de 2 pokemon que son del tipo respectivo. 

	Despues se muestra la numeracion que se da a cada tipo, es decir a lo largo del codigo, cuando nos refiramos a un tipo numericamente se hara con los valores asignados en esta tabla. 

-pokemon_contrincantes/pokemon_elegibles.txt
	Estos dos archivos se conforman de la primera linea un numero natural n que representa la cantidad de datos que contiene cada archivo, son n cadenas que representan nombres de pokemon. En pokemon contrincantes son aquellos que se podran usar en la primer opcion del menu, se profundizara mas adelante. 

Sigamos con los archivos .h
	En este proyecto se hace uso de dos cabezeras creadas y algunas tracionales como stdio.h y stdlib.h
-screen.h
	Este archivo contiene 3 funciones principales gotoxy, clearScreen, setColor, las cuales se usan con fines visuales en el codigo, este archivo como el screen.c se dieron como recurso durante el curso. 
-funciones.h
	En este archivo estan las funciones que se crearon especificamente para este proyecto, ademas de las funciones tambien se declara una struct que renombramos con pokemon, aqui se almacenan todas las caracteristicas. Posteriormente se profundizara en las demas funciones. Hay algunas macros que se usan para darle otro aspecto al texto en consola. 

Al ultimo pero no menos importante hablaremos de los archivos .c
-screen.c 
	Contiene las funcines definias en screen.h, nuevamente, solo es con fines de mostrar cosas en consola. 
-funciones.c
	Hemos llegado a la parte donde profundizaremos en cada funcion, no todas las funciones que son utilizadas son las que estan en este archivo, hay un par o dos que estan en el archivo principal, es por eso que me limitare a decir que este archivo se pueden encontrar algunos comentarios que creo pueden ayudar a entender mejor el proceso que siguen las funciones, ademas, los nombres de las funciones y las variables me parece que son claros, sin embargo cabe resaltar que pk es una abreviacion de pokemon, este nombre se usa en algunos punteros a la estructura que definimos en funciones.h. 

-asistente_batallas_pokemon.c
	Primero se incluyen las cabeceras necesarias a travez de funcion.h,  y declaramos como variables globales a 10 pokemon, dentro de la funcion main, solo se llama a la funcion inicizliar(), la cual, por medio de apuntadores llena los datos de todos los obtejos pokemon declarados al inicio, llena su nombrem su tipo de manera numerica y alfabetica, con las referencias de la tabla del archivo datos.txt, y despues se hace una unica llamada a la funcion menu(), en esta funcion se imprime la pantalla de titulo y las opciones, recolecta la opcion que digite el usuario y manda llamar a la funcion acciones(), esta funciones unicamente es un swicht que manda llamar la funcion correspondiente a lo que digite el usuario. 

	Comencemos por selector(), que corresponde a la primera opcion que presenta el menu, en esta opcion el usario elige un pokemon de la lista de oponentes y el codigo a traves de recursividad elige el mejor tipo para estar en una batalla con el pokemon elegido. 

	Sigamos con la segunda opcion, Comparar pokemon, aqui se despliegan las listas de pokemon posibles, las funciones que muestran los nombres leen desde los archivos .txt lo mas resaltable de esta opcion es que utiliza punteros a las struct pokemon para obtener datos y poder hacer la comparacion

	La 3era opcion unicamente imprime las listas de las que hablamos anteriormente, se hizo uso de punterios tipo FILE para poder abrir y obtener los datos de los archivos .txt 

	Por ultimo, la cuarta opcion es salir del menu

	Cabe resaltar que cada una de las funciones al finalizar pregunta al usuario si desea volver al menu o salir. Resumiendo, en este proyecto se hizo uso de variables globales, recursividad, funciones, creacion de ficheros, apuntadores, estructuras struct y swicht, definicion de tipos y manipulacion de archivos de txt desde el codigo en C. 




