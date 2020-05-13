//MIO PROBLEMA: ELIMINARE DALLA LISTA L'ELEMENTO DI VALORE k, SE ESISTE
//SOLUZIONE 2
#include <stdio.h>
#include <stdlib.h>

struct elem {
	int k;
	struct elem *next;
};

struct elem *insInOrdine(struct elem *top, int k);
void stampaLista(struct elem *top);
//la funzione restituisce sempre il top della lista
struct elem *eiliminaElementoK(struct elem *top, int k, int *p_res);

int main() {
	int n,i,k, flag, res;
	struct elem *top=NULL; //LISTA VUOTA
	printf("Quanti elementi vuoi inserire? ");
	scanf("%d", &n);
	for (i=0;i<n;++i){
		printf("Dammi un elemento: ");
		scanf("%d",&k);
		top=insInOrdine(top,k);
	}
	stampaLista(top);
  printf("Dammi il valore k: ");
  scanf("%d", &k);
  top = eiliminaElementoK(top, k, &res);
  //if(flag==1) printf("Elemento trovato ed eliminato:\n", );
  //else printf("Elemento non trovato\n");
  if(res==1) printf("Ho trovato l'elemento\n");
  else printf("NON ho trovato l'elemento\n");
  stampaLista(top);
	return 0;
}

struct elem *eiliminaElementoK(struct elem *top, int k, int *p_res){
      // la lista è ordinata
    struct elem *canc=top, *p=NULL;
    *p_res=0;
    while (canc != NULL && canc->k < k){
      p=canc;
      canc=canc->next;
    }
    if (canc != NULL && canc->k ==k){
      *p_res=1;
      //sono sulla testa
      if(p==NULL)  top=canc->next;
      //non sono sulla testa
      else  p->next=canc->next;
      canc->next=NULL;
      free(canc);
      }
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
