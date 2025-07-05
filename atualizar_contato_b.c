/* FUNÇÃO 2 */
/* ELIANE PEREIRA DOS SANTOS e BEATRIZ PEREIRA DE JESUS SANTOS */

/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>

typedef struct {
	char nome[50];
	char telefone1[12];
	char telefone2[12];
	char telefone3[12];
	char email[50];
	char instagram[50];
	int numero_de_acesso;
} tContato;

tContato vetor[50];

        int atualiza_contatinho(int indice, int codigo, char inf_n[]) {

	switch(codigo){
    case 1:
		strcpy(vetor[indice].nome, inf_n);
		break;

    case 2:
		strcpy(vetor[indice].telefone1, inf_n);
		break;
		
    case 3:
		strcpy(vetor[indice].telefone2, inf_n);
		break;

    case 4:
		strcpy(vetor[indice].telefone3, inf_n);
		break;

    case 5:
		strcpy(vetor[indice].email, inf_n);
        break;
        
    case 6:
        strcpy(vetor[indice].instagram, inf_n);
        break;
        
    default:
        return 0;
        
	}
	    return 1;
	    

}

int main()
{
    int codigo;
    int indice =-1;
    char inf_n[50];
    
	printf("insira o código da informação:");
	scanf("%d", &codigo);
	strcpy(vetor[0].nome, "Lua");
	
	printf("Qual será a mudança:");
	scanf("%s", inf_n);
	
	char nome[50];
	printf("qual o nome quer mudar:");
	scanf("%s", nome);
	
	for(int i = 0; i < 50; i++){
	    if(!(strcmp(vetor[i]. nome , nome))){
	        indice = i;
	        break;
	    }
	}
	
    atualiza_contatinho(indice, codigo, inf_n);
    
    printf("o numero de Lua eh: %s", vetor[0]. telefone1);
	
}
