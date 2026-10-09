# Setup in VSCode mit PlatformIO

1. [Visual Studio Code](https://code.visualstudio.com/) installieren und öffnen.
2. Links in der Seitenleiste auf **Extensions** (`Strg+Shift+X`) klicken, nach **PlatformIO IDE** suchen und installieren. Danach VSCode neu starten und warten, bis PlatformIO fertig initialisiert ist (kann einige Minuten dauern).
3. Auf das PlatformIO-Icon (Ameisenkopf) in der Seitenleiste klicken und unter *PIO Home* auf **Open** → **New Project** wählen.
4. Das Projekt wie folgt anlegen:
    - **Name:** dein Benutzername
    - **Board:** `Arduino Nano ATmega328` (`nanoatmega328`)
    - **Framework:** `Arduino`
    - **Location:** Haken bei *Use default location* entfernen und den Ordner dieses Repositories wählen (oder den Standardordner nutzen und die Repository-Dateien dorthin kopieren).
5. Auf **Finish** klicken und warten, bis PlatformIO die benötigten Toolchains heruntergeladen hat.
6. In der `platformio.ini` sollte jetzt stehen:
    ```ini
    [env:nanoatmega328]
    platform = atmelavr
    board = nanoatmega328
    framework = arduino
    ```
   Die benötigten Libraries (siehe unten) werden über `lib_deps` automatisch installiert.
7. Board per USB anschließen und mit der Statusleiste unten arbeiten:
    - ✔ **Build** – Projekt kompilieren
    - → **Upload** – Programm auf das Board laden
    - 🔌 **Serial Monitor** – serielle Ausgabe anzeigen

# Librarys
Adafruit GFX Library by Adafruit
Adafruit SSD1306
Adafruit BusIO by Adafruit

# Bug fixing:
Wenn der Upload fehlschlägt:
- Serial Monitor Terminals / Serial Plotter schließen
- evtl. andere Programme die den USB Port blockieren schließen
- USB Port wechseln
- Wenn "uploading" im Terminal erscheint -> den RESET Button am Board drücken, sodass der Upload passieren kann.

Falls der falsche Port erscheint:
- Geräte Manager öffnen
- Gerät ein und aus stecken und schauen unter: Anschlüsse (COM& [...]) welcher Anschluss erscheint bzw. verschwindet.
- im Terminal mode eingeben und schauen welcher Port besetzt ist.
- der .ini datei anpassen: upload_port=COM3 
    - für linux upload_port = /dev/ttyUSB*

DHT11 Temperatur und Feuchtigkeit:
https://arduinogetstarted.com/tutorials/arduino-dht11

OLED:
https://learn.adafruit.com/adafruit-gfx-graphics-library/graphics-primitives

I2C arduino:
https://docs.arduino.cc/learn/communication/wire/

Lichtsensor:
https://github.com/claws/BH1750
