/*
GROUP 6
Smith Jilks ENM221-0092/2017
Ian Kibandi ENM221-0167/2017
Gideon Felix ENM221-0083/2017
Rodney Osodo ENM221-0091/2017
 */

float sensorValue = 0, capacity = 0;  //Variable to store the value from the sensor
int red_led_pin = 10, green_led_pin=11, blue_led_pin=12, sensorPin = A0;  //Pins for leds
int heater = 13, temperature_pin = 4, level_switch_pin = 3, temperature, level_switch;

void setup() {
  // put your setup code here, to run once:
  pinMode(red_led_pin, OUTPUT);
  pinMode(green_led_pin, OUTPUT);
  pinMode(blue_led_pin, OUTPUT);
  pinMode(sensorPin, INPUT);
  pinMode(temperature_pin, INPUT);
  pinMode(level_switch_pin, INPUT);
  pinMode(heater, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(sensorPin);//Read the value from the sensor
  capacity = ((sensorValue * 6280)/5);
  sensorValue = (sensorValue * 5)/1024;
  temperature = digitalRead(temperature_pin);
  level_switch = digitalRead(level_switch_pin);
  Serial.println(temperature);
  Serial.println(sensorValue);
  if (sensorValue < 0.7962){
        digitalWrite(blue_led_pin, LOW);
        digitalWrite(red_led_pin, LOW);
        digitalWrite(green_led_pin, LOW);
        digitalWrite(red_led_pin, HIGH);//Turn on the red led pin on
    }
    else if ((sensorValue < 1.5924) && (sensorValue >= 0.7962)){
        digitalWrite(blue_led_pin, LOW);
        digitalWrite(red_led_pin, LOW);
        digitalWrite(green_led_pin, LOW);
        digitalWrite(blue_led_pin, HIGH);//Turn on the blue led pin on
    }
    else if ((sensorValue >= 3.5828)){
        digitalWrite(blue_led_pin, LOW);
        digitalWrite(red_led_pin, LOW);
        digitalWrite(green_led_pin, LOW);
        digitalWrite(green_led_pin, HIGH);//Turn on the green led pin on
    }
    else
    {
        digitalWrite(blue_led_pin, LOW);
        digitalWrite(red_led_pin, LOW);
        digitalWrite(green_led_pin, LOW);
    }
    if(level_switch == LOW){
      digitalWrite(heater, LOW);
      Serial.print("Switch OFF");
    }
    else if ((level_switch == HIGH) && (temperature == LOW)){
      digitalWrite(heater, HIGH);
      Serial.print("Switch ON");
    }
    else if ((level_switch == HIGH) && (temperature == HIGH)){
      digitalWrite(heater, LOW);
      Serial.print("Switch OFF");
    }
    else
    {
      Serial.print("Thermostat is on");
    }
}
