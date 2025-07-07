#include <string.h>

#include <prog/tipos.h>
#include <prog/prototipos.h>
#include <prog/utilidades.h>

struct Contato contatinhos[MAX_CONTATOS];
size_t num_contatinhos = 0;


int main() {
    criar_contato_teste("Carlos Lima", "976543210", "carlos@email.com", 20);
    criar_contato_teste("Ana Silva", "8765-4321", "ana@email.com", 15);
    criar_contato_teste("Diana Souza", "12345678", "diana@email.com", 12);
    criar_contato_teste("Fernanda Oliveira", "956781234", "fer@email.com", 10);
    criar_contato_teste("Bruno Costa", "98877665", "bruno@email.com", 8);
    criar_contato_teste("Gustavo Pereira", "909090909", "guga@email.com", 7);
    criar_contato_teste("Eduardo Santos", "34567890", "eduardo@email.com", 3);
    criar_contato_teste("Helena Almeida", "910111213", "helena@email.com", 2);
    criar_contato_teste("Igor Rodrigues", "914151617", "igor@email.com", 1);



    for (int i = 0; i < num_contatinhos; i++) {
        printar_contato(contatinhos[i]);
    }

    return 0;
}

