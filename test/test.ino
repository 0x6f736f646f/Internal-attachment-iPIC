/*
GROUP 6
Smith Jilks ENM221-0092/2017
Ian Kibandi ENM221-0167/2017
Gideon Felix ENM221-0083/2017
Rodney Osodo ENM221-0091/2017
 */

int heater = 13, temperature_pin = 3, level_switch_pin = 4, temperature, level_switch;

void setup() {
  pinMode(temperature_pin, INPUT);
  pinMode(level_switch_pin, INPUT);
  pinMode(heater, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  temperature = digitalRead(temperature_pin);
  level_switch = digitalRead(level_switch_pin);
  Serial.println(temperature);
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
      Serial.print(F("Thermostat is on"));
    }
}
