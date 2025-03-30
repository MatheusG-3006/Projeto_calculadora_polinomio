#include <stdio.h>
#include <math.h>
#include "funcoes.h"
#define MAX_GRAU 10 

int main() {
    int opcao, grau1 = -1, grau2 = -1;
    float coeficiente1[MAX_GRAU + 1], coeficiente2[MAX_GRAU + 1], x;

    do {
        printf("\n======= MENU =======\n");
        printf("1. Ler polinômio\n");
        printf("2. Calcular valor de P(x)\n");
        printf("3. Somar polinômios\n");
        printf("4. Multiplicar polinômios\n");
        printf("5. Visualização Passo a Passo\n");
        printf("6. Sair\n");
        printf("====================\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        printf("\n");

        switch(opcao) {
            case 1:
                printf("Lendo primeiro polinômio:\n");
                lerPolinomio(&grau1, coeficiente1);
                mostrarP(grau1, coeficiente1);

                printf("\nLendo segundo polinômio:\n");
                lerPolinomio(&grau2, coeficiente2);
                mostrarP(grau2, coeficiente2);
                break;

            case 2:
                if (grau1 == -1) {
                    printf("Erro: Nenhum polinômio foi lido ainda!\n");
                    break;
                }
                printf("Informe o valor de x: ");
                scanf("%f", &x);
                printf("Resultado de P(%.2f) = %.2f\n", x, calcularP(grau1, coeficiente1, x));
                break;

            case 3:
                if (grau1 == -1 || grau2 == -1) {
                    printf("Erro: Leia dois polinômios primeiro!\n");
                    break;
                }
                somarP(grau1, coeficiente1, grau2, coeficiente2);
                break;

            case 4:
                if (grau1 == -1 || grau2 == -1) {
                    printf("Erro: Leia dois polinômios primeiro!\n");
                    break;
                }
                multiplicarP(grau1, coeficiente1, grau2, coeficiente2);
                break;

            case 5:
            if (grau1 == -1 || grau2 == -1) {
                printf("Erro: Leia dois polinômios primeiro!\n");
                break;
            }
            visualizarPassoaPasso(grau1, coeficiente1, grau2, coeficiente2);
            break;

            case 6: 
            printf("Encerrado\n");
            break;

            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 6);

    return 0;
}
