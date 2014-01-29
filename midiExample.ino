void setup(){
  Serial.begin(9600); 
}

void loop(){
  //first read sensor and get a sense of the range of values
  int reading = analogRead(A0);  
  Serial.println(reading);
  

}


//this function is never called
void midiNote(int cmd, int pitch, int vel){ 
  Serial.write(cmd);
  Serial.write(pitch);
  Serial.write(vel);
}
