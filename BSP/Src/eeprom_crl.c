#include "eeprom_crl.h"

EEPROM_INFO eeprom;

/**
 * @brief	eeprom状态判定，是否写入过
 *
 * @param   
 *
 * @return  void
**/
void eeprom_statu_judge( void )
{
    uint8_t eeprom_statu_flag;

    eeprom_statu_flag = ISP_Read(EEPROM_STATU_JUDGE);
    //printf("The value of eeprom_statu_flag is 0x%02x \r\n",(int)eeprom_statu_flag);
    if( eeprom_statu_flag == 0xFF)
    {
        eeprom.pwm_info          = 0x03;          // 0000 0011  pwm默认开，3档风速
        eeprom.led_info          = 0x01;          // 0000 0001  led默认开
        eeprom.ac220_info        = 0x07;          // 0000 0111  220V输出默认三路使能
        eeprom.sync_info         = 0x00;          // 0000 0000  同步模式默认关闭
        eeprom.mode_info         = 0x02;          // 0000 0010  工作模式默认普通
        eeprom.temp_alarm_value  = 0x50;          // NTC1 alarm value 默认80℃

        eeprom_data_record(); 
    }
    eeprom_data_init();    
}

/**
 * @brief	eeprom 数据写入
 *
 * @param   
 *
 * @return  void
**/
void eeprom_data_record( void )
{
    ISP_Earse(0x0000);

    ISP_Write(PWM_ADDR,eeprom.pwm_info);
    ISP_Write(LED_ADDR,eeprom.led_info);
    ISP_Write(AC220_ADDR,eeprom.ac220_info);
    ISP_Write(SYNC_ADDR,eeprom.sync_info);
    ISP_Write(MODE_ADDR,eeprom.mode_info);
    ISP_Write(TEMP_ALARM,eeprom.temp_alarm_value);

    ISP_Write(EEPROM_STATU_JUDGE,0x58);

    // printf("The value of 0 is : 0x%02x \r\n",(int)eeprom.pwm_info);
    // printf("The value of 1 is : 0x%02x \r\n",(int)eeprom.led_info);
    // printf("The value of 2 is : 0x%02x \r\n",(int)eeprom.ac220_info);
    // printf("The value of 3 is : 0x%02x \r\n",(int)eeprom.temp_alarm_value1);
    // printf("The value of 4 is : 0x%02x \r\n",(int)eeprom.temp_alarm_value2);
    // printf("The value of 5 is : 0x%02x \r\n",(int)eeprom.temp_alarm_value3);
}

/**
 * @brief	eeprom 数据初始化
 *
 * @param   
 *
 * @return  void
**/
void eeprom_data_init( void )
{
    /*    PWM风速初始化    */
    eeprom.pwm_info = ISP_Read(PWM_ADDR);

    PWMB_CCR7 = eeprom.pwm_info * 184;

    /*    LED开关状态初始化    */
    eeprom.led_info = ISP_Read(LED_ADDR);

    led_ctrl(eeprom.led_info );

    /*    三路220V输出使能初始化    */
    eeprom.ac220_info = ISP_Read(AC220_ADDR);

    ac_dc.ac220_out1_flag = ((eeprom.ac220_info) & 0x01);
    ac_dc.ac220_out2_flag = ((eeprom.ac220_info >> 1) & 0x01);
    ac_dc.ac220_out3_flag = ((eeprom.ac220_info >> 2) & 0x01);

    /*    同步状态初始化    */
    eeprom.sync_info = ISP_Read(SYNC_ADDR);

    ac_dc.sync_flag = eeprom.sync_info;

    /*    工作模式初始化    */
    eeprom.mode_info = ISP_Read(MODE_ADDR);

    ac_dc.mode_info  = eeprom.mode_info;

    /*    报警温度初始化    */
    eeprom.temp_alarm_value = ISP_Read(TEMP_ALARM);

    temp.temp_alarm_value = eeprom.temp_alarm_value;
}
