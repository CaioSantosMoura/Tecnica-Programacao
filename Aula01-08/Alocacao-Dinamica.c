#include <stdio.h>
#include <stdlib.h> // Necess�rio para malloc, free

int main() {
    int *vetor;  // Ponteiro para int
    int tamanho;

    // Solicita ao usu�rio o tamanho do vetor
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    // 1 - Manejo de Entrada e Valida��o: O que aconteceria se o usu�rio inserisse um valor negativo para o tamanho do vetor?
    // Como voc� modificaria o c�digo para lidar com essa situa��o de forma adequada?
    if (tamanho <= 0) {
        printf("O tamanho do vetor deve ser um n�mero positivo.\n");
        return 1; // C�digo de erro
    }

    // Aloca mem�ria dinamicamente para o vetor
    vetor = (int *)malloc(tamanho * sizeof(int));

    // Verifica se a aloca��o foi bem-sucedida
    if (vetor == NULL) {
        printf("Erro ao alocar mem�ria.\n");
        return 1; // C�digo de erro
    }


    // Preenche o vetor com valores
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = i * 10; // Atribui valores m�ltiplos de 10
    }

    // Exibe os valores armazenados no vetor
    printf("Conte�do do vetor:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    // Libera a mem�ria alocada
    free(vetor);

    // 2 - Gest�o de Mem�ria: O que aconteceria se a fun��o malloc() falhasse devido � falta de mem�ria dispon�vel?
    // Como voc� pode garantir que o programa n�o tente acessar mem�ria n�o alocada?
    vetor = NULL; // Define o ponteiro para NULL ap�s liberar a mem�ria

    return 0;
}
