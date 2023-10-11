#include "utils.h"
#include <stdio.h>
#include <stdarg.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

/**
 *  println
 * 
 *  Stampa sullo schermo cosa stampa printf più una nuova riga (newline)
 * 
 *  Parametri:
 *      const char * fmt, ...
 *      
 *      fmt: la stringa da stampare. 'fmt' vuol dire 'format'
 *      
 *      ...: altri parametri per formattare 'fmt'
 * 
 *  Return:
 *      nulla
 */
void println(const char * fmt, ...) {
    va_list args;
    va_start(args, fmt);
    
    vprintf(fmt, args);
    printf("\n");
    
    va_end(args);
}

/**
 *  printwln
 * 
 *  Stampa sullo schermo cosa stampa vw_printw più una nuova riga (newline).
 *  La funzione vw_printw è una funzione di ncurses che permette di stampare
 *  alla sua finestra (window).
 * 
 *  Parametri:
 *      const char * fmt, ...
 *      
 *      fmt: la stringa da stampare. 'fmt' vuol dire 'format'
 *      
 *      ...: altri parametri per formattare 'fmt'
 * 
 *  Return:
 *      nulla
 */
void printwln(const char * fmt, ...) {
    va_list args;
    va_start(args, fmt);
    
    vw_printw(stdscr, fmt, args);
    printw("\n");
    
    va_end(args);
}

/**
 *  getln
 * 
 *  Prende l'input dell'utente finche non preme il tasto
 *  'Enter' cioè l'invio.
 * 
 *  Meglio di scanf perchè prende tutto ciò che nel buffer.
 * 
 *  Parametri:
 *      nessuno
 * 
 *  Return:
 *      char * line
 * 
 *      line: una stringa che contiene l'input dell'utente
 */
char* getln() {
    int size = 1;
    int allocSize = 1;
    char * line = malloc(allocSize);
    line[0] = '\0';

    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        line[size - 1] = ch;

        size++;
        if (size >= allocSize) {
            allocSize *= 2;
            line = (char*) realloc(line, allocSize);
        }
    }
    
    char * string = malloc(size);
    memcpy(string, line, size);
    string[size - 1] = '\0';
    free(line);

    return string;
}

/**
 *  toDouble
 *  
 *  Prende una stringa e la converte in un tipo double.
 * 
 *  Consente di avere una stringa non conforme alla normalità
 *  cioè stringhe con input strane tipo "12.232edfs" oppure
 *  "   1232,231dkj 24", etc.
 * 
 *  Supporta anche la comma come punto.
 * 
 *  Parametri:
 *      const char * string, ...
 *  
 *      string: la stringa di fare la conversione
 * 
 *      ...: il primo argomento è di tipo boolean
 *           che se vero allora usa anche la comma
 *           come punto.
 *           E' in modalita variadica cioè "..."
 *           per evitare di chiamare toDouble mettendo
 *           'false' se non abbiamo bisogno la
 *           funzionalità di usare la comma.
 * 
 *  Return:
 *      double num
 * 
 *      num: il numero double convertito dalla stringa
 */
double toDouble(const char * string, ...) {
    double num = 0.0;
    int pos = 0;
    bool isNeg = false;
    bool dotFound = false;
    bool useComma = false;

    va_list args;
    va_start(args, string);
    useComma = va_arg(args, int) == true;
    va_end(args);

    for (int i = 0; isspace(string[i]); i++, pos++);

    isNeg = string[pos] == '-';
    if (isNeg) pos++;

    for (int decPlace = 1; isdigit(string[pos]) || string[pos] == '.' || (useComma && string[pos] == ','); pos++) {
        if (string[pos] == '.' || (useComma && string[pos] == ',')) {
            if (dotFound) break;

            dotFound = true;
            continue;
        }

        int digit = string[pos] - '0';
        if (!dotFound) {
            num *= 10;
            num += digit;
        } else {
            double dec = digit / pow(10, decPlace);
            decPlace++;
            num += dec;
        }
    }

    if (isNeg) num *= -1;

    return num;
}

/**
 *  getDouble
 * 
 *  Prende un input di tipo double dall'utente.
 * 
 *  Parametri:
 *      nessuna
 *  
 *  Return:
 *      double num
 *  
 *      num: l'input double dell'utente
 */
double getDouble() {
    char * input = getln();
    double num = toDouble(input);
    free(input);
    return num;
}

/**
 *  getDoubleComma
 * 
 *  Prende un input di tipo double dall'utente e
 *  permette l'utente di usare la comma come punto.
 * 
 *  Così piu' "Italian-friendly".
 * 
 *  Parametri:
 *      nessuna
 *  
 *  Return:
 *      double num
 *  
 *      num: l'input double dell'utente
 */
double getDoubleComma() {
    char * input = getln();
    double num = toDouble(input, true);
    free(input);
    return num;
}
