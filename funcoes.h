#ifndef Funcoes_H
#define Funcoes_H
#define MAX_GRAU 10
void mostrarP(int grau, float coeficiente[]);
void lerPolinomio(int *grau, float coeficiente[]);
float calcularP(int grau, float coeficiente[], float x);
void somarP(int grau1, float coeficiente1[], int grau2, float coeficiente2[]);
void multiplicarP(int grau1, float coeficiente1[], int grau2, float coeficiente2[]);
void visualizarPassoaPasso(int grau1, float coeficiente1[], int grau2, float coeficiente2[]);
void visualizarpassoapassoSoma(int grau1, float coeficiente1[], int grau2, float coeficiente2[]);
void visualizarpassoapassoMultiplicacao(int grau1, float coeficiente1[], int grau2, float coeficiente2[]);

#endif
