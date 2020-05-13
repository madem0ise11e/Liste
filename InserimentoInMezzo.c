
#include <stdio.h>
#include <stdlib.h>

struct elem {
	int k;
	struct elem *next;
};

struct elem *insInOrdine(struct elem *top,int k);
void stampaLista(struct elem *top);
int main() {
	int n,i,k;
	struct elem *top=NULL; //LISTA VUOTA
	printf("Quanti elementi vuoi inserire? ");
	scanf("%d", &n);
	for (i=0;i<n;++i){
		printf("Dammi un elemento:");
		scanf("%d",&k);
		top=insInOrdine(top,k);
	}
	stampaLista(top);
	return 0;
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
