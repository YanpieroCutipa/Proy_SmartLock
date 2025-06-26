# 🔒 SmartLock  🔒
Candado Inteligente con RFID para mochilas y bicicletas
SmartLock es un sistema de seguridad portátil basado en RFID, diseñado como alternativa moderna y tecnológica a los candados convencionales. Utiliza una tarjeta RFID personal (como un carné universitario) para permitir únicamente al usuario propietario abrir o cerrar su mochila o bicicleta, ofreciendo seguridad, comodidad y eficiencia.

## ⚠️ Problemática
En contextos urbanos o estudiantiles, el uso de candados tradicionales con llaves o combinaciones presenta varios problemas:

- Son fáciles de olvidar o perder.
- Pueden ser forzados o abiertos por terceros.
- No ofrecen personalización ni control de acceso.

SmartLock surge como una solución ante estas limitaciones, con el objetivo de brindar un sistema seguro que funcione mediante identificación por radiofrecuencia (RFID), utilizando tarjetas únicas que solo el usuario registrado puede usar para abrir o cerrar el candado.

## 🎯 Propósito del Proyecto
El propósito de SmartLock es:

- Reemplazar los candados mecánicos tradicionales por un sistema electrónico de seguridad inteligente.
- Permitir el bloqueo y desbloqueo mediante tarjetas RFID personalizadas (como carnés universitarios).
- Fomentar el uso de tecnología accesible y portátil en entornos cotidianos como campus, ciclovías o espacios públicos.

## 🛠️ Tecnologías y Componentes Utilizados
### Hardware
🔹 Arduino Nano – Microcontrolador que gestiona todo el sistema.

🔹 Módulo RFID RC522 – Lector de tarjetas RFID para autenticación de usuarios.

🔹 Servomotor SG90 – Controla la apertura o cierre del candado.

🔹 Módulo TP5400 – Circuito de carga para la batería.

🔹 Batería de litio-ion 1000mAh – Fuente de energía recargable.

🔹 Switch – Para encendido o control manual del sistema.

🔹 Carcasa de MDF – Estructura física cortada en láser para contener los componentes.

### Software
🔹 Librerías utilizadas:
```cpp
- SPI.h – Comunicación entre Arduino y el lector RFID.
- MFRC522.h – Control del lector RFID.
- Servo.h – Control del servomotor.
```

## ⚙️ Funcionamiento General
El sistema funciona de la siguiente manera:

Al acercar una tarjeta RFID al lector:
- Si el UID es reconocido, el servomotor se activa para abrir o cerrar el candado.
- Si el UID no está registrado, se niega el acceso y se muestra “DESCONOCIDO” en el monitor serial.
- Se puede registrar más de una tarjeta autorizada.
- El sistema previene múltiples lecturas rápidas con una pausa de 4 segundos tras cada acción.
- Todo esto se realiza sin conexión a internet y de forma totalmente autónoma gracias a la batería incorporada.

## 👨‍💻 Estado del Proyecto

✅ Funcional – Versión prototipo lista para demostración

🔧 Futuras mejoras posibles:
- Registro dinámico de tarjetas desde una app móvil.
- Control por Bluetooth o Wi-Fi.
- Alarma anti-manipulación.
