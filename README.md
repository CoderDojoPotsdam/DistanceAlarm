# Abstandsmesser

## Setup
1. [Arduino IDE downloaden](https://www.arduino.cc/en/software)
2. Diese installieren.
3. Paket öffnen
![](https://pad.ccc-p.org/uploads/upload_7fc8a7c5b0a732c25e9c28837ba10e29.jpg)
4. Arduino aus der Verpackung nehmen, Breadboard auch
5. Arduino mit dem blauen Kabel mit dem Computer verbinden
6. In der Arduino IDE mit Werkzeuge > Port den richtigen Port auswählen
![](https://pad.ccc-p.org/uploads/upload_05c0c4516abed63761781ac56291fddb.png)
7. Überprüfen, dass bei Board "Arduino Uno" ausgewählt ist

## Setup mBlock (optional)
1. [mBlock dowloaden](https://mblock.makeblock.com/en-us/download/)
2. [installieren.](https://www.mblock.cc/doc/en/part-one-basics/mblock-5-pc.html)
3. mBlock öffnen
4. Sprache auf Deutsch stellen
5. Arduino mit dem blauen Kabel mit dem Computer verbinden
6. Geräte -> hinzufügen -> Arduino Uno

## Start
1. Arduino Software starten
2. Arduino mit dem blauen Kabel mit dem Computer verbinden
3. [Ultraschall](https://www.waycon.de/produkte/ultraschallsensoren/messprinzip-ultraschallsensoren/) Abstandssensor in das Breadboard einstecken
![](https://pad.ccc-p.org/uploads/upload_0c876c2750299d88177136540b52159e.jpg)
Dieser passt sehr gut genau in das Breadboard.
Bis zum Anschlag hineinstecken, auch wenn dies etwas schwer sein könnte:
![](https://pad.ccc-p.org/uploads/upload_fd3ac487eda8f3382f68148390fb5dec.jpg)
4. 4 Jumperkabel raussuchen und den Ultraschallsensor mit dem Arduino verbinden
![](https://pad.ccc-p.org/uploads/upload_7cff6eeba699668f5fcc916863959e96.jpg)
Jetzt geht es ans Verbinden:
Dafür nutzen wir ein Breadboard. Dieses erlaubt es uns, ohne Löten mithilfe von Jumperkabeln die Komponenten zu verbinden. Dafür gibt es zwischen den Löchern intern Leitungen nach folgendem Schema:
![](https://pad.ccc-p.org/uploads/upload_ecb5a4e8eb9cbfe3c46338baae8d5510.png)
![](https://pad.ccc-p.org/uploads/upload_e8b5bde3ec5fd2845f3d0e013c368037.jpg)
Das Kabel also genau in die gleiche Spalte des Breadboards stecken, wie auch die vier Pins des Sensors sind. Insgesamt sieht das dann so aus:
![](https://pad.ccc-p.org/uploads/upload_e60c78b7f54cefbb907f45c89d63e2bd.jpg)
5. Nun verbindet ihr die Kabel mit dem Arduino. Dabei wird VCC mit 5V verbunden, Gnd mit Gnd, Trig mit 7 und Echo mit 6.

![](https://pad.ccc-p.org/uploads/upload_401a8d23a71db41d320148b37907d360.svg)

Folgender Code misst den Abstand und gibt ihn am Computer aus:
6. [Testcode in die IDE kopieren](https://funduino.de/nr-10-entfernung-messen)
Siehe DistanceMeter/


7. Dann diese Datei speichern. Dazu geht ihr unter Datei > Speichern unter und speichert es an einen Ort in eurem Computer an dem ihr das Programm wiederfindet.
8. Nun müsst ihr das Programm auf euren Arduino hochladen. Nutzt dazu den :arrow_right:-Button  in der linken oberen Ecke.
![](https://pad.ccc-p.org/uploads/upload_d42b63648c0b8ed2ab12c1b21022fa6e.png)
9. Super jetzt ist das Programm auf eurem Arduino! Aber wo sehen wir den gemessenen Abstand? Geht dazu unter Werkzeuge > Serieller Monitor
![](https://pad.ccc-p.org/uploads/upload_d644c251f980b855eb32d630b2bf0edf.png)
Jetzt seht ihr jederzeit den aktuell gemessenen Abstand
![](https://pad.ccc-p.org/uploads/upload_ca0b3f4a44448ccc6c04f4688fdebcfb.png)
Hältst du die 1,5m Abstand immer ein?

## Weiterführend
[Wie bediene ich einen Active Buzzer](https://funduino.de/nr-08-toene-erzeugen)
Aber was ist wenn jemand nicht die 1,5m Abstand einhält und uns gefährdet? dann wollen wir einen lauten Signalton von uns geben.
1. Sucht das Element "Active Buzzer" aus dem Karton raus. Auf der Vorderseite könnt ihr eine Übersicht über alle enthaltenen Teile sehen und so sehen, wie dieser Active Buzzer aussieht.
2. Auch diesen müssen wir jetzt mit dem Arduino verbinden. Dazu stecken wir ihn zunächst wieder in das Breadbord und verbinden ihn entsprechend. Dazu nutzen wir wieder Jumperkabel und das Breadboard. ![](https://pad.ccc-p.org/uploads/upload_ed8624839fbe5b61e45d9afb3f201ad4.jpg)
Eine Seite des Buzzers ist mit einem + gekennzeichnet. Diese verbinden wir mit dem Port 9 und die andere mit einem freien GND Port. Der Buzzer muss auch richtig ins Breadboard gesteckt werden und ist hier zur Illustration nur aufgelegt.
3. Um jetzt bei einem bestimmten Abstand einen Ton auszugeben müssen wir unseren Code noch um folgende Zeilen ergänzen:
``` C
if (entfernung < 150){
      tone(9,220);
      delay(1000);
      noTone(9);
    }
```
Da wir unseren Abstand in Centimetern messen schauen wir also, ob der Abstand kleiner als 150cm ist und wenn dem so ist, dann geben wir einen Ton ab.
! Spiele etwas mit der Höhe des Tons und probiere aus, was passiert, wenn du statt der 100 eine 300 eingibst.!

## Abstand merken

Statt jedes mal den Code wieder hochzuladen, wenn wir die Entfernung ändern wollen, ab der ein Ton ertönt, wollen wir jetzt eine gemessene Entfernung speichern. Dazu wollen wir einen Knopf benutzen.

### Aufbau


![](https://pad.ccc-p.org/uploads/upload_e2c5de4d39a1da5d0703b3ac7d258154.svg )

1. Suche im Karton die Tüte mit den Buttons und nimm einen heraus.
2. Stecke den Button in das Breadboard.
3. __!Achtung:__ Der Button muss in der richtigen Richtung gesteckt werden:
![](https://pad.ccc-p.org/uploads/upload_79f1e173a6cbc0c0ad7419ccfcca7787.png =150x)
5. Schließe den Button auf einer Seite an Pin 8 und auf der anderen Seite an GND an.
6. Lade den Code auf den Arduino hoch

Du solltest zunächst keinen Ton hören. Wenn du jetzt etwas vor der Sensor hälst und dabei den Knopf drückst, kannst du einen Abstand einstellen. Wenn du danach etwas dichter an den Sensor hälst, als du vorher eingestellt hast, solltest du einen Ton hören.

### Code

Siehe DistanceAlarm/
