#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct persona {
    char *nome;
    char *cognome;
    int nascita;
    struct persona* padre;
};
typedef struct persona Persona;

/*  Data la struttura sopra indicata, realizzare le due funzioni
    sottostanti: la prima che crea una entità persona nello heap (con padre a NULL), 
    la seconda che dato un nome, un anno di nascita, un array non vuoto di persone e 
    la sua dimensione, crea un figlio della persona più anziana in tale array.
    Come riferimento si consideri che l'esecuzione del test deve
    fornire risultato positivo.
    */

Persona *crea(char *nome,char *cognome,int nascita){
    Persona *p = (Persona *)malloc(sizeof(Persona));
    p->nome = nome;
    p->cognome = cognome;
    p->nascita = nascita;
    p->padre = NULL;
    return p;
}

Persona *creaFiglio(char *nome,int nascita,Persona **padri,int npadri){
    Persona *anziano=padri[0];
    int i=1;
    for (;i<npadri;i++) if (padri[i]->nascita<anziano->nascita) anziano=padri[i];
    Persona *p=crea(nome,anziano->cognome,nascita);
    p->padre=anziano;
    return p;
}

int test(void){
    Persona *p0=crea("mario","bianchi",1974);
    Persona *p1=crea("mario","rossi",1973);
    Persona *padri[]={p0,p1};
    Persona *p2=creaFiglio("giulio",1980,padri,2);
    return  strcmp(p1->nome,"mario")==0 &&
            strcmp(p1->cognome,"rossi")==0 &&
            p1->nascita==1973 &&
            p1->padre==NULL &&
            strcmp(p2->nome,"giulio")==0 &&
            strcmp(p2->cognome,"rossi")==0 &&
            p2->nascita==1980 &&
            p2->padre==p1;
}

int main(void){
    printf("%d\n",test());
    return 0;
}
