#include <stdio.h>
#include <stdlib.h>
#include "dados.h"
#include "lista_simples.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	node_t *lista=NULL;
    node_t *fim=NULL;
    
	data_t d1;
	inserir_dados(&d1);
	inserirInicio(&lista, d1);
	/*inserirFim(&lista, d1);*/
	/*inserirFim2(&lista,&fim, d1);*/
	inserir_dados(&d1);
	inserirInicio(&lista, d1);
	/*inserirFim(&lista, d1);*/
	/*inserirFim2(&lista,&fim, d1);*/
	listar(lista);
	
	printf("Indique aluno a remover \n");
	inserir_dados(&d1);
	if (!removerElemento(&lista, d1))
		printf("Lista vazia ou elemento não encontrado !!\n");
	listar(lista);

	printf("Indique aluno a remover \n");
	inserir_dados(&d1);
	if (!removerElemento(&lista, d1))
		printf("Lista vazia ou elemento não encontrado !!\n");
	listar(lista);
	
		printf("Indique aluno a remover \n");
	inserir_dados(&d1);
	if (!removerElemento(&lista, d1))
		printf("Lista vazia ou elemento não encontrado !!\n");
	listar(lista);
		
	/*mostrar_dados(d1);*/
	
	return 0;
}
