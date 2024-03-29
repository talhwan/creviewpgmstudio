#include "guest.h"
#include "menu.h"

#include <stdio.h>

int main(){
    displayMenu();
    displayGuest();
    return 0;
    /*
    PS C:\workspace\psproject\week4> gcc -c main.c
    PS C:\workspace\psproject\week4> gcc -c menu.c
    PS C:\workspace\psproject\week4> gcc -c guest.c
    PS C:\workspace\psproject\week4> gcc main.c guest.o menu.o -o shop
    PS C:\workspace\psproject\week4> ./shop
    */
}