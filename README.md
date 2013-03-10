ToastFlow
=========

Toaster reflow oven controller.

##Usage

Put boards with solder paste in the oven. Press the red button. When the led switches off you can take the boards out or something.


##About

Schematic is in KiCad. Schematic idea is from [ST app note "MICROCONTROLLER AND TRIACS ON THE 110/240V MAINS"](http://www.datasheetcatalog.org/datasheet/SGSThomsonMicroelectronics/mXxuyw.pdf). [Reflow profile](http://www.actel.com/documents/Solder_Reflow_LeadFree.pdf).

Uses weird temperature sensor. Heats boards to 150 degrees (1.3 kΩ, 3.143V, 41200), keeps there for 1m 10s and heats it up to 220 degrees (1.8 kΩ, 2.75V, 36000) 1m 30s.

| Part      | Value |Pack | Code  |
|-----------|-------|-----|-------|
|Attiny13   |       | SO8 |1704567|
|Temp sensor|       |DO-34|1672407|
|
