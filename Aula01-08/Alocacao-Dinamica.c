#include <stdio.h>
#include <stdlib.h> // Necessário para malloc, free

int main() {
    int *vetor;  // Ponteiro para int
    int tamanho;

    // Solicita ao usuário o tamanho do vetor
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    // 1 - Manejo de Entrada e Validação: O que aconteceria se o usuário inserisse um valor negativo para o tamanho do vetor?
    // Como você modificaria o código para lidar com essa situação de forma adequada?
    if (tamanho <= 0) {
        printf("O tamanho do vetor deve ser um número positivo.\n");
        return 1; // Código de erro
    }

    // Aloca memória dinamicamente para o vetor
    vetor = (int *)malloc(tamanho * sizeof(int));

    // Verifica se a alocação foi bem-sucedida
    if (vetor == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1; // Código de erro
    }


    // Preenche o vetor com valores
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = i * 10; // Atribui valores múltiplos de 10
    }

    // Exibe os valores armazenados no vetor
    printf("Conteúdo do vetor:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    // Libera a memória alocada
    free(vetor);

    // 2 - Gestão de Memória: O que aconteceria se a função malloc() falhasse devido à falta de memória disponível?
    // Como você pode garantir que o programa não tente acessar memória não alocada?
    vetor = NULL; // Define o ponteiro para NULL após liberar a memória

    return 0;
}
