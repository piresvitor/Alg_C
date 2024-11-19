#include <stdio.h>

// Define o tipo nota (float)
typedef float nota;

// Define o registro aluno com os campos: ra, notas das provas p1 e p2 e media
struct aluno { 
	int   ra;
	nota nota_p1, nota_p2;
	float media; 
};


int main ()
{
	struct aluno aluno1;

	// recebe os campos do aluno1
	printf ("Digite o RA do aluno: ");
	scanf ("%d", &aluno1.ra);

	printf ("Digite a nota da P1: ");
	scanf ("%f", &aluno1.nota_p1);

	printf ("Digite a nota da P2: ");
	scanf ("%f", &aluno1.nota_p2);

  	aluno1.media = (aluno1.nota_p1 + aluno1.nota_p2)/2;

	// imprime os dados do aluno1
	printf ("\nO aluno %d tirou média %.2f\n", aluno1.ra, aluno1.media);
	printf ("Notas: P1 = %.2f, P2 = %.2f\n\n", aluno1.nota_p1, aluno1.nota_p2);

	return (0);
}
