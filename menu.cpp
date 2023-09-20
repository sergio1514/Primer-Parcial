// las librerias adicionales incluyen reloq, contador d tiempo y ejecucion simultanea para probar encendido

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

const int numRows = 8;
const int numCols = 8;

using namespace std;

int main()
{
    int opcion;
    bool repetir = true;
    
    do {
        system("cls");
        
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
        
        int numero1, numero2;
		float resultado;
        switch (opcion) {
            case 1:
               
    {
    char matriz[numRows][numCols];

    // Inicializar la matriz con espacios en blanco
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            matriz[i][j] = ' ';
        }
    }

    // Generar una semilla para números aleatorios
    std::srand(std::time(nullptr));

    // Recorrer cada posición de la matriz
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            // Colocar un asterisco en la posición actual
            matriz[i][j] = '*';

            // Imprimir la matriz
            for (int x = 0; x < numRows; x++) {
                for (int y = 0; y < numCols; y++) {
                    std::cout << matriz[x][y] << " ";
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;

            // Esperar 100 milisegundos
            std::this_thread::sleep_for(std::chrono::milliseconds(100));

            // Restaurar el espacio en blanco en esa posición
            matriz[i][j] = ' ';
        }
    }

    // Imprimir "OK" al finalizar
    std::cout << "LOS 64 LED DE LA MATRIX DE 8X8 ESTAN OK" << std::endl;

    return 0;
}
               
                system("pause>nul");
                break;
                
            case 2:

{
    int numRows = 8;
    int numCols = 8;

    // Reservar memoria dinámica para la matriz
    char** matriz = new char*[numRows];
    for (int i = 0; i < numRows; i++) {
        matriz[i] = new char[numCols];
    }

    // Inicializar la matriz con espacios en blanco
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            matriz[i][j] = ' ';
        }
    }

    int numAsteriscos = 2;

    // Rellenar la matriz con asteriscos según el patrón
    for (int i = 0; i < numRows; i++) {
        int espacioInicial = (numCols - numAsteriscos) / 2;

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
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            std::cout << matriz[i][j];
        }
        std::cout << std::endl;
    }

    // Liberar la memoria dinámica
    for (int i = 0; i < numRows; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;

    return 0;
}

                system("pause>nul");
                break;
                
            case 3:

{
    const int numRows = 8;
    const int numCols = 8;

    // Reservar memoria dinámica para la matriz
    char** matriz = new char*[numRows];
    for (int i = 0; i < numRows; i++) {
        matriz[i] = new char[numCols];
    }

    // Inicializar la matriz con espacios en blanco
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            matriz[i][j] = ' ';
        }
    }

    // Rellenar la matriz con asteriscos según el patrón
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if ((i % 4 < 2 && j % 4 < 2) || (i % 4 >= 2 && j % 4 >= 2)) {
                matriz[i][j] = '*';
            }
        }
    }

    // Imprimir la matriz
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            std::cout << matriz[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Liberar la memoria dinámica
    for (int i = 0; i < numRows; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;

    return 0;
}

                
                system("pause>nul");
                break;
                
            case 4:
             

                
                system("pause>nul");     
                break;
                
            case 5:
             

                system("pause>nul");     
                break;
                
                
            case 6:
             

                system("pause>nul");     
                break;
                
  
            
             
                
                system("pause>nul");     
                break;
            
            
            case 0:
            	repetir = false;
            	break;
            	
            	
          
        }        
    } while (repetir);
	 
    return 0;
}





