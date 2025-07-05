/* FUNÇÃO 3 */
/*
BERNARDO DOS SANTOS DE SANTANA, THIAGO RICHARD FURTADO ALVES e LUCAS DANIEL
*/

#include <string.h>
#include <stdio.h>

#define TAMANHO 1000

typedef struct {
    char nome[TAMANHO];
    char telefone1[TAMANHO];
    char telefone2[TAMANHO];
    char telefone3 [TAMANHO];
    char email[TAMANHO];
    char instagram[TAMANHO];
    int acessos;

} lista_contatos;

lista_contatos contato[TAMANHO];


int busca_contato (char c[]){
    
    for (int i=0; i<TAMANHO; i++){
        if (strncmp(contato[i].nome, c, strlen(c)-1) == 0) {
            contato[i].acessos++;
            return i;
        }    
    }
    return -1;
}

int nomes_iguais(int indice){
    int qntd_nomes_iguais = 0;
    char nome_contato_referencia[TAMANHO];
    char nome_lista[TAMANHO];

    int i;
    for (i=0; contato[indice].nome[i] != ' ' && contato[indice].nome[i] != '\0'; i++) {
        nome_contato_referencia[i] = contato[indice].nome[i];
    }
    nome_contato_referencia[i] = '\0';


    for(int k=0; k<TAMANHO; k++){
        int e;
        for (e=0; contato[k].nome[e] != ' ' && contato[k].nome[e] != '\0'; e++) {
            nome_lista[e] = contato[k].nome[e];
        }
        nome_lista[e] = '\0';

        if (strcmp(nome_lista, nome_contato_referencia) == 0) {
            qntd_nomes_iguais++;
        }
    }
    return qntd_nomes_iguais;
}


int main(){
  //captura de valores para teste:
    int numero_contatos = 0;
    printf("Digite o número de contatos: \n");
    scanf("%d", &numero_contatos);
    getchar();

    for (int i=0; i<numero_contatos; i++){
        printf("Digite o nome do contato:\n");
        
        for (int e=0; ; e++) {
        contato[i].nome[e] = getchar();
         if (contato[i].nome[e] == '\n'){
              contato[i].nome[e] = '\0';
              break;
            }
        }

        contato[i].acessos = 0;
        printf("Nome da pessoa %d %s | Acessos: %d\n", i, contato[i].nome, contato[i].acessos);

    }

//implentação das funções:
        char nome[TAMANHO];
        int indice;
        printf("Digite o nome (ou a parte inicial) do contato procurado:\n");
        
        for (int e=0; ; e++) {
        nome[e] = getchar();
         if (nome[e] == '\n'){
              nome[e] == '\0';
              break;
            }
        }

        indice = busca_contato(nome);

        if (indice == -1){
            puts ("\nNao ha contatos com esse nome");
            return 1;
        }

        int numero;
        numero = nomes_iguais(indice);

        for (int i=indice; i<(indice+numero); i++){
            
            printf("\n(%d) %s", i, contato[i].nome);
            printf("\nTel1: %s", contato[i].telefone1);
            printf("\nTel2: %s",  contato[i].telefone2);
            printf("\nTel3: %s", contato[i].telefone3);
            printf("\nE-mail: %s", contato[i].email);
            printf("\nInsta: %s", contato[i].instagram);
            printf("\nAcessos: %d", contato[i].acessos);
        }

    return 0;
}

