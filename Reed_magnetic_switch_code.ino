int sensor =5;
int led=13;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sensor,INPUT);
  pinMode(led,OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
  bool value =digitalRead(sensor);
  Serial.println(value);
  if(value==1){
    digitalWrite(led,HIGH);
    Serial.println("LED on");

  }else{
    digitalWrite(led,LOW);
  }

}
