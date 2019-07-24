#include <iostream>
/*
GROUP 6
Ian Kibandi ENM221-0167/2017
Smith Jilks ENM221-0092/2017
Gideon Felix ENM221-0083/2017
Rodney Osodo ENM221-0091/2017
 */
using namespace std;

float temperature, level_switch;
int thermostat;

void check(float, float);

int main(){
    check(34, 1);
    return 0;
}

void check(float x, float y){
    temperature = x;
    level_switch = y;
    if(level_switch == 0){
        thermostat = 0;
        cout << "Switch OFF" << endl;
    }
    else if ((level_switch == 1) && (temperature < 50)){
        thermostat = 1;
        cout << "Switch ON" << endl;
    }
    else if ((level_switch == 1) && (temperature >= 60)){
        thermostat = 0;
        cout << "Switch OFF" << endl;
    }
    else
    {
        cout << "Thermostat is on" << endl;
    }
    
}