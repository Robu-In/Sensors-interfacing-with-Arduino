int pin = 7;
int pin1 =13;
int tapstatus;

void setup() {
  // put your setup code here, to run once:
  pinMode(pin,INPUT);
  pinMode(pin1,OUTPUT);
  
  Serial.begin(9600);


}

void loop() {
  // put your main code here, to run repeatedly:
  tapstatus=digitalRead(pin);
  if(tapstatus==1){
    digitalWrite(pin1,HIGH);
    Serial.println("Knock detected");
    delay(1000);
    digitalWrite(pin1,LOW);
  }

}
