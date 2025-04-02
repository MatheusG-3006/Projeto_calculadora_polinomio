#include <stdio.h>
#include <math.h>
#include "funcoes.h"

void mostrarP(int grau, float coeficiente[]) {
    printf("P(x) = ");
    for (int i = grau; i >= 0; i--) {
        if (coeficiente[i] != 0) {
            if (i != grau) {
                printf(coeficiente[i] >= 0 ? " + " : " - ");
                if (coeficiente[i] < 0) coeficiente[i] = -coeficiente[i]; 
            }
            if (i == 0) printf("%.2f", coeficiente[i]);
            else if (i == 1) printf("%.2fx", coeficiente[i]);
            else printf("%.2fx^%d", coeficiente[i], i);
        }
    }
    printf("\n");
}

void lerPolinomio(int *grau, float coeficiente[]) {
    printf("Informe o grau do polinômio: ");
    scanf("%d", grau);
    
    if (*grau > MAX_GRAU) {
        printf("Erro: Grau máximo permitido é %d\n", MAX_GRAU);
        *grau = -1;
    }
    
    printf("Digite os coeficientes (do termo de grau %d ao termo independente):\n", *grau);
    for (int i = *grau; i >= 0; i--) {
        printf("Coeficiente do termo x^%d: ", i);
        scanf("%f", &coeficiente[i]);
    }
}

float calcularP(int grau, float coeficiente[], float x) {
    float resultado = 0.0;
    for (int i = 0; i <= grau; i++) {
        resultado += coeficiente[i] * pow(x, i);
    }
    return resultado;
}

void somarP(int grau1, float coeficiente1[], int grau2, float coeficiente2[]) {
    int resultadoGrauP = (grau1 > grau2) ? grau1 : grau2;
    float resultadoCoeficiente[MAX_GRAU + 1] = {0};

    for (int i = 0; i <= grau1; i++) resultadoCoeficiente[i] += coeficiente1[i];
    for (int i = 0; i <= grau2; i++) resultadoCoeficiente[i] += coeficiente2[i];

    printf("Resultado da soma:\n");
    mostrarP(resultadoGrauP, resultadoCoeficiente);
}

void multiplicarP(int grau1, float coeficiente1[], int grau2, float coeficiente2[]) { 
    int resultadoGrauP = grau1 + grau2;
    float resultadoCoeficiente[resultadoGrauP + 1];  

    for (int i = 0; i <= resultadoGrauP; i++) {
        resultadoCoeficiente[i] = 0.0;
    }

    for (int i = 0; i <= grau1; i++) {
        for (int j = 0; j <= grau2; j++) {
            resultadoCoeficiente[i + j] += coeficiente1[i] * coeficiente2[j];
        }
    }
    
    mostrarP(resultadoGrauP, resultadoCoeficiente);  
}

void visualizarPassoaPasso(int grau1, float coeficiente1[], int grau2, float coeficiente2[]) {
    int op;
    do { 
    printf("Escolha a operação para visualizar o passo a passo:\n");
    printf("1. Somar polinômios\n");
    printf("2. Multiplicar polinômios\n");
    printf("3. Sair\n");
    printf("Escolha uma Opcao: ");
    scanf("%d", &op);

    switch(op) {
        case 1: 
        visualizarpassoapassoSoma(grau1, coeficiente1, grau2, coeficiente2);
        break;

        case 2: 
        visualizarpassoapassoMultiplicacao(grau1, coeficiente1, grau2, coeficiente2);
        break; 

        case 3: 
        printf("Encerrado!\n");
        break;
        
        default: 
        printf("Opcao Invalida\n");
    }
    } while(op != 3); 
}

void visualizarpassoapassoSoma(int grau1, float coeficiente1[], int grau2, float coeficiente2[]) {
       printf("Soma dos polinômios:\n\n");
    int grauResultado = (grau1 > grau2) ? grau1 : grau2;

    for (int i = grauResultado; i >= 0; i--) {
        float resultado = coeficiente1[i] + coeficiente2[i];
        
        printf("Soma do coeficiente de x^%d: %.2f + %.2f = %.2f\n", i, coeficiente1[i], coeficiente2[i], resultado);

        if (resultado != 0) {
            if (resultado > 0 && i != grauResultado) {
                printf("+ ");
            } else if (resultado < 0) {
                printf("- ");
                resultado = -resultado;
            }

            if (i == 0) {
                printf("%.2f", resultado);
            } else if (i == 1) {
                printf("%.2fx", resultado);
            } else {
                printf("%.2fx^%d", resultado, i);
            }
            printf("\n");
        }
    }
}

void visualizarpassoapassoMultiplicacao(int grau1, float coeficiente1[], int grau2, float coeficiente2[]) {
    printf("\nCálculo da multiplicação dos polinômios:\n\n");

    int grauResultado = grau1 + grau2;
    float coeficienteResultado[grauResultado + 1];

    for (int i = 0; i <= grauResultado; i++) {
        coeficienteResultado[i] = 0;
    }

    for (int i = 0; i <= grau1; i++) {
        for (int j = 0; j <= grau2; j++) {
            float resultado = coeficiente1[i] * coeficiente2[j];
            int grauProduto = i + j;

            coeficienteResultado[grauProduto] += resultado;

            printf("Multiplicacao de %.2f * %.2f = %.2f, adicionando x^%d\n",
                   coeficiente1[i], coeficiente2[j], resultado, grauProduto);
        }
    }    printf("\nResultado:\n");
    for (int k = grauResultado; k >= 0; k--) {
        if (coeficienteResultado[k] != 0) {
            if (coeficienteResultado[k] > 0 && k != grauResultado) {
                printf(" + ");
            } else if (coeficienteResultado[k] < 0) {
                printf(" - ");
                coeficienteResultado[k] = -coeficienteResultado[k];
            }

            if (k == 0) {
                printf("%.2f", coeficienteResultado[k]);
            } else if (k == 1) {
                printf("%.2fx", coeficienteResultado[k]);
            } else {
                printf("%.2fx^%d", coeficienteResultado[k], k);
            }
        }
    }
    printf("\n");
}
