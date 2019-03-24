#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ler_aposta(int *vet,int nNumeros){
	printf("Digite os %d Numeros:\n",nNumeros );
	printf("Somente numeros entre 0 e 100 sao permitidos!!\n");
	for (int i = 0; i < nNumeros; i++){
		scanf("%d",&vet[i]);
		if(vet[i] < 0 || vet[i] > 100){
			while(vet[i] < 0 || vet[i] > 100){

					printf("ERRO!!!\n");
					printf("Valor invalido.Nao pertence ao intervalo [0,100]!!\n");
					printf("Digite um numero valido!\n");
					scanf("%d",&vet[i]);

			}
		}
	}
}
void sorteia_valores(int *sorteio, int n){
	for (int i = 0; i < n; i++){
		sorteio[i] = rand() % 100;
	}
}
int* compara_aposta(int *aposta, int *sorteio, int *qtdacertos, int na, int ns){
	int totalAcertos = 0,k = 0;
	for (int i = 0; i < na ; i++){
		for (int j = 0; j < ns; j++){
			if(aposta[i] == sorteio[j]) totalAcertos++;
		}

	}
	//printf("\nTotal de acertos: %d\n",totalAcertos );
	qtdacertos = (int*)malloc(totalAcertos*(sizeof(int))+1);
	for (int i = 0; i < na ; i++){
		for (int j = 0; j < ns; j++){
			if(aposta[i] == sorteio[j]){
				qtdacertos[k] = aposta[i];
				k++;
			}
		}

	}
	qtdacertos[k] = '\n';

	return qtdacertos;
}


int main(){
	int quanApostar = 0;
	int quanSorteados = 0;
	int *apostas,*sorteados,*quantAcertos;
	srand(time(NULL));
	printf("__________________________Hello!!!!________________________\n" );
	printf("_________________helcome to Bingo de Prog II_______________\n\n");

	while(quanApostar < 1 || quanApostar > 20){
		printf("Digite a quantida de numeros que vc deseja apostar(entre 1 e 20): ");
		scanf("%d",&quanApostar);
		if(quanApostar < 1 || quanApostar > 20){
			printf("ERRO!!!\n");
			printf("Valor incorreto.Somente numeros entre 1 e 20 sao permitidos!\n");
		}
	}
	apostas = (int*)malloc(quanApostar*(sizeof(int)));
//protótipo: void ler_aposta(int*aposta, int n);
	ler_aposta(apostas,quanApostar);
	printf("\n\n");
	for (int i = 0; i < quanApostar; i++){
		printf("%d, ",apostas[i] );

	}
	printf("\nDigite a quantidade de numeros que serao sorteados: \n");
	scanf("%d",&quanSorteados);
	sorteados = (int*)malloc(quanSorteados*(sizeof(int)));
//void sorteia_valores(int *sorteio, int n);
	sorteia_valores(sorteados,quanSorteados);
	printf("\n\n");

	for (int i = 0; i < quanSorteados; i++){
		printf("%d, ",sorteados[i] );

	}
//protótipo: int*compara_aposta(int *aposta, int *sorteio, int *qtdacertos, int na, int ns);
	quantAcertos = compara_aposta(apostas,sorteados,quantAcertos,quanApostar,quanSorteados);

	int k = 0;
	printf("\n\nNumeros que foram sorteados:\n");
	if(quantAcertos[k] == '\n'){
		printf("NENHUM!!!!!!\n");
		printf("HAHAHAHAHHAAHA\n");
		printf("Tente mais uma vez! Quem sabe voce tenha mais sorte ;-)\n");
	}
	while(quantAcertos[k] != '\n'){
		printf("%d, ",quantAcertos[k] );
		k++;
	}
	printf("\n");



	free(apostas);
	free(quantAcertos);
	free(sorteados);

	return 0;
}
