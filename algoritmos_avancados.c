#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Struct Sala:
    - nome: nome do cômodo
    - esquerda: ponteiro para sala à esquerda
    - direita: ponteiro para sala à direita
*/
typedef struct Sala {
    char nome[50];
    struct Sala *esquerda;
    struct Sala *direita;
} Sala;

/*
    criarSala():
    Cria uma nova sala dinamicamente e retorna seu endereço.
*/
Sala* criarSala(char nome[]) {
    Sala* nova = (Sala*) malloc(sizeof(Sala));
    strcpy(nova->nome, nome);
    nova->esquerda = NULL;
    nova->direita = NULL;
    return nova;
}

/*
    explorarSalas():
    Permite o jogador navegar pela árvore usando:
    - 'e' para a esquerda
    - 'd' para a direita
    - 's' para sair
*/
void explorarSalas(Sala *atual) {
    char escolha;

    while (atual != NULL) {
        printf("\nVocê está em: %s\n", atual->nome);

        // Se for nó folha, não há mais caminhos
        if (atual->esquerda == NULL && atual->direita == NULL) {
            printf("Este cômodo não possui mais caminhos. Fim da exploração!\n");
            return;
        }

        printf("Escolha um caminho:\n");
        printf("e - Ir para a esquerda\n");
        printf("d - Ir para a direita\n");
        printf("s - Sair da mansão\n");
        printf("Opcao: ");
        scanf(" %c", &escolha);

        if (escolha == 'e' || escolha == 'E') {
            if (atual->esquerda != NULL) {
                atual = atual->esquerda;
            } else {
                printf("Nao existe caminho para a esquerda!\n");
            }
        }
        else if (escolha == 'd' || escolha == 'D') {
            if (atual->direita != NULL) {
                atual = atual->direita;
            } else {
                printf("Nao existe caminho para a direita!\n");
            }
        }
        else if (escolha == 's' || escolha == 'S') {
            printf("Voce decidiu sair da mansao.\n");
            return;
        }
        else {
            printf("Opcao invalida!\n");
        }
    }
}

int main() {

    /*
        Montagem automática da árvore da mansão:

                     Hall de Entrada
                 /                      \
          Sala de Estar             Cozinha
           /         \              /       \
      Biblioteca   Jardim      Despensa   Porão
    */

    Sala *hall        = criarSala("Hall de Entrada");
    Sala *estar       = criarSala("Sala de Estar");
    Sala *cozinha     = criarSala("Cozinha");
    Sala *biblioteca  = criarSala("Biblioteca");
    Sala *jardim      = criarSala("Jardim");
    Sala *despensa    = criarSala("Despensa");
    Sala *porao       = criarSala("Porão");

    // Conectar salas
    hall->esquerda = estar;
    hall->direita  = cozinha;

    estar->esquerda = biblioteca;
    estar->direita  = jardim;

    cozinha->esquerda = despensa;
    cozinha->direita  = porao;

    // Iniciar exploração
    printf("=== Detective Quest ===\n");
    printf("Explorando a mansao...\n");

    explorarSalas(hall);

    printf("\nObrigado por jogar!\n");

    return 0;
}


