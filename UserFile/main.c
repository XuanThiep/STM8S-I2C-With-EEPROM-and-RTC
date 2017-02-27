#include "stm8s.h"
#include "mystm8sxxx.h"

/*		MCU STM8S207C8
 *      SDA	PE2
 *      SCL	PE1
 *      FT24C256A: A1=A2=A3=0V;
 */


#define AT24C32_ADD			0x50
#define DS1307_ADD			0x68

uint8_t write_data[200]={'A','R','M','C','O','R','E','T','E','X','M','4','S','T','M','8','I','2','C','.'};
uint8_t receive_data[200];

uint8_t BCD_2_DEC(uint8_t data);
uint8_t DEC_2_BCD(uint8_t data);
uint8_t index=1;
void main(void)
{

	clk_config_16MHz_hse();
	delay_using_timer4_init();

	GPIO_Init(GPIOC,GPIO_PIN_3,GPIO_MODE_OUT_PP_HIGH_FAST);

	i2c_master_init();

	//	for(uint8_t i=0;i<200;i++)
	//	{
	//		write_data[i]='9';
	//		receive_data[i]=0;
	//	}
	//	i2c_mem_write_arr(AT24C32_ADD<<1,0x00,I2C_MEMORY_ADDRESS_SIZE_16BIT,write_data,20);
	//	i2c_mem_write_arr(AT24C32_ADD<<1,32,I2C_MEMORY_ADDRESS_SIZE_16BIT,write_data,32);
	//	i2c_mem_write_arr(AT24C32_ADD<<1,64,I2C_MEMORY_ADDRESS_SIZE_16BIT,write_data,32);
	//	i2c_mem_write_arr(AT24C32_ADD<<1,96,I2C_MEMORY_ADDRESS_SIZE_16BIT,write_data,32);
	//	i2c_mem_write_arr(AT24C32_ADD<<1,128,I2C_MEMORY_ADDRESS_SIZE_16BIT,write_data,32);
	//	i2c_mem_write_arr(AT24C32_ADD<<1,160,I2C_MEMORY_ADDRESS_SIZE_16BIT,write_data,32);
	//	i2c_mem_write_arr(AT24C32_ADD<<1,192,I2C_MEMORY_ADDRESS_SIZE_16BIT,write_data,32);
//		write_data[0]=DEC_2_BCD(0);
//		write_data[1]=DEC_2_BCD(10);
//		write_data[2]=DEC_2_BCD(21);
//		write_data[3]=DEC_2_BCD(7);
//		write_data[4]=DEC_2_BCD(4);
//		write_data[5]=DEC_2_BCD(2);
//		write_data[6]=DEC_2_BCD(17);
//		i2c_mem_write_arr(DS1307_ADD<<1,0,I2C_MEMORY_ADDRESS_SIZE_8BIT,write_data,7);
	while (1)
	{
		//i2c_mem_read_arr(AT24C32_ADD<<1,0,I2C_MEMORY_ADDRESS_SIZE_16BIT,receive_data,20);
                delay_ms(500);
                index++;
		i2c_mem_read_arr(DS1307_ADD<<1,0x00,I2C_MEMORY_ADDRESS_SIZE_8BIT,receive_data,7);
		GPIO_WriteReverse(GPIOC,GPIO_PIN_3);
		//delay_ms(500);
	}
}



uint8_t BCD_2_DEC(uint8_t data)
{
	return (data>>4)*10+(data&0x0f);
}
uint8_t DEC_2_BCD(uint8_t data)
{
	return ((data/10)<<4)|(data%10);
}








#ifdef USE_FULL_ASSERT

/**
 * @brief  Reports the name of the source file and the source line number
 *   where the assert_param error has occurred.
 * @param file: pointer to the source file name
 * @param line: assert_param error line source number
 * @retval : None
 */
void assert_failed(u8* file, u32 line)
{ 
	/* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

	/* Infinite loop */
	while (1)
	{
	}
}
#endif


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
