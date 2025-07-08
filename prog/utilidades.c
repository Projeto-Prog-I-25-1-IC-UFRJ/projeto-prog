#include <stdio.h>
#include <string.h>

#include "tipos.h"

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

void linha_csv(Contato c, FILE *fp) {
    fprintf(
        fp,
        "%s,%s,%s,%s,%s,%s,%u\n",
        c.nome, c.telefone1, c.telefone2, c.telefone3, c.email, c.instagram,
        c.num_acessos
    );
}

