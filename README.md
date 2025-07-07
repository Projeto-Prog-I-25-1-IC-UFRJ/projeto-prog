# projeto-prog
O Projeto Final de Programação de Computadores I do período 2025.1

## Função 1

### `criar_contato_a`

Funciona, mas não verifica se o `nome` não é vazio.

### `criar_contato_b`

Funciona perfeitamente.

## Função 2

### `naofunciona/atualizar_contato_a`

Tenta fazer coisas desnecessárias (que não foram pedidas no enunciado) e, por conta disso, é mais vulnerável a erros. Várias coisas não funcionam, por exemplo, não é possível alterar o nome, simplesmente não faz nada.

### `atualizar_contato_b`

Funciona perfeitamente.

## Função 3

### `buscar_contato_a`

Funciona perfeitamente.

### `buscar_contato_b`

Funciona perfeitamente.

### `deveriafuncionar/buscar_contato_c`

Deveria funcionar, mas a lista de contatos não está sendo ordenada, então não funciona. Não há qualquer erro visível no código, e assumir que a lista está ordernada estaria correto de acordo com o enunciado, mas infelizmente nenhum grupo implementou a funcionalidade de reordenar a lista nas funções que manipulam o vetor e, portanto, o código não funciona.

## Função 4

### `identificar_quem_ligou_a`

Funciona perfeitamente, mas precisou ser alterada para retornar a string em vez de printar na tela

### `identificar_quem_ligou_b`

Funciona, mas não verifica o número por completo. Por exemplo, se tivermos números "91234" e "9123" e eu passar "9123" ele vai retornar o "91234" se ele vier primeiro, em vez de achar o número exato, ele vê só o começo.

## Função 5

### `excluir_contato_a`

Funciona perfeitamente.

### `excluir_contato_b`

Funciona perfeitamente.

## Função 7

### `adiciona_nove_a`

- Somente adiciona o 9 em números celulares
- Não adiciona 9 a strings vazias

### `adiciona_nove_b`

- Adiciona o 9 a qualquer número com menos dígitos
- Strings vazias viram "9"
