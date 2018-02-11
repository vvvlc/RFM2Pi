# RFM2Pi
======

[![Build Status](https://travis-ci.org/openenergymonitor/RFM2Pi.svg?branch=master)](https://travis-ci.org/openenergymonitor/RFM2Pi)

## RFM2Pi full support for RFM69 
- I replaced original RFM2Pi firmware that uses JeeLib with RMF69 library. [Source code](/firmware/RFM69CW_RFM69_Demo_ATmega328/RFM69CW_RFM69_Demo_ATmega328/src/src.ino)
- [Compiled firmware](/firmware/RFM69CW_RFM69_Demo_ATmega328/V13_RFM69CW_RFM69_Demo_ATmega328.cpp.hex)
- [Sample output](/firmware/RFM69CW_RFM69_Demo_ATmega328/V13_FunkyV3_RFM69CW_RFM69_Demo_ATmega328.txt)

### Features
```
[RF69demo.13] @ i0 g0 @ 868 MHz

Available commands:
  <nn> i     - set node ID (standard node ids are 1..30)
  <n> b      - set MHz band (4 = 433, 8 = 868, 9 = 915)
  <nnnn> o   - change frequency offset within the band (default 1600)
               96..3903 is the range supported by the RFM12B
  <nnn> g    - set network group (RFM12 only allows 212, 0 = any)
  <n> c      - set collect mode (advanced, normally 0)
  t          - broadcast max-size test packet, request ack
  l          - show led activity
  ...,<nn> a - send data packet to node <nn>, request ack
  ...,<nn> s - send data packet to node <nn>, no ack
  ...,<nn> r - send ACK reply data packet to node <nn>
  ...,<nn> w - preddefined ACK reply data packet to node <nn>
  <n> q      - set quiet mode (1 = don't report bad packets)
  <n> x      - set reporting format (0: decimal, 1: hex, 2: hex+ascii)
  <nnn> y    - enable signal strength trace mode, default:0 (disabled)
               sample interval <nnn> secs/100 (0.01s-2.5s) eg 10y=0.1s
  <nn> j     - sends local temperatur to node j
             - if j>256 it displays temperatur in 1min time frames
  u          - upload firmware using FOTA/Wireless programming
  m          - dumps registers
  ... n      - set encryption key, consists of 16 numbers, 
             - if less than 16 number provided they are padded by zeros
             - 0n mean disable encryption
             - 1,2,3n -> 1,2,3,0,0,0,0,0,0,0,0,0,0,0,0,0
  <n> p      - promiscuite mode 0 off, 1 on
  v          - display version and configuration
  h          - display help
  123 z      - total power down, needs a reset to start up again
Current configuration:
 @ i0 g0 @ 868 MHz
```
- 1,2,3,0,0,0,0,0,0,0,0,0,0,0,0,0n     command to set an encryption key.
- I have some support for FOTA but it is not streamlied version because I stole some stuff from Wireless programming library.

Current version of firmware is not compatible with latest RFM69, I use a custom version 
https://github.com/vvvlc/RFM69, https://github.com/vvvlc/WirelessProgramming



## RFM12B / RFM69CW to Raspberry Pi board

With the addition of an RFM12Pi expansion board to receive data via wireless from other [OpenEnergyMonitor modules](http://openenergymonitor.org/emon/Modules) such as an emonTx energy and temperature monitoring node or an emonGLCD display. A Raspberry Pi used to forward data to an emoncms sever or/and log data locally to a localy instance of Emoncms server running on the Pi.

# Hardware Design
For hardware designs see https://github.com/openenergymonitor/Hardware/tree/master/RFM2Pi

## Documentation Overview
http://openenergymonitor.org/emon/emonbase/raspberrypi



## Technial Wiki
http://wiki.openenergymonitor.org/index.php?title=RFM12Pi_V2



### The RFM12Pi is sold through the OpenEnergyMonitor shop:
http://shop.openenergymonitor.com/raspberry-pi/
