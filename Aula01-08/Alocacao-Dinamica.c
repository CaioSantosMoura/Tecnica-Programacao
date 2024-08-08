#include <stdio.h>
#include <stdlib.h>

int main() {
    int *vetor;
    int tamanho, novoTamanho;

    // 1 - Manejo de Entrada e Validação
    printf("Digite o tamanho inicial do vetor: ");
    if (scanf("%d", &tamanho) != 1 || tamanho <= 0) {
        printf("O tamanho do vetor deve ser um número positivo.\n");
        return 1; // Código de erro
    }

    // Aloca memória dinamicamente para o vetor
    vetor = (int *)malloc(tamanho * sizeof(int));
    if (vetor == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1; // Código de erro
    }

    // Preenche o vetor com valores
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = i * 10; // Inicialização com valores múltiplos de 10
    }

    // Exibe os valores armazenados no vetor
    printf("Conteúdo do vetor:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    // 2 - Gestão de Memória
    // Solicita ao usuário o novo tamanho do vetor
    printf("Digite o novo tamanho do vetor (deve ser maior que o tamanho atual): ");
    if (scanf("%d", &novoTamanho) != 1 || novoTamanho <= tamanho) {
        printf("Novo tamanho deve ser maior que o tamanho atual.\n");
        free(vetor); // Libera a memória alocada antes de encerrar
        return 1; // Código de erro
    }

    // 3 - Realocação de Memória
    // Realoca memória para o vetor
    int *temp = (int *)realloc(vetor, novoTamanho * sizeof(int));
    if (temp == NULL) {
        printf("Erro ao realocar memória.\n");
        free(vetor); // Libera a memória original se a realocação falhar
        return 1; // Código de erro
    }
    vetor = temp;

    // Preenche o novo espaço com valores
    for (int i = tamanho; i < novoTamanho; i++) {
        vetor[i] = i * 10;
    }

    // Exibe os valores armazenados no vetor após realocação
    printf("Conteúdo do vetor após realocação:\n");
    for (int i = 0; i < novoTamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    // 4 - Desempenho e Eficiência
    // O uso de realloc pode ser ineficiente se o tamanho do vetor for alterado com muita frequência.
    // Para minimizar realocações frequentes, você pode alocar mais memória do que o necessário inicialmente
    // e aumentar a alocação conforme a necessidade. Isso reduz a frequência das realocações.

    // 5 - Segurança de Memória
    // Após liberar a memória, defina o ponteiro para NULL para evitar acesso a memória não válida
    free(vetor);
    vetor = NULL;

    // 6 - Tratamento de Dados
    // Solicita ao usuário novos valores para o vetor
    printf("Digite o tamanho do vetor para nova entrada de dados: ");
    if (scanf("%d", &tamanho) != 1 || tamanho <= 0) {
        printf("O tamanho do vetor deve ser um número positivo.\n");
        return 1; // Código de erro
    }

    // Realoca memória para o vetor com o novo tamanho
    vetor = (int *)malloc(tamanho * sizeof(int));
    if (vetor == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1; // Código de erro
    }

    // Solicita ao usuário os valores para o vetor
    printf("Digite %d valores inteiros:\n", tamanho);
    for (int i = 0; i < tamanho; i++) {
        while (scanf("%d", &vetor[i]) != 1) {
            printf("Entrada inválida. Digite um valor inteiro:\n");
            while (getchar() != '\n'); // Limpa o buffer de entrada
        }
    }

    // Exibe os valores armazenados no vetor
    printf("Conteúdo do vetor:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    // Libera a memória alocada
    free(vetor);3
    vetor = NULL; // Define o ponteiro para NULL após liberar a memória

    return 0;
}
