#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
/* Um programa que pega do usu�rio a quantidade de alunos, o nome, data de nascimento e 3 notas E retorna a m�dia, se o aluno est� Aprovado; Reprovado ou de 
Recupera��o. Tamb�m retorna a idade e a maior media*/

float FuncaoMedia(int n1[3]); /*Fun��o que c�lcula a m�dia das notas*/
int IdadeAtual(int anoDeNascimento, int anoAtual); /*Fun��o que c�lcula a idade do aluno*/


	struct dataDeNascimento{ /*Struct para a data de nascimento*/
		int dia, mes, ano, idade;
		}; typedef struct dataDeNascimento dataDeNascimento;
		
	struct cadastro{ /*Struct para o cadastro*/
		char nome[50];
		dataDeNascimento data_de_Nascimento;
		int notas[3]; /*Vetor de variavel para armazenar as notas em espa�os diferentes*/
		float media;
	}; typedef struct cadastro cadastro;


int main (void){
 	
 	setlocale(LC_ALL, "Portuguese");

	int qtdAlunos = 0; /*Armazena a quantidade de alunos*/
	
	printf("Insira a quantidade de alunos a ser cadastrados:\n");	
		scanf("%d", &qtdAlunos);
	
	cadastro Cadastro[qtdAlunos]; /*Vetor da variavel Cadastro do tipo struct cadastro*/
	
	printf("\n\n------------------------------------------ Cadastro de Aluno(s) ------------------------------------------\n\n");
	
	int clienteX; /*Controla o vetor da varialvel Cadastro, ou seja, contrala de qual aluno pertence os dados*/
	
	for (clienteX = 0; clienteX <= qtdAlunos -1; clienteX++){ /*Aqui pede cada dado(s) de cada aluno(s) informado pela quantidade de alunos*/
		printf("\t\t\t\t\tInsira os dados do %d� aluno\n", clienteX+1);
		fflush(stdin);
		puts("Nome:"); /*Pede o nome*/
			fgets(Cadastro[clienteX].nome, 50, stdin); Cadastro[clienteX].nome[strcspn(Cadastro[clienteX].nome, "\n")] = 0;
		printf("\nData de Nascimento(dd/mm/aaaa): "); /*Pede a Data de nascimento*/
			scanf("%d", &Cadastro[clienteX].data_de_Nascimento.dia);scanf("%d", &Cadastro[clienteX].data_de_Nascimento.mes);
			scanf("%d", &Cadastro[clienteX].data_de_Nascimento.ano);
		printf("\nNotas:\n\n"); fflush(stdin); /*Pede as Notas*/ 
			printf("Trabalho (de 0 � 10): ");
				scanf("%d", &Cadastro[clienteX].notas[0]);
			printf("Avalia��o (de 0 � 10): ");
				scanf("%d", &Cadastro[clienteX].notas[1]);
			printf("Caderno (de 0 � 10): ");
				scanf("%d", &Cadastro[clienteX].notas[2]);
			Cadastro[clienteX].media = FuncaoMedia(Cadastro[clienteX].notas); /*Armazena no Cadastro do aluno X o resultada de retorno da Fun��oMedia*/
			printf("\n");
			}
	system("cls"); //Limpa a tela
	for (clienteX = 0; clienteX <= qtdAlunos -1; clienteX++){
		Cadastro[clienteX].data_de_Nascimento.idade = IdadeAtual(Cadastro[clienteX].data_de_Nascimento.ano, 2023); /*Armazena na Cadastro do aluno X o valor de
		retorno da fun��o IdadeAtual*/
	}

	printf ("------------------------------------------ Exibi��o de Medias ------------------------------------------\n\n");

	for(clienteX = 0; clienteX <= qtdAlunos -1; clienteX++){ /*Exibi a media de cada aluno e diz se est� aprovado, reprovado ou de recupera��o*/
		printf("O aluno %s (%d anos) tem a nota de %.1f", Cadastro[clienteX].nome, Cadastro[clienteX].data_de_Nascimento.idade, Cadastro[clienteX].media);
		if (Cadastro[clienteX].media >= 7.0 && Cadastro[clienteX].media <= 10.0){ /*Teste 1 para ver se est� aprovado*/
			printf(". Aprovado!\n\n", Cadastro[clienteX].nome);
		} else {
			if (Cadastro[clienteX].media >= 5.0 && Cadastro[clienteX].media <= 6.9){ /*Se n�o passou no Teste 1, vem para o Teste 2 para saber se est� de recupera��o*/
				printf(". Recupera��o!\n\n", Cadastro[clienteX].nome);
			} else{
				if (Cadastro[clienteX].media >= 0.0 && Cadastro[clienteX].media <= 4.9){ /*Teste para ver se o aluno est� de recupera��o*/
					printf(". Reprovado!\n\n", Cadastro[clienteX].nome);
				}
			}
		}
	}		
	
	float maiorMedia = -0.1; /*Armazena a maior media*/
	char nomeMaiorMedia[50] = ""; /*Armazena o nome do aluno a quem pertence a maior media*/
	
	for(clienteX = 0; clienteX <= qtdAlunos -1; clienteX++){
		if (Cadastro[clienteX].media > maiorMedia){ /*Se a media do aluno X for maior que a maior media atual, ent�o*/
			maiorMedia = Cadastro[clienteX].media; /*a variavel maiorMedia passa a valer o valor da media do aluno X*/
			strcpy (nomeMaiorMedia, Cadastro[clienteX].nome); /*E a variavel nomeMaiorMedia passa a valer o nome do aluno X*/
		}
	}

	printf ("\nA maior media � de %.1f do aluno %s", maiorMedia, nomeMaiorMedia); /*Exibe a maior media e a quem pertence*/
	
	return 0;
}

//Fun��o que calcula a m�dia 
float FuncaoMedia(int n1[3]){ /*Recebe como parametro um vetor de inteiros de 3 posi��es (notas)*/
	float media = 0.0;

	media = (n1[0] + n1[1] + n1[2]) / 3.0; /*Calcula a media entre eles*/

return media;/*Retorna o valor da media*/
}

//Fun��o que calcula a idade
int IdadeAtual(int anoDeNascimento, int anoAtual){ /*Recebe o ano de nascimento e o ano atual*/
	
	int idade;
	idade = anoAtual - anoDeNascimento; /*C�lculo um menos o outro*/
	
	return idade; /*Retorna a idade*/
}
