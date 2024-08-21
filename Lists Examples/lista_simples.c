#include <stdlib.h>
#include "dados.h"
#include "lista_simples.h"

node_t * criar_nodo(data_t d1)
{
	node_t *aux=(node_t *)malloc(sizeof(node_t));
	aux->data=d1;
	aux->next=NULL;
	return aux;
}

void inserirInicio(node_t **lista, data_t d1)
{
	node_t *elemento=criar_nodo(d1);
	if (*lista == NULL){
	*lista = elemento;
	}
	else{
	elemento->next =*lista;
	*lista = elemento;
	}
}

void inserirFim(node_t **lista, data_t d1){
node_t *elemento=criar_nodo(d1);
node_t *aux;
aux = *lista;
if(*lista == NULL){
*lista = elemento;
}
else{
/* Percorre a lista até encontrar o último elemento */
while (aux->next != NULL){
	aux = aux->next;
}
aux->next = elemento;
}}

void inserirFim2(node_t **lista, node_t **fim, data_t d1){
node_t *elemento=criar_nodo(d1);
if(*lista == NULL){
*lista = elemento;
*fim=elemento;
}
else{
(*fim)->next = elemento;
*fim=elemento;
} 
}

int removerElemento(node_t **lista, data_t valorProcurado){
node_t *aux, *ant;
int encontrou=0;
aux = *lista;
ant = *lista;
/* Percorre a lista até encontrar o elemento (nó) procurado */
while (encontrou == 0 && aux != NULL){
	if (igual(aux->data,valorProcurado)) /* função igual a implementar */
			encontrou = 1;
	else{
		ant = aux;
		aux=aux->next;
	}
}
if (encontrou){
/* Verifica se o elemento (no’) encontrado e’ o primeiro da lista */
	if (ant == aux && aux == *lista){
		*lista = aux->next;
}
/*Caso o elemento(nó) encontrado nao seja o primeiro da lista*/
else{
	ant->next=aux->next;
}
/* Liberta a memoria alocada */
free(aux);
aux = NULL;
return 1;
}
/*Retorna zero indicando que o elemento(no) nao foi encontrado*/
return 0;
}


void listar(node_t *lista)
{
	node_t *aux=lista;
	while(aux!=NULL) {
		mostrar_dados(aux->data);
		aux = aux->next;
	}

}
