#include "funciones.h"



//Obtener el tipo 
void tipo (pokemon *  x)
{
	//printf("Tipo -> ");
	setColor(selectColor(x -> type));
	printf("%s  ", x -> tipo );
	

	return; 
}


int selectColor(int x)
{ // Elige un color de screen.h que combine con el tipo 
	switch(x)
	{		
		case 1: 
  			return 1;
  				break;
  				
  		case 2: 
  			return 4;
  				break; 
  		case 3: 
  			return 6; 
  				break; 
  		case 4: 
  			return 3;
  				break; 
  		case 5:   
  			return 5; 
  				break;
  
  		default:
  			return 0; 
	  			break;
	}  
}

// Menu 


void menu ()
{	
	int option = 0; 

	clearScreen();	
		
		//printf(" ----------------------------------");
		printf("\033[47m"); // banda gris 
		gotoxy(23, 3); 
		setColor(1); // imprime rojo 
		printf(" \033[5m Asistente "); //  parpadea
		printf("\033[30m de batallas"); // negro/gris
		printf("\033[37 m  Pokemon "); // blanco 
		setColor(0); 

		printf("\n");

		gotoxy(22, 8); 
		printf("\t \t MENU \n");
		gotoxy(22, 9);
		printf("1.- Elegir al mejor combatiente  \n");
		gotoxy(22, 10);
		printf("2.- Comparar pokemon especificos \n");
		gotoxy(22, 11);
		printf("3.- Consultar la lista de pokemon disponibles \n");
		gotoxy(22, 12);
		printf("4.- Salir \n");

		gotoxy(25, 15); 
		printf(" \033[5m --->  \x1B[0m" );

		scanf("%d", &option); 

		printf("%d ", option );
		acciones(option); 
}

//Acciones del menu 
void acciones(int option)
{ // Recibe parametros de la funcion menu y llama a otra funcion
	switch (option)
	{
		case 1: 
			selector(); 
			break; 
		case 2: 
			selectPokemon();  
			break; 
		case 3: 
			listas(); 
			 break; 
		case 4: 
			salir(); 
		default: 
			break;  
	}

}

//Comparar el tipo
void  comparar (pokemon * propio, pokemon *oponente)
{	
	int tipo_oponente; 
	int   debilidad; 
	float ventaja; 
	int color_propio = selectColor (propio -> type); 
	int color_oponente = selectColor (oponente -> type);  




	tipo_oponente = oponente -> type;

	// printf("Usted ha elegido comparar un pokemon de tipo: %s contra uno de tipo %s \n", propio.tipo, oponente.tipo);

	ventaja = advantaje((float)propio-> type, oponente-> type);
	debilidad = weakness((float)propio -> type, oponente -> type); 

	clearScreen();

	printf("\t \t \t Usted ha elegido compara  a: \n \n ");
	printf("Nombre: ");
	setColor(color_propio);
	printf("\t  %s ", propio -> name);
	setColor(color_oponente); 
	printf("\t \t  %s\n", oponente -> name);
	setColor(0); 
	printf(" Tipo:\t \t  "); 
	tipo(propio);
	setColor(0);
	printf("\t \t "); 
	tipo(oponente); 
	setColor(7);
	printf("\n Multiplicador \t %0.1f \t \t \t  %d ", ventaja, debilidad);



	setColor(2);
	printf("\n ------------------------------------------------- \n ");

	setColor(0);


	/*

	Despues de imprimir en consola la informacion de ambos pokemon 
	los compara y arroja una conclusion teniendo en cuenta la ventaja y debilidad que tiene el primero respecto al segundo 
	*/


	if(ventaja > debilidad)
		printf("Parece que %s tiene mejores atributos \n ", propio-> name);
	else if (debilidad > ventaja)
		printf(" El tipo de %s le da mayor ventaja en combate \n", oponente -> name);
	else 
		printf("Vaya, parece son igual de fuertes, intenta compara a pokemon con \n tipos disntintos\n");


	printf(" \n Para salir presione 0, para regresar al menu presione cualquier otra tecla \n  \t \t ->");
	int opcion; 
	scanf("%d", &opcion); 
	if (opcion)
	{
		menu();
	}
	else
		salir(); 
}



float  advantaje (int x, int  y) 
{	// Usando la informacion del archivo datos.txt 
	// la tabla ventajas
	// regresa el multiplicador del ataque teniendo como argumento los tipos 
	// en la estructura este valor se identifica como type 
	switch (x)
	{
		case 1: 
			if (y == 4)
				return 0.5;
			return 1;  
			break; 
		
		case 2: 
			if (y == 4)
				return 2; 
			return 1; 
			break;

		case 3:
			if (y == 4)
				return 0.5; 
			if(y == 5)
				return 0; 
			return 1; 
			break; 

		default: 
			break;  
	}			
}


int weakness (int  x, int y)
{
	// Usando la informacion del archivo datos.txt 
	// la tabla desventajas 
	// regresa el multiplicador del ataque teniendo como argumento los tipos 
	// en la estructura este valor se identifica como type 


	switch(x)
	{
		case 1: 
			if( y == 4)
				return 2; 
			return 1; 
			break; 

		case 2: 
			return 1; 
			break; 

		case 3: 
			if(y == 5)	
				return 0; 
			return 1; 
			break; 

		default:
			break; 
	}

}



void lista () 
{
	clearScreen();

	printf("\t \t  Pokemon disponibles para elegir :\n");
	printf(" \t \n");
	//se abre el archivo donde estan almacenados los nombres de los pokemon 
	FILE *fp; 
	char buffer [100]; 
	fp = fopen ("pokemon_elegibles.txt", "r"); 

	int n; 
	fscanf(fp, "%d", &n); 
	//fscanf(fp, "\n");
	// Se lee cuantos datos hay y se imprimen todos 
	for (int i = 0; i < n; ++i)
	{
		fscanf(fp, "%s" ,buffer); 
 		printf("\t \t % d -%s", i + 1, buffer);
 		printf("\n");
 	}

	fclose(fp); 
}

void lista_oponentes ()
{
	
	printf("\n");
	printf("\t   Pokemon como oponentes disponibles :\n");
	printf(" \t \n");
	// Se abre el archivo donde estan guardados los datos
	FILE *fp; 
	char buffer [100]; 
	fp = fopen ("pokemon_contrincantes.txt", "r"); 

	int n; 
	fscanf(fp, "%d", &n); 
	//fscanf(fp, "\n");
	// Se imprimen todos los nombres en el archivo 
	for (int i = 0; i < n; ++i)
	{
		fscanf(fp, "%s" ,buffer); 
 		printf("\t \t % d -%s", i + 1, buffer);
 		printf("\n");
 	}

	fclose(fp);
}

void listas()
{

	// Imprime el contenido de las listas de pokemon disponibles 
	lista(); 
	lista_oponentes(); 

	int seleccion; 

	printf("Para volver al menu presione cualquier tecla , para salir 0 \n ->");
	scanf("%d", &seleccion); 

	if (seleccion)
		menu();
	else
		salir(); 
}


// Exit 
void salir()
{	system("exit"); }


