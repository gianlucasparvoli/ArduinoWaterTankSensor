#include <LiquidCrystal.h>            // incluyo la libreria del display lcd
LiquidCrystal lcd(7, 8, 9, 10, 11, 12); //   declaro el pin 7,8,9,10,11,12 como RS, EN, d4, d5, d6, d7


#define echoPin 5 // Echo Pin
#define trigPin 6 // Trigger Pin
#define LEDPin 0 // Onboard LED
#define indicador 13 //LED que indica situacion de poca o nula cantidad de agua

int maximumRange = 200; // Maximum range needed
int minimumRange = 0; // Minimum range needed
long duration, distance,distance1, litro,distance2,distance3,distance4,distance5; // Duration used to calculate distance

void setup() {
   lcd.begin(16, 2);   // declaro que el display utilizado es de 16 caracteres x 2 filas
   Serial.begin (9600);
   pinMode(trigPin, OUTPUT);
   pinMode(echoPin, INPUT);
   pinMode(LEDPin, OUTPUT); // Use LED indicator (if required)
   pinMode(indicador, OUTPUT);
}

void loop() {
  /* The following trigPin/echoPin cycle is used to determine the
   distance of the nearest object by bouncing soundwaves off of it. */ 

 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);

 //Calculate the distance (in cm) based on the speed of sound.
 distance1 = duration/58.2;
   Serial.println(distance1);    Serial.print(" cm ");
 
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);

 //Calculate the distance (in cm) based on the speed of sound.
 distance2 = duration/58.2;
   Serial.println(distance2);    Serial.print(" cm ");

 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);

 //Calculate the distance (in cm) based on the speed of sound.
 distance3 = duration/58.2;
   Serial.println(distance3);    Serial.print(" cm ");

 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);

 //Calculate the distance (in cm) based on the speed of sound.
 distance4 = duration/58.2;
   Serial.println(distance4);    Serial.print(" cm ");

 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);

 //Calculate the distance (in cm) based on the speed of sound.
 distance5 = duration/58.2;
   Serial.println(distance5);    Serial.print(" cm ");

distance = (distance1+distance2+distance3+distance4+distance5)/5;
  Serial.println("Total: "); Serial.print(distance);    Serial.print(" cm ");

 litro  = -8.5*distance+1200; //Conversion de cm a litros. La cuenta cambia segun el tanque
 Serial.println("Total: "); Serial.print(litro);    Serial.print(" lts \n");
 
 if (distance >= maximumRange || distance <= minimumRange){ //if para el serial
   /* Send a negative number to computer and Turn LED ON 
   to indicate "out of range" */
   Serial.println("-1");
   digitalWrite(LEDPin, HIGH); 
 } else {
   /* Send the distance to the computer using Serial protocol, and
   turn LED OFF to indicate successful reading. */
   Serial.print(distance); Serial.print(" cm ; ");
   Serial.print(litro); Serial.print(" lts");
   Serial.println("");
   digitalWrite(LEDPin, LOW); 
 }


  if(distance >= 100 && distance <=120){  //if para el display
  lcd.clear();
  lcd.setCursor(5,1);
  lcd.print("ALERTA");
  lcd.setCursor(7,0);
  lcd.print(" Litros");
  lcd.setCursor(2,0);
  lcd.print(litro);

  digitalWrite(indicador, HIGH); 
  delay(200);
  digitalWrite(indicador, LOW); 
  delay(200);
  
}

 else if(distance >120){
  lcd.clear();
  lcd.setCursor(1,1);
  lcd.print("ALERTA CRITICO");
  lcd.setCursor(7,0);
  lcd.print(" Litros");
  lcd.setCursor(2,0);
  lcd.print(litro);

  digitalWrite(indicador, HIGH); 
   delay(10); 
}

else{
  lcd.clear();
  lcd.setCursor(7,0);
  lcd.print(" Litros");
  lcd.setCursor(2,0);
  lcd.print(litro);
  digitalWrite(indicador, LOW); 
  }



 delay(5000);
}
