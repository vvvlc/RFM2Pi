#!/bin/bash

sudo service emonhub stop

avrdude -v -c arduino -p ATMEGA328P -P /dev/ttyAMA0 -b 38400 -U flash:w:firmware/dev/RFM69CW_RF12_Demo_ATmega328_Pulse_DS18B20/compiled.hex

sudo service emonhub start
