#include <stdio.h>

typedef float nota;

struct _provas { 
  nota p1; 
  nota p2;
  nota p3;
};

typedef struct _provas provas;   

typedef struct _aluno {
  int ra;         
  provas notas; 
  nota media;
} aluno;


int main ()
{
  aluno aluno1;

  printf ("Digite o RA do aluno: ");
  scanf ("%d", &aluno1.ra);

  printf ("Digite a nota da primeira prova: ");
  scanf ("%f", &aluno1.notas.p1);

  printf ("Digite a nota da segunda prova: ");
  scanf ("%f", &aluno1.notas.p2);

  printf ("Digite a nota da terceira prova: ");
  scanf ("%f", &aluno1.notas.p3);

  aluno1.media = (aluno1.notas.p1 + aluno1.notas.p2 + aluno1.notas.p3) / 3;

  printf ("\nO aluno %d obteve a média %.2f\n\n", aluno1.ra, aluno1.media);

	return (0);
}
