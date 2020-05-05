#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 50

struct studente {
  char cognome[MAXLEN];
  char nome[MAXLEN];
  int matricola;
  float mediaVoti;
  struct studente *next;
};

struct studente *addInTesta(struct studente *s[], int i);
//struct studente *addInCoda(struct studente *s[], int i);
void stampaLista(struct studente* top);

int main(){
  int i=0, n=0;
  struct studente *s[MAXLEN];
  printf("Quanti studenti vuoi aggiungere? ");
  scanf("%d", &n);
  for(i=0; i<n; ++i){
    s[] = addInTesta(s,i);
  //  top2 = addInCoda(top2,i);
  }
  printf("stampa Lista in testa");
  stampaLista(s);
  printf("stampa Lista in coda");
//  stampaLista(top2);
return 0;
}

struct studente *addInTesta(struct studente *s[], int i){
  struct studente *tmp = (struct studente *)malloc(sizeof(struct studente));
  tmp->cognome = i;
  tmp->nome = i;
  tmp->matricola = i;
  tmp->mediaVoti = i;
  tmp->next=t;
  s=tmp;
  return s;
}

void stampaLista(struct studente* top){
  struct studente *tmp;
  tmp=top;
  printf("\nStampa Lista: \n");
  while(tmp!=NULL){
    printf("%s %s %d %f", tmp->cognome, tmp->nome, tmp->matricola, tmp->mediaVoti);
    tmp=tmp->next;
  }
}