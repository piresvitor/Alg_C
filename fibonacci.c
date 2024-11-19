/*----------------------------------------
          FIBONACCI FUNCTION           	
------------------------------------------

Usage:	
./fibonacci [numero_de_termos] [algoritmo]

Entradas:

1. numero_de_termos = qtde de termos da 
						    sequencia de Fibonacci.

2. algoritmo = 0 para iterativo ou
				   1 para recursivo

Saídas:

1. valor final da sequencia
2. tempo consumido (ms)

------------------------------------------
A sequencia de Fibonacci é dada por:

F (0) = 0;
F (1) = 1;
F (N > 1) = F (N-1) + F(N-2)
------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_N 0		//qtde mínima de termos da sequencia
#define MAX_N 200		//qtde máxima de termos da sequencia
#define ITERATIVE 0	//usa função iterativa
#define RECURSIVE 1	//usa função recursiva

/* função recursiva */
double FiboRecursive(int numberOfTerms);
/* função iterativa */
double FiboIterative(int numberOfTerms);
/* função para computar tempo consumido */
double computeElapsedTime(clock_t init, clock_t fim);

int main (int argc, char *argv[])
{
	int numTerms;	//numero de termos da sequencia
	int alg;			//tipo de algoritmo escolhido
	double resultFibonacci;		//armazena o termo da sequencia
	clock_t startTime, endTime;	//marcadores de tempo
	double elapsedTime;			//armazena tempo consumido

	/* Erro 1: numero de parâmetros diferente de três */
	if (argc != 3) {
		printf("Usage: ./fibonacci [number_of_terms] [algorithm]\n");
		exit(EXIT_FAILURE); //maneira de avisar o sistema que houve uma falha
	}

	/* converte os parâmetros de entrada de char para int */
	numTerms = atoi(argv[1]);
	alg = atoi(argv[2]);

	/* Erro 2: número do termo desejado é inválido */
	if ((numTerms < MIN_N) || (numTerms > MAX_N)){
		printf("The number of therms must be limited between %d-%d!\n", MIN_N, MAX_N);
		exit(EXIT_FAILURE);
	}

	/* Erro 3: código do algoritmo desejado é inválido */
	if ((alg != ITERATIVE) && (alg != RECURSIVE)){
		printf("The algorithm must be 0 for iterative or 1 for recursive!\n");
		exit(EXIT_FAILURE);
	}	

	/* Se o algoritmo escolhido for iterativo */
	if (alg == ITERATIVE){
		printf("Algorithm: Iterative\n");

		startTime = clock(); //pega hora do sistema
		resultFibonacci = FiboIterative(numTerms-1); //chama rotina de Fibonacci iterativa (o número de termos é decrementado em 1 porque a sequencia de Fibonacci começa em zero. Portanto, F(0) é o primeiro termo da sequencia)
		endTime = clock(); //pega hora do sistema
	}
	else{
		/* Se o algoritmo escolhido for recursivo */
		printf("Algorithm: Recursive\n");

		
		startTime = clock(); //pega hora do sistema
		resultFibonacci = FiboRecursive(numTerms-1); //chama rotina de Fibonacci recursiva
		endTime = clock(); //pega hora do sistema
	}
	
	/* Imprime o termo desejado da sequencia de Fibonacci */
	printf("Fibonacci(%d) = %g\n", numTerms, resultFibonacci);
	
	/* Calcula o tempo total consumido */
	elapsedTime = computeElapsedTime(startTime, endTime);
	/* Imprime o tempo total consumido */
	printf("Elapsed time (ms) = %.2lf\n", elapsedTime);
	
	/* Avisa o sistema que o programa executou corretamente */
	exit(EXIT_SUCCESS);
}


/* função recursiva para encontrar o n-ésimo
termo da sequencia de Fibonacci */
double FiboRecursive(int numberOfTerms)
{
	if (numberOfTerms < 2)
		return (numberOfTerms);
	else
		return (FiboRecursive(numberOfTerms - 1) + FiboRecursive(numberOfTerms - 2));
}


/* função iterativa para encontrar o n-ésimo
termo da sequencia de Fibonacci */
double FiboIterative(int numberOfTerms)
{
	double fibo = 0, i = 1;
	int k;

	// fibo = F(n - 2) e i = F(n - 1)
	for (k = 1; k <= numberOfTerms; k++){
		fibo = i + fibo;
		i = fibo - i;
	}
		
	return (fibo);
}


/* função que calcula a diferença de tempo 
(em segundos) entre duas marcações distintas */
double computeElapsedTime(clock_t  ini, clock_t  fim)
{
	double totalTime;

	//totalTime = difftime(fim, ini);

	totalTime = ((double)fim - ini) / CLOCKS_PER_SEC * 1000;

	return (totalTime);
}

