#include <stdio.h> 
#include <stdlib.h> 

typedef int data_t;

typedef struct lista {
	int numero;
	data_t data;
//	int nome;
//	float teste1;
//	float teste2;
//	float projeto;
	struct lista *next;
	struct lista *prev;	
}Lista_t;

void inserirElemento(Lista_t **lista, Lista_t *elemento){

	if(*lista == NULL){
		*lista = elemento;
	}
	else{
		elemento->next=*lista;
		/*supondo que o campo previous de elemento está a NULL*/
		(*lista)->prev=elemento;		
		*lista = elemento;
	}
}

int removerElemento(Lista_t **lista, data_t valorProcurado){
	Lista_t *aux;
	int encontrou=0;
	aux = *lista;
	/* Percorre a lista até encontrar o elemento (nó) procurado */
	while (encontrou == 0 && aux != NULL){
		if (aux->data == valorProcurado){
			encontrou = 1;
		} else {
		  aux=aux->next;
		} 
	}
	if (encontrou == 1){
		/* Verifica se o elemento (no’) encontrado e’ o primeiro da lista */
		if (aux->prev == NULL && aux == *lista){
			*lista=aux->next;
			(*lista)->prev=NULL;
		}
		/*Caso o elemento(nó) encontrado nao seja o primeiro da lista*/
		else{
			(aux->prev)->next=aux->next;
			aux->next->prev=aux->prev;
		}
		/* Liberta a memoria alocada */
		free(aux);
		aux = NULL;
		return 1;
	}
	/*Retorna zero indicando que o elemento(no) nao foi encontrado*/
	return 0;
}

Lista_t *preencherElemento(Lista_t **lista){

	Lista_t *elemento = (Lista_t*)malloc(sizeof(Lista_t));

	printf("numero: ");
	scanf("%d", &elemento->numero);
	
	return elemento;
}

void listarElemento(Lista_t *lista){

	if (lista == NULL){
		printf("Lista vazia");
	} else {
		while (lista != NULL){
			printf ("%d ... ", lista->numero);
			lista = lista->next;
		}
	}	
}

int main(){
	Lista_t *lista = NULL;
	Lista_t *elemento = NULL;
	
	elemento = preencherElemento(&lista);	
	inserirElemento(&lista, elemento);	
	
	listarElemento(lista);

	return 0;
}
