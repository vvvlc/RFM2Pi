
void onPulse() {
  
  if ( (millis() - pulsedebouncetime) > min_pulsewidth) {
    pulsedebouncetime=millis();
    
    lastpulsetime = pulsetime;
    pulsetime = micros();
    
    rfm2pi.pulsecount++;
    rfm2pi.pulsepower = int((3600000000.0 / (pulsetime - lastpulsetime))/pulses_per_wh);
    
  }
    
  // digitalWrite(LED, HIGH); 
  // delay(2); 
  // digitalWrite(LED, LOW);
}

//Send emonPi data to Pi serial /dev/ttyAMA0 using struct JeeLabs RF12 packet structure
void send_as_rf12_demo_packet()   
{
  byte binarray[sizeof(rfm2pi)];
  memcpy(binarray, &rfm2pi, sizeof(rfm2pi));
  
  Serial.print("OK ");
  Serial.print(pulse_nodeid);
  for (byte i = 0; i < sizeof(binarray); i++) {
    Serial.print(' ');
    Serial.print(binarray[i]);
  }
  Serial.print(" (-0)");
  Serial.println();
  
  delay(10);
}
