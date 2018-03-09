//file name=sg90.c  
#include <stdio.h>  
#include <errno.h>  
#include <string.h>  
#include <stdlib.h>  
#include <wiringPi.h>  
#include <softPwm.h>

#define DEBUG

#define RANGE 200    //20MS
#define servo_pin 26
#define infrared1_pin 27
#define infrared2_pin 28
#define infrared3_pin 29

#define STILL 0
#define ROTATE 1

void gpio_init(void);
unsigned char infrared_check(void);
int servo_automate(int mode);
void servo_manual(int degree);
void servo_rotate_period(int time,int servo_state);


int main(int argc, char** argv)
{
	gpio_init();
	delay(1000);
	while(1){
		//softPwmWrite(servo_pin,5);
		//delay(1000);
		//softPwmWrite(servo_pin,25);
		//delay(1000);
		servo_automate(ROTATE);
		delay(500);
	}	
	exit(0);
}

void gpio_init(void)
{
	wiringPiSetup();
	pinMode(infrared1_pin,INPUT);
	pinMode(infrared2_pin,INPUT);
	pinMode(infrared3_pin,INPUT);	
	softPwmCreate(servo_pin,15,RANGE);
}

unsigned char infrared_check(void)
{
	unsigned char infrared_state = 0;
	infrared_state |= digitalRead(infrared1_pin);
	infrared_state |= digitalRead(infrared2_pin)<<1;
	infrared_state |= digitalRead(infrared3_pin)<<2;
#ifdef DEBUG	
	printf("infrared_state: %d \n",infrared_state);
#endif
	return infrared_state;
}	

int servo_automate(int mode)
{
	unsigned char infrared_state = 0;
	unsigned char servo_state = 0;
	infrared_state = infrared_check();
	switch(infrared_state){
		case 0x01:
		case 0x03:
		case 0x05:
		case 0x07:
			softPwmWrite(servo_pin,5);
			servo_state = 1;
			break;
		case 0x02:
		case 0x06:
			softPwmWrite(servo_pin,15);
			servo_state = 2;
			break;
		case 0x04:
			softPwmWrite(servo_pin,25);
			servo_state = 3;
			break;
		default:
			break;
	}
#ifdef DEBUG
	printf("servo_state: %d \n",servo_state);
#endif
	if(mode == 1){
		servo_rotate_period(5,servo_state);
	}
	return servo_state;
}

void servo_manual(int degree)
{
	int servo_degree = 0;
	servo_degree = degree*20/180+5;
	if(servo_degree < 5) servo_degree = 5;
	else if(servo_degree > 25) servo_degree = 25;
	softPwmWrite(servo_pin,servo_degree);
#ifdef DEBUG	
	printf("servo_degree: %d \n",servo_degree);
#endif	
	softPwmWrite(servo_pin,servo_degree);
	
}

void servo_rotate_period(int time,int servo_state)
{
	static int degree = 0;
	static int rotate_flag = 0;
	int servo_degree = 0;
	delay(time);
	if(servo_state == 0){
		if((rotate_flag == 0) && (degree < 180)){
			degree++;
		}
		else if(rotate_flag == 1 && degree >0){
			degree--;
		}
		else if(rotate_flag == 0 && degree == 180){
			rotate_flag = 1;
		}
		else if(rotate_flag == 1 && degree == 0){
			rotate_flag = 0;
		}
		servo_degree = degree*20/180+5; 
		softPwmWrite(servo_pin,servo_degree);	
	}
	else if(servo_state == 1){
		degree = 0;
		servo_degree = 5;
		softPwmWrite(servo_pin,servo_degree);
	}
	else if(servo_state == 2){
		degree = 90;
		servo_degree = 15;
		softPwmWrite(servo_pin,servo_degree);
	}
	else if(servo_state == 3){
		degree = 180;
		servo_degree = 25;
		softPwmWrite(servo_pin,servo_degree);
	}
}



