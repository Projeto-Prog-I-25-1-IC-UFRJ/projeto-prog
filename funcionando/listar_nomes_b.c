/* FUNÇÃO 8 */
/* RENATO VILLARDI MORAES e EVANDRO RHARI */

/*
Autor: Evandro Rhari & Renato Villardi Moraes
Data: 02/07/2025
Descrição: Implementa uma função que imprime o nome de todos os contatos que começam com a letra
Entrada: letra (char): caractere a ser buscado
Saída: Nenhuma, mas printa os nomes na tela.
Defesa: Caracteres dentro da tabela ASCII
*/


#include<stdio.h>

#include <prog/tipos.h>

/*
* Recebe um caractere e, se for letra, devolve ele minúsculo
* @param letra (char): letra a ser transformada em minuscula 
* @return A letra em forma minúscula
*/
char minuscula(char letra){
    if(letra >= 'A' && letra <= 'Z')
        letra += 32;
    return letra;
}   


/*
* Imprime o nome de todos os contatos que começam com a letra
* @param letra (char): caractere a ser buscado
*/
void listar_nomes(char letra){
    letra = minuscula(letra);

    for(int i=0; i<num_contatinhos; i++){
        if(minuscula(contatinhos[i].nome[0]) == letra)
            printf("%dº contato:\t%s\n", i+1, contatinhos[i].nome);
    }
}

