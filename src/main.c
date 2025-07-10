#include <stdio.h>
#include <string.h>

#include <ncurses.h>

#include <prog/tipos.h>
#include <prog/prototipos.h>
#include <prog/utilidades.h>

#define CTRL(x) ((x) & 0x1f)
#define NCURSES_COMECAR { \
    initscr(); \
    cbreak(); \
    raw(); \
    noecho(); \
    keypad(stdscr, TRUE); \
}


struct Contato contatinhos[MAX_CONTATOS];
size_t num_contatinhos = 0;

enum tela {
    TELA_PRINCIPAL,
    CRIACAO_DE_CONTATO,
    EDICAO_DE_CONTATO,
    IDENTIFICAR_QUEM_LIGOU,
    EXCLUIR_CONTATO,
    AGLUTINAR_CONTATOS,
    ADICIONAR_NOVE,
    CONTATOS_COM_LETRA,
    CINCO_CONTATOS
};

int main() {
    NCURSES_COMECAR

    ler_csv();

    enum tela tela = TELA_PRINCIPAL;
    int scroll = 0;

    while (1) {
        clear();

        switch(tela) {
        case TELA_PRINCIPAL:
        case IDENTIFICAR_QUEM_LIGOU:
        case CONTATOS_COM_LETRA:
            break;

        case CINCO_CONTATOS:
            break;

        case CRIACAO_DE_CONTATO:
            endwin();

            printf("Para criar um contato, digite uma linha nesse formato:\r\n");
            printf("Nome,Telefone1,Telefone2,Telefone3,Email,Instagram,0\n\n");

            ler_linha_csv(stdin);

            printf("Pressione enter para voltar à aplicação");
            getchar();

            NCURSES_COMECAR
        }

        refresh();

        int c = getch();
        switch (c) {
        case CTRL('c'):
        case 'q':
            endwin();
            return 0;

        case 27:
            tela = TELA_PRINCIPAL;
            break;

        case 'c':
            tela = CRIACAO_DE_CONTATO;
            break;

        case 'i':
            tela = IDENTIFICAR_QUEM_LIGOU;
            break;

        case 'x':
            tela = EXCLUIR_CONTATO;
            break;

        case 'a':
            tela = AGLUTINAR_CONTATOS;
            break;

        case 'n':
            tela = ADICIONAR_NOVE;
            break;

        case 'l':
            tela = CONTATOS_COM_LETRA;
            break;

        case 'r':
            tela = CINCO_CONTATOS;
            break;
        }
    }
    
    /*

    for (int i = 0; i < num_contatinhos; i++) {
        // printar_contato(contatinhos[i]);
        linha_csv(contatinhos[i], stdout);
    }

    escrever_csv();
    */

    endwin();
    return 0;
}

