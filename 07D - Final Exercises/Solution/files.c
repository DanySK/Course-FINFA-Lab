 
#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

/* 
 * Realizzare la funzione sotto riportata che, presi in ingresso due puntatori a file (e quindi a file già aperti e non da
 * chiudere) e una stringa C priva di spazi, riversa il file di ingresso in uscita eliminando tutte le righe che contengono
 * esattamente una occorrenza della stringa. La funzione restituisca un valore negativo se le scritture su file comportano
 * errori, altrimenti restituisca il numero di linee eliminate.
 * 
 * Come riferimento si consideri che l'esecuzione del main chiama la funzione su stdin e stdout, e preleva la stringa da linea
 * di comando. Ad esempio richiamando il programma con:
 * 
 * ./files will
 * 
 * e dando in ingresso il testo:
 * 
 * when I was just a little girl,
 * I asked my mother, "what will I be?
 * will I be pretty? will I be rich?"
 * here's what she said to me
 * 
 * si dovrà avere in uscita:
 * 
 * when I was just a little girl,
 * will I be pretty? will I be rich?"
 * here's what she said to me
 * 
 * per lavorare sui file si suggerisce di usare le seguenti funzioni di libreria:
 * 
 * 
 * 
 * char * fgets ( char * str, int num, FILE * stream );
 * 
 * Get string from stream
 * Reads characters from stream and stores them as a C string into str until (num-1) characters have been read or either a
 * newline or the end-of-file is reached, whichever happens first. A newline character makes fgets stop reading, but it is
 * considered a valid character by the function and included in the string copied to str. A terminating null character is
 * automatically appended after the characters copied to str. Notice that fgets is quite different from gets: not only fgets
 * accepts a stream argument, but also allows to specify the maximum size of str and includes in the string any ending newline
 * character.
 * 
 * Parameters
 * str - Pointer to an array of chars where the string read is copied.
 * num - Maximum number of characters to be copied into str (including the terminating null-character).
 * stream - Pointer to a FILE object that identifies an input stream. stdin can be used as argument to read from the standard
 * input.
 * 
 * Return Value
 * On success, the function returns str. If the end-of-file is encountered while attempting to read a character, the eof
 * indicator is set (feof). If this happens before any characters could be read, the pointer returned is a null pointer (and the
 * contents of str remain unchanged). If a read error occurs, the error indicator (ferror) is set and a null pointer is also
 * returned (but the contents pointed by str may have changed).
 * 
 * 
 * 
 * int fputs ( const char * str, FILE * stream );
 * 
 * Write string to stream
 * Writes the C string pointed by str to the stream. The function begins copying from the address specified (str) until it
 * reaches the terminating null character ('\0'). This terminating null-character is not copied to the stream. Notice that fputs
 * not only differs from puts in that the destination stream can be specified, but also fputs does not write additional
 * characters, while puts appends a newline character at the end automatically.
 * 
 * Parameters
 * str - C string with the content to be written to stream.
 * stream - Pointer to a FILE object that identifies an output stream.
 * 
 * Return Value
 * On success, a non-negative value is returned. On error, the function returns EOF and sets the error indicator (ferror).
 * 
 * 
 * 
 * int strncmp ( const char * str1, const char * str2, size_t num );
 * 
 * Compare characters of two strings
 * Compares up to num characters of the C string str1 to those of the C string str2. This function starts comparing the first
 * character of each string. If they are equal to each other, it continues with the following pairs until the characters differ,
 * until a terminating null-character is reached, or until num characters match in both strings, whichever happens first.
 * 
 * Parameters
 * str1 - C string to be compared.
 * str2 - C string to be compared.
 * num - Maximum number of characters to compare. size_t is an unsigned integral type.
 * 
 * Return Value
 * Returns an integral value indicating the relationship between the strings:
 * <0 if the first character that does not match has a lower value in ptr1 than in ptr2
 * 0 if the contents of both strings are equal
 * >0 if the first character that does not match has a greater value in ptr1 than in ptr2
 * 
 * 
 * 
 * size_t strlen ( const char * str );
 * 
 * Get string length
 * Returns the length of the C string str. The length of a C string is determined by the terminating null-character.
 * 
 * Parameters
 * str - C string.
 * 
 * Return Value
 * The length of string. 
 */

#define IOERROR -1
#define MAX_LINE_LENGTH 10000

int exactlyOneOccurrence(char *source, char* str)
{
    int occurrencies;
    int cmpsize = strlen(str);
    for (occurrencies = 0; *source  != '\0'; source = source + 1) {
        if (!strncmp(source, str, cmpsize)) {
            if (occurrencies > 0) {
                return FALSE;
            }
            occurrencies++;
        }
    }
    return occurrencies;
}

int f(FILE *in, FILE* out, char* cmp)
{
    char buffer[MAX_LINE_LENGTH];
    int count;
    for (count = 0; fgets(buffer, MAX_LINE_LENGTH, in) != NULL;) {
        if (!exactlyOneOccurrence(buffer, cmp)) {
            if (fputs(buffer, out) < 0) {
                return -1;
            }
        } else {
            count++;
        }
    }
    return count;
}


int main(int argc, char **argv)
{
    if (argc!=2){
        printf("This program requires exactly one argument.\n");
        return 1;
    }
    int h=f(stdin, stdout, argv[1]);
    if (h<0){
        printf("Error.\n");
        return h;
    } else{
        printf("Removed %d line%s\n", h, h > 1 ? "s" : "");
        return 0;
    }
}
