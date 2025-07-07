/* FUNÇÃO 3 */
/* FERNANDO GUERRA e GABRIELA LIMA */

#include <string.h>
#include <stdio.h>

#include <prog/tipos.h>

#define contato contatinhos
#define TAMANHO num_contatinhos

int buscar_contato(char c[]){
    
    for (int i=0; i<TAMANHO; i++){
        if (strncmp(contato[i].nome, c, strlen(c)-1) == 0) {
            contato[i].num_acessos++;
            return i;
        }    
    }
    return -1;
}

int numero_de_contatos_iguais(int indice){
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


