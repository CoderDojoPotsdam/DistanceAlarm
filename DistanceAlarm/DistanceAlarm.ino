int trigger = 7;
int echo = 6;
int buzzer = 9;
int button = 8;
long dauer = 0;
long entfernung = 0;
long umbruch = 0;

void setup() {
  Serial.begin (9600); //Serielle kommunikation starten, damit man sich später die Werte am serial monitor ansehen kann.
  pinMode(trigger, OUTPUT); // Ausgang um ein Signal zu senden
  pinMode(echo, INPUT); // Eingang damit wir Echo empfangen können
  pinMode(button, INPUT_PULLUP); // Eingang, der wenn der Button nicht gedrückt wird HIGH ist
  pinMode(buzzer, OUTPUT); // Ausgang um den Ton zu senden
}

void loop() {
  if (millis() % 1000 == 0) { // wenn eine Sekunde vergangen ist
    digitalWrite(trigger, LOW); //Hier nimmt man die Spannung für kurze Zeit vom Trigger-Pin, damit man später beim senden des Trigger-Signals ein rauschfreies Signal hat.
    delay(5); //Dauer: 5 Millisekunden
    digitalWrite(trigger, HIGH); //Jetzt sendet man eine Ultraschallwelle los.
    delay(10); //Dieser „Ton“ erklingt für 10 Millisekunden.
    digitalWrite(trigger, LOW);//Dann wird der „Ton“ abgeschaltet.
    dauer = pulseIn(echo, HIGH); //Mit dem Befehl „pulseIn“ zählt der Mikrokontroller die Zeit in Mikrosekunden, bis der Schall zum Ultraschallsensor zurückkehrt.
    entfernung = (dauer / 2) * 0.03432; //Nun berechnet man die Entfernung in Zentimetern. Man teilt zunächst die Zeit durch zwei (Weil man ja nur eine Strecke berechnen möchte und nicht die Strecke hin- und zurück). Den Wert multipliziert man mit der Schallgeschwindigkeit in der Einheit Zentimeter/Mikrosekunde und erhält dann den Wert in Zentimetern.
    if (entfernung >= 500 || entfernung <= 0) //Wenn die gemessene Entfernung über 500cm oder unter 0cm liegt,…
    {
      Serial.println("Kein Messwert"); //dann soll der serial monitor ausgeben „Kein Messwert“, weil Messwerte in diesen Bereichen falsch oder ungenau sind.
    }
    else // Ansonsten…
    {
      if (entfernung < umbruch) { // wenn die Entfernung größer als der gespeicherte Umbruch ist
        Serial.println("zu dicht"); // dann soll der serial monitor ausgeben "zu dicht" ausgeben
        tone(buzzer,220); // ...und der Buzzer einen Ton machen
      } else { // Ansonsten…
        Serial.println("weit genug weg"); // soll "weit genug weg" im serial monitor ausgegeben werden
        noTone(buzzer); // ...und der Buzzer den Ton stoppen
      }
    }
  }

  if (digitalRead(button) == LOW) { // wenn der Knopf gedrückt wird
    umbruch = entfernung; // die derzeitige entfernung wird in umbruch gespeichert
  }
}
