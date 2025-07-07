#include <stddef.h>

#define TAMANHO_STRING 50
#define MAX_CONTATOS 200

struct Contato {
    char nome[TAMANHO_STRING];
    char telefone1[TAMANHO_STRING];
    char telefone2[TAMANHO_STRING];
    char telefone3[TAMANHO_STRING];
    char email[TAMANHO_STRING];
    char instagram[TAMANHO_STRING];
    unsigned int num_acessos;
};

extern struct Contato contatinhos[MAX_CONTATOS];
extern size_t num_contatinhos;

