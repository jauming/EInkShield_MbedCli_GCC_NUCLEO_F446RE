/*
Copyright (c) 2017-2018, E Ink Holdings Inc., All Rights Reserved
SPDX-License-Identifier: LicenseRef-PBL

This file and the related binary are licensed under the Permissive Binary 
License, Version 1.0 (the "License"); you may not use these files except in 
compliance with the License.

You may obtain a copy of the License here: 
LICENSE-permissive-binary-license-1.0.txt and at
https://www.mbed.com/licenses/PBL-1.0

See the License for the specific language governing permissions and limitations 
under the License.
*/
#ifndef EINK_SHIELD_H //EinkShield.h
#define EINK_SHIELD_H

typedef enum {
    EL029TR1,  
    WF102,
	  ED013TC2,
	  ET011TJ2,
} EPD_driver;

class EinkShield {
private:
    DigitalOut bsi  ; //(D7);
    DigitalOut rstn ; //(D6);
    DigitalIn  busyn; //(D5);
    DigitalOut csb  ; //(D10);
    DigitalOut dc   ; //(D2);
    DigitalOut scl  ; //(D13);
    DigitalOut sda  ; //(D11);
       
    EPD_driver driver;
    
    void SPI_Write(unsigned char value);
    
    void W21_WriteCMD(unsigned char command);
    void W21_WriteDATA(unsigned char data);  
          
    void W21_Part_lut_bw(void);    
    void W21_Part_update_setting(void);        
    void W21_Part_image_by_id(unsigned char id);
   
    void W21_Update(void);
     
    void spi_Table(uint8_t *pucTable);
             
    void Load_LUT (unsigned int LUT, unsigned char const *LUT_Value);
    void Load_LUTC(unsigned int LUT, unsigned char const *LUT_Value);
    void Load_LUT2(unsigned int LUT, unsigned char *LUT_Value, unsigned int LUT_Counter);
   
    void spi_9b_init(void);
    void spi_9b_send_9b(unsigned int dat);    
    void spi_9b_send(unsigned int dcx, unsigned char dat);        
                        
    void check_busy_high(void);
    void check_busy_low(void);
    void SPI_COMMAND(unsigned char dat);

    void EInk_Parameter_Initial(void);  
    void EPD_DTM1_Initial(void);
    void Upload_Temperature_LUT(void);
    
public:
    EinkShield(EPD_driver driver,
          PinName bsi_pin,
          PinName rstn_pin,
          PinName busyn_pin,
          PinName csb_pin,
          PinName dc_pin,
          PinName scl_pin,
          PinName sda_pin);
          
    void EPD_Init(void);
    void EPD_Display_KWR(unsigned char const *img_kw, unsigned char const *img_r);
    
    void EPD_Display_KW (unsigned char const *img_kw);                
    void EPD_Display_Red(void); 
    void EPD_Display_Black(void);  
    void EPD_Display_White(void);    
};



#endif
