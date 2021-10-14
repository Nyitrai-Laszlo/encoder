int sw=13;
int outputCLK=11;
int outputDT=12;
int most=1;
int ezelott=1;
int szamlalo=0;
int led=3;
int fenyero=0;
void setup() {
 Serial.begin(9600);
 Serial.println("Encoder kezelo program!");
for(int i=11;i<=13;i++) pinMode(i, INPUT_PULLUP);
pinMode (led, OUTPUT);
//digitalWrite(led, 1);
}

void loop() {
if (digitalRead(sw)==0) {
  szamlalo=50;
  }

most=digitalRead(outputCLK);
if (most != ezelott)
{
  //Serial.println("Tekerés van!!");
if (digitalRead(outputDT) != most)
{szamlalo=szamlalo-10;
szamlalo=constrain(szamlalo,0,100);
Serial.print("A fényerő: ");
Serial.print(szamlalo);
Serial.println("%");
  }
else {
  szamlalo=szamlalo+10;}
  szamlalo=constrain(szamlalo,0,100);
  Serial.print("A fényerő: ");
Serial.print(szamlalo);
Serial.println("%");
  

//Serial.println(szamlalo);
}

ezelott=most;
fenyero=map(szamlalo,0,100,0,255);
//Serial.println
analogWrite(led, fenyero);


/*for(int i=11;i<=13;i++) {
Serial.print(digitalRead(i));
Serial.print("; ");
}
Serial.println("");*/

}
