//Incluindo bibliotecas
#include <stdio.h> 
#include <stdlib.h>
#include <locale.h>



int main(int argc, char*argv[]){ //Começando o programa
	
	setlocale(LC_ALL, "Portuguese"); //Setando caracteres em português para permitir ç e acentos.
	
	float N1, AP, AI, N3; //Criando varíaveis para guardar o valor da N1, da AP, da AI e da N3
	
	//Dando Boas vindas e Pedindo o valor da nota da N1
	printf("\n");
	printf("---------------------------------------------------------------------------------\n");
	printf("                  Seja Bem vindo(a) a calculadora de média da ----               ");
	printf("\n---------------------------------------------------------------------------------\n");
	
	printf("\nPara começarmos a calcular a média, comece digitando a sua nota da Prova N1:");
	scanf("%f", &N1); //Escaneando o valor da Nota N1 e guardando na variável N1
	
	printf("\nAgora para continuar, digite a nota da AP:");
	scanf("%f", &AP); //Escaneando o valor da AP e guardando na variável AP
	
	printf("\nEm seguida, digite a nota da AI:");
	scanf("%f", &AI); //Escaneando o valor da AI e guardando na variável AI
	
	float N2 = (AP + AI) / 2; //Calculando o valor da nota N2 somando os valores de AP E AI, depois dividindo por 2.
	float media = (N1 + N2) / 2; //Calculando o valor da media somando os valores de N1 e N2,depois dividindo por 2.
	
	printf("\n\n\n\n A nota da sua N1 foi de: %.2f\n\n A nota da sua AP foi de: %.2f\n\n A nota da sua AI foi de: %.2f\n\n A nota da sua N2 foi de: %.2f\n\n A sua média foi de: %.2f\n\n", N1, AP, AI, N2, media); //Exibindo valores de N1, AP, AI, N2 e da media com apenas 2 casas decimais.
	
	if(media >= 6){ //Se a média for maior ou igual a seis falar que foi aprovado e deixar em verde
		system("color 02");
		printf("\n\n\n\n\n\nParabéns, você foi Aprovado!");
	}
	
	else{ //Se não deixar em vermelho, falar que não passou,pausar o sistema, limpar a exibição anterior.....
		system("color 04");
		printf("\n\n\n\n\n\nInfelizmente você ficou de recuperação.");
		system("pause");
		system("cls");

		system("color 07"); //Voltando à cor padrão
		printf(" Agora que sabemos que você ficou de recuperação, digite a nota que você tirou na N3:\n"); 
		scanf("%f", &N3); //Escaneando e guardando o valor da N3 em uma variável

		float nova_media; //Criando uma variavel para a nova média após prova N3

		if(N1 > N2){ //Se a nota da N1 for maior que a da N2, a nova média vai ser composta da soma da N1 + N3 e da divisão do resultado por 2.
			nova_media = (N1 + N3) / 2;
			printf("\nA nota da sua N3 foi de: %.2f,A nota da sua N1 foi de: %.2f, e sua nova média foi de: %.2f.", N3, N1, nova_media); //Exibindo a nota da N3, N1 e da nova média.
		}
		else{ //Se a nota da N2 for maior que a da N1, a nova média vai ser composta da soma da N2 + N3 e da divisão do resultado por 2.
			nova_media = (N2 + N3) / 2;
			printf("\nA nota da sua N3 foi de: %.2f,A nota da sua N2 foi de: %.2f, e sua nova média foi de: %.2f.", N3, N2, nova_media); //Exibindo a nota da N3, N2 e da nova média.
		}
		
		if(nova_media >= 6){ //Se a nova média pós N3 for maior ou igual a 6 falar que foi aprovado e deixar em verde
			system("color 02");
			printf("\n\n\n\n\n\nParabéns, você foi Aprovado!");
		}
		else{ //Se a nova média pós N3 for menor que 6 falar que foi reprovado e deixar em vermelho
			system("color 04"); 
			printf("\n\n\n\n\n\nInfelizmente você foi reprovado.");
		}
	}
	return 0;
}
