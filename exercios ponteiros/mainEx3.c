/*3) Construa um programa (main) que aloque em tempo de execução (dinamicamente)
uma matriz de ordem m x n (linha por coluna), usando 1+m chamadas a função malloc.
Agora, aproveite este programa para construir uma função que recebendo os
parametros m e n aloque uma matriz de ordem m x n e retorne um ponteiro para esta
matriz alocada. Crie ainda uma função para liberar a área de memória alocada pela
matriz. Finalmente, crie um novo programa (main) que teste/use as duas funções
criadas acima.*/
/* 



Este programa nao funciona direito!!!!!!




*/

#include <stdio.h>
#include <stdlib.h>
int **alocaMatriz(int m,int n){//m linhas,n colunas
	int **matriz,i,j;
	matriz = (int**)malloc(m*(sizeof(int*)));

	for (i = 0; i < m; i++){
		matriz[i] = (int*)malloc(n*sizeof(int));
		for (j = 0; j < n;j++ ){
			matriz[i][j] = rand() % 100;
		}
	}
	return matriz;
}
freeMat(int linhas,int colunas ,int **matriz){
	int i;
	for (i = 0; i < linhas; i) free(matriz[i]);
		free(matriz);
	
}

int main(){
	int m,n,i,j;
	int **mat;

	printf("Digite m e n:\n");
	scanf("%d %d",&m,&n);
/*
	mat = (int**)malloc(m*sizeof(int*));

	for (int i = 0; i < m; i++){
		mat[i] = (int*)malloc(n*sizeof(int));
		for (int j = 0; j < n;j++ ){
			mat[i][j] = rand() % 100;
		}
	}*/
	mat = alocaMatriz(m,n);

	for (i = 0; i < m; i++){
		for (j = 0; j < n;j++ ){
			printf("%d ",mat[i][j] );
		}
		printf("\n");
	}
	freeMat(m,n,mat);

	return 0;
}
