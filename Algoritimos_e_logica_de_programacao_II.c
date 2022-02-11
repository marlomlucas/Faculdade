/* ====== Marlom Camaran Lucas === ALP 2 === 12/07/2021 ======
=> Dados para perguntas e soma de pontuação. Geralmente uso com dicionário{}, lista[] ou tupla() porem em C pesquisei bastante e não achei nada viavel para este caso.
=> Pensei em fazer em um outro ".txt" como "BD" e usar "for, while etc..." para ler e atribuir no inico do sistema, mas o Studeo não permite anexar dois arquivos.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>

//Struct Cadastro
struct cadastro{
	char nome[60], cpf[12], sexo;
	int idade;
};

//Func Valida CPF
validacpf(){
	char cpf[12];
	do{
		printf("Informe seu CPF 'Somente os numeros': ");
		fgets(cpf, 12, stdin);
		fflush(stdin);
		if(strlen(cpf) == 11){
			break;
		}else{
			printf("CPF Invalido.\n");
		}
	}while(true);
		return cpf;
};


int main(){
	setlocale(LC_ALL, "Portuguese");//Ajuste acentuação com "pt-br" No arquivo salva caractesres erradas, mas ao listar mostra correto"
	
	struct cadastro paciente;
	char quest[11][81], resp, leitura;
	int acumula, count, pontos[11], op;
	
	FILE *arquivo;//Variavel "Arquivo"
	arquivo = fopen("lista_classificacao_risco.txt", "a+");//Local e tipo de leitura/gravação
	
	//===================================== Dados para perguntas e soma de pontuação. ========================================================
	strcpy(quest[0], "Tem Febre?");
	strcpy(quest[1], "Tem dor de cabeça?");
	strcpy(quest[2], "Tem secreção nasal ou espirros?");
	strcpy(quest[3], "Tem dor/irritação na garganta?");
	strcpy(quest[4], "Tem tosse seca?");
	strcpy(quest[5], "Tem dificuldade respiratoria?");
	strcpy(quest[6], "Tem dores no corpo?");
	strcpy(quest[7], "Tem diarreia?");
	strcpy(quest[8], "Esteve em contato, nos ultimos 14 dias, com um caso diagnosticado com COVID-19?");
	strcpy(quest[9], "Esteve em locais com grande aglomeração ?");
	pontos[0] = 5; pontos[1] = 1; pontos[2] = 1; pontos[3] = 1; pontos[4] = 3; pontos[5] = 10; pontos[6] = 1; pontos[7] = 1; pontos[8] = 10; pontos[9] = 3;
	
	printf("1 - Iniciar sistema de Classificação de risco CV19...\n");
	printf("2 - Listar Pacientes cadastrados.\n");
	printf("==> ");
	scanf("%d", &op);
	fflush(stdin);
	system("cls");
	
	switch(op){
		case 1:
			printf("Iniciando sistema de Classificação...");
			sleep(3);
			system("cls");
			while("True"){
				printf("====== Totem classificação de risco COVID-19 ======\n\n");
				strcpy(paciente.cpf, validacpf());
				
				printf("Informe Nome completo: ");
				fgets(paciente.nome, 60, stdin);
				fflush(stdin);
				
				printf("Informe sexo: [Masculino = M | Feminino = F]: ");
				scanf("%c", &paciente.sexo);
				fflush(stdin);
				
				printf("Informe sua Idade: ");
				scanf("%d", &paciente.idade);
				fflush(stdin);
				
				system("cls");
				
				printf("=== Responda o questionario a seguir ===\n\n");
				acumula=0;
				for(count=0; count<10; count++){
					while("True"){
						printf("%s [S = Sim | N = Não]: ", quest[count]);
						scanf("%c", &resp);
						resp = tolower(resp);//Joga para minusculo para fazer o IF
						fflush(stdin);
						switch(resp){
							case 's':
								acumula += pontos[count];
								break;
							case 'n':
								break;
							default:
								printf("*** Opcao Invalida, responda S para Sim ou N para Não.\n");
						}
						if(resp == 's' || resp == 'n'){
							break;
						}
					}
				}
				system("cls");
				printf("==> Total de pontos: %d \n", acumula);
				
				//===================== Gravando Dados ".txt" =============================
				fprintf(arquivo, "\n==============================\n");
				fprintf(arquivo, "CPF: %s\nNOME: %sSEXO: %c\nIDADE: %d\nPONTUAÇÃO: %d", paciente.cpf, paciente.nome, paciente.sexo, paciente.idade, acumula);//Grava no Arquivo
				fprintf(arquivo, "\n==============================");
				fclose(arquivo);//Fecha arquivo
				//==================================================================
				
				if(acumula <= 9){
					printf("==> Risco Baixo. Siga a faixa Verde ate a sala de espera.\n");
					sleep(8);
					system("cls");
				}else if(acumula >= 10 && acumula <= 19){
					printf("==> Risco Médio. Siga a faixa Amarela ate a sala de espera.\n");
					sleep(8);
					system("cls");
				}else if (acumula >= 20){
					printf("==> Risco Alto. Siga a faixa Vermelha ate a sala de espera.\n");// ==> Caso risco Alto ou Salas no limite da capacidade. Notificação via sistema e/ou Luzes | Alerta sonoro. "Arduino/Raspberry"
					sleep(8);
					system("cls");
				}else{
					printf("**Falha na Classificação**\n==> **Favor aguarde no local indicado, um atendente foi notificado e esta a caminho.**");// ==> Notificação via sistema e/ou Luzes | Alerta sonoro. "Arduino/Raspberry"
					sleep(8);
					system("cls");
				}
			}
			break;
		case 2:
			printf("Carregando lista...");
			sleep(1);
			system("cls");
			printf("=== Lista de pacientes, classificação de risco CV19 ===\n");
			while(true){
				leitura = fgetc(arquivo);//le arquivo
				if(leitura == EOF){
					printf("\n==> Fim lista.");
					break;
				}else{
					printf("%c", leitura);
				}
			};
			fclose(arquivo);//Fecha arquivo
			break;
	}
	return 0;
}
