#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

/* 
 * Realizzare la funzione filter sotto riportata che implementa un semplice cifratore rotativo. Un cifratore rotativo è la forma
 * più semplice di cifratore, in cui a ciascun carattere ne viene uno successivo di un certo numero di posizioni.
 * 
 * La funzione filter in questione accetta tre parametri:
 *
 * char *inpath è una stringa che indica il percorso del file da (de)cifrare. Il file dovrà essere aperto dalla funzione e chiuso
 * al termine delle operazioni. Nel caso in cui tale stringa sia identica a "stdin", deve essere associato al file descriptor di
 * ingresso lo standard input.
 * 
 * char *outpath è una stringa che indica il percorso del file da salvare. Il file dovrà essere aperto dalla funzione e chiuso
 * al termine delle operazioni. Nel caso in cui tale stringa sia identica a "stdout", deve essere associato al file descriptor di
 * ingresso lo standard output.
 *
 * int rot è il numero di "movimenti" da effettuare. Può essere negativo.
 * 
 * La funzione deve restituire zero in caso di corretta terminazione, -1 altrimenti.
 * 
 * Si ricorda che è possibile andare al carattere successivo semplicemente sommando 1 al carattere corrente, è possibile
 * andare avanti di due caratteri sulla tabella ASCII sommando 2, e così via.
 * 
 * Come riferimento, si consideri che l'esecuzione del programma avente come parametri:
 * cipher.txt decoded.txt -1
 * dovrà produrre in decoded.txt un nuovo file contenente una frase leggibile in lingua inglese. A fini di debug, si consideri
 * inoltre che il programma potrà essere eseguito avendo come parametri
 * stdin stdout 1
 * nel qual caso, a fronte dell'inserimento sull console della stringa abcd, ci si aspetta in risposta la stringa bcde. Si noti
 * infine che, nel caso in cui venga letto il carattere speciale '\n', esso non dovrà essere modificato, ma semplicemente
 * riportato in output.
 * 
 * Si riportano di seguito alcune funzioni di utilità che possono essere sfruttate.
 * 
 * 
 * 
 * int strcmp ( const char * str1, const char * str2);
 * 
 * Compare characters of two strings
 * Compares up to num characters of the C string str1 to those of the C string str2. This function starts comparing the first
 * character of each string. If they are equal to each other, it continues with the following pairs until the characters differ,
 * until a terminating null-character is reached.
 * 
 * Parameters
 * str1 - C string to be compared.
 * str2 - C string to be compared.
 * 
 * Return Value
 * Returns an integral value indicating the relationship between the strings:
 * <0 if the first character that does not match has a lower value in ptr1 than in ptr2
 * 0 if the contents of both strings are equal
 * >0 if the first character that does not match has a greater value in ptr1 than in ptr2
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
 */

int filter(char *inpath, char* outpath, int rot) {
    FILE *in;
    if (!strcmp(inpath, "stdin")) {
        in = stdin;
    } else {
        in = fopen(inpath, "r");
    }
    if (in == NULL) {
        return -1;
    }
    FILE * out;
    if (!strcmp(outpath, "stdout")) {
        out = stdout;
    } else {
        out = fopen(outpath, "w");
    }
    if (out == NULL) {
        return -1;
    }
    char curchar;
    while ((curchar = getc(in)) != EOF) {
        if(curchar != '\n')  {
            curchar += rot;
        }
        putc(curchar, out);
    }
    fclose(in);
    fclose(out);
    return 0;
}

int main(int argc, char **argv)
{
    if (argc != 4) {
        printf("Exactly three parameters are required (input file, output file, start char, end char, number of rotations)\n");
        return -1;
    }
    char *in = argv[1];
    char *out = argv[2];
    int rotations = atoi(argv[3]);
    return filter(in, out, rotations);
}
