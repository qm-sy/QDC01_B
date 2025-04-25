#ifndef __DHT11_H_
#define __DHT11_H_

#include "delay.h"
#include "sys.h"
#include "gpio.h"
#include "communication.h"
#include "ntc.h"

void DHT11_start();
void Read_DHT11(void);   //温湿传感启动

#endif