/* FUNÇÃO 9 */
/* NICOLAS GOMES e BERNARDO MAGNO */

#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 

#include <prog/tipos.h>

#define agenda contatinhos
#define total_contatos num_contatinhos

// função para listar os 5 contatos mais acessados em ordem decrescente.
int cinco_contatos(Contato top5[5]) {
    // Retorna 0 se a agenda estiver vazia.
    if (total_contatos == 0) {
        return 0;
    }

    // Determine quantos contatos vamos retornar máximo de 5 ou o total disponíveL
    int num_para_retornar = (total_contatos >= 5) ? 5 : total_contatos;

     // Cria uma cópia da agenda para ser ordenada, preservando a original.
    Contato* agenda_temporaria = (Contato*)malloc(total_contatos * sizeof(Contato));

    memcpy(agenda_temporaria, agenda, total_contatos * sizeof(Contato));

    // Ordena a cópia da agenda pelo 'num_acessos' em ordem decrescente (Bubble Sort).
    for (int i = 0; i < total_contatos - 1; i++) {
        for (int j = 0; j < total_contatos - i - 1; j++) {
            if (agenda_temporaria[j].num_acessos < agenda_temporaria[j+1].num_acessos) {
                Contato aux = agenda_temporaria[j];
                agenda_temporaria[j] = agenda_temporaria[j+1];
                agenda_temporaria[j+1] = aux;
            }
        }
    }

     // Copia os primeiros contatos da agenda ordenada para o vetor de resultado.
    for (int i = 0; i < num_para_retornar; i++) {
        top5[i] = agenda_temporaria[i];
    }

    // Libera a memória da cópia e retorna o resultado final.
    free(agenda_temporaria);
    return num_para_retornar;
}

