/*2) Faça uma função que receba um valor n e crie dinamicamente um vetor de n
elementos e retorne um ponteiro. Crie uma função que receba um ponteiro para um
vetor e um valor n e imprima os n elementos desse vetor. Construa também uma
função que receba um ponteiro para um vetor e libere esta área de memória. Ao final,
crie uma função principal que leia um valor n e chame a função criada acima. Depois, a
função principal deve ler os n elementos desse vetor. Então, a função principal deve
chamar a função de impressão dos n elementos do vetor criado e, finalmente, liberar a
memória alocada através da função criada para liberação.*/
#include <stdio.h>
#include <stdlib.h>
int *retornaPonteiro(int n){
	return (int*)malloc(n*(sizeof(int)));
}
void imprime(int n,int *vet){
	
		for (int i = 0; i < n; i++){
		printf("%d\n",vet[i] );
	}
}

void liberar(int **vet){
	free(*vet);
}


int main(){
	int n,size;
	int *vetor;
	printf("Diga o valor de n:\n");
	scanf("%d",&n);

	vetor = retornaPonteiro(n);

	for (int i = 0; i < n; i++){
		vetor[i] = rand() % 100;
	}
	printf("\n\n");
	imprime(n,vetor);
	liberar(&vetor);
	//free(vetor);

	imprime(n,vetor);

	
	return 0;
}