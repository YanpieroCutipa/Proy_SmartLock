#include <SPI.h>         // Librería para comunicación SPI (necesaria para el lector RFID)
#include <MFRC522.h>     // Librería para el lector RFID MFRC522
#include <Servo.h>       // Librería para controlar servos

// Definición de pines del lector RFID
#define RST_PIN	9
#define SS_PIN	10
MFRC522 mfrc522(SS_PIN, RST_PIN); // Inicializa el lector RFID

Servo myservo;           // Objeto para controlar el servo
bool EST_INI = 0;        // Estado inicial del sistema (si ya se inicializó el servo)
bool EST = 0;            // Estado actual (abierto o cerrado)
int POS = 0;             

void setup() {
	Serial.begin(9600);     // Inicializa comunicación serial para depuración
	SPI.begin();            
	mfrc522.PCD_Init();     // Inicializa el lector RFID
  //myservo.detach(2);    // Desconectar el servo
  delay(500);             // Pequeño retraso al iniciar
}

// UID actuales leídas por el lector
byte ActualUID[4];
// Dos tarjetas RFID autorizadas
byte TARJETA1[4]= {0x82, 0x09, 0x25, 0x03};  
byte TARJETA2[4]= {0xE3, 0x60, 0x03, 0x0E};

void loop() {
	if ( mfrc522.PICC_IsNewCardPresent()) {  // Verifica si hay una tarjeta presente
    if ( mfrc522.PICC_ReadCardSerial()) {   // Lee el número de serie (UID) de la tarjeta
      for (byte i = 0; i < mfrc522.uid.size; i++) { 
        ActualUID[i]=mfrc522.uid.uidByte[i]; // Guarda el UID leído
      }               

      // Compara el UID leído con TARJETA1
      if(compareArray(ActualUID,TARJETA1)){
        if (EST_INI == 0){           // Si el sistema no está inicializado
          EST_INI = 1;              // Marca como inicializado
          myservo.attach(2);       // Conecta el servo al pin 2
          myservo.write(0);        // Mueve a posición inicial
          delay(500);
        } else {
          if (EST == 0){           // Si está cerrado
            EST = 1;               // Cambia a abierto
            for (POS = 0; POS <= 180; POS += 1) {
              myservo.write(POS);  // Abre el servo progresivamente
              delay(15);
            }
          } else {                 // Si está abierto
            EST = 0;               // Cambia a cerrado
            for (POS = 180; POS >= 0; POS -= 1) {
              myservo.write(POS);  // Cierra el servo progresivamente
              delay(15);
            }
          }
        }
        Serial.println("RECONOCIDO");  // UID reconocido

      // Repite el mismo proceso para TARJETA2
      } else if(compareArray(ActualUID,TARJETA2)){
        if (EST_INI == 0){
          EST_INI = 1;
          myservo.attach(2);
          myservo.write(0);
          delay(500);
        } else{
          if (EST == 0){
            EST = 1;
            for (POS = 0; POS <= 180; POS += 1) {
              myservo.write(POS);
              delay(15);
            }
          } else{
            EST = 0;
            for (POS = 180; POS >= 0; POS -= 1) {
              myservo.write(POS);
              delay(15);
            }
          }
        }
        Serial.println("RECONOCIDO");

      } else {
        Serial.println("DESCONOCIDO"); // UID no reconocido
      }

      mfrc522.PICC_HaltA();  // Detiene la lectura de la tarjeta
      delay(4000);           // Espera para evitar múltiples lecturas rápidas
    } 
	}
}

// Función para comparar dos arrays de 4 bytes (UIDs)
boolean compareArray(byte array1[],byte array2[]) {
  if(array1[0] != array2[0]) return false;
  if(array1[1] != array2[1]) return false;
  if(array1[2] != array2[2]) return false;
  if(array1[3] != array2[3]) return false;
  return true;
}
