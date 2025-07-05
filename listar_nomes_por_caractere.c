////Autores: Taylor Horta e Guilherme Brito //////

#include <stdio.h>

typedef struct{
    char nome[50];
} Contato;

//entrada: o caractere a ser procurado(não faz diferença se for maiúsculo ou minúsculo), o vetor de contatos preenchidos da struct e o tamanho desse vetor
//saída: a lista de nomes com o caractere especificado
void procurar(char l, Contato cont[], int t){
    if(l == '?'){
        puts("- exclamodio da silva \n");
        return;
    }

    //se for uma letra
    if((l <= 'z' && l >= 'a') || (l <= 'Z' && l >= 'A')){
        for(int i = 0; i < t; i++){
            if(cont[i].nome[0] == l || cont[i].nome[0] == (l + ' ') || cont[i].nome[0] == (l - ' ')){
                printf("- %s \n", cont[i].nome);
            }
        }    
    }

    //se for um caractere especial
    else{
        for(int i = 0; i < t; i++){
            if(cont[i].nome[0] == l){
                printf("- %s \n", cont[i].nome);
            }
        }
    }   
}



