#include <stdio.h>
#include <string.h>
typedef struct {
    char nome[50];
    char telefone1[20];
    char telefone2[20];
    char telefone3 [20];
    char email[30];
    char instagram[30];
    int acessos;

}Contatos;

// Função acesso retorna o indice do nome procurado e atualiza o numero de acessos do contato. Se o nome não for encontrado a função retorna -1.
int indice_vetor(Contatos vetor[], char busca[], int tam){
    int n = strlen(busca);
    int j = 0;
    for(; j < tam; j++){
        for(int i = 0; i<n; i++){
            if(vetor[j].nome[i] != busca[i]){
                
                break;
            }
            if(i == n-1 ){
                
                vetor[j].acessos++;
                return j;
            }
        }

    }
    return -1;
}

// função posição retorna o número de contatos com o nome buscado pelo usuário. 
int numero_de_contatos_iguais(Contatos vetor[], char busca[], int n ){
    int tam = strlen(busca);
    int cont  = 0;
    for(int j = 0; j < tam; j++){
        for(int i = 0; i<n; i++){
            if(vetor[j].nome[i] != busca[i]){
                
                break;
            }
            if(i == n-1 ){
                cont ++;
            }
        }

    }   
    return cont;

}

// Essa main é uma interface que retorna ao usuário todas as informações dos contatos com o nome inserido.
int main(){

    Contatos vetor[100];
    char nome[50];
    printf("busque um nome\n");
    scanf("%[^\n]", nome);
    getchar();
    int tam = strlen(nome);
    int indice = indice_vetor(vetor, nome, tam);
    int cont = numero_de_contatos_iguais(vetor, nome, tam);
    if(indice == -1){
        printf("não encontrado");
        return 0;
    }
    for(int i = 0; i< cont; i++){
        printf("Nome - %s\ntelefone1 - %s\ntelefone2 - %s\ntelefone3 -  %s\nemail -  %s\ninstagram -  %s\n", vetor[indice].nome, vetor[indice].telefone1, vetor[indice].telefone2, vetor[indice].telefone3, vetor[indice].email, vetor[indice].instagram);
        indice++;
    }

    return 0;
}
