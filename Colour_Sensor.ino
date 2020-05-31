#define S0 2
#define S1 3
#define S2 4
#define S3 7
#define sensorOut 5

#define ledR 12
#define ledY 8

int frequency = 0;
int color=0;

void setup() {
  // put your setup code here, to run once:
pinMode(S0,OUTPUT);
pinMode(S1,OUTPUT);
pinMode(S2,OUTPUT);
pinMode(S3,OUTPUT);
pinMode(sensorOut,INPUT);
pinMode(ledR,OUTPUT);
pinMode(ledY,OUTPUT);

digitalWrite(S0,HIGH);
digitalWrite(S1,LOW);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
color = readColor();
  delay(10); //10
}

// Custom Function - readColor()
int readColor() {
  // Setting red filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  int R = frequency;
  // Printing the value on the serial monitor
  Serial.print("R= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.print("  ");
  delay(50);
  // Setting Green filtered photodiodes to be read
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  int G = frequency;
  // Printing the value on the serial monitor
  Serial.print("G= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.print("  ");
  delay(50);
  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  int B = frequency;
  // Printing the value on the serial monitor
  Serial.print("B= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.println("  ");
  delay(50);
  if(R<75 & R>45 & G<210 & G>128 & B<170 & B>110){
    color = 1; // Red
    Serial.println("Red");
    digitalWrite(ledR,HIGH);
    delay(200);
    digitalWrite(ledR,LOW);
  }
  if(R<90 & R>70 & G<225 & G>195 & B<170 & B>110){
    color = 1; // Red
    Serial.println("Red");
    digitalWrite(ledR,HIGH);
    delay(200);
    digitalWrite(ledR,LOW);
  }
  
  /*if(G<55 & G>43 & B<47 &B>35){
    color = 2; // Orange
    Serial.println("Orange");
  }*/
  if(R<93 & R>61 & G<73 & G>40 & B<100 & B>65){
    color = 3; // Green
    Serial.println("Green");
  }
  if(R<35 & R>15 & G<48 & G>30 & B<66 & B>50){
    color = 4; // Yellow
    Serial.println("Yellow");
     digitalWrite(ledY,HIGH);
    delay(200);
    digitalWrite(ledY,LOW);
  }
  if(R<70 & R>40 & G<100 & G>70 & B<125 & B>88){
    color = 4; // Yellow
    Serial.println("Yellow");
     digitalWrite(ledY,HIGH);
    delay(200);
    digitalWrite(ledY,LOW);
  }
  /*if(R<56 & R>46 & G<65 & G>55){
    color = 5; // Brown
    Serial.println("Brown");
  }*/
  if (G<83 & G>63 & B<55 &B>35 & R<160 & R>110){//G<58 & G>45 & B<40 &B>26
    color = 6; // Blue
    Serial.println("Blue");
    
    delay(200);
    
  }
  if (G<143 & G>95 & B<83 &B>55 & R<270 & R>170){//G<58 & G>45 & B<40 &B>26
    color = 6; // Blue
    Serial.println("Blue");
    
    delay(200);
    
  }
  return color;  
}
