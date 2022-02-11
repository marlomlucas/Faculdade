/*
Autor: Marlom Camaran Lucas
Data: 07/06

Iniciei as variaveis desta manei pq a variavel "maria" estava iniciando com valor 1 coloquei um printf antes do "while" para verificar o inicio dela, estava com 1.
Não consegui descobrir o pq, ai iniciei todas assim. Obs: mesmo sem iniciar as coutras estavam com 0 só a maria que inicia com 1
Prazo para envio da atividade se esgotando, tive que mandar assim.
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include <unistd.h>

int main(){
	setlocale(LC_ALL, "Portuguese");//Ajuste Acentuação.
	
	//Variaveis
	int opmenu, vereador, joao, maria, ze, nulo, invalido, prefeito, zureta, sgomes, nulopre, invalidopre;
		opmenu = vereador = joao = maria = ze = nulo = invalido = prefeito = zureta = sgomes = nulopre = invalidopre = 0;
	
    while("True"){
    	printf("====== Pesquisa Eleitoral ======\n");
		printf(" 1 - Votar\n 2 - Apuração dos votos\n 3 - Sair\n");
    	printf("=> ");
		scanf("%d", &opmenu);
		fflush(stdin);
		if(opmenu == 1){
			system("cls");
			printf("=== Vote para Vereador ===\n \n");
			printf("111 - Joao do Frete \n222 - Maria da Pamonha \n333 - Ze da Farmacia \n444 - Voto Nulo \n");
			printf("Numero do candidato=> ");
			scanf("%d", &vereador);
			fflush(stdin);
			switch(vereador){
				case 111:
					joao+=1;
					printf("Voto para Joao do Frete \n");
					break;
				case 222:
					maria+=1;
					printf("Voto para Maria da Pamonha \n");
					break;
				case 333:
					ze+=1;
					printf("Voto para Ze da Farmacia \n");
					break;
				case 444:
					nulo+=1;
					printf("Voto Nulo \n");
					break;
				default:
					invalido+=1;
					printf("Voto Invalido \n");
					break;
			}
			sleep(3);
			system("cls");
			
			printf("=== Vote para Prefeito ===\n \n");
			printf(" 11 - Dr. Zureta\n 22 - Senhor Gomes\n 44 - Voto Nulo\n");
			printf("Numero do candidato=> ");
			scanf("%d", &prefeito);
			fflush(stdin);
			switch(prefeito){
				case 11:
					zureta+=1;
					printf("Voto para Dr. Zureta \n");
					break;
				case 22:
					sgomes+=1;
					printf("Voto para Senhor Gomes \n");
					break;
				case 44:
					nulopre+=1;
					printf("Voto Nulo \n");
					break;
				default:
					invalidopre+=1;
					printf("Voto Invalido \n");
					break;
			}
			sleep(3);
			system("cls");
		}
		else if(opmenu == 2){
			system("cls");
			printf("=== Apuração Votos ===\n\n");
			printf("=== Vereadores ===\n");
			printf("Joao do Frete | %d Votos \n", joao);
			printf("Maria da Pamonha | %d Votos \n", maria);
			printf("Ze da Farmacia | %d Votos \n", ze);
			printf("Votos Nulos | %d \n", nulo);
			printf("Votos Invalidos | %d \n", invalido);
			printf("=====================\n\n");
			printf("=== Prefeitos ===\n");
			printf("Dr. Zureta | %d Votos \n", zureta);
			printf("Senhor Gomes | %d Votos \n", sgomes);
			printf("Votos Nulos | %d \n", nulopre);
			printf("Votos Invalidos | %d \n", invalidopre);
			printf("=== Fim Apuração ===\n\n");
		}
		else if(opmenu == 3){
			printf("Saindo...");
			break;
		}else{
			system("cls");
			printf("---> Opção invalida. \n\n");
		}
	}
	return 0;
}
