// Funcion para el  patron 1,  matriz 8x8



#include <iostream>

void imprimirPatron1();
void imprimirPatron2();
void imprimirPatron4();
void inicializarMatriz(char matriz[8][8]);
void imprimirMatriz(char matriz[8][8]);




int main() {
    imprimirPatron1();
    imprimirPatron2();
    imprimirPatron4();
    return 0;
}

void inicializarMatriz(char matriz[8][8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            matriz[i][j] = ' ';
        }
    }
}

void imprimirMatriz(char matriz[8][8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            std::cout << matriz[i][j];
        }
        std::cout << std::endl;
    }
}

void imprimirPatron1() {
    char matriz[8][8];
    inicializarMatriz(matriz);

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
    imprimirMatriz(matriz);
}


void imprimirPatron2() {
    char matriz[8][8];
    inicializarMatriz(matriz);

    for (int i=0; i<8;i++){
        matriz[i][i] = '*';
        matriz[i][7-i] = '*';
    }

    imprimirMatriz(matriz);
}

void imprimirPatron4() {
    char matriz[8][8];

    inicializarMatriz(matriz);

    //  Primera mitad
    for (int i=0; i<4;i++){
        for(int j=i; j<i+4;j++){
            matriz[i][j] = '*';
        }
    }

    // Segunda mitad
    for (int i=7; i>3;i--){
        for(int j=0;j<4;j++)
            matriz[i][7-i+j] = '*';


    }

    imprimirMatriz(matriz);
}

