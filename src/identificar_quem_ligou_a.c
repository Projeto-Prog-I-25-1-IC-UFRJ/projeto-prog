/* FUNÇÃO 4 */
/* LETICIA PESSÔA e ISABEL ALENCAR */

#include <stdio.h>
#include <string.h>

#include <prog/tipos.h>

char* quem_ligou(char tel[]){
    int resp=-1;
    for(int i=0; i<num_contatinhos; i++){
        int r1 = strcmp(contatinhos[i].telefone1,tel);
        int r2 = strcmp(contatinhos[i].telefone2,tel);
        int r3 = strcmp(contatinhos[i].telefone3,tel);
        if(r1==0||r2==0||r3==0){
            resp=i;//indice do contato na lista de contatos
        }
    }
    if (resp==-1)
        return NULL;
    else
        return contatinhos[resp].nome;
}
