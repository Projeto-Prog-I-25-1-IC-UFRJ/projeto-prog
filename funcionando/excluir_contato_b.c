/* FUNÇÃO 5 */
/* GABRIEL RESENDE e MARIA EDUARDA */

#include <stdio.h>

#include <prog/tipos.h>

int exclui_contato(int indice) { //recebe o indice do contato

    if(indice < num_contatinhos && indice >= 0) { //verifica se o contato existe na lista

        for(int i=indice; i<num_contatinhos-1; i++) {
            contatinhos[i] = contatinhos[i+1]; //troca todos os contatos que estao a frente do contato deletado uma posição anterior ate o ultimo contato registrado
        }

        num_contatinhos--;//diminue o valor do tamanho da lista de contatos


        return 1;
    }

    else { //se o contato nao consta na lista a função retorna erro com a mensagem a seguir

        return -1;
    }
}
