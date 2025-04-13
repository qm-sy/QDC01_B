#ifndef __POWER_CRL_H_
#define __POWER_CRL_H_

#include "sys.h"
#include "gpio.h"

#define FAN_ON    1
#define FAN_OFF   0


typedef struct 
{
    uint8_t  zero_flag;        //220V输入触发标志位
    uint16_t time_delay;               //移相延时
    uint8_t  ac220_out1_flag;
    uint8_t  ac220_out2_flag;
    uint8_t  ac220_out3_flag;
    uint8_t  sync_flag;
    uint8_t  mode_info;
}AC_DC;

extern AC_DC ac_dc;

void Power_Statu_Init( void );
void led_ctrl( uint8_t on_off );
void ac_220v_crl( uint8_t power_level );

#endif