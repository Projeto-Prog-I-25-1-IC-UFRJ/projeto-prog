#include <stdio.h>
#include <string.h>
typedef struct{ //substituir com função do criar contato
    char Nome[10];
    char tel1[13];
    char tel2[13];
    char tel3[13];
    char email[1];
    char instagram[1];
    int num;
}tcontatinho;

int indet_quem_ligou(tcontatinho lista[],int n, char tel[]);

int indet_quem_ligou(tcontatinho lista[],int n, char tel[]){ //inserir na funcao lista dos contatos, tamanho e telefone de busca
    int resp=-1;
    for(int i=0; i<n; i++){
        int r1 = strcmp(lista[i].tel1,tel);
        int r2 = strcmp(lista[i].tel2,tel);
        int r3 = strcmp(lista[i].tel3,tel);
        if(r1==0||r2==0||r3==0){
            resp=i;//indice do contato na lista de contatos
        }
    }
    if (resp==-1)
        return -1;
    else
        return printf("%s",lista[resp].Nome);
}