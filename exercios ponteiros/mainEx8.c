/*8) Crie uma função que receba como parâmetros dois vetores de inteiros, v1 e v2, e as
suas respectivas quantidades de elementos, n1 e n2. A função deverá retornar um
ponteiro para um terceiro vetor, v3, com capacidade para (n1 + n2) elementos,
alocado dinamicamente, contendo a união de v1 e v2. Por exemplo, se v1 = {11, 13, 45,
7} e v2 = {24, 4, 16, 81, 10, 12}, v3 irá conter {11, 13, 45, 7, 24, 4, 16, 81, 10, 12}. O
cabeçalho dessa função deverá ser o seguinte: int* uniao(int *v1, int n1, int *v2, int
n2); Em seguida, crie a função principal do programa para chamar a função uniao
passando dois vetores informados pelo usuário (ou declarados estaticamente). Em
seguida, o programa deve exibir na tela os elementos do vetor resultante. Não
esqueça de liberar a memória alocada dinamicamente.*/
#include <stdio.h>
#include <stdlib.h>
int* uniao(int *v1, int n1, int *v2, int n2){
	int *v3;
	int cont = 0;
	v3 = (int*)malloc((n1+n2)*(sizeof(int))+1);

	for (int i = 0; i < n1; i++){
		v3[cont] = v1[i];
		cont++;
	}
	for (int i = 0; i < n2 ; i++){
		v3[cont] = v2[i];
		cont++;
	}
	v3[cont] = '\n';
	return v3;
}

int main(){
	int n1,n2,*vetor3,cont = 0;
	printf("Digite n1 e n2 respectivamente:\n");
	scanf("%d %d",&n1,&n2);
	int vetor1[n1],vetor2[n2];

	for (int i = 0; i < n1; i++){
		vetor1[i] = rand() % 20;
	}
	for (int i = 0; i < n2; i++){
		vetor2[i] = rand() % 20;
	}
	for (int i = 0; i < n1; i++){
		printf("%d, ",vetor1[i] );
	}
	printf("\n\n");
	for (int i = 0; i < n2; i++){
		printf("%d, ",vetor2[i] );

	}
	printf("\n\n");


// int* uniao(int *v1, int n1, int *v2, int n2
	vetor3 = uniao(vetor1,n1,vetor2,n2);


	while(vetor3[cont] != '\n'){
		printf("%d, ",vetor3[cont] );
		cont++;
	}

	free(vetor3);

	return 0;
}