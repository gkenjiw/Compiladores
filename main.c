#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Token{
    Soma,
    Subtracao,
    Multiplicacao,
    Divisao,
    Indeterminado,
};

struct TokenList {
    enum Token token;
    struct TokenList *next;
};

void tokenizar(char *s, struct TokenList **tokens) {
    *tokens = NULL;
    struct TokenList *tail = NULL;
    while (*s != '\0') {
        if (*s == '+') {
            struct TokenList *node = malloc(sizeof(struct TokenList));
            node->token = Soma;
            node->next = NULL;
            if (tail == NULL) {
                *tokens = node;
            } else {
                tail->next = node;
            }
            tail = node;
        } else if (*s == '-') {
            struct TokenList *node = malloc(sizeof(struct TokenList));
            node->token = Subtracao;
            node->next = NULL;
            if (tail == NULL) {
                *tokens = node;
            } else {
                tail->next = node;
            }
            tail = node;
        } else if (*s == '*') {
            struct TokenList *node = malloc(sizeof(struct TokenList));
            node->token = Multiplicacao;
            node->next = NULL;
            if (tail == NULL) {
                *tokens = node;
            } else {
                tail->next = node;
            }
            tail = node;
        }else if (*s == '/') {
            struct TokenList *node = malloc(sizeof(struct TokenList));
            node->token = Divisao;
            node->next = NULL;
            if (tail == NULL) {
                *tokens = node;
            } else {
                tail->next = node;
            }
            tail = node;
        }else if (*s != ' ') {
            struct TokenList *node = malloc(sizeof(struct TokenList));
            node->token = Indeterminado;
            node->next = NULL;
            if (tail == NULL) {
                *tokens = node;
            } else {
                tail->next = node;
            }
            tail = node;
        }
        s++;
    }
}

void imprimir_tokens(struct TokenList *tokens) {
    printf("Tokens: [");
    while (tokens != NULL) {
        switch (tokens->token) {
            case Soma:
                printf("Soma, ");
                break;
            case Subtracao:
                printf("Subtração, ");
                break;
            case Multiplicacao:
                printf("Multiplicação, ");
                break;
            case Divisao:
                printf("Divisão, ");
                break;
            case Indeterminado:
                printf("Indeterminado, ");
                break;
        }
        tokens = tokens->next;
    }
    printf("]\n");
}

int main() {
    struct TokenList *tokens;
    FILE *fp;
    char line[255];

    fp = fopen("tokens.txt", "r");
    if (fp == NULL) {
        printf("Error opening the file!\n");
        exit(1);
    }

    if (fgets(line, sizeof(line), fp)) {
        tokenizar(line, &tokens);
        imprimir_tokens(tokens);
    } else {
        printf("Error reading the file!\n");
        exit(1);
    }

    fclose(fp);
    return 0;
}