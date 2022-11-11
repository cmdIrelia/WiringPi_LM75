#include <iostream>
#include <wiringPi.h>

#define LED_PIN (2)

using namespace std;


int main (void)
{
    wiringPiSetup();
    cout<<"wiringPi init done.\n";


    pinMode (LED_PIN, OUTPUT) ;
    for (;;)
    {
        cout<<digitalRead(LED_PIN)<<endl;
        digitalWrite (LED_PIN, 1-digitalRead(LED_PIN));
        delay (1000);
    }
    return 0 ;
}

