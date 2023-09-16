#include <iostream>

int main() {
    //dimensiones matriz (8x8)
    int filas = 8;
    int columnas = 8;

    // Crear una matriz dinámica de caracteres
    char **matriz = new char *[filas];
    for (int i = 0; i < filas; i++) {
        matriz[i] = new char[columnas];
    }

    // Llenar  matriz con  patrón
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if ((i / 2) % 2 == 0) {
                if ((j / 2) % 2 == 0) {
                    matriz[i][j] = '*';
                } else {
                    matriz[i][j] = ' ';
                }
            } else {
                if ((j / 2) % 2 == 0) {
                    matriz[i][j] = ' ';
                } else {
                    matriz[i][j] = '*';
                }
            }
        }
    }

    // Imprimir matriz
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            std::cout << matriz[i][j];
        }
        std::cout << std::endl;
    }

    // Liberar  memoria
    for (int i = 0; i < filas; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;

    return 0;
}
