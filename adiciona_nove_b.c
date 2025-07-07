/* FUNÇÃO 7 */
/* JOAO RODRIGO DIAS COSTA e JOAO PEDRO MORENO MACHADO */

/*
Autor: Joao Rodrigo Dias Costa e João Pedro Moreno Machado
Data: 02/07/2025
Descrição: A funcao verifica se há números que estão abaixo do limite imposto pela entrada, e 
se houver, adiciona o número 9 no inicio, retorna quantos telefones foram alterados no total.
Entrada: Um inteiro representando o quantidade de números que um telefone deve ter
Saída: a quantidade de telefones alterados
Defesa: Tipos alheios ao int e entrada negativa
Observacoes: O programa considera que ha um array com o nome contatinhos e tipo Contatinho,
no qual telefone1[], telefone2[] e telefone3[] sao membros do struct, com tipo string.
*/

#include <stdio.h>
#include <string.h>

int add_nove(int digitos){

    // declarando int de retorno (contagem)
    int count = 0;

    // calculando o tamanho do vetor
    int tam = sizeof(contatinhos)/sizeof(contatinhos[0]);
    
    // iterando por todos os contatos no vetor
    for (int i = 0; i < tam; i++)
    {
        // definindo um vetor com os tres telefones para facilitar a manipulacao de dados
        char numeros[3][sizeof(contatinhos[0].telefone1)];

        strcpy(numeros[0], contatinhos[i].telefone1);
        strcpy(numeros[1], contatinhos[i].telefone2);
        strcpy(numeros[2], contatinhos[i].telefone3);

        // iterando por cada numero de telefone do contato
        for (int j = 0; j < 3; j++)
        {
            // tamanho do numero em questao
            int tam_str = strlen(numeros[j]);

            // se for menor que o numero de caracteres desejavel
            if (tam_str < digitos){

                // criando string somente com 9
                char novo_numero[16];
                novo_numero[0] = '9';
                novo_numero[1] = '\0';

                // adicionando a string do 9 com a string do numero
                strcat(novo_numero, numeros[j]);
                strcpy(numeros[j], novo_numero);
                
                count++;
            }
        }

        // copia os numeros alterados para o vetor original
        strcpy(contatinhos[i].telefone1, numeros[0]);
        strcpy(contatinhos[i].telefone2, numeros[1]);
        strcpy(contatinhos[i].telefone3, numeros[2]);
    }

    return count;
}
