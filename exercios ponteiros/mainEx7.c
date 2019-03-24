/*7) Crie um programa para manipular vetores. O seu programa deve implementar uma
função que receba um vetor de inteiros V e retorne um outro vetor de inteiros alocado
dinamicamente com todos os valores de V que estejam entre o valor mínimo e
máximo (que também são passados como parâmetro para a função). A função deve
obedecer ao seguinte protótipo: int* valores_entre(int *v, int n, int min, int max, int
*qtd); A função recebe: • v: vetor de números inteiros; • n: a quantidade de elementos
do vetor v; • min: valor mínimo a ser buscado; • max: valor máximo a ser buscado; A
função deve: • Verificar a quantidade de elementos do vetor que sejam maiores do
que min e menores que max; • Caso a quantidade seja maior do que 0 (zero), alocar
dinamicamente uma área do exato tamanho necessário para armazenar os valores; •
Copia os elementos do vetor que sejam maiores do que min e menores que max para a
área alocada dinamicamente. A função retorna: • O endereço da área alocada
dinamicamente, preenchida com os números maiores do que min e menores que max,
ou NULL, caso essa relação de números não tenha sido criada; • A quantidade de
números carregados na área alocada dinamicamente, através do parâmetro qtd. Em
seguida, crie a função principal do programa para inicializar um vetor de inteiros, exibir
esses valores na tela e pedir para o usuário digitar o valor mínimo e máximo a ser
buscado. Em seguida o programa deverá chamar a função valores_entre e exibir na
tela os valores resultantes. Lembre-se de exibir uma mensagem de erro caso nenhum
valor seja encontrado. Não se esqueça de liberar a memória alocada dinamicamente.*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int* valores_entre(int *v, int n, int min, int max, int*qtd){
	int quant = 0;
	int quantQtq = 0;
	int i;
	for (i = 0; i < n; i++){
		if((v[i] > min) && (v[i] < max)) quant++;
	}
	if(quant > 0){

		qtd = (int*)malloc(quant*(sizeof(int))+1);

		for (i = 0; i < n; i++){

			if((v[i] > min) && (v[i] < max)){
				qtd[quantQtq] = v[i];
				quantQtq++;
			}
		}//
		qtd[quantQtq] = '\0';
		return qtd;
	}
	else{
		return NULL;
	}
}

int main(){
	int nNumeros;
	int max, min;
	int *vettorAlocado;
	int i;

	printf("Digite o tamanho do vetor:\n");
	scanf("%d",&nNumeros);

	int vetor[nNumeros];
	for (i = 0; i < nNumeros; i++){
		vetor[i] = rand() % 100;
	}
	for (i = 0; i < nNumeros; i++){
		printf("%d\n",vetor[i] );
	}


	printf("Digite o valor maximo:\n");
	scanf("%d",&max);
	printf("Digite o valor minimo\n");
	scanf("%d",&min);

//int* valores_entre(int *v, int n, int min, int max, int*qtd)
	vettorAlocado = valores_entre(vetor,nNumeros,min,max,vettorAlocado);

	if(vettorAlocado == NULL){
		printf("ERRO!!!\nNenhum valor encontrado.\n");
	}
	else{
		printf("Novo Vetor alocado:\n");
		i = 0;
		while(vettorAlocado[i] != '\0'){
			printf("%d\n",vettorAlocado[i] );
			i++;
		}
	}
	free(vettorAlocado);



	return 0;
}
