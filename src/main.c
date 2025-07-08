#include <stdio.h>
#include <string.h>

#include <prog/tipos.h>
#include <prog/prototipos.h>
#include <prog/utilidades.h>

struct Contato contatinhos[MAX_CONTATOS];
size_t num_contatinhos = 0;


int main() {
    ler_csv();

    for (int i = 0; i < num_contatinhos; i++) {
        // printar_contato(contatinhos[i]);
        linha_csv(contatinhos[i], stdout);
    }

    escrever_csv();

    return 0;
}

