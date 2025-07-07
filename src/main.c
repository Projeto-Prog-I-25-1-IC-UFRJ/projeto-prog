#include <string.h>

#include <prog/tipos.h>
#include <prog/prototipos.h>
#include <prog/utilidades.h>

struct Contato contatinhos[MAX_CONTATOS];
size_t num_contatinhos = 0;


int main() {
    criar_contato("Carlos Lima", "976543210", "12345678", "", "carlos@email.com", "@carlosrj");
    criar_contato("Ana Silva", "8765-4321", "", "", "ana@email.com", "");
    criar_contato("Diana Souza", "12345678", "", "", "diana@email.com", "");
    criar_contato("Fernanda Oliveira", "956781234", "", "", "fer@email.com", "");
    criar_contato("Bruno Costa", "98877665", "", "", "bruno@email.com", "");
    criar_contato("Gustavo Pereira", "909090909", "", "", "guga@email.com", "");
    criar_contato("Eduardo Santos", "34567890", "", "", "eduardo@email.com", "");
    criar_contato("Helena Almeida", "910111213", "", "", "helena@email.com", "");
    criar_contato("Igor Rodrigues", "914151617", "", "", "igor@email.com", "");



    for (int i = 0; i < num_contatinhos; i++) {
        printar_contato(contatinhos[i]);
    }

    return 0;
}

