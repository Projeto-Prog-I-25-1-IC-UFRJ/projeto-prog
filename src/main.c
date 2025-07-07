#include <string.h>

#include <prog/tipos.h>
#include <prog/prototipos.h>

struct Contato contatinhos[MAX_CONTATOS];
size_t num_contatinhos = 0;


int main() {
    num_contatinhos = 2;
    strcpy(contatinhos[0].nome, "amongus");
    strcpy(contatinhos[0].telefone1, "87654321");
    strcpy(contatinhos[0].telefone2, "998762434");
    strcpy(contatinhos[0].telefone3, "998762434");
    strcpy(contatinhos[0].email, "amongus@ic.ufrj.br");
    strcpy(contatinhos[0].instagram, "@sus");
    contatinhos[0].num_acessos = 0;

    strcpy(contatinhos[1].nome, "imposter");
    strcpy(contatinhos[1].telefone1, "998762434");
    strcpy(contatinhos[1].telefone2, "87654321");
    strcpy(contatinhos[1].telefone3, "998762434");
    strcpy(contatinhos[1].email, "imp@ic.ufrj.br");
    strcpy(contatinhos[1].instagram, "@potus");
    contatinhos[1].num_acessos = 0;

    adicionar_nove(9);

    return 0;
}

