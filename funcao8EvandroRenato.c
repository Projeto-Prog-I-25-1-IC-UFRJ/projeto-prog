/*
Autor: Evandro Rhari & Renato Villardi Moraes
Data: 02/07/2025
Descrição: Implementa uma função que imprime o nome de todos os contatos que começam com a letra
Entrada: letra (char): caractere a ser buscado
Saída: Nenhuma, mas printa os nomes na tela.
Defesa: Caracteres dentro da tabela ASCII
*/


#include<stdio.h>

// Struct e array usados para testes
// typedef struct {
//     char Nome[100];
//     char Telefone1[12];
//     char Telefone2[12];
//     char Telefone3[12];
//     char Email[100];
//     char Instagram[31];
//     int numeroDeAcessos;
// } contato;
// contato contatinhosApp[] = {
//     {"Evandro Rhari", "", "", "", "", "", 0},
//     {"Renato", "", "", "", "", "", 0},
//     {"Rodrigo", "", "", "", "", "", 0},
//     {"♡Biel", "", "", "", "", "", 0},
//     {"Gaspar", "", "", "", "", "", 0},
//     {"Marcatto", "", "", "", "", "", 0},
//     {"Coraggio", "", "", "", "", "", 0},
//     {"Glutto", "", "", "", "", "", 0},
//     {"Renatto", "", "", "", "", "", 0},
//     {"Ganaccio", "", "", "", "", "", 0},
//     {"Ranaccio", "", "", "", "", "", 0}
// };

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
void listarNomesPorLetra(char letra){
    int tamanhoDaLista = sizeof(contatinhosApp)/(sizeof(contatinhosApp[0]));

    letra = minuscula(letra);

    for(int i=0; i<tamanhoDaLista; i++){
        if(minuscula(contatinhosApp[i].Nome[0]) == letra)
            printf("%dº contato:\t%s\n", i+1, contatinhosApp[i].Nome);
    };
}
