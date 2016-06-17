#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <string.h>
#define TRUE 1

int main()
{
	/* Carrega as palavras e os temas*/
	char  * palavras[20][2] =
	{
		{"abelha","mel"},
		{ "goleiro","futebol" },
		{ "teste","teste tema" },
		{ "teste","teste tema" },
		{ "teste","teste tema" },
		{ "teste","teste tema" },
		{ "teste","teste tema" },
		{ "teste","teste tema" },
		{ "teste","teste tema" },
		{ "teste","teste tema" },
		{ "teste","teste tema" },
		{ "teste","teste tema" },
		{ "teste","teste tema" },
		{ "teste","teste tema" },
		{ "teste","teste tema" },
		{ "teste","teste tema" },
		{ "teste","teste tema" },
		{ "teste","teste tema" },
		{ "teste","teste tema" },
		{ "teste","teste tema" },
	};

	/* Inicio do laço principal do jogo */
	do
	{
		//Intializes random number generator
		time_t t;
		srand(time(&t));
		int index = rand() % 20;

		index = 0;
		char *palavra = palavras[index][0];
		char *tema = palavras[index][1];

		int index_qtdletras = 0;
		while (palavra[index_qtdletras] != '\0') ++index_qtdletras; //calculando a quantidade de letras da palavra.
		int qtd_letras = index_qtdletras; //strlen(palavra); 
		int qtd_chutes = qtd_letras * 2;
		char *letras_encontradas_p = (char*)malloc(sizeof(char) * qtd_letras);
		int qtd_letras_econtradas = 0;

		printf("O tema e: --- %s ----\n", tema);
		for (int i = 0; i < qtd_letras; i++) printf("*");
		printf("\n");
		printf("=>\n");


		int acertou = 0;
		do
		{
			printf("Informe uma letra: ");
			char letra;
		ler:
			letra = getchar(); //Lendo a letra inputada.
			if (letra == ' ' || letra == '\n')
				goto ler;
			int encontrou_letra = 0;


			for (int i = 0; i < qtd_letras; i++)
			{
				if (letra == letras_encontradas_p[i])
				{
					printf("Essa letra ja foi informada. Informe outra letra: ");
					goto ler;
				}
			}


			// Verificando se a letra existe na palavra
			for (int i = 0; i < qtd_letras; i++)
			{
				if (palavra[i] == letra)
				{
					printf("letra %c na posicao %i\n", letra, i);
					encontrou_letra = 1;
					qtd_letras_econtradas++;
					letras_encontradas_p[i] = letra;
				}
			}

			if (encontrou_letra)
			{
				acertou = 1;
				for (int i = 0; i < qtd_letras; i++)
				{
					if (palavra[i] == letras_encontradas_p[i])
						printf("%c", letras_encontradas_p[i]);
					else
					{
						printf("*");
						acertou = 0;
					}
				}
				if (acertou == 1)
				{
					printf("\nPARABENS! voce acertou!\n");
				}
				else
					printf("\nAinda restam: %i chances\n", qtd_chutes);
			}
			else
			{
				printf("\nAinda restam: %i chances\n", qtd_chutes);
				//printf("roda a roda...\n\n\n");
			}

			qtd_chutes--; //usando operador de pos decremento
		} while (acertou == 0 && qtd_chutes >= 0);
		if (qtd_chutes <= 0)
			printf("Game Over.\n");
		printf("Jogar novamente? S/N:");
		char resposta;
	ler2:
		resposta = getchar();
		if (resposta == 'n' || resposta == 'N')
			exit(0);
		else if (resposta == '\n' || resposta == ' ')
			goto ler2;
		else if (resposta != 'S' && resposta != 's')
		{
			printf("Opcao incorreta.  Jogar novamente? S/N: ");
			goto ler2;
		}
	} while (TRUE);
}
