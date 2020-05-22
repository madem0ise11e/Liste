#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 50

struct studente {
  char cognome[MAXLEN];
//  char nome[MAXLEN];
//  int matricola;
//  float mediaVoti;
  struct studente *next;
};

struct studente *addInTesta(struct studente *t, char cog[]);
//struct studente *addInCoda(struct studente *s[], int i);
void stampaLista(struct studente *top);

int main(){
  int i=0, n=0;
  char cog;
  struct studente *top;
  top = NULL;
  printf("Quanti studenti vuoi aggiungere? ");
  scanf("%d", &n);
  for(i=0; i<n; ++i){
    addInTesta(top,cog);
  //  s2 = addInCoda(s2,i);
  }
  printf("stampa Lista in testa");
  stampaLista(top);
//  printf("stampa Lista in coda");
//  stampaLista(s2);
return 0;
}

struct studente *addInTesta(struct studente *t, char cog[]){
  struct studente *tmp = (struct studente *)malloc(sizeof(struct studente));
//  printf("Inserisci cognome: ");
  //scanf("%s", cog);
  tmp->cognome = cog;
  tmp->next=t;
  t=tmp;
  return t;
}

void stampaLista(struct studente *top){
  struct studente *tmp;
  tmp=top;
  printf("\nStampa Lista: \n");
  while(tmp!=NULL){
    printf("%s", tmp->cognome/*, tmp->nome, tmp->matricola, tmp->mediaVoti*/);
    tmp=tmp->next;
  }
}
