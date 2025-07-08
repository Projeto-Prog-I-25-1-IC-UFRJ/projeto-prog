/* FUNÇÃO 2 */
/* JOAO MIGUEL SALES DE ALENAR e ALEXANDRE RIMES BANDEIRA */

#include<stdio.h>
#include<string.h>

#include <prog/tipos.h>

#define contatos contatinhos

int atualizar_contato(int indice, int codInf, char novaInf[]){
    switch (codInf)
    {
    case 1:
        strcpy(contatos[indice].nome,novaInf);
        return indice;
    case 2:
        strcpy(contatos[indice].telefone1,novaInf);
        return indice;
    case 3:
        strcpy(contatos[indice].telefone2,novaInf);
        return indice;
    case 4:
        strcpy(contatos[indice].telefone3,novaInf);
        return indice;
    case 5:
        strcpy(contatos[indice].email,novaInf);
        return indice;
    case 6:
        strcpy(contatos[indice].instagram,novaInf);
        return indice;
    }
    return -1;
}


