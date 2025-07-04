#include<stdio.h>
#include<string.h>

//valores máximos dos vetores
#define max_cont 1000
#define max 100
#define tel 18

//estrutura de dados de cada contato utilizada.
typedef struct {
char nome[max];
char telefone1[tel];
char telefone2[tel];
char telefone3[tel];
char email[max];
char instagram[max];
int num_acessos;
} contato;

//nomes que considerei para os vetores
contato contatos_agenda[max_cont];
char procurar_nome[max];

//função que busca a posição do contato no vetor
int buscar_contato(char procurar_nome[]){
    int esq=0, dir=0;
    
    /*já que não sei se o número de contatos preenchidos está sendo 
    salvo em algum lugar, usei esse comando para descobrir a informação 
    de quantos contatos foram salvos. */
    for ( ;dir < max_cont; dir++) {
        if (strlen(contatos_agenda[dir].nome) == 0) {
            break; // chegou no fim da lista preenchida
        }
    } dir--;
    
    /*busca binária do nome no vetor, já que o vetor deve estar
    em ordem alfabética. */
    while (esq != dir) {
        int meio = (esq + dir) / 2;
        if (strncmp(procurar_nome, contatos_agenda[meio].nome, strlen(procurar_nome)) <= 0)
            dir = meio;
        else {esq = meio + 1;}
    }
    
    //garante que a posição será a menor possível.
    for(int j = esq; j >= 0; j--) {
        if (strncmp(contatos_agenda[j].nome, procurar_nome, strlen(procurar_nome)) == 0) {
        esq=j;} else {break;}
    }   
    //retorno da função 
    if (strncmp(procurar_nome, contatos_agenda[esq].nome, strlen(procurar_nome)) == 0) {
        contatos_agenda[esq].num_acessos += 1; 
    /*se for necessário apenas saber a quantidade de acessos a um contato de maneira separada
    o número de acessos já é atualizado aqui, porém ele atualiza individualmente para cada contato
    a mais que será impresso na chamada da segunda função. Caso isso não seja necessário, retirar
    essa parte e a condição "if" da segunda função.  */    
        return esq;
    } 
    else {return -1;}
}


//função que imprime contatos repetidos
int mesmo_nome (int pos) {
    int quant_repetida = -1;
    for(int i = pos; contatos_agenda[i].nome[0] != '\0' && strncmp(contatos_agenda[i].nome, procurar_nome, strlen(procurar_nome)) == 0; i++) {
    printf("%s \n", contatos_agenda[i].nome);
    printf("telefone 1: %s \n", contatos_agenda[i].telefone1);
    if (contatos_agenda[i].telefone2[0] != '\0') {
    printf("telefone 2: %s \n", contatos_agenda[i].telefone2);}
    if (contatos_agenda[i].telefone3[0] != '\0') {
    printf("telefone 3: %s \n", contatos_agenda[i].telefone3);}
    if (contatos_agenda[i].email[0] != '\0') {
    printf("email: %s \n", contatos_agenda[i].email);}
    if (contatos_agenda[i].instagram[0] != '\0') {
    printf("intagram: %s \n", contatos_agenda[i].instagram);}
    if (i != pos) {contatos_agenda[i].num_acessos += 1;} //condição pode ser retirada a depender do que é necessário ser retornado. 
    printf("você acessou esse contato: %d vezes \n\n", contatos_agenda[i].num_acessos);
    quant_repetida++;
    }
    return quant_repetida;
}

// função principal
int main() {  
    
    //permite o usuário digitar o nome desejado para a procura.  
    puts ("procurar nome:");  
    fgets(procurar_nome, max, stdin);  
    procurar_nome[strcspn(procurar_nome, "\n")] = '\0';  

    //chamada das funções 
    int posicao = buscar_contato(procurar_nome);  
    if (posicao >= 0) {  
        mesmo_nome(posicao);
    }  
    else {printf ("não foi achado nenhum contato");}
return 0;
}