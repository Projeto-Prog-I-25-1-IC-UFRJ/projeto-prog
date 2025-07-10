/* FUNÇÃO 1 */
/* LUYDGI BARBOSA e PEDRO BINOTO */

#include <stdio.h>
#include <string.h>

#include <prog/tipos.h>

#define contatos contatinhos
#define pos num_contatinhos

int criar_contato(char nome[], char tel1[], char tel2[], char tel3[], char email[], char insta[])
{
    if(pos == MAX_CONTATOS)
    {
        printf("Número máximo de contatos atingido!\n");
        return -1;
    }
    strcpy(contatos[pos].nome, nome);
    strcpy(contatos[pos].telefone1, tel1);
    strcpy(contatos[pos].telefone2, tel2);
    strcpy(contatos[pos].telefone3, tel3);
    strcpy(contatos[pos].email, email);
    strcpy(contatos[pos].instagram, insta);
    contatos[pos].num_acessos = 0;

    pos++;
    return 1;
}
