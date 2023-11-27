#include <stdio.h>
#include <stdlib.h>
#include "lib/arrayutils.h"
#include "lib/utils.h"
#include "lib/test.h"

const char *options[] = {
    "Inserimento Array",
    "Mostrare Array",
    "Trovare Somma",
    "Trovare Moltiplicazione",
    "Trovare Media",
    "Cercare Indice di un Elemento",
    "Trovare Massimo Valore",
    "Trovare Minimo Valore",
    "Inversa Array",
    "Ordina Array",
    "Esci"
};
const int optionsSize = sizeof(options) / sizeof(options[0]);
enum MenuOptions {
    INSERT_OPTION,
    SHOW_OPTION,
    SUM_OPTION,
    MULTIPLY_OPTION,
    AVERAGE_OPTION,
    FIND_ELEMENT_OPTION,
    FIND_MAX_OPTION,
    FIND_MIN_OPTION,
    REVERSE_OPTION,
    SORT_OPTION,
    EXIT_OPTION
};

void pause();
double *insertArray(int *outLength);

int main() {
    int length = 0;
    double *array = NULL;

    int option = 0;
    while ((option = showInteractiveMenu("Scegliere l'operazione:", options, optionsSize, option)) != EXIT_OPTION) {
        system("clear");

        switch (option) {
        case INSERT_OPTION:
            free(array);
            array = insertArray(&length);
            break;
        case SHOW_OPTION:
            printf("Il contenuto dell'array e' ");
            printArray(array, length);
            println("\n");
            pause();
            break;
        case SUM_OPTION:
            println("La somma dell'array e' %.2lf", sumArray(array, length));
            println("");
            pause();
            break;
        case MULTIPLY_OPTION:
            println("La moltiplicazione dell'array e' %.2lf", multiplyArray(array, length));
            println("");
            pause();
            break;
        case AVERAGE_OPTION:
            println("La media dell'array e' %.2lf", averageArray(array, length));
            println("");
            pause();
            break;
        case FIND_ELEMENT_OPTION:
            printf("Inserire l'elemento da cercare: ");
            double toFind = getDoubleComma();
            println("");

            int index = indexOf(toFind, array, length);
            if (index == -1) {
                println("L'elemento non esiste nell'array!");
            } else {
                println("L'elemento si trova nell'indice %d.", index);
            }

            println("");
            pause();
            break;
        case FIND_MAX_OPTION:
            println("Il valore massimo nell'array e' %.2lf", findMax(array, length));
            println("");
            pause();
            break;
        case FIND_MIN_OPTION:
            println("Il valore minimo nell'array e' %.2lf", findMin(array, length));
            println("");
            pause();
            break;
        case REVERSE_OPTION:
            reverseArray(array, length);
            printf("L'array e' stato inversato: ");
            printArray(array, length);
            println("\n");
            pause();
            break;
        case SORT_OPTION:
            mergesort(array, length);
            printf("L'array e' stato ordinato: ");
            printArray(array, length);
            println("\n");
            pause();
            break;
        }
    }

    free(array);

    system("clear");
    println("Programma terminato.");

    return 0;
}

void pause()
{
    println("Premere 'Invio' per continuare...");
    free(getln());
}

double *insertArray(int *outLength)
{
    int length;
    while (true) {
        printf("Inserire la dimensione dell'array: ");
        length = getDouble();

        if (length <= 0) {
            println("[ERRORE] La dimensione non puo' essere 0!");
            println("");
            continue;
        }

        break;
    }
    println("");

    double *array = malloc(length * sizeof(double));
    println("[INFO] La comma e' supportato. Esempio: 12,4");
    for (int i = 0; i < length; i++) {
        printf("Inserire l'elemento %d: ", i);
        array[i] = getDoubleComma();
    }

    if (outLength != NULL) *outLength = length;

    return array;
}
