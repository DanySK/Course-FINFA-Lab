#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

/* 
 * Realizzare la funzione sotto riportata che presi in ingresso due puntatori a file (e quindi a file già aperti e non da
 * chiudere), un carattere ch e un intero nr, riversa il contenuto del primo file nel secondo, ripetendo nr volte ciascuna
 * occorrenza di ch.
 * La funzione ritorni il numero complessivo di ripetizioni di ch riportate nel file di uscita.
 * 
 * Come riferimento si consideri che l'esecuzione del main chiama la funzione su stdin e stdout, e preleva la stringa da linea
 * di comando. Ad esempio richiamando il programma con:
 * 
 * ./files o 2
 * 
 * e dando in ingresso il testo:
 * 
 * Hello world!
 * 
 * ci si aspetta in uscita
 * 
 * Helloo woorld!
 * 
 * per lavorare sui file si ricorda che è possibile usare le seguenti funzioni di libreria (utilizzate solo quelle che pensate vi
 * servano):
 * 
 * 
 * 
 * int fclose ( FILE * stream );
 * 
 * Close file
 * Closes the file associated with the stream and disassociates it. All internal buffers associated with the stream are
 * disassociated from it and flushed: the content of any unwritten output buffer is written and the content of any unread
 * input buffer is discarded. Even if the call fails, the stream passed as parameter will no longer be associated with the file
 * nor its buffers.
 * 
 * Parameters
 * stream - Pointer to a FILE object that specifies the stream to be closed.
 * 
 * Return Value
 * If the stream is successfully closed, a zero value is returned. On failure, EOF is returned.
 * 
 * 
 * 
 * FILE * fopen ( const char * filename, const char * mode );
 * 
 * Open file
 * Opens the file whose name is specified in the parameter filename and associates it with a stream that can be identified in
 * future operations by the FILE pointer returned. The operations that are allowed on the stream and how these are performed
 * are defined by the mode parameter. 
 * 
 * Parameters
 * filename - C string containing the name of the file to be opened. Its value shall follow the file name specifications of the
 * running environment and can include a path (if supported by the system).
 * mode - C string containing a file access mode. It can be: "r" read: Open file for input operations. The file must exist. "w"
 * write: Create an empty file for output operations. If a file with the same name already exists, its contents are discarded
 * and the file is treated as a new empty file.
 * 
 * Return Value
 * If the file is successfully opened, the function returns a pointer to a FILE object that can be used to identify the stream on
 * future operations. Otherwise, a null pointer is returned.
 * 
 * 
 * 
 * int getc ( FILE * stream );
 * 
 * Get character from stream
 * Returns the character currently pointed by the internal file position indicator of the specified stream. The internal file
 * position indicator is then advanced to the next character. If the stream is at the end-of-file when called, the function
 * returns EOF and sets the end-of-file indicator for the stream (feof). If a read error occurs, the function returns EOF.
 * 
 * Parameters
 * stream - Pointer to a FILE object that identifies an input stream.
 * 
 * Return Value
 * On success, the character read is returned (promoted to an int value). The return type is int to accommodate for the special
 * value EOF, which indicates failure.
 * 
 * 
 * 
 * int putc ( int character, FILE * stream );
 * 
 * Write character to stream
 * Writes a character to the stream and advances the position indicator. The character is written at the position indicated by
 * the internal position indicator of the stream, which is then automatically advanced by one.
 * 
 * Parameters
 * character - The int promotion of the character to be written. The value is internally converted to an unsigned char when
 * written. Because some libraries may implement this function as a macro, and this may evaluate the stream expression more than
 * once, this should be an expression without side effects.
 * stream - Pointer to a FILE object that identifies an output stream.
 * 
 * Return Value
 * On success, the character written is returned. If a writing error occurs, EOF is returned.
 * 
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

int f(FILE *in, FILE* out, char ch, int nr)
{
    return -1;
}


int main(int argc, char **argv)
{
    if (argc != 3){
        printf("This program requires exactly two arguments.\n");
        return 1;
    }
    if (strlen(argv[1]) != 1){
        printf("The first argument must be a single char.\n");
        return 1;
    }
    char ch = argv[1][0];
    int h=f(stdin, stdout, ch, atoi(argv[2]));
    if (h<0){
        printf("Error.\n");
        return h;
    } else{
        printf("\'%c\' has been written %d time%c\n", ch, h, h == 1 ? '\0' : 's');
        return 0;
    }
}
