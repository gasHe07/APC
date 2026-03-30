# Park Whisper - Smart Park Sensor

![Status](https://img.shields.io/badge/Status-Version%201.0-brightgreen)
![University](https://img.shields.io/badge/University-Federico%20II-red)
![Hardware](https://img.shields.io/badge/Hardware-STM32%20F3-blue)
![Hardware](https://img.shields.io/badge/Hardware-ESP32%20Wrover-blue)

## 👤 Autore
* **Elio Fava** (MAT: 0001/25512 / DE9000008)

**Università degli Studi di Napoli Federico II** **Corso:** Architettura e Progetto dei Calcolatori (APC) 

**A.A** 2024/25

**Docente:** Prof. Nicola Mazzocca

---

## 📝 Descrizione del Progetto
**Park Whisper** è un sistema di parcheggio assistito prototipale progettato per veicoli sprovvisti di sensori di serie. L'obiettivo principale è fornire un monitoraggio accurato della distanza dagli ostacoli, trasmettendo le informazioni in tempo reale allo smartphone dell'utente tramite comunicazione wireless.

Il sistema sfrutta un'architettura distribuita per separare la logica di acquisizione ad alta precisione (STM32) dalla logica di connettività e interfaccia utente (ESP32).

---

## 🚀 Funzionalità Principali
Il sistema offre le seguenti capacità:

* **Rilevamento Ultrasuoni:** Misurazione della distanza tramite sensore HC-SR04 con risoluzione al microsecondo.
* **Elaborazione Real-time:** Calcolo della distanza basato su Timer in modalità *Input Capture* su core ARM Cortex-M4.
* **Bridge Wireless:** Trasmissione dati tra schede tramite protocollo UART e propagazione mobile via Bluetooth Classic.
* **Feedback Acustico Adattivo:** Avvisi sonori tramite buzzer con frequenze variabili in base alla criticità della distanza:
    * **Safe (11-15 cm):** 1000 Hz.
    * **Warning (6-10 cm):** 2000 Hz.
    * **Danger (≤ 5 cm):** 3000 Hz.
* **Interfaccia Mobile:** Visualizzazione dei dati su smartphone tramite app terminale Bluetooth (Serial Bluetooth Terminal).

---

## 📊 Architettura del Sistema
Il progetto è strutturato secondo i seguenti livelli logici:

### 1. Acquisizione e Controllo (STM32)
La **STM32F3Discovery** gestisce il trigger del sensore e cattura il segnale di ritorno (Echo). La distanza è calcolata tramite la gestione degli interrupt dei timer. Il sistema gestisce inoltre i LED di bordo per un feedback visivo immediato.

### 2. Gateway e Avvisi (ESP32)
L'**ESP32 Wrover** riceve i dati via seriale, effettua il parsing delle stringhe e trasmette i valori via Bluetooth. Contemporaneamente, pilota un buzzer passivo per generare toni di avviso a frequenza variabile in base ai centimetri ricevuti.

---

## 🛠️ Tecnologie utilizzate
* **Microcontrollori:** * **STM32F303VCT6** (Core ARM Cortex-M4, 72MHz, 256KB Flash).
    * **ESP32 Wrover** (Dual-core, connettività Wi-Fi e Bluetooth Classic/LE integrata, PSRAM aggiuntiva).
* **Sensori:** HC-SR04 (Ultrasonic Sensor).
* **Protocolli:** UART (9600 baud), Bluetooth Classic, PWM (per il controllo del buzzer).
* **Ambienti di Sviluppo:** STM32CubeIDE, Arduino IDE.
