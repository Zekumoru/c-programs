/******************************************************************************

Operazioni Matematiche Di Base
Data: Ott 10, 2023

Descrizione
    Il programma fa le quattro operazioni di base
    della matematicascelto dall'utente:
        1. Addizione 
        2. Sottraezione 
        3. Moltiplicazione 
        4. Divisione


*******************************************************************************/
#include <stdio.h>
#include "lib/menu.h"
#include "lib/utils.h"
#include "lib/basicmath.h"

int main(){
    int option = 0;
    
    while (option != QUIT_OPTION) {
        option = showInteractiveMenu();
        
        double n1, n2;
        double result;
        
        if (option >= ADD_OPTION && option < QUIT_OPTION) {
            if (option == ADD_OPTION) {
                println("ADDIZIONE");
            } else if (option == SUBTRACT_OPTION) {
                println("SOTTRAEZIONE");
            } else if (option == MULTIPLY_OPTION) {
                println("MOLTIPLICAZIONE");
            } else {
                println("DIVISIONE");
            }
    
            println("");

            printf("Inserisci primo numero (puoi usare la comma invece di punto): ");
            n1 = getDoubleComma();
        
            printf("Inserisci secondo numero (puoi usare la comma invece di punto): ");
            n2 = getDoubleComma();
            
            println("");
        }
        
        switch (option) {
            case ADD_OPTION:
                result = add(n1, n2);
                println("%lf + %lf = %lf", n1, n2, result);
                break;
            case SUBTRACT_OPTION:
                result = subtract(n1, n2);
                println("%lf - %lf = %lf", n1, n2, result);
                break;
            case MULTIPLY_OPTION:
                result = multiply(n1, n2);
                println("%lf * %lf = %lf", n1, n2, result);
                break;
            case DIVIDE_OPTION:
                result = divide(n1, n2);
                println("%lf / %lf = %lf", n1, n2, result);
                break;
            case QUIT_OPTION:
                break;
            default:
                println("Non hai scelto giusto!");
        }
        
        if (option != QUIT_OPTION) {
            println("");
            println("Premere 'Enter' ovvero l'invio per tornare al menu...");
            getln();
        }
    }
    return 0;
}
