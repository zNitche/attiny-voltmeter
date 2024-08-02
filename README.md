# attiny-voltmeter
measuring voltage using attiny13 and attiny85

### Foreword
ToDo

### Attiny13 setup
For this little buddy I used Arduino IDE v2 with following hardware package

```
https://github.com/MCUdude/MicroCore (version 2.4.0)
```

Installed by putting 
```
https://mcudude.github.io/MicroCore/package_MCUdude_MicroCore_index.json
```

to `Additional Boards Manager URLs` in the IDE settings

#### Uploading code
In order to upload code to our microcontroller I gonna use USBasp ISP programmer


#### Serial monitor setup
Package from MCUdude comes with built in support for uart operations (<3) all we need is USB <---> UART converter (for example `PL2303`) and proper connection\

##### Wiring
| Converter  | Attiny13 |
| ---------- | -------- |
| RX         |     PB0  |
| TX         |     PB1  |

##### Baund rate
For this project I'm using `1.2 MHz` internal oscilator for which proper serial baundrate is `19200`

#### Setting fuses
After changing properties in `Tools` section, don't forget to save microcontroller fuses by `Burn Bootloader`.

#### Hello World
Alright with everything in place we can verify is everything is working as correctly.

1. Put following code into sketch

```
void setup() {}

void loop() {
  while (true) {
    Serial.println("Hello world");
    delay(2000);
  }
}
```

2. Upload using Programmer
```
Ctrl + Shift + U
```

And if you are the lucky one, you should see `Hello World` printing every 2 seconds. 

### Permissions error with USB persmissions on Linux
If you encounter permission error while using USBasp programmer:

1. Create rule file
```
touch /etc/udev/rules.d/99-usbasp.rules
```

2. put following content into rule file
```
SUBSYSTEM=="usb", ATTRS{idVendor}=="16c0", ATTRS{idProduct}=="05dc", MODE="0666"
```