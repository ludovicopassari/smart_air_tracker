# Gestione della Configurazione del Dispositivo

## Obiettivi
- Il dispositivo deve essere in grado di memorizzare in maniera persistente quelli che sono i parametri di configurazione necessari al dispositivo per funzionare correttamente.

## Requisiti Funzionali
- RF1: Il dispositivo deve essere in grado di leggere dal supporto di memoria persistente quelli che sono i parametri di configurazione attuali del dispositivo.
- RF2: Il dispositivo deve essere in grado di poter scrivere in un supporto di memoria persistente quelli che sono i parametri di configurazione del dispositivo necessari al corretto funzionamento del dispositivo stesso (utilizzando NVS o EEPROM).


## Requisiti Non Funzionali
- RNF1: Le configurazioni devono essere salvate in meno di 2 secondi.
- RNF2: L'interfaccia utente deve essere intuitiva e facile da usare.
- RNF3: Il sistema deve gestire gli errori in modo chiaro e informativo per l'utente.

## Casi d'Uso
### Caso d'Uso 1: Configurare le Impostazioni di Rete
- **Attori**: Utente
- **Flusso Principale**:
  1. L'utente accede alla schermata di configurazione.
  2. L'utente inserisce il SSID e la password.
  3. L'utente preme il pulsante "Salva".
  4. Il sistema memorizza le configurazioni e mostra un messaggio di conferma.

## Requisiti di Interfaccia
- Interfaccia con il modulo NVS per salvare e caricare le configurazioni accessibile attraverso classi stabilite.
- Interfaccia utente per la visualizzazione delle impostazioni.

