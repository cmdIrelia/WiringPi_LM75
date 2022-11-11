#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <iostream>
#include <unistd.h>
#include <time.h>
#include <string>

using namespace std;

string getTime()
{
    time_t timep;
    time (&timep);
    char tmp[64];
    strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S",localtime(&timep));
    return tmp;
}

int InitLM75(const int i2cAddress)
{
    int fd = 0;
    // 初始化I2C设备
    if ((fd = wiringPiI2CSetup (i2cAddress)) < 0)
    {
        cout<<"I2C init failed."<<endl;
        return fd ;
    }
    return fd ;
}

float GetLM75Temperature(const int fd)
{
    unsigned short sdata = 0;
    sdata = wiringPiI2CReadReg16(fd, 0x00);
    sdata = ((sdata>>8)|(sdata<<8));
    short process_value = sdata;
    int final_temperature_H = (process_value>>8);
    float final_temperature_L =((short) (process_value&0xff))/255.f;
    return final_temperature_H + final_temperature_L;
}

int main(int argc, char *argv [])
{

    wiringPiSetup();
    int fd = 0;
    fd = InitLM75(0x48);
    while(1)
    {
        string time_string = getTime();
        cout<<time_string<<"  "<<GetLM75Temperature(fd)<<endl;
        sleep(5);
    }
    return 0 ;
}

