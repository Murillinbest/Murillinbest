#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para armazenar os dados de uma pessoa
typedef struct {
    char nome[50];
    int idade;
    char cpf[12];
} Pessoa;

// Função para adicionar um novo cadastro
Pessoa* adicionarCadastro(Pessoa* cadastros, int* tamanho, int* capacidade) {
    // Verificar se é necessário expandir a capacidade do array
    if (*tamanho == *capacidade) {
        *capacidade = (*capacidade == 0) ? 1 : *capacidade * 2; // Dobrar capacidade
        cadastros = realloc(cadastros, (*capacidade) * sizeof(Pessoa));
        if (cadastros == NULL) {
            printf("Erro ao alocar memoria!\n");
            exit(1);
        }
    }

    // Preencher os dados do novo cadastro
    printf("Informe o nome: ");
    scanf(" %[^\n]", cadastros[*tamanho].nome);
    printf("Informe a idade: ");
    scanf("%d", &cadastros[*tamanho].idade);
    printf("Informe o CPF (apenas numeros): ");
    scanf(" %[^\n]", cadastros[*tamanho].cpf);

    (*tamanho)++; // Incrementar o número de cadastros
    return cadastros;
}

// Função para listar todos os cadastros
void listarCadastros(Pessoa* cadastros, int tamanho) {
    if (tamanho == 0) {
        printf("Nenhum cadastro encontrado.\n");
        return;
    }

    printf("\n=== Lista de Cadastros ===\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Cadastro %d:\n", i + 1);
        printf("Nome: %s\n", cadastros[i].nome);
        printf("Idade: %d\n", cadastros[i].idade);
        printf("CPF: %s\n", cadastros[i].cpf);
        printf("-----------------------\n");
    }
}

// Função para deletar um cadastro pelo índice
Pessoa* deletarCadastro(Pessoa* cadastros, int* tamanho, int* capacidade, int indice) {
    if (indice < 1 || indice > *tamanho) {
        printf("Indice invalido!\n");
        return cadastros;
    }

    indice--; // Ajustar para índice baseado em zero
    for (int i = indice; i < (*tamanho) - 1; i++) {
        cadastros[i] = cadastros[i + 1]; // Deslocar os elementos para a esquerda
    }

    (*tamanho)--; // Reduzir o tamanho
    if (*tamanho < *capacidade / 2) {
        *capacidade /= 2; // Reduzir a capacidade se necessário
        cadastros = realloc(cadastros, (*capacidade) * sizeof(Pessoa));
        if (cadastros == NULL && *tamanho > 0) {
            printf("Erro ao realocar memoria!\n");
            exit(1);
        }
    }

    printf("Cadastro deletado com sucesso!\n");
    return cadastros;
}

int main() {
    Pessoa* cadastros = NULL; // Ponteiro para array dinâmico de cadastros
    int tamanho = 0;         // Número de cadastros atuais
    int capacidade = 0;      // Capacidade atual do array

    int opcao;
    do {
        printf("\n=== Sistema de Cadastro ===\n");
        printf("1. Adicionar Cadastro\n");
        printf("2. Listar Cadastros\n");
        printf("3. Deletar Cadastro\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastros = adicionarCadastro(cadastros, &tamanho, &capacidade);
                break;
            case 2:
                listarCadastros(cadastros, tamanho);
                break;
            case 3: {
                int indice;
                printf("Informe o indice do cadastro a deletar: ");
                scanf("%d", &indice);
                cadastros = deletarCadastro(cadastros, &tamanho, &capacidade, indice);
                break;
            }
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 4);

    // Liberar a memória alocada antes de sair
    free(cadastros);

    return 0;
}
