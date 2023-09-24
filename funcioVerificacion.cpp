int pinData  = 2;
int pinLatch = 3;
int pinClock = 4;
#define TIEMPO 500

void ledWrite(int ledState) {
  shiftOut(pinData, pinClock, LSBFIRST, ledState);
  digitalWrite(pinLatch, HIGH);
  digitalWrite(pinLatch, LOW);
}

void verificacion() {
  for (int i = 0; i < 64; i++) {
    ledWrite(1 << i); // Enciende un LED a la vez
    delay(TIEMPO);
  }
  delay(500);  // Pausa de 500 milisegundos (0.5 segundos) antes de repetir
}

void setup() {
  pinMode(pinData, OUTPUT);
  pinMode(pinLatch, OUTPUT);
  pinMode(pinClock, OUTPUT);
}

void loop() {
  verificacion();
}