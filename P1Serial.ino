void setup() {
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  digitalWrite(13,LOW);
}

void loop() {
  if(Serial.available()){
      const int encendido = Serial.parseInt();
      if(encendido == 1){
        digitalWrite(13,HIGH);
      }else{
        digitalWrite(13,LOW);
      }
    }

}
