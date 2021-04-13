#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#define MAX 60

struct cards{
	int cod;
	char name[20];
	char type[20];
	int life;
	int attack;
	int mana;
	char evol[20];
	int existe;
};
struct cards card[MAX];

int cadastrar(int E, int L);
int listar(int K);
int buscar(int A);
int editar(int M);
int remover(int N);
int Ncartas=0;
int buscSeq(int B);
void quick (card cards[], int inicio, int final);

FILE *arquivo = NULL; //manipulador

int main(){
	int op, N=0, Devol, op2;
	printf("-- Pokemon Card Game --");    
	system("color 70");
  	while(1){
	  	printf("\n\n         Menu     ");
	  	printf("\n ________________________");
	  	printf("\n|  1 - Cadastrar         |");
	  	printf("\n|  2 - Listagem   	 |");
	  	printf("\n|  3 - Ordenar por Codigo|");
	  	printf("\n|  4 - Buscar carta      |");
	  	printf("\n|  5 - Editar carta      |");
	  	printf("\n|  6 - Remover carta     |");
	  	printf("\n|  7 - Sair		 |");
	  	printf("\n|________________________|");
	  	printf("\n\n Opcao Desejada: \n");
  		scanf("%d",&op);
  		arquivo = fopen("ArquivoCG.txt","r+"); //ler se existe o arquivo
		if(arquivo==NULL){
		       arquivo = fopen("ArquivoCG.txt","w+"); //se não existir, criar um arquivo
		}
  		switch(op){
  			case 1: 
				printf("Quantas cartas deseja cadastrar?\n Limite: %d\n Numero de cartas para cadastrar: %d \nQuantidade: ", MAX, MAX-Ncartas);
				scanf("%d",&N);
				if(Ncartas<=MAX){
					Ncartas = Ncartas+N;
					cadastrar(Ncartas,Ncartas-N);
				}
				else printf("Voce atingiu o limite de numero de cartas!\n Cartas cadastradas: %d", MAX);
  				break;
  			case 2:
				if(Ncartas==0){
					printf("Sem cartas cadastradas!\n");
					sleep(1);
				}
				else listar(Ncartas);
				break;
			case 3:
				if(Ncartas==0){
					printf("Sem cartas cadastradas!\n");
					sleep(1);
				}
				quick(0,Ncartas);
				break;	
			case 4:
				if(Ncartas==0){
					printf("Sem cartas cadastradas!\n");
					sleep(1);
				}
				else{
					do{
					printf("\nQual busca voce deseja usar?\n 1 - Sequencial\n 2 - Binaria\n");
					scanf("%d", &op2);
					}while(op2!=1 && op2!=2);
					if(op2==1) buscar(Ncartas);
					if(op2==2) buscBin(Ncartas);
				}buscar(Ncartas);
				break;	
			case 5:
				if(Ncartas==0){
					printf("Sem cartas cadastradas!\n");
					sleep(1);
				}
				else editar(Ncartas);
				break;	
			case 6:
				if(Ncartas==0){
					printf("Sem cartas cadastradas!\n");
					sleep(1);
				}
				else Devol=remover(Ncartas);
				if(Devol==1) Ncartas=Ncartas-1;
				break;	
			case 7:
				exit(0);
				break;
			default:
				printf("Opcao Invalida\n");
				sleep(1);
				break;
  		} 
  		fclose(arquivo); // fecha o arquivo com segurança
  	}
  	return 0;
}

int cadastrar(int E, int L){
	int I,J,CE;
	for(I=L; I<E; I++){
		write(1,"\E[H\E[2J",7);
		CE = 0;
		while(CE==0){
			do{
				printf("\nCode(>0): ");
				scanf("%d",&card[I].cod);
			}while(card[I].cod<=0);
			CE = 1;
			for(J=0;J<I;J++) if(card[J].cod == card[I].cod ) CE = 0;
				if(CE == 0) printf("Codigo ja existe!\n");
		}
  		printf("Name: ");
  		scanf("%s", card[I].name);
  		printf("Type: ");
  		scanf("%s", card[I].type);
  		printf("Evolution: ");
  		scanf("%s", card[I].evol);
  		printf("HP: ");
  		scanf("%d", &card[I].life);
  		printf("Damage Attack: ");
  		scanf("%d", &card[I].attack);
		printf("Cost Attack: ");
		scanf("%d", &card[I].mana);
		card[I].existe==1;
	}				
}

int listar(int K){
	int i;
	for(i=0; i<=K; i++){
		if(card[i].cod>0){
			printf("\n\nCode: %d",card[i].cod);
			printf("\nName: %s",card[i].name);
			printf("\nType: %s", card[i].type);
			printf("\nEvolution: %s", card[i].evol);
			printf("\nHP: %d",card[i].life);
			printf("\nDamage Attack: %d",card[i].attack);
			printf("\nCost Attack: %d \n",card[i].mana);
		}
	}
}

int buscar(int A){
	int BC, i, aux=0;
	printf("\nEntre com o codigo da carta que deseja buscar: ");
	scanf("%d", &BC);
	for(i=0; i<A; i++){
		if(card[i].cod==BC){
			printf("\nCARTA BUSCADA:");
			printf("\nCode: %d",card[i].cod);
			printf("\nName: %s",card[i].name);
			printf("\nType: %s", card[i].type);
			printf("\nEvolution: %s", card[i].evol);
			printf("\nHP: %d",card[i].life);
			printf("\nDamage Attack: %d",card[i].attack);
			printf("\nCost Attack: %d \n",card[i].mana);
			aux=1;	
		}
	}
	if(aux==0) printf("Carta nao encontrada!\n");
	return 0;
}

int editar(int M){
	int BC, i, aux=0;
	printf("\nEntre com o codigo da carta que deseja editar: ");
	scanf("%d", &BC);
	for(i=0; i<M; i++){
		if(card[i].cod==BC){
			printf("\nEDITAR DADOS: \n");
			printf("Name: ");
  			scanf("%s", card[i].name);
  			printf("Type: ");
  			scanf("%s", card[i].type);
  			printf("Evolution: ");
  			scanf("%s", card[i].evol);
  			printf("HP: ");
  			scanf("%d", &card[i].life);
  			printf("Damage Attack: ");
  			scanf("%d", &card[i].attack);
			printf("Cost Attack: ");
			scanf("%d", &card[i].mana);
			aux=1;
		}
	}
	if(aux==0) printf("Carta nao encontrada!\n");
}

int remover(int N){
	int BC, i, aux=0, dev=0;
	printf("\nEntre com o codigo da carta que deseja excluir: ");
	scanf("%d", &BC);
	for(i=0; i<N; i++){
		if(card[i].cod==BC){
			printf("\nEXCLUINDO DADOS... \n");
			card[i].cod=0;
			aux=1;
			dev=1;
		}
	}
	if(aux==0) printf("Carta nao encontrada!\n");
	else printf("Carta excluida!\n");
	return dev;
}

int buscBin(int C){
	int J, K, I, busca, aux=0;
	for(J=1; J<C; J++){
		for(K=0;K<C-1;K++){
			if(card[K].cod > card[K+1].cod){
				card[C] = card[K];
				card[K] = card[K+1];
				card[K+1] = card[C];
			}
		}
	}
	printf("\nEntre com o codigo da carta que deseja buscar: ");
	scanf("%d", &busca);
	for(I=0; I<C; I++){
		if(card[I].cod==busca){
			printf("\nCARTA BUSCADA: ");
			printf("\nCode: %d",card[I].cod);
			printf("\nName: %s",card[I].name);
			printf("\nType: %s", card[I].type);
			printf("\nEvolution: %s", card[I].evol);
			printf("\nHP: %d",card[I].life);
			printf("\nDamage Attack: %d",card[I].attack);
			printf("\nCost Attack: %d \n",card[I].mana);
			aux=1;	
		}
	}
	if(aux==0) printf("Carta nao encontrada!\n");
	sleep(2);
	return 0;
}

void quick(card cards[], int inicio, int final){
	int i,j, pivo;
	pivo = cont/2;
	i=inicio;
	j=final;	
	car caneca;
	while(i<=j){             // deixar passar um posicao do 2º lado
		while(i<pivo && car[i].cod <= card[pivo].cod)i++;
		while(j>pivo && car[i].cod > card[pivo].cod) j--;
		if(i<j){			
			caneca = cards[j];
			cards[j] = cards[i];
			cards[i] = caneca;
			i++;
			j--;
		}	
	}
	if(pivo < j) quick(cards, pivo);
	if(cont > i) quick(cards+pivo, cont - pivo);
}
