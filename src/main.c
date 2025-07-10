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

        switch (tela) {
        case TELA_PRINCIPAL:
        case CONTATOS_COM_LETRA:
        case CINCO_CONTATOS:
            struct Contato cinco[5];
            struct Contato *c;
            int num_c = 0;

            if (tela == TELA_PRINCIPAL) {
                c = contatinhos;
                num_c = num_contatinhos;
            } else if (tela == CINCO_CONTATOS) {
                num_c = cinco_contatos(cinco);
                c = cinco;
            }

            const int szl = 7;
            
            if (scroll > num_c - LINES / 2 / szl)
                scroll = num_c - LINES / 2 / szl;
            if (scroll < 0)
                scroll = 0;

            for (int i = scroll; i < num_c; i++) {
                if (i * szl + 1 - scroll * szl >= LINES)
                    break;
                
                printw("Contato %d\n", i);
                printw("Nome: %s\n", c[i].nome);
                printw("Telefones: %s   %s   %s\n", c[i].telefone1, c[i].telefone2, c[i].telefone3);
                printw("Email: %s\n", c[i].email);
                printw("Insta: %s\n", c[i].instagram);
                printw("N. Acessos: %u\n", c[i].num_acessos);
                printw("\n");
            }

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

        case 'j':
        case KEY_DOWN:
            scroll += 1;
            break;
        case 'k':
        case KEY_UP:
            scroll -= (scroll > 0);
            break;
        }
    }
    

    endwin();
    return 0;
}

