/* FUNÇÃO 8 */
/* TAYLOR HORTA E GUILHERME BRITO */

////Autores: Taylor Horta e Guilherme Brito //////

#include <stdio.h>

#include <prog/tipos.h>

//entrada: o caractere a ser procurado(não faz diferença se for maiúsculo ou minúsculo), o vetor de contatos preenchidos da struct e o tamanho desse vetor
//saída: a lista de nomes com o caractere especificado
void listar_nomes(char l){
    Contato *cont = contatinhos;
    int t = num_contatinhos;

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



