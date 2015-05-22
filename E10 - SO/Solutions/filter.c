#include <stdio.h>
#include <string.h>
/*
 * One tweet is 140 chars, in this case there is a trailing \n\0, so the total is 142.
 */
#define BUFDIM 142
#define SUBN 2
#define TRUE 1
#define FALSE 0

/*
 * Tries to substitute the char in source with the substitution in sub.
 * Returns TRUE if any substitution occurred
 */
int subifmatches(char *source, char* sub) {
    int i = 0;
    char cmp = *source;
    for (i = 1; sub[i] != '\0'; i++) {
        if(cmp == sub[i]) {
            *source = sub[0];
            return TRUE;
        }
    }
    return FALSE;
}

int main (int argc, char **argv){
    char buffer[BUFDIM];
    char *exit = "yxyt\n";
    /*
     * Array of substitutions: for each array, if any of the characters in position [1-N]
     * matches the current character, the substitute with the char at [0].
     */
    char *subs[SUBN];
    subs[0] = "yaeiou";
    subs[1] = "YAEIOU";
    char *res;
    do{
        res = fgets(buffer, BUFDIM, stdin);
        if(res == buffer) {
            int i;
            for(i = 0; res[i] != '\0'; i++){
                int si;
                for(si = 0; si < SUBN && !subifmatches(&res[i], subs[si]); si++);
            }
            fputs(res, stdout);
        }
    } while(res == buffer && strcmp(res, exit) != 0);
    return 0;
}
