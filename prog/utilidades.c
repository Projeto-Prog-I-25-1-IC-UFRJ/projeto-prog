#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "tipos.h"
#include "prototipos.h"

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

void ler_linha_csv(FILE *fp) {
    char linha[400];
    int field = 0;
    char *ultima_posicao = linha;

    criar_contato("Nome", "", "", "", "", "");

    fgets(linha, 400, fp);
    
    for (int i = 0; linha[i]; i++) {
        if (linha[i] == ',') {
            linha[i] = '\0';

            atualizar_contato(num_contatinhos - 1, field, ultima_posicao);

            ultima_posicao = &linha[i + 1];
            field++;
        } else if (linha[i] == '\n')
            linha[i] = '\0';
    }

    contatinhos[num_contatinhos - 1].num_acessos = atoi(ultima_posicao);
}

