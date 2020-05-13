//MIO PROBLEMA: ELIMINARE DALLA LISTA L'ELEMENTO DI VALORE k, SE ESISTE
// SOLUZIONE 3
#include <stdio.h>
#include <stdlib.h>

struct elem {
	int k;
	struct elem *next;
	struct elem *prev;
};

struct elem *insInOrdine(struct elem *top,int k);
void stampaLista(struct elem *top);
// La funzione restituisce che cerca un elemento k, e restituisce il puntatore dell'elemento se
//lo trova altrimenti NULL.
struct elem *cercaElementoK(struct elem *top, int k);
// La funzione che elimina l'elemento puntato da p.
struct elem *eliminaElemento(struct elem *top, struct elem *p);

int main() {
	int n=5,i,k,flag,res;
	struct elem *top=NULL,*p=NULL; //LISTA VUOTA
	printf("Quanti elementi vuoi inserire?");
	scanf("%d",&n);
	for (i=0;i<n;++i){
		printf("Dammi un elemento:");
		scanf("%d",&k);
		top=insInOrdine(top,k);
	}
	stampaLista(top);
	printf("Dammi il valore k:");
	scanf("%d",&k);
	p=cercaElementoK(top,k);
	if (p!=NULL) {
		printf("Ho trovato l'elemento\n");
		top=eliminaElemento(top,p);
		}
		else printf("NON Ho trovato l'elemento\n");
	stampaLista(top);
}
// La funzione restituisce che cerca un elemento k, e restituisce il puntatore dell'elemento se
//lo trova altrimenti NULL.
struct elem *cercaElementoK(struct elem *top, int k){
	return top;
}
// La funzione che elimina l'elemento puntato da p.
struct elem *eliminaElemento(struct elem *top, struct elem *p){
	return top;
}

struct elem *insInOrdine(struct elem *top,int k){
	struct elem *s,*p,*tmp;
	tmp= (struct elem *)malloc(sizeof(struct elem));
	tmp->k=k;
	tmp->next=NULL;
	s=top; p=NULL;
	while (s!=NULL && s->k <= k) {
		p=s;
		s=s->next;
	}
	tmp->next=s;
	if (p==NULL) top=tmp;
	else p->next=tmp;

	return top;
}
void stampaLista(struct elem *top){
	while(top!=NULL){
		printf("%d\n",top->k);
		top=top->next;
	}
}
