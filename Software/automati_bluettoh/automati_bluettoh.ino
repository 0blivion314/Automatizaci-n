#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to enable it
#endif

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);  // Inicializa el puerto serie para ver los datos en el Monitor Serie
  pinMode(26, OUTPUT);
  pinMode(27, OUTPUT);
  pinMode(2, OUTPUT);
  
  SerialBT.begin("ESP32test");  // Nombre del dispositivo Bluetooth
  Serial.println("Dispositivo iniciado, ¡ahora puedes emparejarlo con Bluetooth!");
}

void loop() {
  // Esperar hasta que haya datos disponibles por Bluetooth
  while (!SerialBT.available()) {
    delay(10);  // No bloquear completamente el proceso
  }
  
  // Leer los datos entrantes
  String res = "";
  while (SerialBT.available()) {
    res += (char)SerialBT.read();  // Agregar cada carácter recibido a la cadena
    delay(1);  // Ajustar si es necesario
  }

  // Imprimir los datos recibidos en el Monitor Serie
  Serial.print("Datos recibidos por Bluetooth: ");
  Serial.println(res);  // Imprime la cadena completa recibida

  // Limpiar la cadena para evitar residuos de datos anteriores
  res.trim();

  // Asignando acciones según los comandos recibidos
  if (res == "A") {
    // Encender btn1
    Serial.println("Encendiendo btn1 (LED 1)");
    digitalWrite(26, HIGH); // Encender LED 1
  } else if (res == "a") {
    // Apagar btn1
    Serial.println("Apagando btn1 (LED 1)");
    digitalWrite(26, LOW); // Apagar LED 1
  } else if (res == "B") {
    // Encender btn2
    Serial.println("Encendiendo btn2 (LED 2)");
    digitalWrite(27, HIGH); // Encender LED 2
  } else if (res == "b") {
    // Apagar btn2
    Serial.println("Apagando btn2 (LED 2)");
    digitalWrite(27, LOW); // Apagar LED 2
  } else if (res == "C") {
    // Apagar btn2
    Serial.println("ENCENDIDO btn3 (LED3 )");
    digitalWrite(2, HIGH); // Apagar LED 2
    } else if (res == "c") {
    // Apagar btn2
    Serial.println("Apagando btn3 (LED 33)");
    digitalWrite(2, LOW); // Apagar LED 2
    }
    else{
    Serial.println("Comando desconocido");
  }
}
