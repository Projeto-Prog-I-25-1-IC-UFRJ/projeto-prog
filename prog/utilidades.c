#include <stdio.h>
#include <string.h>

#include "tipos.h"

/* Obrigado NICOLAS GOMES e BERNARDO MAGNO por essa função */
void criar_contato_teste(const char *nome, const char *tel1, const char *email, int acessos) {
    if (num_contatinhos < MAX_CONTATOS) {
        strcpy(contatinhos[num_contatinhos].nome, nome);
        strcpy(contatinhos[num_contatinhos].telefone1, tel1);
        strcpy(contatinhos[num_contatinhos].telefone2, ""); 
        strcpy(contatinhos[num_contatinhos].telefone3, ""); 
        strcpy(contatinhos[num_contatinhos].email, email);
        strcpy(contatinhos[num_contatinhos].instagram, ""); 
        contatinhos[num_contatinhos].num_acessos = acessos;
        num_contatinhos++;
    } else {
        printf("Agenda cheia! Nao foi possivel adicionar '%s'.\n", nome);
    }
}

/* E também por essa, embora modificada */
void printar_contato(Contato contato) {
    printf("%s\n", contato.nome);
    printf("  Telefone 1: %s\n", contato.telefone1);
    printf("  Telefone 2: %s\n", contato.telefone2);
    printf("  Telefone 3: %s\n", contato.telefone3);
    printf("  Email: %s\n", contato.email);
    printf("  Instagram: %s\n", contato.instagram);
    printf("  Acessos: %d\n", contato.num_acessos);
    printf("\n");
}

