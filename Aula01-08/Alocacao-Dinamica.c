#include <stdio.h>
#include <stdlib.h>

int main() {
    int *vetor;
    int tamanho, novoTamanho;

    // 1 - Manejo de Entrada e Valida��o
    printf("Digite o tamanho inicial do vetor: ");
    if (scanf("%d", &tamanho) != 1 || tamanho <= 0) {
        printf("O tamanho do vetor deve ser um n�mero positivo.\n");
        return 1; // C�digo de erro
    }

    // Aloca mem�ria dinamicamente para o vetor
    vetor = (int *)malloc(tamanho * sizeof(int));
    if (vetor == NULL) {
        printf("Erro ao alocar mem�ria.\n");
        return 1; // C�digo de erro
    }

    // Preenche o vetor com valores
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = i * 10; // Inicializa��o com valores m�ltiplos de 10
    }

    // Exibe os valores armazenados no vetor
    printf("Conte�do do vetor:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    // 2 - Gest�o de Mem�ria
    // Solicita ao usu�rio o novo tamanho do vetor
    printf("Digite o novo tamanho do vetor (deve ser maior que o tamanho atual): ");
    if (scanf("%d", &novoTamanho) != 1 || novoTamanho <= tamanho) {
        printf("Novo tamanho deve ser maior que o tamanho atual.\n");
        free(vetor); // Libera a mem�ria alocada antes de encerrar
        return 1; // C�digo de erro
    }

    // 3 - Realoca��o de Mem�ria
    // Realoca mem�ria para o vetor
    int *temp = (int *)realloc(vetor, novoTamanho * sizeof(int));
    if (temp == NULL) {
        printf("Erro ao realocar mem�ria.\n");
        free(vetor); // Libera a mem�ria original se a realoca��o falhar
        return 1; // C�digo de erro
    }
    vetor = temp;

    // Preenche o novo espa�o com valores
    for (int i = tamanho; i < novoTamanho; i++) {
        vetor[i] = i * 10;
    }

    // Exibe os valores armazenados no vetor ap�s realoca��o
    printf("Conte�do do vetor ap�s realoca��o:\n");
    for (int i = 0; i < novoTamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    // 4 - Desempenho e Efici�ncia
    // O uso de realloc pode ser ineficiente se o tamanho do vetor for alterado com muita frequ�ncia.
    // Para minimizar realoca��es frequentes, voc� pode alocar mais mem�ria do que o necess�rio inicialmente
    // e aumentar a aloca��o conforme a necessidade. Isso reduz a frequ�ncia das realoca��es.

    // 5 - Seguran�a de Mem�ria
    // Ap�s liberar a mem�ria, defina o ponteiro para NULL para evitar acesso a mem�ria n�o v�lida
    free(vetor);
    vetor = NULL;

    // 6 - Tratamento de Dados
    // Solicita ao usu�rio novos valores para o vetor
    printf("Digite o tamanho do vetor para nova entrada de dados: ");
    if (scanf("%d", &tamanho) != 1 || tamanho <= 0) {
        printf("O tamanho do vetor deve ser um n�mero positivo.\n");
        return 1; // C�digo de erro
    }

    // Realoca mem�ria para o vetor com o novo tamanho
    vetor = (int *)malloc(tamanho * sizeof(int));
    if (vetor == NULL) {
        printf("Erro ao alocar mem�ria.\n");
        return 1; // C�digo de erro
    }

    // Solicita ao usu�rio os valores para o vetor
    printf("Digite %d valores inteiros:\n", tamanho);
    for (int i = 0; i < tamanho; i++) {
        while (scanf("%d", &vetor[i]) != 1) {
            printf("Entrada inv�lida. Digite um valor inteiro:\n");
            while (getchar() != '\n'); // Limpa o buffer de entrada
        }
    }

    // Exibe os valores armazenados no vetor
    printf("Conte�do do vetor:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    // Libera a mem�ria alocada
    free(vetor);3
    vetor = NULL; // Define o ponteiro para NULL ap�s liberar a mem�ria

    return 0;
}
