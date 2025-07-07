/* FUNÇÃO 5 */
/* NICOLAS BRAYAN (AL) e ARTHUR BASSOTTO (MG) */

//Projeto final
#include <stdio.h>
#include <string.h>

#include <prog/tipos.h>

int exclui_contato(int indice) {
    // verificar se o indice recebido existe na lista

    if(indice < 0 || indice >= num_contatinhos){
        // O índice não se encontra na lista
        return -1;
    }

    else {
        // O indice está na lista, então...

        for(int i = indice; i < num_contatinhos - 1; i++){ 
            // Desloca o indice seguinte para a posição anterior 
            contatinhos[i] = contatinhos[i+1];

        }
        // Quando o contato estiver na última posição, diminuimos o tamanho do vetor
        num_contatinhos--;
        return 1;

    }
}

