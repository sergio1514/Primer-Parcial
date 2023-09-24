// IMPLEMENTCION EN C++ PARCIAL 01
#include <iostream>

  int filas = 8;
  int columnas = 8;

using namespace std;

int main(){
    

    
    int opcion;
    bool repetir = true;
    
    do {
        
        
        // Menú inicial
        cout << "\n\n\t\t\t MATRIZ 8X8" << endl;
        cout << "\t\t\t------------" << endl;
        cout << "\n\t1. VERIFICACION DE 64 LEDS MATRIX" << endl;
        cout << "\t2. PATRON 1." << endl;
        cout << "\t3. PATRON 2." << endl;
        cout << "\t4. PATRON 3." << endl;
        cout << "\t5. PATRON 4." << endl;
        cout << "\t6. PATRON 1, 2, 3 y 4 cada 4 segundos." << endl;
        cout << "\t0. SALIR" << endl;
        cout << "\n\tIngrese una opcion: ";
        cin >> opcion;
        
      
        switch (opcion) {
            
            
            case 1:
            
{
   

    // Llenar la matriz con asteriscos
    char matriz[filas][columnas];
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = '*';
        }
    }

    // Imprimir la matriz
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            std::cout << matriz[i][j] << ' ';
        }
        std::cout << std::endl;
    }

    return 0;
}
               
                system("pause>nul");
                break;
                
            case 2:

{
  

    // Reservar memoria dinámica para la matriz
    char** matriz = new char*[filas];
    for (int i = 0; i < filas; i++) {
        matriz[i] = new char[columnas];
    }

    // Inicializar la matriz con espacios en blanco
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = ' ';
        }
    }

    int numAsteriscos = 2;

    // Rellenar la matriz con asteriscos según el patrón
    for (int i = 0; i < filas; i++) {
        int espacioInicial = (columnas - numAsteriscos) / 2;

        for (int j = espacioInicial; j < espacioInicial + numAsteriscos; j++) {
            matriz[i][j] = '*';
        }

        // Aumentar o disminuir el número de asteriscos según la fila
        if (i < 3) {
            numAsteriscos += 2;
        } else if (i > 3) {
            numAsteriscos -= 2;
        }
    }

    // Imprimir la matriz
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            std::cout << matriz[i][j];
        }
        std::cout << std::endl;
    }

    // Liberar la memoria dinámica
    for (int i = 0; i < filas; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;

    return 0;
}

                system("pause>nul");
                break;
                
            case 3:
{


    // Reservar memoria dinámica para la matriz
    char** matriz = new char*[filas];
    for (int i = 0; i < filas; i++) {
        matriz[i] = new char[columnas];
    }

    // Inicializar la matriz con espacios en blanco
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = ' ';
        }
    }

    // Rellenar la matriz para formar una "X" en las diagonales
    for (int i = 0; i < filas; i++) {
        matriz[i][i] = '*'; // Diagonal de izquierda a derecha
        matriz[i][columnas - i - 1] = '*'; // Diagonal de derecha a izquierda
    }

    // Imprimir la matriz
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            std::cout << matriz[i][j];
        }
        std::cout << std::endl;
    }

    // Liberar la memoria dinámica
    for (int i = 0; i < filas; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;

    return 0;
}


                
                system("pause>nul");
                break;
                
            case 4:
             
{


    // Crear una matriz dinámica de caracteres
    char **matriz = new char *[filas];
    for (int i = 0; i < filas; i++) {
        matriz[i] = new char[columnas];
    }

    // Llenar la matriz con el patrón
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

    // Imprimir la matriz
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            std::cout << matriz[i][j];
        }
        std::cout << std::endl;
    }

    // Liberar la memoria de la matriz
    for (int i = 0; i < filas; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;

    return 0;
}

                
                system("pause>nul");     
                break;
                
            case 5:
             
{
   
    char **matriz = nullptr;

    // Inicializar la matriz
    matriz = new char*[filas];
    for (int i = 0; i < filas; i++) {
        matriz[i] = new char[columnas];
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = ' ';
        }
    }

    // Llenar la matriz con asteriscos
    for (int i = 0; i < 4; i++) {
        for (int j = i; j < i + 4; j++) {
            matriz[i][j] = '*';
        }
    }

    for (int i = 7; i > 3; i--) {
        for (int j = 0; j < 4; j++) {
            matriz[i][7 - i + j] = '*';
        }
    }

    // Imprimir la matriz
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            std::cout << matriz[i][j];
        }
        std::cout << std::endl;
    }

    // Liberar memoria dinámica
    for (int i = 0; i < filas; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;

    return 0;
}



                system("pause>nul");     
                break;
                
                
            case 6:

{
   

    // Llenar la matriz con asteriscos
    char matriz[filas][columnas];
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = '*';
        }
    }

    // Imprimir la matriz
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            std::cout << matriz[i][j] << ' ';
        }
        std::cout << std::endl;
    }

    return 0;
}
             
                
                system("pause>nul");     
                break;
            
            
            case 0:
            	repetir = false;
            	break;
            	
            	
          
        }        
    } while (repetir);
	 
    return 0;
}