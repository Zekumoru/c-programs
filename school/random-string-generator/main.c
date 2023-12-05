/**
 * Random String Generator
 * 
 * \brief Shows a menu to set up generation options and generate a random string based on those options.
 * \date 05-Dec-2023
 * \author Sherwin A.
 * 
 * The random string generator has a time complexity of O(n log n) + O(k) where:
 *  - n: refers to the length of the ignore string.
 *       Any characters in the ignore string is ignored by the generator.
 *  - k: refers to the length of the string to generate.
 * 
 * If n == k then the generator has a time complexity of O(n log n).
 * 
 * The generator is done by using a char table which holds the characters to generate
 * and the table is continuous so as to facilitate character generation and to prevent
 * generating characters that are supposed to be ignored.
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "lib/generator.h"
#include "lib/utils.h"

typedef enum MenuOptions {
    TOGGLE_LOWERCASE_OPTION,
    TOGGLE_UPPERCASE_OPTION,
    TOGGLE_DIGIT_OPTION,
    TOGGLE_SPECIAL_OPTION,
    EDIT_STRING_LENGTH_OPTION,
    EDIT_IGNORES_OPTION,
    GENERATE_OPTION,
    EXIT_OPTION,
} MenuOptions;

const char EDIT_LENGTH_OPTION_TEXT[] = "Modificare la lunghezza della stringa (Attuale: %d)";
const char EDIT_IGNORES_OPTION_TEXT[] = "Modificare i caratteri da ignorare (Attuale: %s)";

Menu *createMenu(int stringLength, char *charIgnores);
int editStringLength();
char *editCharIgnores(char *oldCharIgnores);
void generate(const int length, const int charTypes, const char *ignoreChars);

int main()
{
    srand(time(NULL));

    int stringLength = 10;
    char *charIgnores = NULL;
    Menu *menu = createMenu(stringLength, charIgnores);

    MenuItem *item;
    MenuOptions option;
    while ((option = showMenu(menu)) != EXIT_OPTION) {
        switch (option)
        {
        case TOGGLE_LOWERCASE_OPTION:
        case TOGGLE_UPPERCASE_OPTION:
        case TOGGLE_DIGIT_OPTION:
        case TOGGLE_SPECIAL_OPTION:
            menu->items[option]->toggled = !menu->items[option]->toggled;
            break;
        case EDIT_STRING_LENGTH_OPTION:
            item = menu->items[EDIT_STRING_LENGTH_OPTION];
            stringLength = editStringLength();
            free(item->name);
            item->name = createFormattedString(EDIT_LENGTH_OPTION_TEXT, stringLength);
            break;
        case EDIT_IGNORES_OPTION:
            item = menu->items[EDIT_IGNORES_OPTION];
            charIgnores = editCharIgnores(charIgnores);
            free(item->name);
            item->name = createFormattedString(EDIT_IGNORES_OPTION_TEXT, (charIgnores == NULL)? "Non impostato" : charIgnores);
            break;
        case GENERATE_OPTION:
            int charTypes = 0;
            if (menu->items[TOGGLE_LOWERCASE_OPTION]->toggled) {
                charTypes |= LOWERCASE_ALPHA_CHARS;
            }
            if (menu->items[TOGGLE_UPPERCASE_OPTION]->toggled) {
                charTypes |= UPPERCASE_ALPHA_CHARS;
            }
            if (menu->items[TOGGLE_DIGIT_OPTION]->toggled) {
                charTypes |= DIGIT_CHARS;
            }
            if (menu->items[TOGGLE_SPECIAL_OPTION]->toggled) {
                charTypes |= SPECIAL_CHARS;
            }
            generate(stringLength, charTypes, charIgnores);
            break;
        default:
            printf("Errore: opzione di menu non valida\n");
            return -1;
            break;
        }
    }

    destroyMenu(menu);
    free(charIgnores);

    println("Programma terminato con successo.");

    return 0;
}

Menu *createMenu(int stringLength, char *charIgnores)
{
    Menu *menu = malloc(sizeof(Menu));
    menu->title = createString("Spunta uno o più 'tipi di caratteri' per generazione");
    menu->itemsSize = 8;
    menu->items = malloc(menu->itemsSize * sizeof(MenuItem*));
    menu->items[0] = createMenuItem("Caratteri minuscoli", TOGGLE_MENU_ITEM_TYPE);
    menu->items[1] = createMenuItem("Caratteri maiuscoli", TOGGLE_MENU_ITEM_TYPE);
    menu->items[2] = createMenuItem("Caratteri numerici", TOGGLE_MENU_ITEM_TYPE);
    menu->items[3] = createMenuItem("Caratteri speciali", TOGGLE_MENU_ITEM_TYPE);
    menu->items[4] = createMenuItem(EDIT_LENGTH_OPTION_TEXT, BUTTON_MENU_ITEM_TYPE, stringLength);
    menu->items[5] = createMenuItem(EDIT_IGNORES_OPTION_TEXT, BUTTON_MENU_ITEM_TYPE, (charIgnores == NULL)? "Non impostato" : charIgnores);
    menu->items[6] = createMenuItem("Generare una stringa casuale", BUTTON_MENU_ITEM_TYPE);
    menu->items[7] = createMenuItem("Uscire", BUTTON_MENU_ITEM_TYPE);
    menu->prevChoice = 0;
    return menu;
}

int editStringLength()
{
    int length;
    system("clear");

    while (true) {
        printf("Inserisci la lunghezza della stringa: ");
        length = getDouble();

        if (length < 0) {
            println("[ERRORE] Lunghezza non valida! La lunghezza deve essere un numero positivo.");
            println("");
            continue;
        }

        break;
    }

    return length;
}

char *editCharIgnores(char *oldCharIgnores)
{
    system("clear");
    println("Caratteri precedenti da ignorare: %s", (oldCharIgnores)? oldCharIgnores : "Non impostato");
    println("");
    println("[INFO] Inserire la stringa in cui il generatore ignorera' i caratteri dentro quella stringa.");
    printf("Inserire i nuovi caratteri da ignorare: ");
    char *input = getln(false);

    free(oldCharIgnores);
    if (strlen(input) == 0) return NULL;

    return standardizeIgnoreChars(input);
}

void generate(const int length, const int charTypes, const char *ignoreChars)
{
    char *generated = generateString(length, charTypes, ignoreChars);
    system("clear");
    println("La stringa generata: %s", (strlen(generated))? generated : "Non e' stata generata niente");
    free(generated);

    println("");
    println("Premere 'Invio' per tornare al menu...");
    getln();
}
