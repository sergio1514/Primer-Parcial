int pinData  = 2;
int pinLatch = 3;
int pinClock = 4;
#define TIEMPO 500
char serialInput = ' '; // Inicializa con un valor por defecto

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
  Serial.begin(9600); // Inicializa la comunicación serial a 9600 baudios
}

void loop() {
  if (Serial.available() > 0) {
    serialInput = Serial.read();
    if (serialInput == 'v') {
      verificacion();
    }
  }
}
