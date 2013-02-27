ToastFlow
=========

Toaster reflow oven controller.

##Usage

Put boards with solder paste in the oven. Press the red button. When the led switches off you can take the boards out or something.


##About

Schematic is in KiCad. Schematic idea is from [ST app note "MICROCONTROLLER AND TRIACS ON THE 110/240V MAINS"](http://www.datasheetcatalog.org/datasheet/SGSThomsonMicroelectronics/mXxuyw.pdf). [Reflow profile](http://www.actel.com/documents/Solder_Reflow_LeadFree.pdf).

Uses 100kΩ thermistor. Heats boards to 150 degrees (1.3 kΩ), keeps there for 1m 10s and heats it up to 220 degrees (300 Ω) 1m 30s. Then waits until it has cooled down to 50 degrees (32 kΩ).

| Part     | Value | Pack | Code  |
|----------|-------|------|-------|
| Attiny13 |       | SO8  |1704567|
| Thermistor|      | 2.8mm|1672407|