#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main(){
    int linha, count, quant, linhaveri, repet;
    
    setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	
	printf("Informe quantidade de cartelas a serem geradas: ");
	scanf("%d", &quant);
	fflush(stdin);
	
	int cartelas[10][quant]; //Vetor Cartelas de 10 x por quantas cartelas o usuário quiser
	count=0; //Inicia count
	while(count < quant){
		linha=0;//inicio
	    do{
	        cartelas[linha][count] = rand() % 99; //Inicia cartela
	        repet = 0;//Inicia/Reseta Verificador
	        for(linhaveri = 0; linhaveri < linha; linhaveri++){ // percorre a parte da cartela já preenchida
	            if(cartelas[linhaveri][count] == cartelas[linha][count])
	                repet = 1; // número repetido
	        }
	
	        if(repet == 0) //não repetiu
	            linha++;
	    }while(linha <= 9);
	    
		count++; //Cartelas++
	}
	
	//Mostra Cartelas
	for(count=0; count < quant; count++){
		printf("\n============ %dº Tabela ============\n |", count+1); //"+1" para printar bonitinho.
		for(linha=0; linha <= 9; linha++){
			printf("%.2d|", cartelas[linha][count]);
		}
		printf("\n\n");
	}
	return 0;
}
