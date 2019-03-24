/*4) Construa um programa (main) que aloque em tempo de execução (dinamicamente)
uma matriz de ordem m x n (linha por coluna), usando 2 chamadas a função malloc.
Agora, aproveite este programa para construir uma função que recebendo os
parametros m e n aloque uma matriz de ordem m x n e retorne um ponteiro para esta
matriz alocada. Crie ainda uma função para liberar a área de memória alocada pela
matriz. Finalmente, crie um novo programa (main) que teste/use as duas funções
criadas acima.*/
#include <stdio.h>
#include <stdlib.h>

int main(){
		int m,n,i,j;
	int **mat;

	printf("Digite m e n:\n");
	scanf("%d %d",&m,&n);
	mat = (int**)malloc(m*sizeof(int*));

	for (int i = 0; i < m; i++){
		mat[i] = (int*)malloc(n*sizeof(int));
		for (int j = 0; j < n;j++ ){
			mat[i][j] = rand() % 100;
		}
	}


	for (i = 0; i < m; i++){
		for (j = 0; j < n;j++ ){
			printf("%d ",mat[i][j] );
		}
		printf("\n");
	}
	for (int i = 0; i < m; i++) free(mat[i]);
		free(mat);

	
	return 0;
}
