// RodaARodaCPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
	/* Carrega as palavras e os temas*/
	char  * palavras[20][2] =
	{
		{ "abelha","mel" },
		{ "goleiro","futebol" },
		{ "teste","teste" },
		{ "teste","teste" },
		{ "teste","teste" },
		{ "teste","teste" },
		{ "teste","teste" },
		{ "teste","teste" },
		{ "teste","teste" },
		{ "teste","teste" },
		{ "teste","teste" },
		{ "teste","teste" },
		{ "teste","teste" },
		{ "teste","teste" },
		{ "teste","teste" },
		{ "teste","teste" },
		{ "teste","teste" },
		{ "teste","teste" },
		{ "teste","teste" },
		{ "teste","teste" },
	};


	/* Intializes random number generator */

	time_t t;
	srand((unsigned)time_t(&t));

	int index = rand() % 20;

	char *palavra = palavras[index][0];
	char *tema = palavras[index][1];

	printf("O tema é: %s\n", tema);

	getchar();
}

