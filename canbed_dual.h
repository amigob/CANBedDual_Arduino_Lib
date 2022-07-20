// aruino library for CANBed Dual

#include <Wire.h>
#include <Arduino.h>

#define I2C_ADDR    0X41
#define CANI2C      Wire1
#define DELAY_TIME  0

class CANBedDual
{
    private:
    
    unsigned long timerDelay = 0;
    int canNum = 0;
    
    unsigned char canconfig[48];
    
    private:
    
    unsigned long char2long(unsigned char *str);
    void long2char(unsigned long __t, unsigned char *str);
    void makeCanConfig();
    void sendConfig();
    public:
    
    CANBedDual(int num)
    {
        canNum = num;
    }
    
    void init(unsigned long speed);
    void initFD(unsigned long speed20, unsigned long speedfd);
    
    void initMaskFilt(unsigned char num, unsigned char ext, unsigned long mask, unsigned long filt);
    
    void send(unsigned long id, unsigned char ext, unsigned char rtr, unsigned char fd, unsigned char len, unsigned char *dta);
    byte checkRecv();
    byte read(unsigned long *id, int *ext, int *rtr, int *fd, int *len, unsigned char *str);
};