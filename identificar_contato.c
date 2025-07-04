#include <stdio.h>
#include <string.h>

// typedef struct {
//     char telefone1[50];
//     char telefone2[50];
//     char telefone3[50];
//     char nome[50];
// } contato;

// contato Contato[3];

char* identificar_quem_ligou(char numero[], int tamanho){
    for(int i = 0; i < sizeof(Contato); i++){
        int ok = 1;
        int ok2 = 1;
        int ok3 = 1;
        for(int j = 0; j < tamanho; j++){
            if(numero[j] != Contato[i].telefone1[j]){
                ok = 0;
            }
            if(numero[j] != Contato[i].telefone2[j]){
                ok2 = 0;
            }
            if(numero[j] != Contato[i].telefone3[j]){
                ok3 = 0;
            }
        }
        if (ok == 1 || ok2 == 1 || ok3 == 1){
            return Contato[i].nome;
        }
    }
    return "-1";
}


int main() {
    // for (int cont = 0; cont < 3; cont++) {
    //     printf("Digite o nome do contato: ");
    //     fgets(Contato[cont].nome, sizeof(Contato[cont].nome), stdin); 
    //     printf("Digite um número1: ");
    //     fgets(Contato[cont].telefone1, sizeof(Contato[cont].telefone1), stdin);
    //     printf("Digite um número2: ");
    //     fgets(Contato[cont].telefone2, sizeof(Contato[cont].telefone2), stdin);
    //     printf("Digite um número3: ");
    //     fgets(Contato[cont].telefone3, sizeof(Contato[cont].telefone3), stdin);
    // } // parte usada para testes
    
    char numero_que_ligou[50];
    printf("Digite o numero que quer encontrar: \n");
    fgets(numero_que_ligou, sizeof(numero_que_ligou), stdin);
    int tamanho = strlen(numero_que_ligou);
    printf("A pessoa que ligou foi: %s\n", identificar_quem_ligou(numero_que_ligou, tamanho));

    return 0;
}




