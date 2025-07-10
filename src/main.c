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
    timeout(5); \
    curs_set(0); \
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
    CINCO_CONTATOS,
    TELA_AJUDA
};

int main() {
    NCURSES_COMECAR

    ler_csv();

    enum tela tela = TELA_PRINCIPAL;
    int scroll = 0;

    while (1) {

        switch (tela) {
        case TELA_AJUDA:
            clear();
            printw(
                "q ou Ctrl-C - fechar programa\n"
                "h           - tela de ajuda\n"
                "ESC         - voltar para a tela principal\n"
                "c           - criar um contato\n"
                "i           - identificar quem ligou\n"
                "x           - excluir um contato\n"
                "a           - aglutinar contatos\n"
                "n           - adicionar 9 a todos os contatos\n"
                "l           - contatos que começam com uma letra\n"
                "r           - cinco contatos mais acessados\n"
                "j ou <seta para baixo> - scroll para baixo\n"
                "k ou <seta para cima> - scroll para cima"
            );

            break;
        case TELA_PRINCIPAL:
        case CINCO_CONTATOS:
            clear();
            struct Contato cinco[5];
            struct Contato *c;
            int num_c = 0;

            if (tela == TELA_PRINCIPAL) {
                c = contatinhos;
                num_c = num_contatinhos;
                printw("LISTA DE CONTATOS\n");
            } else if (tela == CINCO_CONTATOS) {
                num_c = cinco_contatos(cinco);
                c = cinco;
                printw("CINCO MAIS ArESSADOS\n");
            }

            const int szl = 7;
            
            if (scroll > num_c - LINES / 2 / szl)
                scroll = num_c - LINES / 2 / szl;
            if (scroll < 0)
                scroll = 0;

            for (int i = scroll; i < num_c; i++) {
                if (i * szl + 2 - scroll * szl >= LINES)
                    break;
                
                if (tela == TELA_PRINCIPAL)
                    printw("Contato %d\n", i);
                else
                    printw("Contato\n");
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

            printf("Para criar um contato, digite uma linha nesse formato:\n");
            printf("Nome,Telefone1,Telefone2,Telefone3,Email,Instagram,0\n\n");

            ler_linha_csv(stdin);

            printf("Pressione enter para voltar à aplicação");
            getchar();

            tela = TELA_PRINCIPAL;
            NCURSES_COMECAR
            break;

        case CONTATOS_COM_LETRA:
            endwin();

            printf("Digite a letra para buscar:\n");
            char letra = getchar();
            if (letra != '\n') {
                getchar();
                printf("\n");

                listar_nomes(letra);

                printf("\nPressione enter para voltar à aplicação");
                getchar();
            }

            tela = TELA_PRINCIPAL;
            NCURSES_COMECAR
            break;

        case IDENTIFICAR_QUEM_LIGOU:
            endwin();

            char input[200];
            printf("Digite o número de telefone:\n");
            fgets(input, 199, stdin);
            input[strlen(input) - 1] = '\0';
            
            char *output = quem_ligou(input);
            if (output)
                printf("\nQUEM LIGOU: %s\n", output);
            else
                printf("\nNAO SEI QUEM LIGOU\n");

            printf("\nPressione enter para voltar à aplicação");
            getchar();

            tela = TELA_PRINCIPAL;
            NCURSES_COMECAR
            break;

        case EXCLUIR_CONTATO:
            endwin();

            printf("Digite o índice do contato que deseja excluir:\n");
            printf("(Esse número pode ser visto na tela principal)\n");

            int indice = -1;
            scanf("%d", &indice);
            getchar();
            if (indice >= 0 && indice < num_contatinhos) {
            
                if (exclui_contato(indice) == 1) {
                    printf("Contato exclúido\n");
                } else {
                    printf("Houve um erro\n");
                }

                printf("\nPressione enter para voltar à aplicação");
                getchar();
            }

            tela = TELA_PRINCIPAL;
            NCURSES_COMECAR
            break;

        case AGLUTINAR_CONTATOS:
            endwin();

            printf("Digite os índices do contatos que deseja aglutinar separados por espaços:\n");
            printf("(Esses números podem serem vistos na tela principal)\n");

            int indice1 = -1, indice2 = -1;
            scanf("%d %d", &indice1, &indice2);
            getchar();
            if (indice1 >= 0 && indice1 < num_contatinhos && indice2 >= 0 && indice2 < num_contatinhos) {
            
                aglutinar_contatos(indice1, indice2);

                printf("\nPressione enter para voltar à aplicação");
                getchar();
            }

            tela = TELA_PRINCIPAL;
            NCURSES_COMECAR
            break;
        
        case ADICIONAR_NOVE:
            endwin();

            printf("Quantos dígitos os telefones devem ter?\n");

            int num_digitos = -1;
            scanf("%d", &num_digitos);
            getchar();
            if (num_digitos >= 0) {
                int r = adicionar_nove(num_digitos);
                printf("Modificados %d telefones\n", r);

                printf("\nPressione enter para voltar à aplicação");
                getchar();
            }

            tela = TELA_PRINCIPAL;
            NCURSES_COMECAR
            break;
        }

        refresh();

        int c = getch();
        switch (c) {
        case CTRL('c'):
        case 'q':
            endwin();
            printf("\n");
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

        case 'h':
            tela = TELA_AJUDA;
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

