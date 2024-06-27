const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 11;
const int ledPin = 12;
long duration;
int distance;
int safetyDistance;
void setup() {
Serial.begin(9600);
// pinMode(13,OUTPUT);
pinMode(11,OUTPUT);
pinMode(5,INPUT);
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(buzzer, OUTPUT);
pinMode(ledPin, OUTPUT);
Serial.begin(9600); // Starts the serial communication
}
void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
safetyDistance = distance;
if (safetyDistance <= 20) // You can change safe distance from here changing value Ex. 20 , 40 , 60 , 80 , 100, all in cm
{
digitalWrite(buzzer, HIGH);
digitalWrite(ledPin, HIGH);
}
else{
digitalWrite(buzzer, LOW);
digitalWrite(ledPin, LOW);
}
long s1=digitalRead(5);
Serial.println(s1);
if(s1==LOW)
{
delay(1000);
// digitalWrite(13,HIGH); //beeps the buzzer.
// delay(1000);
digitalWrite(11,HIGH);
delay(5000);
}
else{
delay(500);
digitalWrite(13,LOW);
digitalWrite(11,LOW);
}
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
}