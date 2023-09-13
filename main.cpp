// Funcion para el  patron 1,  matriz 8x8



#include <iostream>



void imprimirPatron() {
    char matriz[8][8];

    // Inicio de la matriz 8x8 con espacios en blanco
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            matriz[i][j] = ' ';
        }
    }

    int numAsteriscos = 2;

    // LLenar la matriz con asteriscos deacuerdo al patrón 1
    for (int i = 0; i < 8; i++) {
        int espacioInicial = (8 - numAsteriscos) / 2;

        for (int j = espacioInicial; j < espacioInicial + numAsteriscos; j++) {
            matriz[i][j] = '*';
        }

        // Aumentar y disminuir la cantidad de asteriscos según la fila deacuerdo al patron 1.
        if (i < 3) {
            numAsteriscos += 2;
        } else if (i > 3) {
            numAsteriscos -= 2;
        }
    }

    // Impresion de la matriz de 8x8 con el patron 1.
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            std::cout << matriz[i][j];
        }
        std::cout << std::endl;
    }
}

int main() {
    imprimirPatron();
    return 0;
}
