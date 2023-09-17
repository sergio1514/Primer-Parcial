#include <iostream>

void imprimirPatron1();
void imprimirPatron2();
void imprimirPatron4();
void inicializarMatriz(char **&matriz, int filas, int columnas);
void imprimirMatriz(char **matriz, int filas, int columnas);

int main() {
    imprimirPatron1();
    imprimirPatron2();
    imprimirPatron4();
    return 0;
}

void inicializarMatriz(char **&matriz, int filas, int columnas) {
    matriz = new char *[filas];
    for (int i = 0; i < filas; i++) {
        matriz[i] = new char[columnas];
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = ' ';
        }
    }
}

void imprimirMatriz(char **matriz, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            std::cout << matriz[i][j];
        }
        std::cout << std::endl;
    }
}

void imprimirPatron1() {
    int filas = 8;
    int columnas = 8;
    char **matriz = nullptr;

    inicializarMatriz(matriz, filas, columnas);

    int numAsteriscos = 2;

    // LLenar la matriz con asteriscos de acuerdo al patrón 1
    for (int i = 0; i < filas; i++) {
        int espacioInicial = (columnas - numAsteriscos) / 2;

        for (int j = espacioInicial; j < espacioInicial + numAsteriscos; j++) {
            matriz[i][j] = '*';
        }

        // Aumentar y disminuir la cantidad de asteriscos según la fila de acuerdo al patrón 1.
        if (i < 3) {
            numAsteriscos += 2;
        } else if (i > 3) {
            numAsteriscos -= 2;
        }
    }

    // Impresión de la matriz de 8x8 con el patrón 1.
    imprimirMatriz(matriz, filas, columnas);

    // Liberar memoria dinámica
    for (int i = 0; i < filas; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;
}

void imprimirPatron2() {
    int filas = 8;
    int columnas = 8;
    char **matriz = nullptr;

    inicializarMatriz(matriz, filas, columnas);

    for (int i = 0; i < filas; i++) {
        matriz[i][i] = '*';
        matriz[i][columnas - 1 - i] = '*';
    }

    imprimirMatriz(matriz, filas, columnas);

    // Liberar memoria dinámica
    for (int i = 0; i < filas; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;
}

void imprimirPatron4() {
    int filas = 8;
    int columnas = 8;
    char **matriz = nullptr;

    inicializarMatriz(matriz, filas, columnas);

    // Primera mitad
    for (int i = 0; i < 4; i++) {
        for (int j = i; j < i + 4; j++) {
            matriz[i][j] = '*';
        }
    }

    // Segunda mitad
    for (int i = 7; i > 3; i--) {
        for (int j = 0; j < 4; j++) {
            matriz[i][7 - i + j] = '*';
        }
    }

    imprimirMatriz(matriz, filas, columnas);

    // Liberar memoria dinámica
    for (int i = 0; i < filas; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;
}
