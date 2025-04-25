#ifndef __POWER_CRL_H_
#define __POWER_CRL_H_

#include "sys.h"
#include "gpio.h"
#include "ntc.h"
#include "eeprom_crl.h"
#include "dht11.h"

#define FAN_ON    1
#define FAN_OFF   0

typedef struct 
{
    uint8_t  zero_flag;        //220V输入触发标志位
    uint16_t time_delay;               //移相延时
    uint8_t  ac220_out1_enable;
    uint8_t  ac220_out2_enable;
    uint8_t  ac220_out3_enable;
    uint8_t  ac220_out1_temp_allow;
    uint8_t  ac220_out2_temp_allow;
    uint8_t  ac220_out3_temp_allow;
    uint8_t  sync_flag;
    uint8_t  mode_info;

    uint8_t signal_in_flag;
    uint8_t ac220_flag;

}AC_DC;

typedef struct 
{
    uint8_t  gonglv_cnt;        //220V输入触发标志位
    uint8_t  gonglv_s;               //移相延时
    uint8_t  gonglv_min;
    uint16_t gonglv_h;
    uint8_t  gonglv_memory_flag;
}GONGLV;

extern AC_DC ac_dc;
extern GONGLV gonglv;

void Power_Statu_Init( void );
void power_time_Init( void );
void led_ctrl( uint8_t on_off );
void ac_220v_crl( uint8_t power_level );
void sync_ctrl( void );
void temp_scan( void );
void fan_ctrl( uint8_t level );
void mode_ctrl( uint8_t mode_num );

#endif