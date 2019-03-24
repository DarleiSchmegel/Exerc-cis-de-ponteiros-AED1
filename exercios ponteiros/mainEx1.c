/*1) Faça um programa que leia um valor n e crie dinamicamente um vetor de n elementos
e passe esse vetor para uma função que vai ler os elementos desse vetor. Depois, no
programa principal, o vetor preenchido deve ser impresso. Além disso, antes de
finalizar o programa, deve-se liberar a área de memória alocada.*/
#include <stdio.h>
#include <stdlib.h>

void lerElementos(int tamanhoN,int *str){
	printf("Digite %d numeros:\n",tamanhoN );
	for (int i = 0; i < tamanhoN; i++){
		scanf("%d",&str[i]);

	}

}

int main(){

	int n;
	int *vetor;
	printf("Diga o valor de n:\n");
	scanf("%d",&n);

	vetor = (int*)malloc(n*(sizeof(int)));
	lerElementos(n,vetor);

	for (int i = 0; i < n; i++){
		printf("%d\n",vetor[i] );

	}


	free(vetor);

	return 0;
}