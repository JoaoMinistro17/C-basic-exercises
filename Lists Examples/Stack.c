// EXERCICIO PILHA

#include <stdio.h>
#include <stdlib.h>

typedef int data_t;
/* definição da lista ligada */
typedef struct node {
	data_t data;
	struct node* next;
} node_t;

/* definição da stack */
typedef struct stack {
	node_t *topo;
} stack_t;

// create – cria uma nova stack
stack_t *create(){
	stack_t *aux=(stack_t *)malloc(sizeof(stack_t));
	aux->topo=NULL;
	return aux;
}

// push – inclui elemento no topo
void push(stack_t *s, int d){
	node_t *elemento=(node_t *)malloc(sizeof(node_t));
	
	elemento->data=d;
	elemento->next=NULL;
	
	if(s->topo==NULL){
		s->topo=elemento;
	}else{
		elemento->next=s->topo;
		s->topo=elemento;
	}
}

// pop – remove elemento do topo
int* pop(stack_t *s){
	node_t *aux;
	data_t *p=NULL;
	aux=s->topo;
	if (s->topo!=NULL){
		s->topo=aux->next;
		p=(int *)malloc(sizeof(int));
		*p=aux->data;
		free(aux);
		aux=NULL;
	}
	return p;
}

// peek – inspeciona qual o elemento no topo, não retira
int* peek(stack_t *s){
	data_t *p=NULL;
	if (s->topo!=NULL){
		p=(int *)malloc(sizeof(int));
		*p=s->topo->data;
	}
	return p;
}

// empty - determina se a stack está vazia.
int empty(stack_t *s){
	if (s->topo==NULL){
		return 1;
	}else{
		return 0;
	}
}

// destroy – apaga uma stack
// destroy – uma possível implementação em C
void destroy(stack_t **s){
	node_t *aux=(*s)->topo;
	node_t *ant=aux;
	while (aux !=NULL)
	{
		aux=aux->next;
		free(ant);
		ant=aux;
	}
	free(*s);
	*s=NULL;
}

// destroy – outra possível implementação em C
/*	void destroy(stack_t **s){
		while (!empty(*s))
			pop(*s);
			free(*s);
			*s=NULL;
}	*/

int main (){
	
	stack_t *s;
	
	create();
	push(s, 5);
	
	int aux;		
	aux = peek(s);
	printf("TOPO: %d", aux);
	
	return 0;
}
