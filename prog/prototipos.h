
int adicionar_nove(unsigned int quantidade_digitos);

int criar_contato(
    const char* nome, char telefone1[], char telefone2[], char telefone3[],
    char email[], char instagram[]
);

int atualizar_contato(int indice, int codigo, char inf_n[]);

int buscar_contato(char busca[]);
int numero_de_contatos_iguais(int indice);
char *quem_ligou(char numero[]);

int exclui_contato(int indice);

