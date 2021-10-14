int sw=13;
int outputCLK=11;
int outputDT=12;
int most=1;
int ezelott=1;
int szamlalo=0;


void setup() {
 Serial.begin(9600);
 Serial.println("Encoder kezelo program!");
for(int i=11;i<=13;i++) pinMode(i, INPUT_PULLUP);

}

void loop() {
if (digitalRead(sw)==0) {
  szamlalo=0;
  delay(200);
  Serial.println(szamlalo);
  }

most=digitalRead(outputCLK);
if (most != ezelott)
{
  //Serial.println("Tekerés van!!");
if (digitalRead(outputDT) != most)
{szamlalo++;
szamlalo=constrain(szamlalo,-10,10);
  }
else {
  szamlalo--;
  szamlalo=constrain(szamlalo,-10,10);
  
}
Serial.println(szamlalo);
}

ezelott=most;


/*for(int i=11;i<=13;i++) {
Serial.print(digitalRead(i));
Serial.print("; ");
}
Serial.println("");*/

}
