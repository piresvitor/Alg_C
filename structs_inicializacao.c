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
	struct aluno aluno1 = {987654, 5.5, 4.9, 5.2},
				 aluno2 = {.ra = 987654, .nota_p1 = 5.5, .nota_p2 = 4.9};

  	aluno2.media = (aluno2.nota_p1 + aluno2.nota_p2)/2;

	// imprime os dados do aluno1
	printf ("\nO aluno %d tirou média %.2f\n", aluno1.ra, aluno1.media);
	printf ("Notas: P1 = %.2f, P2 = %.2f\n\n", aluno1.nota_p1, aluno1.nota_p2);

	// imprime os dados do aluno2
	printf ("\nO aluno %d tirou média %.2f\n", aluno2.ra, aluno2.media);
	printf ("Notas: P1 = %.2f, P2 = %.2f\n\n", aluno2.nota_p1, aluno2.nota_p2);


	return (0);
}
