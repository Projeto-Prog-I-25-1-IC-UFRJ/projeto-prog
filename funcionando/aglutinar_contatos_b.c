/* FUNÇÃO 6 */
/* JULIANA SALARINI DE SOUZA E MELLO e MANUELA NUNES DOS SANTOS */

/*(6) Aglutinar dois contatos.
● Essa função está sendo criada para ser usada caso o usuário perceba que, por engano, salvou duas
vezes o mesmo contatinho na agenda. Ela deve receber dois índices, correspondentes às posições no
vetor dos contatinhos que serão aglutinados. As informações serão agregada em um único contatinho,
correspondente ao primeiro índice fornecido, da seguinte forma:
● Todas as informações do contatinho armazenado na posição indice1 são mantidas;
● Para cada informação armazenada no contatinho armazenado na posição indice2, verifique se
esta informação já aparece no contatinho do índice 1, caso não apareça, inclua essa informação
no contatinho índice 1.
● Depois, apague o contatinho do índice 2 (pode chamar a função para excluir contato, feita por
outro grupo.
● A partir da interface da função para buscar contatos, crie uma interface que mostre na tela todos os
contatos repetidos (com um mesmo nome fornecido), com um número para cada um. O usuário poderá
então escolher os dois números dos contatos que deseja aglutinar.*/

#include <string.h>
#include <stdio.h>

#include <prog/tipos.h>
#include <prog/prototipos.h>

#define contatos contatinhos

void aglutinar_contatos(int i1, int i2) {
    // checar se os telefones do contato 2 são todos diferentes dos do contato 1
    if (strcmp(contatos[i2].telefone1, contatos[i1].telefone1) != 0 &&
        strcmp(contatos[i2].telefone1, contatos[i1].telefone2) != 0 &&
        strcmp(contatos[i2].telefone1, contatos[i1].telefone3) != 0) {
        if (contatos[i1].telefone1[0] == '\0') strcpy(contatos[i1].telefone1, contatos[i2].telefone1);
// checar se espaço pros telefones está vazio no contato 1 - se tiver, deve ser preenchido com as informações do contato 2, se não estiver, deve ser matido
        else if (contatos[i1].telefone2[0] == '\0') strcpy(contatos[i1].telefone2, contatos[i2].telefone1);
        else if (contatos[i1].telefone3[0] == '\0') strcpy(contatos[i1].telefone3, contatos[i2].telefone1);
    }

    if (strcmp(contatos[i2].telefone2, contatos[i1].telefone1) != 0 &&
        strcmp(contatos[i2].telefone2, contatos[i1].telefone2) != 0 &&
        strcmp(contatos[i2].telefone2, contatos[i1].telefone3) != 0) {
        if (contatos[i1].telefone1[0] == '\0') strcpy(contatos[i1].telefone1, contatos[i2].telefone2);
        else if (contatos[i1].telefone2[0] == '\0') strcpy(contatos[i1].telefone2, contatos[i2].telefone2);
        else if (contatos[i1].telefone3[0] == '\0') strcpy(contatos[i1].telefone3, contatos[i2].telefone2);
    }

    if (strcmp(contatos[i2].telefone3, contatos[i1].telefone1) != 0 &&
        strcmp(contatos[i2].telefone3, contatos[i1].telefone2) != 0 &&
        strcmp(contatos[i2].telefone3, contatos[i1].telefone3) != 0) {
        if (contatos[i1].telefone1[0] == '\0') strcpy(contatos[i1].telefone1, contatos[i2].telefone3);
        else if (contatos[i1].telefone2[0] == '\0') strcpy(contatos[i1].telefone2, contatos[i2].telefone3);
        else if (contatos[i1].telefone3[0] == '\0') strcpy(contatos[i1].telefone3, contatos[i2].telefone3);
    }

    // se email do contato 1 estiver vazio, deve ser preenchido com o do contato 2
    if (contatos[i1].email[0] == '\0') {
        strcpy(contatos[i1].email, contatos[i2].email);
    }

    // se instagram do contato 1 estiver vazio, deve ser preenchido com o do contato 2
    if (contatos[i1].instagram[0] == '\0') {
        strcpy(contatos[i1].instagram, contatos[i2].instagram);
    }

    // exclui contato 2
    exclui_contato(i2);
}

