#include <stdio.h>
#include <stdlib.h>

/* defini��o do tipo de dados a armazenar em cada n� */
typedef int data_t;
/* defini��o de um n�, contendo os dados, o apontadorpara o pr�ximo elemento e o apontador para o anterior*/
typedef struct node {
	data_t data;
	struct node* next;
	struct node* previous;
} node_t;

void inserirInicio(node_t **lista, node_t *elemento){
	if(*lista == NULL){
		*lista = elemento;
	}
	else{
		elemento->next =*lista;
		/*supondo que o campo previous de elemento est� a NULL*/
		(*lista)->previous=elemento;
		*lista = elemento;
	}
}

int removerElemento(node_t **lista, data_t valorProcurado){
	node_t *aux;
	int encontrou=0;
	aux = *lista;
	/* Percorre a lista at� encontrar o elemento (n�) procurado */
	while (encontrou == 0 && aux != NULL){
		if (igual(aux->data,valorProcurado)) /* fun��o igual a implementar */
		encontrou = 1;
		else
		aux=aux->next;
	}
	if (encontrou == 1){
		/* Verifica se o elemento (no�) encontrado e� o primeiro da lista */
		if (aux->previous == NULL && aux == *lista){
			*lista = aux->next;
			(*lista)->previous=NULL;
		}
		/*Caso o elemento(n�) encontrado nao seja o primeiro da lista*/
		else{
			(aux->previous)->next=aux->next;
			aux->next->previous=aux->previous;
		}
		/* Liberta a memoria alocada */
		free(aux);
		aux = NULL;
		return 1;
	}
	/*Retorna zero indicando que o elemento(no) nao foi encontrado*/
	return 0;
}

int main(){
	node_t *lista;
	

}


