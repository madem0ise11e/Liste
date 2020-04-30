#include <stdio.h>
#include <stdlib.h>
//al momento non ho ancora allocato memoria per una struct
struct elem {
    int mat;
    //qui posso inserire quanti campi voglio e di qualunque tipo
    struct elem *next;
};

struct elem *addInTesta(struct elem *t, int i);
void stampaLista( struct elem* top);
int main() {
    int i=0, n=0;
    //la lista più piccola che potete creare, cioè una lista vuota
    //ho allocato la memoria in maniera automatica solo per il puntatore
    struct elem *top=NULL;
    //************************************************************
    printf("Quanti elementi vuoi aggiungere? ");
    scanf("%d", &n);
    for(i=0; i<n; ++i){
        top = addInTesta(top,i); //passo (d)

    }
    stampaLista(top);
return 0;
}

struct elem *addInTesta(struct elem *t, int i){
    struct elem *tmp=(struct elem *) malloc(sizeof(struct elem)); //passo (b)
    tmp->mat=i;
    tmp->next=t; //passco (c)
    t=tmp;
    return t;
}

void stampaLista( struct elem* top){
    struct elem *tmp;
    tmp=top;
    printf("\nStampa Lista:\n");
    while(tmp!=NULL){ //sono sicura che all'interno del while tmp e' diverso da NULL
                      //in modo tale da poter accedere ai campi!!!
    printf("%d\n", tmp->mat);
    tmp=tmp->next;
    }
}
