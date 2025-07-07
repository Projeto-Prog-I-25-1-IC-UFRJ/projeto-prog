/* FUNÇÃO 4 */
/* RYAN DIAS e BERNARDO MAIA */

#include <stdio.h>
#include <string.h>

#include <prog/tipos.h>

char* quem_ligou(char numero[]){
    int tamanho = strlen(numero);
    for(int i = 0; i < num_contatinhos; i++){
        int ok = 1;
        int ok2 = 1;
        int ok3 = 1;
        for(int j = 0; j < tamanho; j++){
            if(numero[j] != contatinhos[i].telefone1[j]){
                ok = 0;
            }
            if(numero[j] != contatinhos[i].telefone2[j]){
                ok2 = 0;
            }
            if(numero[j] != contatinhos[i].telefone3[j]){
                ok3 = 0;
            }
        }
        if (ok == 1 || ok2 == 1 || ok3 == 1){
            return contatinhos[i].nome;
        }
    }
    return NULL;
}





