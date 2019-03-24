/*5) Criar um tipo abstrato de dados que represente uma pessoa, contendo nome, data de
nascimento e CPF. Crie uma variável que é um ponteiro para este TAD (no programa
principal). Depois crie uma função que receba este ponteiro e preencha os dados da
estrutura e também uma uma função que receba este ponteiro e imprima os dados da
estrutura. Finalmente, faça a chamada a esta função na função principal.
6)Com referência &*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
struct pessoa{
	char nome[20];
	int data;
	long long int cpf;
};

void prenche(struct pessoa **fulano){
	printf("Diga o nome do cidadao: ");
	fgets((*fulano)->nome ,20,stdin);
	//getchar();
	printf("Diga a Idade :");
	scanf("%d",&(*fulano)->data);
	printf("Diga o CPF : ");
	scanf("%ld",&(*fulano)->cpf);

}
void imprime(struct pessoa *fulano){
		printf("\n");
		printf("Nome : %s",fulano->nome);
		printf("Data : %d\n",fulano->data);
		printf("CPF : %ld\n",fulano->cpf);
}


int main(){
	struct pessoa *nPessoas;
	nPessoas = (struct pessoa*)malloc(sizeof(struct pessoa));

	prenche(&nPessoas);
	imprime(nPessoas);
	free(nPessoas);
	return 0;
}
