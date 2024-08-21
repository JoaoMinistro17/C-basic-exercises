/******************************************************************************/
/*                                 Includes                                   */
/******************************************************************************/

#include <stdio.h>  /*Permite a definição de variáveis/constantes, bem como a leitura de dados escritos pelo teclado e a demonstração dos mesmos na tela*/
#include <stdlib.h> /*Permite a criação de funçõies que envolvem o armazentamento de dados, bem como a sua alteração*/
#include <locale.h> /*Permite a introdução de caracteres referentes a uma certa Língua. Por exemplo, língua portuguesa*/
#include <string.h> /*Permite a introdução de funções utilizadas para manipular strings*/
#include <conio.h>  /* Para a função skip

/******************************************************************************/
/*                                 Structs                                    */
/******************************************************************************/

typedef struct contaBanco {
    int codigo_conta;
    char tipo_conta;     
    float saldo_conta;
    int codigo_cli_conta;
	struct contaBanco *prox_conta;		//apontador para o proximo cliente
}Conta;
typedef struct contaCliente{
    int codigo_cli;
	char nome_cli[50];
    char morada_cli[50];       
    float saldo_cli;			
    struct contaCliente *prox_cli;		//apontador para a proxima conta
}Cliente;
typedef struct movimentos {
    int dia_mov;
    int mes_mov;
    int ano_mov;
    char tipo_mov;       
    float valor_mov;
    struct movimentos *prox_mov;
}Movimentos;

// FILE *fp;
/******************************************************************************/
/*                                 Funções                                    */
/******************************************************************************/
void skip(void){
	//	printf("\nOperação realizada com sucesso!\n");
		printf("\nPressione Qualquer Tecla Para Continuar...");
		getch();
		fflush(stdin);
		system("cls");
}

void clear_buffer(void) {  // apagar buffer de entrada devido ao gets
    int c;
    while(c != EOF && (c = getchar()) != '\n' );
}

/*Menu Principal*/
void menuPrincipal (){	
	printf("--------------------------------\n");
	printf("\tMenu Principal\n");    
	printf("--------------------------------\n");
	     
	    printf("\n\t 1. Novo Cliente  ");
		printf("\n\t 2. Gerir Clientes ");
		printf("\n\t 3. Gerir Contas ");
	
		printf("\n\n\t 9. Sair\n\n");
		
		printf("Introduza um número: ");
}
/*Menu Clientes, referente a gerir os clientes*/
void menuClientes (){
	system("cls");
	printf("--------------------------------\n");
	printf("\tMenu Clientes\n");
	printf("--------------------------------\n");
	
		printf("\n\t 1. Editar ficha do cliente ");
		printf("\n\t 2. Eliminar ficha do cliente ");
		printf("\n\t 3. Ver informação do cliente ");
		printf("\n\t 4. Saldo global do cliente");
		printf("\n\t 5. Listagem de clientes");
		printf("\n\t 6. Listagem de clientes por localidade");
		printf("\n\t 7. Listagem de clientes com saldo negativo");
	
		printf("\n\n\t 9. Voltar\n\n");

		printf("\nIntroduza um número: ");	
}
/*Menu Contas, referente a gerir contas*/
void menuContas (){	
	system("cls");
	
	printf("--------------------------------\n");
	printf("\tMenu Contas\n");
	printf("--------------------------------\n");
	
		printf("\n\t 1. Criar conta");
		printf("\n\t 2. Editar conta");
		printf("\n\t 3. Eliminar conta");
		printf("\n\t 4. Movimentos");
		printf("\n\t 5. Visualizar conta");
		printf("\n\t 6. Listagem de contas");

		printf("\n\n\t 9. Voltar\n\n");

		printf("\nIntroduza um número: ");
} 
//--------------------------------------------------------------------------------
void addListaConta(Conta* novo_conta, Conta** lista_conta){ //adicionar a nova conta a lista
    if ((*lista_conta) == NULL) {
        (*lista_conta) = novo_conta;
    } else {
        novo_conta->prox_conta = (*lista_conta);
        (*lista_conta) = novo_conta;
    }
}
//--------------------------------------------------------------------------------
void addListaCli(Cliente* novo_cli, Cliente** lista_cli){  //adicionar o novo cliente a lista
    if ((*lista_cli) == NULL) {  			// se a lista esta vazia
        (*lista_cli) = novo_cli; 			// insere diretamente na lista 
    } else { 								// caso ja existam elementos na lista
        novo_cli->prox_cli = (*lista_cli);  // apontador prox_cli passa a apontar para o novo cliente
        (*lista_cli) = novo_cli;			// insere o novo cliente
    }
}
//--------------------------------------------------------------------------------
Conta *novaConta (Conta **lista_conta, Cliente *lista_cli, int *i_conta){
	printf("--------------------------------\n");
	printf("Nova conta \n");
	printf("--------------------------------\n");

	int codigoCliente;
	int ver=0;
	
	Conta* novo_conta = (Conta*)malloc(sizeof(Conta));
	
	printf("\nIntroduza o seu código de cliente para associar: "); // associar cada conta do banco a uma conta de cliente obrigatoriamente
	scanf("%d", &codigoCliente);	
		
	while(ver==0 && lista_cli != NULL)    /* Enquanto nao chega no fim da lista */
	{
    	if (lista_cli->codigo_cli == codigoCliente){ 		// se encontra o codigo de cliente que o utilizador insere
    		novo_conta->codigo_cli_conta = lista_cli->codigo_cli;  	// guarda na lista Conta uma variavel com o valor do codigo do cliente
    		ver = 1;  	// verificar que a conta pretendida foi encontrada
    		
    		printf("\nTipo de conta ( o - ORDEM | p - PRAZO ): ");
			scanf(" %c", &novo_conta->tipo_conta);
				
			novo_conta->codigo_conta = (*i_conta);
			(*i_conta)++;
			novo_conta->saldo_conta = 0;
			novo_conta->prox_conta = NULL;    		
		}						
    	lista_cli = lista_cli->prox_cli;    // metodo para avancar na lista  
	}	
	if (ver != 1){
		printf("\nConta de cliente não encontrada!\n");
	}		
	skip();
	return novo_conta;
}
//--------------------------------------------------------------------------------
Cliente *novoCliente (int *i_cli){
	system("cls");
	printf("--------------------------------\n");
	printf("Novo cliente \n");
	printf("--------------------------------\n");
	
	Cliente* novo_cli = (Cliente*)malloc(sizeof(Cliente));
	
	printf("\n Nome: ");
	gets(novo_cli->nome_cli);

	printf("\n Morada: ");
	gets(novo_cli->morada_cli);
	
	novo_cli->codigo_cli = (*i_cli);
	(*i_cli)++;
	novo_cli->saldo_cli = 0;
	novo_cli->prox_cli = NULL;
	
//	fp = fopen ("banco.txt", "a+");
	
//	if(fp==NULL) return(NULL);
	
//	fprintf (fp, "%s %s\n", novo_cli->nome_cli, novo_cli->morada_cli);	          

//	fclose(fp);
	
	skip();
	return novo_cli;
}	
//--------------------------------------------------------------------------------
void listaClientes(Cliente *lista_cli){
    printf("--------------------------------\n");
	printf("Lista de clientes \n");
	printf("--------------------------------\n");
	
	if(lista_cli==NULL){ 
    printf("\nA Lista de clientes está vazia!\n");
    } else {
        while(lista_cli != NULL){ // percorre a lista ate ao seu final
            printf("\nCodigo %d\nNome: %s\nMorada: %s\n\n", lista_cli->codigo_cli, lista_cli->nome_cli, lista_cli->morada_cli);
            lista_cli = lista_cli->prox_cli;             
        }
    }      
    skip();
}
//--------------------------------------------------------------------------------
void listaConta (Conta *lista_conta){
	printf("--------------------------------\n");
	printf("Lista de contas \n");
	printf("--------------------------------\n");
	
	char tipoConta[5];
	if(lista_conta == NULL){
		printf("\nA lista de contas está vazia!\n\n");
	} else {
		while(lista_conta != NULL)   		/* Enquanto nao chega no fim da lista */
		{
			if (lista_conta->tipo_conta == 'p'){
				strcpy(tipoConta, "prazo");			
			}
			if (lista_conta->tipo_conta == 'o'){
				strcpy(tipoConta, "ordem");
			}		
			printf("\nCodigo: %d\nTipo: %s\nSaldo: %.2f\nConta de cliente associada com o código %d\n", lista_conta->codigo_conta, tipoConta, lista_conta->saldo_conta, lista_conta->codigo_cli_conta);			
		    lista_conta = lista_conta->prox_conta;    
		}		
	}
	printf("\nINTRODUZA QUALQUER TECLA PARA CONTINUAR...");
	getch();
	
	system("cls");	
}
//--------------------------------------------------------------------------------
void editarCliente (Cliente **lista_cli){
	printf("--------------------------------\n");
	printf("Editar ficha do cliente \n");
	printf("--------------------------------\n");
		
	Cliente *aux;
	int codigoCliente;
	int encontrou=0;
	int opcao;
	char novoNome[50];
	char novaMorada[50];
	
	aux = *lista_cli;
	
	if (!aux){
		printf("\nA lista de clientes está vazia!\n");
	} else {
		printf("Introduza o codigo de cliente: ");
		scanf("%d", &codigoCliente);
		
		/* Percorre a lista até encontrar o elemento (nó) procurado */
		while (encontrou == 0 && aux != NULL){
			if (aux->codigo_cli == codigoCliente){ 	
				encontrou = 1;		
				
				printf("O que pretende editar?\n\n");
				printf("\t1. Nome\n");
				printf("\t2. Morada\n");
				printf("\t9. Voltar\n");
				printf("\nIntroduza um número: ");
				scanf("%d", &opcao);				
				
				switch(opcao){
					case 1: 
						printf("%s", aux->nome_cli);
						printf("Introduza o novo nome: ");
						scanf("%s", novoNome);
						strcpy (aux->nome_cli, novoNome);
						break;					
					case 2:
						printf("Introduza a nova morada: ");
						scanf("%s", novaMorada);
						strcpy(aux->morada_cli, novaMorada);
						break;
					case 9:
						break;					
				}			
			}
			aux=aux->prox_cli;
		}
		if (encontrou == 0){
			printf("Conta de cliente não encontrada!");
		}	
	}		
	skip();
}
//--------------------------------------------------------------------------------
void eliminarCliente (Cliente **lista_cli, int *i_cli){
	printf("--------------------------------\n");
	printf("Eliminar conta do cliente \n");
	printf("--------------------------------\n");
	
	Cliente *aux, *ant;
	int codigoCliente;
	int encontrou=0;
	aux = *lista_cli;
	ant = *lista_cli;
	
	if (!aux){
		printf("\nA lista de clientes está vazia!\n");
	} else {
		printf("Introduza o codigo de cliente: ");
		scanf("%d", &codigoCliente);
		
		/* Percorre a lista até encontrar o elemento (nó) procurado */
		while (encontrou == 0 && aux != NULL){
			if (aux->codigo_cli == codigoCliente) /* função igual a implementar */
			encontrou = 1;
			else{
				ant = aux;
				aux=aux->prox_cli;
			}
		}
		if (encontrou==1){
		/* Verifica se o elemento (no’) encontrado e’ o primeiro da lista */
			if (ant == aux && aux == *lista_cli){
				*lista_cli = aux->prox_cli;
			}
			/*Caso o elemento(nó) encontrado nao seja o primeiro da lista*/
			else{
				ant->prox_cli=aux->prox_cli;
			}
			/* Liberta a memoria alocada */
			free(aux);
			aux = NULL;
			i_cli--; //retira 1 ao numero total de clientes
		} else {
		/*Escreve indicando que o elemento(no) nao foi encontrado*/
			printf("Cliente não encontrado");
		}
	}
	skip();
}
//--------------------------------------------------------------------------------
void visualizarCliente (Cliente *lista_cli){
	printf("--------------------------------\n");
	printf("Visualizar ficha do(s) cliente(s) \n");
	printf("--------------------------------\n");
	int codigoCliente; 
	int ver=0;
	
	if (lista_cli == NULL){
		printf("\nA lista está vazia!\n");
	} else {	
		printf("Introduza o codigo de cliente: ");
		scanf("%d", &codigoCliente);
	
		while(lista_cli)    /* Enquanto nao chega no fim da lista */
		{
			if (codigoCliente == lista_cli->codigo_cli){ // caso encontre o cliente pretendido mostra no ecra a sua informação relativa
				printf("\nNome: %s\nMorada: %s\n\n", lista_cli->nome_cli, lista_cli->morada_cli);
				ver=1;
			}
		    lista_cli = lista_cli->prox_cli;     
		}
		if (ver==0){
			printf("O cliente não existe...\n");
		}
	}	
	skip();
}
//--------------------------------------------------------------------------------
void saldoGlobalCliente (Cliente *lista_cli, Conta *lista_conta){
	printf("--------------------------------\n");
	printf("Saldo global de um cliente \n");
	printf("--------------------------------\n");
	
	int encontrou = 0, encontrou2 = 0;
	int codigoCliente;
	float saldoGlobal = 0;
	float saldoGlobalPrazo = 0;
	float saldoGlobalOrdem = 0;
	
	if (lista_cli == NULL || lista_conta == NULL){ // se uma das contas tiver vazia
		printf("\nA lista de clientes ou contas está vazia.\n");
	} else {
		printf("Introduza o numero de cliente: ");
		scanf("%d", &codigoCliente);
				
		while (lista_cli != NULL && encontrou != 1){
			if (lista_cli->codigo_cli == codigoCliente){
				encontrou=1;
				//percorre a lista de contas apos percorrer a lista de clientes e encontrar o cliente pretendido
				while (lista_conta){
					if (lista_cli->codigo_cli == lista_conta->codigo_cli_conta){ //encontrou a conta pertencente ao cliente especifico
						encontrou2=1;
						saldoGlobal += lista_conta->saldo_conta;
						
						if (lista_conta->tipo_conta == 'o'){
							saldoGlobalOrdem += lista_conta->saldo_conta;
						} else {					
							saldoGlobalPrazo += lista_conta->saldo_conta;
						}											
					}
					lista_conta = lista_conta->prox_conta;
				}	//percorrer a lista de contas						
			}
			lista_cli = lista_cli->prox_cli;
		} // percorrer a lista de clientes
		
		if (encontrou == 1 && encontrou2 == 1){
			printf("\nSaldo global do cliente %d: %.2f\n",codigoCliente, saldoGlobal);
			printf("\nSaldo das contas á ordem: %.2f", saldoGlobalOrdem);
			printf("\nSaldo das contas a prazo: %.2f\n", saldoGlobalPrazo);			
		}		
		if (encontrou != 1) printf("\nCliente não encontrado.\n");
		if (encontrou2 != 1) printf("\nConta não encontrada.\n");
	}
	skip();
}
//--------------------------------------------------------------------------------	
void listaClienteLocal (Cliente *lista_cli){
	printf("--------------------------------\n");
	printf("Lista de contas por localidade \n");
	printf("--------------------------------\n");	
	
	char localidade[50];
	
	if (!lista_cli){
			printf("\nA lista de clientes está vazia!\n");
		} else {		
			printf("Introduza a localidade: ");
			gets(localidade);
			
			while(lista_cli)	// Enquanto nao chega no fim da lista 
			{
				if (strcmp(localidade, lista_cli->morada_cli) == 0) { 		// caso encontre o cliente pretendido mostra no ecra a sua informação relativa
					printf("\nCodigo %d\nNome: %s\n\n", lista_cli->codigo_cli, lista_cli->nome_cli, lista_cli->morada_cli);
				}
			    lista_cli = lista_cli->prox_cli;     
			}	
		}	
	skip();
}
//--------------------------------------------------------------------------------
void listaClienteSaldoNeg (Cliente *lista_cli, Conta *lista_conta){
	printf("--------------------------------\n");
	printf("Lista de clientes com saldo negativo \n");
	printf("--------------------------------\n");	
	int encontrou;
	float saldoGlobal;
	
/* metodo mais eficaz para a função	*/
//	if (!lista_cli){
//		printf("\nNão existem contas de cliente!\n");
//	} else {		
//		while(lista_cli)	/* Enquanto nao chega no fim da lista */
//		{
//			encontrou = 1;
//			if (lista_cli->saldo_cli < 0) { 		// caso encontre o cliente pretendido mostra no ecra a sua informação relativa
//			}
//		    lista_cli = lista_cli->prox_cli;     
//		}	
//	}
//	if (encontrou != 1){
//		printf("\nNão existem contas com saldo negativo\n");
//	}	
		
	if (lista_cli == NULL || lista_conta == NULL){ // se uma das contas tiver vazia
		printf("\nA lista de clientes ou contas está vazia.\n");
	} else {

		while (lista_cli != NULL && encontrou != 1){
				encontrou=1;
				//percorre a lista de contas apos percorrer a lista de clientes e encontrar o cliente pretendido
				while (lista_conta){
					if (lista_cli->codigo_cli == lista_conta->codigo_cli_conta){ //encontrou a conta pertencente ao cliente especifico
						encontrou=1;
						saldoGlobal += lista_conta->saldo_conta;											
					}
					lista_conta = lista_conta->prox_conta;
				}	//percorrer a lista de contas
				if (saldoGlobal < 0){
					printf("\nCodigo %d\nNome: %s\nMorada: %s\nSaldo do cliente: %.2f\n", lista_cli->codigo_cli, lista_cli->nome_cli, lista_cli->morada_cli, saldoGlobal);
				}						
			lista_cli = lista_cli->prox_cli;
		} // percorrer a lista de clientes	
	}
	skip();
}
//--------------------------------------------------------------------------------
void editarConta (Conta **lista_conta){
	printf("--------------------------------\n");
	printf("\tEditar conta: \n");
	printf("--------------------------------\n");
	
	Conta *aux;
	int codigoConta;
	int encontrou=0;
	int opcao;
	char novoTipo;
	aux = *lista_conta;
	
	if ((*lista_conta) == NULL){ // caso a lista esteja vazia
		printf("A lista de contas está vazia!!");
	} else {
		
		printf("Introduza o codigo da conta: ");
		scanf("%d", &codigoConta);
		
		/* Percorre a lista até encontrar o elemento (nó) procurado */
		while (encontrou == 0 && aux != NULL){
			if (aux->codigo_conta == codigoConta){ 	
				encontrou = 1;		
				
				printf("O que pretende editar?\n\n");
				printf("\t1. Tipo de conta\n");
				printf("\t9. Voltar");
				printf("\n\nIntroduza um número: ");
				scanf("%d", &opcao);				
				
				switch(opcao){
					case 1: 
						printf("Introduza o novo tipo de conta ( o- Ordem | p- Prazo ): ");
						scanf(" %c", &novoTipo);
						aux->tipo_conta = novoTipo;
						break;					
					case 9:
						break;
					default: printf("Valor inválido");
				}			
			}
			aux=aux->prox_conta;
		}
		if (encontrou == 0){
			printf("Conta de cliente não encontrada!");
		}			
	}	
	skip();	
}
//--------------------------------------------------------------------------------
void eliminarConta (Conta **lista_conta, int *i_conta){
	printf("--------------------------------\n");
	printf("\tEliminar conta : \n");
	printf("--------------------------------\n");
	
	Conta *aux, *ant;
	int codigoConta;
	int encontrou=0;
	aux = *lista_conta;
	ant = *lista_conta;
	
	if (!lista_conta){
		printf("\nA lista de contas está vazia!\n");
	} else {
		printf("Introduza o codigo da conta: ");
		scanf("%d", &codigoConta);
		
		/* Percorre a lista até encontrar o elemento (nó) procurado */
		while (encontrou == 0 && aux != NULL){
			if (aux->codigo_conta == codigoConta) /* função igual a implementar */
			encontrou = 1;
			else{
				ant = aux;
				aux=aux->prox_conta;
			}
		}
		if (encontrou==1){
			/* Verifica se o elemento (no’) encontrado e’ o primeiro da lista */
			if (ant == aux && aux == *lista_conta){
				*lista_conta = aux->prox_conta;
			}
			/*Caso o elemento(nó) encontrado nao seja o primeiro da lista*/
			else{
				ant->prox_conta=aux->prox_conta;
			}
			/* Liberta a memoria alocada */
			free(aux);
			aux = NULL;
			i_conta--; //retira 1 ao numero total de clientes
		} else {
		/*Escreve indicando que o elemento(no) nao foi encontrado*/
			printf("Conta não encontrada");
		}	
	}
	skip();	
}
//--------------------------------------------------------------------------------
int menuMovimentos(){
	int opc;	
	
	printf("\n\t1. Depositar dinheiro");	
	printf("\n\t2. Retirar dinheiro");
	printf("\n\t3. Transferir dinheiro");	
	printf("\n\n\t9. Voltar");		
	printf("\n\nIntroduza um número: ");
	scanf("%d", &opc);
	system("cls");
	
	return opc;
}
//--------------------------------------------------------------------------------
void movimentosConta (Conta **lista_conta){
	printf("--------------------------------\n");
	printf("\tMovimentos da conta \n");
	printf("--------------------------------\n");	
	int a = 0; 		//verificacao para voltar ao menu contas sem aparecer a funcao skip() 
	int codigoConta, codigoConta2, codigoContaTran, encontrou=0, encontrou2=0;
	int opcao, ver;
	
	float deposito, retirar, transferencia;
	
//	Cliente *temp;
//	temp = *lista_cli;
	Conta *aux, *aux2, *auxver, *auxver2;
	aux = *lista_conta;
	aux2 = *lista_conta;
	auxver = *lista_conta;   //verificar se existem contas a ordem
	auxver2 = *lista_conta;	 //verificar se existem contas a prazo
	
	//caso a lista esteja vazia
	if (!(*lista_conta)){
		printf("\nA lista de contas está vazia!!\n");
	} else {				
		opcao = menuMovimentos();
		
		switch (opcao){	
			// colocar em funcao os 3 cases 
			case 1:			
				printf("Introduza o codigo da conta ");
				scanf("%d", &codigoConta);	
				
				//percorrer o no e fazer o deposito 
				while (encontrou == 0 && aux != NULL)
				{
					if (aux->codigo_conta == codigoConta){
						encontrou = 1;											
						printf("\nIntroduza o montante que deseja depositar: ");
						scanf("%f", &deposito);	
						if (deposito <= 0){
							printf("\nImpossível depositar valores menores ou iguais a 0.\n");
						} else {
							aux->saldo_conta += deposito;								
						}
					}
					aux=aux->prox_conta;
				}			
				//caso nao encontre 
				if (encontrou == 0){
					printf("\nConta não encontrada!");
				}				
				break;										
			case 2:				
				printf("\nIntroduza o codigo da conta: ");
				scanf("%d", &codigoConta);
				
				while (encontrou == 0 && aux != NULL){
					if (aux->codigo_conta == codigoConta){
						encontrou = 1;	
							printf("\nIntroduza o montante que deseja retirar: ");
							scanf("%f", &retirar);	
							if (retirar <= 0){
								printf("\nImpossível retirar valores menores ou iguais a 0.\n");
							} else {
								aux->saldo_conta -= retirar;
							}	
					}	
					aux=aux->prox_conta;		
				}
				//caso nao encontre 
				if (encontrou == 0){
					printf("\nConta não encontrada!");
				}			
				break;				
			case 3:				
				printf("\nIntroduza o codigo da conta: ");
				scanf("%d", &codigoConta);						
				printf("\nIntroduza o codigo da conta que deseja efetuar a tranferencia: ");
				scanf("%d", &codigoContaTran);				
				printf("\nIntroduza o montante que deseja tranferir: ");
				scanf("%f", &transferencia);
				
			///-------------------------------------------------Verificar se a transferencia é possível nas duas contas		
				while (auxver){
					if (auxver->codigo_conta == codigoConta){	
						if (auxver->tipo_conta == 'o'){
							encontrou = 1;
						}
					}
					auxver = auxver->prox_conta;	
				}				
				while (auxver2){ 	
					if (auxver2->codigo_conta == codigoContaTran){	
							encontrou2 = 1; 
					}
					auxver2 = auxver2->prox_conta;	
				}
				if (encontrou == 1 && encontrou2 == 1) ver = 1;
				else ver = 0;
				if (codigoConta == codigoContaTran) ver = 0;
			///-------------------------------------------------																				
				//verifica se ambas as contas existem e se sao validas (á ordem)
				//ver toma o valor de 1 se a transferencia é possivel, senão 0.
				
				if (ver == 1){				
					while (aux){ 			//percorre a lista
						if (aux->codigo_conta == codigoConta){
							aux->saldo_conta = aux->saldo_conta - transferencia;
						}
						aux=aux->prox_conta;
					}								
							
					while (aux2){			//percorre a lista
						if (aux2->codigo_conta == codigoContaTran){
							aux2->saldo_conta = aux2->saldo_conta + transferencia;
						}
						aux2=aux2->prox_conta;
					}								
										
				} else { // fim do if
					printf("\nErro! Não foi possível efetuar a transferência.\n");
				}
				break;
			case 9: a = 1;
		}
	}
	if (a != 1) skip();
}
//--------------------------------------------------------------------------------
void visualizarConta (Conta *lista_conta){
	printf("--------------------------------\n");
	printf("Visualizar conta \n");
	printf("--------------------------------\n");

	int codigoConta; 
	int encontrou=0;
	char tipoConta[5];

	if (!lista_conta){
		printf("\nA lista de contas está vazia!\n");
	} else {
		printf("\nIntroduza o codigo da conta: ");
		scanf("%d", &codigoConta);

		while(lista_conta != NULL){    /* Enquanto nao chega no fim da lista */
			if (codigoConta == lista_conta->codigo_conta){			
				if (lista_conta->tipo_conta == 'p')
					strcpy(tipoConta, "prazo");						
				if (lista_conta->tipo_conta == 'o')
					strcpy(tipoConta, "ordem");
						
				printf("\n\nTipo: %s\nSaldo: %.2f\nCódigo associado a conta de cliente com o codigo: %d\n\n", tipoConta, lista_conta->saldo_conta, lista_conta->codigo_cli_conta);
				encontrou=1;
			}
		    lista_conta = lista_conta->prox_conta;     
		}
		if (encontrou==0){
			printf("A conta não existe");
		}			
	}	
	skip();
}

/******************************************************************************/
/*                        Início da função principal                          */
/******************************************************************************/

int main () 
{	
/*Introdução de caracteres específicos da Língua Portuguesa*/
	setlocale (LC_ALL, "Portuguese");

	int menuP, menuB; // menuE, menuBs;
	//int voltarP, voltarE, voltarB, voltarBs;	
	
	Cliente *lista_cli = NULL; /* Ponteiro para a cabeca da lista */
	Conta *lista_conta = NULL;  /* Ponteiro para a cabeca da lista */
	Cliente *novo_cli=NULL;
	Conta *novo_conta=NULL;
	
	// fopen, fclose, getc, putc, getw, putw, fprintf, fscanf, fgets, fputs, feof		
	FILE *fp;    // abrir o arquivo em modo escrita em binario
		
	int i_cli=1;
	int i_conta=1;
				
	/*Mensagem Inicial apresentada na janela do programa ao iniciar o mesmo*/	
	printf("\t\t--------------------------------------------------------------------\n");
	printf("\t\t\t\t\tBem Vindo Ao Banco \n");
	printf("\t\t--------------------------------------------------------------------\n\n");		
	while (1){				
		menuPrincipal ();
		scanf("%d", &menuP);
		clear_buffer();
		
		while ( menuP!=1 && menuP!=2 && menuP!=3 && menuP!=9 )
		{
			printf("\nIntroduza um número válido:");
			scanf("%d", &menuP);
			clear_buffer();
		}					
		/*Atribuição de uma caixa referente a cada Função do Evento, de modo a permitir a navegação por parte do utilizador pelo programa*/
		switch (menuP) 
		{				
			case 1: novo_cli = novoCliente(&i_cli);			
				addListaCli(novo_cli, &lista_cli);																
			break;	// break case 1								
			case 2: menuClientes ();				
				scanf ("%d", &menuB);
				clear_buffer();
					
				while (menuB!=1 && menuB!=2 && menuB!=3 && menuB!=4 && menuB!=5 && menuB!=6 && menuB!=7 && menuB!=9) 
					{
						printf("\nIntroduza um número válido:");
						scanf("%d", &menuB);
					}					
				system("cls");
					
				switch (menuB) 
				{
					case 1: editarCliente (&lista_cli); 									
						break;								
					case 2: eliminarCliente (&lista_cli, &i_cli);								
						break;									
					case 3:	visualizarCliente (lista_cli); 								
						break;								
					case 4: saldoGlobalCliente (lista_cli, lista_conta); 			
						break;	
					case 5: listaClientes (lista_cli);	 								
						break;	
					case 6: listaClienteLocal (lista_cli);
						break;
					case 7: listaClienteSaldoNeg (lista_cli, lista_conta);
						break; 						
					case 9: 
						break;
				}
			break; // break case 2		
			case 3: menuContas ();				
				scanf ("%d", &menuB);
				clear_buffer();
					
				while (menuB!=1 && menuB!=2 && menuB!=3 && menuB!=4 && menuB!=5 && menuB!=6 && menuB!=9)
				{
					printf("\nIntroduza um número válido:");
					scanf("%d", &menuB);
					clear_buffer();
				}					
				system("cls");
					
				switch (menuB) 
				{
					case 1: novo_conta = novaConta (&lista_conta, lista_cli, &i_conta); 
							addListaConta(novo_conta, &lista_conta);									
						break;								
					case 2: editarConta (&lista_conta);							
						break;									
					case 3:	eliminarConta (&lista_conta, &i_conta); 								
						break;								
					case 4: movimentosConta (&lista_conta);			
						break;								
					case 5: visualizarConta (lista_conta); 									
						break;									
					case 6: listaConta (lista_conta);								
						break;									
					case 9:	break;
				}
			break; // break case 3
			
			case 9: return 0;											
		}					
	}
}
