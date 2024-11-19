#include <stdio.h>


/* definicao dos registros */
typedef struct Data{
	int dia;
	int mes;
	int ano;
} data;


/* prototipo das funcoes */
void imprimirData(data var_data);
data maisAntiga(data data1, data data2);


/* funcao principal */
int main() {
  	data d1, d2, d3;

  	printf("Informe a primeira data (dd/mm/aaaa): ");
  	scanf("%d/%d/%d", &d1.dia, &d1.mes, &d1.ano);

  	printf("Informe a segunda data (dd/mm/aaaa): ");
  	scanf("%d/%d/%d", &d2.dia, &d2.mes, &d2.ano);

  	d3 = maisAntiga(d1, d2);

  	printf("Data mais antiga: ");
  	imprimirData(d3);
  	
  	return 0;
}


/* implementacao das funcoes */

void imprimirData(data var_data){
	printf("%02d/%02d/%04d\n", var_data.dia, var_data.mes, var_data.ano);
}


data maisAntiga(data data1, data data2){
	if( (data2.ano < data1.ano) || 
		(data2.ano == data1.ano && data2.mes < data1.mes) || 
		(data2.ano == data1.ano && data2.mes == data1.mes && data2.dia == data1.dia) ) {

		return (data2);
	} else {
		return (data1);
	}
}