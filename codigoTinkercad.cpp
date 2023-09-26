int pinData = 2;
int pinLatch = 3;
int pinClock = 4;

int *ptrPatrones;
float *ptrTiempo;

// Función verificacion(), PRUEBA LOS LED.
void verificacion() {
  unsigned long startTime = millis(); // ALMACENA EL TIEMPO.
  unsigned long currentTime = startTime;

  while (currentTime - startTime < 6000) { // ENCIENDE Y APAGA 6 SEG.
    shiftOut(pinData, pinClock, LSBFIRST, 255); // PRENDE C/U DE LOS LED.
    digitalWrite(pinLatch, HIGH);
    digitalWrite(pinLatch, LOW);
    delay(600); // ESPERA 0.6 SEG.

    shiftOut(pinData, pinClock, LSBFIRST, 0); // APAGA LOS LEDs.
    digitalWrite(pinLatch, HIGH);
    digitalWrite(pinLatch, LOW);
    delay(600); // ESPERA 0.6 SEG.

    currentTime = millis(); // TIEMPO ACTUALIZADO.
  }

  // APAGADO DE LED.
  imagen(0, 0, 0, 0, 0, 0, 0, 0);
}

// Función imagen(), PARA INTRODUCIR PATRONES
void imagen(int aled, int bled, int cled, int dled, int eled, int fled, int gled, int hled) {
  shiftOut(pinData, pinClock, LSBFIRST, hled);
  shiftOut(pinData, pinClock, LSBFIRST, gled);
  shiftOut(pinData, pinClock, LSBFIRST, fled);
  shiftOut(pinData, pinClock, LSBFIRST, eled);
  shiftOut(pinData, pinClock, LSBFIRST, dled);
  shiftOut(pinData, pinClock, LSBFIRST, cled);
  shiftOut(pinData, pinClock, LSBFIRST, bled);
  shiftOut(pinData, pinClock, LSBFIRST, aled);
  digitalWrite(pinLatch, HIGH);
  digitalWrite(pinLatch, LOW);
}

// Función ingreso(), DATOS PUERTO SERIAL.
void ingreso(char ing[8]) {
  int verif = 0, posicion = 0;
  Serial.println("INGRESAR DATO: ");
  while (true) {
    if (Serial.available()) {
      posicion = 0;
      while (Serial.available() > 0) {
        delay(50);
        ing[posicion] = Serial.read();
        posicion++;
      }
      Serial.print("INGRESADO: ");
      Serial.println(ing);
      if (ing[0] == 'v') { // Cambiamos 'test' a 'v'
        verificacion();
        for (int i = 0; i <= posicion; i++) {
          ing[i] = NULL;
        }
      } else {
        break;
      }
    }
  }
}

// ARREGLO DE BINARIO A DECIMAL.
int BinToInt(char ing[8]) {
  int i = 0;
  int n = 0;

  while (ing[i] == '0' || ing[i] == '1') {
    if (ing[i] == '0')
      n <<= 1;
    else {
      n ^= 1;
      n <<= 1;
    }
    ++i;
  }
  n >>= 1;
  return (n);
}

// PUBLIK -- IMPRIME PATRONES.
void publik(int patrones, float tiempo) {
  int cantidad = 0;
  char patron[9] = {};
  int patronA;
  cantidad = (patrones * 8) - 1;
  int *array = new int[cantidad + 1];

  int aux = 0;
  int tiempoaux = int(tiempo * 1000.0);

  for (int i = 0; i < patrones * 8; i++) {
    ingreso(patron);
    patronA = BinToInt(patron);
    array[aux] = patronA;
    aux = aux + 1;
    if ((i + 1) % 8 == 0) {
      Serial.println("DATO INGRESADO");
    }
  }
  while (true) {
    for (int k = 0; k < (patrones * 8) - 1; k = k + 8) {
      imagen(array[k], array[k + 1], array[k + 2], array[k + 3], array[k + 4], array[k + 5], array[k + 6], array[k + 7]);
      delay(tiempoaux);
    }
    if (patrones == 1) {
      break;
    }
  }

  // Libera la memoria dinámica
  delete[] array;
}

void setup() {
  pinMode(pinData, OUTPUT);
  pinMode(pinLatch, OUTPUT);
  pinMode(pinClock, OUTPUT);

  digitalWrite(pinData, 0);
  digitalWrite(pinLatch, 0);
  digitalWrite(pinClock, 0);

  Serial.begin(9600);
  Serial.println("EL PROGRAMA INICIARA TESTEANDO LOS LEDS, LUEGO SOLICITARA UNA CANTIDAD DE PATRONES.");
  Serial.println("EL PROGRAMA SOLICITARA EL TIEMPO PARA MOSTRAR.");
  Serial.println("SE INGRESAN LOS PATRONES POR FILAS DE 1 A 8 ASI, Ej una 'X' en las diagonales:");
  Serial.println("ENTRE 10000001, 01000010, 00100100, 00011000, 00011000, 00100100, 01000010, 10000001");
  Serial.println("DIGITE 'v' PARA VERIFICAR LEDS EN CUALQUIER MOMENTO.");

  // EJECUTA LA FUNCION verificacion().
  verificacion();
}

void loop() {
  char *aux = new char[5];

  Serial.println("NUMERO DE PATRONES: ");
  ingreso(aux);
  *ptrPatrones = atoi(aux);
  Serial.print("No. PATRONES: ");
  Serial.println(*ptrPatrones);

  delete[] aux;

  if (*ptrPatrones != 1) {
    Serial.println("TIEMPO: ");
    aux = new char[5]; // Reasigna memoria dinámica
    ingreso(aux);
    *ptrTiempo = atof(aux);
    Serial.print("TIEMPO :");
    Serial.println(*ptrTiempo);
    delete[] aux;
  }

  Serial.println("INTRODUCIR PATRONES.");
  publik(*ptrPatrones, *ptrTiempo);

  Serial.println("EMPEZAR NUEVAMENTE.");
}
