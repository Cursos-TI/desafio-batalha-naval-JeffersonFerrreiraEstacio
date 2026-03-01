#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_HABILIDADE 5
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

// Função para exibir o tabuleiro formatado
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            if (tabuleiro[i][j] == AGUA) printf(". ");
            else if (tabuleiro[i][j] == NAVIO) printf("N ");
            else if (tabuleiro[i][j] == HABILIDADE) printf("X ");
        }
        printf("\n");
    }
    printf("\n");
}

// Função para aplicar a matriz de habilidade no tabuleiro principal
void aplicarHabilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], int origLinha, int origColuna) {
    // Calcula o deslocamento para centralizar a matriz 5x5 no ponto de origem
    int offset = TAM_HABILIDADE / 2;

    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (habilidade[i][j] == 1) {
                // Calcula a posição real no tabuleiro
                int novaLinha = origLinha + (i - offset);
                int novaColuna = origColuna + (j - offset);

                // Condicional para garantir que está dentro dos limites do tabuleiro
                if (novaLinha >= 0 && novaLinha < TAM_TABULEIRO && novaColuna >= 0 && novaColuna < TAM_TABULEIRO) {
                    tabuleiro[novaLinha][novaColuna] = HABILIDADE;
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};

    // 1. Posicionamento de alguns navios para demonstração
    tabuleiro[2][2] = NAVIO;
    tabuleiro[8][8] = NAVIO;

    // 2. Definição das Matrizes de Habilidade (5x5) usando lógica condicional
    int cone[TAM_HABILIDADE][TAM_HABILIDADE] = {0};
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE] = {0};
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE] = {0};

    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            // Lógica do Cone (triângulo para baixo)
            if (i == 0 && j == 2) cone[i][j] = 1;
            if (i == 1 && j >= 1 && j <= 3) cone[i][j] = 1;
            if (i == 2) cone[i][j] = 1;

            // Lógica da Cruz
            if (i == 2 || j == 2) cruz[i][j] = 1;

            // Lógica do Octaedro (Losango)
            // Soma das distâncias do centro (2,2) não pode passar de 2
            if (abs(i - 2) + abs(j - 2) <= 2) octaedro[i][j] = 1;
        }
    }

    // 3. Aplicação das Habilidades em pontos específicos
    printf("--- HABILIDADE EM CONE (Origem 2,5) ---\n");
    aplicarHabilidade(tabuleiro, cone, 2, 5);
    exibirTabuleiro(tabuleiro);

    // Reset para próxima demonstração (opcional)
    printf("--- HABILIDADE EM CRUZ (Origem 5,2) ---\n");
    aplicarHabilidade(tabuleiro, cruz, 5, 2);
    exibirTabuleiro(tabuleiro);

    printf("--- HABILIDADE EM OCTAEDRO (Origem 7,7) ---\n");
    aplicarHabilidade(tabuleiro, octaedro, 7, 7);
    exibirTabuleiro(tabuleiro);

    return 0;