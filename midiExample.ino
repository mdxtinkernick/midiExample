void setup(){
  //change serial speed to correct speed for midi
  Serial.begin(31250); 
}

void loop(){
  //map sensor and get a useful range of values
  int reading = analogRead(A0);
  //50 to 500 is the range of values I got with my sensor
  //0 to 12 will cover an octave in semitones
  int betterValue=map(reading, 50, 500, 0, 12);
  //comment out this as it will be sent along with the midi data and mess up things
  //Serial.println(reading);
  
  //betterValue by itself was too low (pitch 0 is very low
  //we need to add an offset to it
  int startNote=50;
  midiNote(0x90, startNote+betterValue, 127);
  delay(10);
  midiNote(0x90, startNote+betterValue, 0);
  delay(10);

  
}


//this function is now called twice each time thorough the loop 
void midiNote(int cmd, int pitch, int vel){ 
  Serial.write(cmd);
  Serial.write(pitch);
  Serial.write(vel);
}
