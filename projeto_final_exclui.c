//Projeto final
#include <stdio.h>
#include <string.h>

 typedef struct {
        char nome[10];
        char numero[10]; 
    }contatos;

contatos lista [3]; // Lista de Contados Global
int tamanho; //tamanho da lista de contatos atual

int exclui_contatos (int indice){
    tamanho = 3;

    // verificar se o indice recebido existe na lista

    if(indice < 0 || indice >= tamanho){
        // O índice não se encontra na lista
        return -1;
    }

    else {
        // O indice está na lista, então...

        for(int i = indice; i < tamanho - 1; i++){ 
            // Desloca o indice seguinte para a posição anterior 
            lista[i] = lista[i+1];

        }
        // Quando o contato estiver na última posição, diminuimos o tamanho do vetor
        tamanho--;
        return 1;

    }
    }
    int main(){
        
        strcpy(lista[0].nome, "Joao");
        strcpy(lista[0].numero, "12345");

        strcpy(lista[1].nome, "Maria");
        strcpy(lista[1].numero, "67890");

        strcpy(lista[2].nome, "Luan");
        strcpy(lista[2].numero, "22222");

        int indice_contato; //indice do contato que o usuário deseja exluir 
        int excluiu;//usado para confirmar se excluiu o contato

        puts("Digite o indice do contato a ser excluido\n");
        scanf("%d",&indice_contato); //recebe o indice
        excluiu = exclui_contatos(indice_contato);
        //confirma se o contato foi excluido
        excluiu == 1 ? puts("o contato foi excluido com sucesso!\n") : puts("falha na exclusao do contato\n");   

        
        for(int j = 0; j < tamanho; j++){
            printf("%d - Contatos existentes: \n Nome: %s \n Número: %s \n", j, lista[j].nome, lista[j].numero);
        }
        
        return 0;
}
