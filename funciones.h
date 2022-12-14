#include <stdio.h>
#include <stdlib.h>
#include "screen.h"

// 1 = bold; 5 = slow blink; 31 = foreground color red
// 34 = foreground color blue

#define COLOR_BOLD  "\e[1m"
#define COLOR_OFF   "\e[m"
#define COLOR_BOLD_SLOW_BLINKING      "\e[1;5m"
#define COLOR_BOLD_SLOW_BLINKING_RED  "\e[1;5;31m"
#define COLOR_BOLD_BLUE               "\e[1;34m"



// Selector de combatientes  
void selector ();

//Funcion recursiva 
int mejor_pokemon (int seleccionado, int tipo_a_encontrar); 

//Manera de almancenar los pokemon
typedef struct pokemonStruct
{
	char * name; 
	char * tipo; 
	int type; 
} pokemon; 


//Imprime el menu en pantalla 
void menu();

//Acciones del menu 
void acciones(int option); 

//Inicializa los pokemon 
void inicializar(); 
	

//Obtencion del tipo 

void tipo (pokemon *x); 


//Comparacion del tipo
void  comparar (pokemon * propio, pokemon *oponente); 



// Elegir el color en base al tipo 

int selectColor(int x); 


// Comparar los multiplicadores por tipo 
float  advantaje (int x, int  y); 
int weakness (int  x, int y);


// Imprime una lista de los pokemon disponibles 
void listas (); 
void lista(); 
void lista_oponentes(); 

// Permite al usuario seleccionar a su pokemon 

//
void selectPokemon(); 

//Exit 
void salir (); 
