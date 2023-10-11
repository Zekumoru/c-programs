#ifndef UTILS_H
#define UTILS_H

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
void println(const char * fmt, ...);

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
void printwln(const char * fmt, ...);

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
char* getln();

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
double toDouble(const char* string, ...);

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
double getDouble();

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
double getDoubleComma();

#endif
