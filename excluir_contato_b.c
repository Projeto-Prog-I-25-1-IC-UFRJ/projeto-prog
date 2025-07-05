/* FUNÇÃO 5 */
/* GABRIEL RESENDE e MARIA EDUARDA */

#include <stdio.h>

struct Contato {};

int tamanho; //tamanho da lista de contatos atual(exemplo: se a lista possui 93 contatos o tamanho é 93)
struct Contato lista_contatos[1000];//vertor global da lista de contatos

int exclui_contato(int indice) { //recebe o indice do contato

    if(indice < tamanho && indice >= 0) { //verifica se o contato existe na lista

        for(int i=indice; i<tamanho-1; i++) {
            lista_contatos[i] = lista_contatos[i+1]; //troca todos os contatos que estao a frente do contato deletado uma posição anterior ate o ultimo contato registrado
        }

        tamanho--;//diminue o valor do tamanho da lista de contatos

        printf("O contado com índice %d foi excluido\n", indice);

        return 1;
    }

    else { //se o contato nao consta na lista a função retorna erro com a mensagem a seguir

        printf("O contado com índice %d não existe\n", indice);
        return -1;
    }
}
