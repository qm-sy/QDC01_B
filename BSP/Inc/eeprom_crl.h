#ifndef __EEPROM_CRL_H_
#define __EEPROM_CRL_H_

#include "eeprom.h"
#include "sys.h"
#include "power_crl.h"
#include "ntc.h"
#include "stdio.h"

#define PWM_ADDR              0x0000
#define LED_ADDR              0x0001
#define AC220_ADDR            0x0002
#define SYNC_ADDR             0X0003  
#define MODE_ADDR             0X0004  
#define TEMP_ALARM            0X0005

#define EEPROM_STATU_JUDGE    0X0010         

typedef struct 
{
    uint8_t  pwm_info;
    uint8_t  led_info;         
    uint8_t  ac220_info;   
    uint8_t  sync_info;
    uint8_t  mode_info;     
    uint8_t  temp_alarm_value;        
}EEPROM_INFO;

extern EEPROM_INFO eeprom;

void eeprom_statu_judge( void );
void eeprom_data_record( void );
void eeprom_data_init( void );

#endif