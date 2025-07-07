/* FUNÇÃO 6 */
/* RYAN BRAGA e PEDRO BAVIER */

#include <stdio.h>
#include <string.h>

#include <prog/tipos.h>
#include <prog/prototipos.h>

#define agenda contatinhos

void aglutinar_contatos(int i1, int i2)
{
    printf("Agluinando contato %s com %s...\n\n", agenda[i1].nome, agenda[i2].nome);
    if (agenda[i1].telefone1[0] == '\0')
    {
        if (agenda[i2].telefone1[0] != '\0')
        {
        strcpy(agenda[i1].telefone1, agenda[i2].telefone1);
        }
        else if (agenda[i2].telefone2[0] != '\0')
        {
        strcpy(agenda[i1].telefone1, agenda[i2].telefone2);
        }
        else if (agenda[i2].telefone3[0] != '\0')
        {
        strcpy(agenda[i1].telefone1, agenda[i2].telefone3);
        }
    }

    if (agenda[i1].telefone2[0] == '\0')
    {
        if (agenda[i2].telefone1[0] != '\0' && strcmp(agenda[i1].telefone1, agenda[i2].telefone1) != 0)
        {
        strcpy(agenda[i1].telefone2, agenda[i2].telefone1);
        }
        else if (agenda[i2].telefone2[0] != '\0' && strcmp(agenda[i1].telefone1, agenda[i2].telefone2) != 0)
        {
        strcpy(agenda[i1].telefone2, agenda[i2].telefone2);
        }
        else if (agenda[i2].telefone3[0] != '\0' && strcmp(agenda[i1].telefone1, agenda[i2].telefone3) != 0)
        {
        strcpy(agenda[i1].telefone2, agenda[i2].telefone3);
        }
    }

    if (agenda[i1].telefone3[0] == '\0')
    {
        if (agenda[i2].telefone1[0] != '\0' && strcmp(agenda[i1].telefone2, agenda[i2].telefone1) != 0 && strcmp(agenda[i1].telefone1, agenda[i2].telefone1) != 0)
        {
        strcpy(agenda[i1].telefone3, agenda[i2].telefone1);
        }
        else if (agenda[i2].telefone2[0] != '\0' && strcmp(agenda[i1].telefone2, agenda[i2].telefone2) != 0&& strcmp(agenda[i1].telefone1, agenda[i2].telefone2) != 0)
        {
        strcpy(agenda[i1].telefone3, agenda[i2].telefone2);
        }
        else if (agenda[i2].telefone3[0] != '\0' && strcmp(agenda[i1].telefone2, agenda[i2].telefone3) != 0&& strcmp(agenda[i1].telefone1, agenda[i2].telefone3) != 0)
        {
        strcpy(agenda[i1].telefone3, agenda[i2].telefone3);
        }
    }
    if (agenda[i1].email[0] == '\0')
    {
        strcpy(agenda[i1].email, agenda[i2].email);
    }

    if (agenda[i1].instagram[0] == '\0')
    {
        strcpy(agenda[i1].instagram, agenda[i2].instagram);
    }
    agenda[i1].num_acessos += agenda[i2].num_acessos;
    exclui_contato(i2);
}

