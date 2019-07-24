/*
GROUP 6
Smith Jilks ENM221-0092/2017
Ian Kibandi ENM221-0167/2017
Gideon Felix ENM221-0083/2017
Rodney Osodo ENM221-0091/2017
 */

int sensorPin = A0; //select the input pin for the level sensor
float sensorValue = 0, capacity = 0;  //Variable to store the value from the sensor
int red_led_pin = 10, green_led_pin=11, blue_led_pin=12;  //Pins for leds
/* 
red_led lights on when its empty
green_led lights on when its full
blue_led lights on when it needs to be refilled
*/
void setup() {
  // put your setup code here, to run once:
  pinMode(red_led_pin, OUTPUT);
  pinMode(green_led_pin, OUTPUT);
  pinMode(blue_led_pin, OUTPUT);
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(sensorPin);//Read the value from the sensor
  capacity = ((sensorValue * 6280)/5);
  sensorValue = (sensorValue * 5)/1024;
  Serial.println(sensorValue);
  if (sensorValue < 0.7962){
        digitalWrite(blue_led_pin, LOW);
        digitalWrite(red_led_pin, LOW);
        digitalWrite(green_led_pin, LOW);
        digitalWrite(red_led_pin, HIGH);//Turn on the red led pin on
        //Lights on only red led and turns off the others incaed they were on
        Serial.print(("Normal Capacity: ") + String(capacity, 2));
    }
    else if ((sensorValue < 1.5924) && (sensorValue >= 0.7962)){
        digitalWrite(blue_led_pin, LOW);
        digitalWrite(red_led_pin, LOW);
        digitalWrite(green_led_pin, LOW);
        digitalWrite(blue_led_pin, HIGH);//Turn on the blue led pin on
        //Lights on only blue led and turns off the others incaed they were on
        Serial.print(("Normal Capacity: ") + String(capacity, 2));
    }
    else if ((sensorValue >= 3.5828)){
        digitalWrite(blue_led_pin, LOW);
        digitalWrite(red_led_pin, LOW);
        digitalWrite(green_led_pin, LOW);
        digitalWrite(green_led_pin, HIGH);//Turn on the green led pin on
        //Lights on only green led and turns off the others incaed they were on
        Serial.print(("Normal Capacity: ") + String(capacity, 2));
    }
    else
    {
        digitalWrite(blue_led_pin, LOW);
        digitalWrite(red_led_pin, LOW);
        digitalWrite(green_led_pin, LOW);
        //Does not light on any led since the tank is normal
        Serial.print(("Normal Capacity: ") + String(capacity, 2));
    }
}
