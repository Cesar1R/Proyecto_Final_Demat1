#include "funciones.h"


	pokemon Vulpix;
	pokemon Meowth;
	pokemon Wartortle;
	pokemon Dunsparce;
	pokemon Entei;
	pokemon Dusknoir;
	pokemon Misdreavus;
	pokemon Cranidos;
	pokemon Sudowoodo;
	pokemon Zangoose;

int main()
{

	inicializar(); 
	menu();

	return 0;
}


void selectPokemon() 
{
	int pokemon1, pokemon2; 
	pokemon *pk1, *pk2; 
	lista(); 
	lista_oponentes(); 


	printf("\n \tDigite un numero de cada lista anterior \n   \n \n  //para volver al menu anterior  digite al menos un 0 o ambos\\\\ \n \n \t \t -->  "); 
	scanf("%d %d", &pokemon1, &pokemon2); 

	if (pokemon2 == 0 || pokemon1 == 0)
		menu(); 
	else
	{

		switch(pokemon1)
		{
			case 1: 
				pk1 = &Wartortle; 
				break; 

			case 2: 
				pk1 = &Dunsparce; 
				break;
			case 3: 
				pk1 = &Vulpix; 
				break; 
			case 4: 
				pk1 = &Entei;
				break; 
			case 5: 
				pk1 = &Meowth; 
				break; 

			case 6: 
				pk1 = &Zangoose; 
				break; 

			default: 
				break; 
		}

		switch(pokemon2)
		{
			case 1: 
				pk2 = &Meowth; 
				break;

			case 2: 
				pk2 = &Zangoose; 
				break; 

			case 3: 
				pk2 = &Sudowoodo; 
				break; 

			case 4: 
				pk2 = &Cranidos; 
				break; 

			case 5: 
				pk2 = &Misdreavus; 
				break; 

			case 6: 
				pk2 = &Dusknoir; 
				break; 

			default:
				break; 


		}

		comparar(pk1, pk2); 
		
	} 


}

void inicializar() 
{
	pokemon * vp  = &Vulpix; 
	vp -> name = "Vulpix";  
	vp -> tipo = "fuego"; 
	vp -> type = 1; 

	pokemon * wrt = &Wartortle; 
	wrt -> name = "Wartortle"; 
	wrt -> tipo = "agua"; 
	wrt -> type = 2; 

	pokemon * dnp = &Dunsparce; 
	dnp -> name = "Dunsparce";
	dnp -> tipo = "agua";
	dnp -> type = 2; 

	Entei.name = "Entei"; 
	Entei.tipo = "fuego";
	Entei.type =1; 

	Meowth.name = "Meowth"; 
	Meowth.tipo = "normal"; 
	Entei.type = 3; 

	Zangoose.name = "Zangoose";
	Zangoose.tipo = "normal";
	Zangoose.type = 3; 

	Sudowoodo.name = "Sudowoodo"; 
	Sudowoodo.tipo = "roca"; 
	Sudowoodo.type = 4; 

	Cranidos.name = "Cranidos"; 
	Cranidos.tipo = "roca"; 
	Cranidos.type = 4; 

	Misdreavus.name = "Misdreavus"; 
	Misdreavus.tipo = "fantasma"; 
	Misdreavus.type = 5; 

	Dusknoir.name = "Dusknoir"; 
	Dusknoir.tipo = "fantasma"; 
	Dusknoir.type = 5; 


}


void selector ()
{	
	clearScreen(); 
	gotoxy(23, 3);
	
	lista_oponentes(); 
	pokemon * pk2; 

	printf("\tSelecciona un oponente \n \t -> ");

	int oponente; 
	scanf("%d", &oponente);

	switch(oponente)
	{
		case 1: 
			pk2 = &Meowth; 
			break;

		case 2: 
			pk2 = &Zangoose; 
			break; 

		case 3: 
			pk2 = &Sudowoodo; 
			break; 

		case 4: 
			pk2 = &Cranidos; 
			break; 

		case 5: 
			pk2 = &Misdreavus; 
			break; 

		case 6: 
			pk2 = &Dusknoir; 
			break; 

		default:
			break; 
	}
	
	char * palabras [] = {"Fuego", "Agua", "Normal"}; 
	printf("Lo mejor seria elegir un pokemon de tipo %s \n", palabras[mejor_pokemon(pk2 -> type, 1) - 1]);

	int a; 
	printf("\n Para regresal al menu presione cualquier tecla, para salir presione 0\n -> ");
	scanf("%d", &a); 
	

	if (a)
		menu();
	else
		salir();

}


int mejor_pokemon (int seleccionado, int tipo_a_encontrar)
{
	if (tipo_a_encontrar > 3 )
	{
		return tipo_a_encontrar; 
	}


	int ventaja_actual = advantaje(tipo_a_encontrar, seleccionado); 
	int ventaja_siguiente = advantaje(tipo_a_encontrar + 1, seleccionado); 
	return ventaja_siguiente >= ventaja_actual ? (tipo_a_encontrar + 1) : (tipo_a_encontrar); 

}