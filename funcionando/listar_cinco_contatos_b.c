/* FUNÇÃO 9 */
/* LEONARDO OLIVEIRA e GABRIEL MAIA */

#include <stdio.h>
#include <string.h>

#include <prog/tipos.h>

#define contatos contatinhos
#define total_contatos num_contatinhos

// Função que lista os 5 contatos mais acessados 
int cinco_contatos(Contato top5[5]) {
    Contato temp[MAX_CONTATOS];

    // Copia os contatos existentes para um vetor temporário
    for (int i = 0; i < total_contatos; i++) {
        temp[i] = contatos[i];
    }

    // Ordena em ordem decrescente de acessos (bubble sort simples)
    for (int i = 0; i < total_contatos - 1; i++) {
        for (int j = 0; j < total_contatos - i - 1; j++) {
            if (temp[j].num_acessos < temp[j + 1].num_acessos) {
                Contato aux = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = aux;
            }
        }
    }

    // Copia os 5 primeiros contatos ordenados para o vetor de saída
    for (int i = 0; i < 5 && i < total_contatos; i++) {
        top5[i] = temp[i];
    }

    return (total_contatos >= 5) ? 5 : total_contatos;
}

