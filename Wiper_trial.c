#include<stdio.h>
#include<stdlib.h>

#define LOW 1
#define MEDIUM 2
#define HIGH 3
//#include"Wiper_functions.h"

int Battery_check(int level);
int Auto(int RS_val);
int Manual(int Wiper_Off_M,int Input);
void PWM(int pwm);

int main()
{
    int BAT_LEVEL,Light,RAIN_SENSE_VAL,MODE,WiperOff,Manual_In,PWM_signal;
    printf("BATTERY STATUS\n");
    scanf("%d",&BAT_LEVEL);
    Light=Battery_check(BAT_LEVEL);
    if(Light==1)
    {
        printf("*****RED LED*****\nBattery Low. Wiper cannot be turned on\n");
        exit(0);
    }
    else
    {
        printf("Mode Switch Value\n");
        scanf("%d",&MODE);
        if(MODE==1)
        {
            printf("Rain sense value\n");
            scanf("%d",&RAIN_SENSE_VAL);
            PWM_signal=Auto(RAIN_SENSE_VAL);
        }
        else
        {
            printf("Wiper Off button\n");
            scanf("%d",&WiperOff);
            if(WiperOff==1)
               {
                  printf("WIPER TURNED OFF MANUALLY\n");
                  exit(0);
               }
            printf("Manual input\n");
            scanf("%d",&Manual_In);
            PWM_signal=Manual(WiperOff,Manual_In);
        }
        PWM(PWM_signal);
    }
}

void PWM(int pwm)
{
    switch(pwm)
    {
        case 0:printf("0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n");break;
        case 1:printf("1 1 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n");break;
        case 2:printf("1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0 0\n");break;
        case 3:printf("1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1\n");break;
        default:printf("* * * * * * * * * * * * * * * * * * * *\n");break;
    }

}


int Manual(int Wiper_Off_M,int Input)
{
    int PWM2;

    //else
    {
        if(Input==LOW)
            PWM2=1;
        else if(Input==MEDIUM)
            PWM2=2;
        else if(Input==HIGH)
            PWM2=3;
    }
    return PWM2;
}

int Auto(int RS_val)
{
    int PWM1;
    if(RS_val>=0&&RS_val<50)
        PWM1=0;
    else if(RS_val>=50&&RS_val<250)
        PWM1=1;
    else if(RS_val>=250&&RS_val<1000)
        PWM1=2;
    else
        PWM1=3;
    return PWM1;
}

int Battery_check(int level)
{
    int LED;
    if(level>=3)
        LED=0;
    else
        LED=1;
    return LED;
}
