/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "screen.h"

void gotoxy(int x,int y){
    printf("%c[%d;%df",0x1B,y,x);
}

/* 
#include <cstdio>
#include <windows.h>
void GotoXY(int x, int y) // en windows
{
 COORD coord;
 coord.X = x;
 coord.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
*/

void clearScreen(void){

    for(int r=0;r<SCREEN_NR;r++)
        for(int c=0;c<SCREEN_NC;c++){
            gotoxy(c+1,r+1);
            printf(" ");
        }
}

void setColor(int idxColor){
    //printf("\x1B[0m"); return;
    switch (idxColor) {
        case I_NRM:
            printf("\x1B[0m");
            break;
        case I_RED:
            printf("\x1B[31m");
            break;
        case I_GRN:
            printf("\x1B[32m");
            break;
        case I_YEL:
            printf("\x1B[33m");
            //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_YELLOW);
            break;
        case I_BLU:
            printf("\x1B[34m");
            break;
        case I_MAG:
            printf("\x1B[35m");
            break;
        case I_CYN:
            printf("\x1B[36m");
            break;
        case I_WHT:
            printf("\x1B[37m");
            break;
    }

}

/*
// en windows
#include <windows.h>
//Define extra colours
#define FOREGROUND_WHITE        (FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN)
#define FOREGROUND_YELLOW           (FOREGROUND_RED | FOREGROUND_GREEN)
#define FOREGROUND_CYAN             (FOREGROUND_BLUE | FOREGROUND_GREEN)
#define FOREGROUND_MAGENTA          (FOREGROUND_RED | FOREGROUND_BLUE)
#define FOREGROUND_BLACK        0

#define FOREGROUND_INTENSE_RED      (FOREGROUND_RED | FOREGROUND_INTENSITY)
#define FOREGROUND_INTENSE_GREEN    (FOREGROUND_GREEN | FOREGROUND_INTENSITY)
#define FOREGROUND_INTENSE_BLUE     (FOREGROUND_BLUE | FOREGROUND_INTENSITY)
#define FOREGROUND_INTENSE_WHITE    (FOREGROUND_WHITE | FOREGROUND_INTENSITY)
#define FOREGROUND_INTENSE_YELLOW   (FOREGROUND_YELLOW | FOREGROUND_INTENSITY)
#define FOREGROUND_INTENSE_CYAN     (FOREGROUND_CYAN | FOREGROUND_INTENSITY)
#define FOREGROUND_INTENSE_MAGENTA  (FOREGROUND_MAGENTA | FOREGROUND_INTENSITY)

// ejemplo de poner un color

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_YELLOW);
*/