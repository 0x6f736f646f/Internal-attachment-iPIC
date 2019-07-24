#include <iostream>
/*
GROUP 6
Ian Kibandi ENM221-0167/2017
Smith Jilks ENM221-0092/2017
Gideon Felix ENM221-0083/2017
Rodney Osodo ENM221-0091/2017
 */
using namespace std;

class Operations {
    private:
        float level_sensor, capacity; 
        int red_led, green_led, blue_led;
        /* 
        red_led lights on when its empty
        green_led lights on when its full
        blue_led lights on when it needs to be refilled
        */
    public:
        Operations(float x){
            level_sensor = x;
            capacity = ((level_sensor * 6280)/5);//Checking the water level capacity
        }
        void check_level(){
            if (level_sensor < 0.7962){
                blue_led = 0;
                green_led = 0;
                red_led = 1;
                //Lights on only red led and turns off the others incaed they were on
                cout << "Empty\nCapacity: "<< capacity << endl;
            }
            else if ((level_sensor < 1.5924) && (level_sensor >= 0.7962)){
                green_led = 0;
                red_led = 0;
                blue_led = 1;
                //Lights on only blue led and turns off the others incaed they were on
                cout << "Refill\nCapacity: "<< capacity << endl;
            }
            else if (level_sensor >= 3.5828){
                blue_led = 0;
                red_led = 0;
                green_led = 1;
                //Lights on only green led and turns off the others incaed they were on
                cout << "Full\nCapacity: "<< capacity << endl;
            }
            else
            {
                blue_led = 0;
                red_led = 0;
                green_led = 0;
                //Does not light on any led since the tank is normal
                cout << "Normal\nCapacity: "<< capacity << endl;
            }
               
        }
};

int main(){
    Operations ops(0.4);
    ops.check_level();
    return 0;
}