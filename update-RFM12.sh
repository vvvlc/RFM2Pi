#!/bin/bash

sudo service emonhub stop

avrdude -v -c arduino -p ATMEGA328P -P /dev/ttyAMA0 -b 38400 -U flash:w:firmware/RFM69CW_RF_Demo_ATmega328/RFM12_Demo_ATmega328.cpp.hex

sudo service emonhub start
