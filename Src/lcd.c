#include "lcd.h"


void clockTime(int x)//?????????? ????? ????? ???????
{
	switch(x)
	{
		case 0:
		{
			Lcd_write_str("0");
			break;
		}
		case 1:
		{
			Lcd_write_str("1");
			break;
		}
		case 2:
		{
			Lcd_write_str("2");
			break;
		}
		case 3:
		{
			Lcd_write_str("3");
			break;
		}
		case 4:
		{
			Lcd_write_str("4");
			break;
		}
		case 5:
		{
			Lcd_write_str("5");
			break;
		}
		case 6:
		{
			Lcd_write_str("6");
			break;
		}
		case 7:
		{
			Lcd_write_str("7");
			break;
		}
		case 8:
		{
			Lcd_write_str("8");
			break;
		}
		case 9:
		{
			Lcd_write_str("9");
			break;
		}
	}
}







void Lcd_write_str(uint8_t *STRING)//?????? ??????
{
	char c; //?????? ?? ??????
	while (c=*STRING++){//?????????? ?? ???? ??????
	if(c>=192) Lcd_write_data(russian[c-192]);//???? ? ??? ??????? ???????
	else Lcd_write_data(c);//????? ??????
	}
}

void Lcd_goto(uint8_t x,uint8_t y)//??????? ???????
{
	switch(x)
		{
			case 0://?????????? ?????? ??????
				Lcd_write_cmd(y|0x80);//???????
				break;
			case 1://??????
				Lcd_write_cmd(0x40+y|0x80);//??????? ?? ?????
				break;
			case 2://??????
				Lcd_write_cmd(0x10+y|0x80);//??????? ?? ????? ???????? ????????
				break;
			case 3://?? ? ?????????
				Lcd_write_cmd(0x50+y|0x80);//??????? ?? ?????
				break;
		}
}

void Init_pin_out()//????????? ?????? ?? ?????
{
	/*RCC_APB2PeriphClockCmd(init_port, ENABLE);//???????????? ????? B
	GPIO_InitTypeDef init_pin;//???????? ?????????
	init_pin.GPIO_Pin  = pin_e | pin_rs | pin_rw | pin_d7 | pin_d6 | pin_d5 | pin_d4;//4, 5, 6, 7 , 12, 11, 10 ??????
	init_pin.GPIO_Mode = GPIO_Mode_Out_PP;//?? ?????
	init_pin.GPIO_Speed = GPIO_Speed_50MHz;//????????
	GPIO_Init (port, &init_pin);//?????? ? ????????? ??????? ????????*/
        GPIO_InitTypeDef GPIO_InitStruct = {0};
        GPIO_InitStruct.Pin = RS|RW|E|D4|D5|D6|D7;
        GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
        HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
}
void Init_pin_in()//????????? ?????? ?? ????
{
	/*RCC_APB2PeriphClockCmd(init_port, ENABLE);//???????????? ????? B
	GPIO_InitTypeDef init_pin;//???????? ?????????
	init_pin.GPIO_Pin  =  pin_d7 | pin_d6 | pin_d5 | pin_d4 ;//4, 5, 6 ? 7 ??????
	init_pin.GPIO_Mode = GPIO_Mode_IPD;//?? ????
	init_pin.GPIO_Speed = GPIO_Speed_50MHz;//????????
	GPIO_Init (port, &init_pin);//?????? ? ????????? ??????? ????????*/
        GPIO_InitTypeDef GPIO_InitStruct = {0};
        GPIO_InitStruct.Pin = D4|D5|D6|D7;
        GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
        GPIO_InitStruct.Pull = GPIO_PULLUP;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
        HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
}

void Lcd_write_cmd(uint8_t cmd )
{
	Init_pin_out();//????????? ????? ?? ?????
	del=24000; while (del--){}//????????
	//rs_0;//?????????? ??? ????? ???????????? ???????
        
	GPIO_Write(port,((cmd>>4)<<lcd_shift));//???????? ??????? ?????
	e_1;//???????? ????????
	del=10; while (del--){}//????????
	e_0;//??????????? ????????
	GPIO_Write(port,(0x00)<<lcd_shift);//
	GPIO_Write(port,((cmd&0x0F)<<lcd_shift));//???????? ??????? ?????
	del=10; while (del--){}//????????
	e_1;//???????? ????????
	del=10; while (del--){}//????????
	e_0;rs_0;rw_0;//??????????? ????????
}

void Lcd_write_data(uint8_t data)
{
	Init_pin_out();//????????? ????? ?? ?????
	GPIO_Write(port,((data>>4)<<lcd_shift));//???????? ??????? ?????
	e_1;rs_1;//???????? ???????? ??????
	del=10; while (del--){}//????????
	e_0;//??????????? ????????
	GPIO_Write(port,(0x00)<<lcd_shift);
	GPIO_Write(port,((data&0x0F)<<lcd_shift));//???????? ??????? ?????
	del=10; while (del--){}//????????
	e_1;rs_1;//???????? ????????
	del=10; while (del--){}//????????
	e_0;rs_0;rw_0;//???????????
	GPIO_Write(port,(0x00)<<lcd_shift);
}

void Init_lcd()//????????????? ???????
{
	Init_pin_out();//????????? ????? ?? ?????

	del=72000; while (del--){}//????????
	Lcd_write_cmd(Function_set);//???????? 4 ?????? ?????
	del=72000; while (del--){}//????????

	Lcd_write_cmd(Display_on_off_control);//???????? ???????, ????????? ?????? ? ???????
	del=72000; while (del--){}//????????

	Lcd_write_cmd(Display_clear);//??????? ??????
	del=72000; while (del--){}//????????

    Lcd_write_cmd(Entry_mode_set);//??????? ????? ?????????
}

void Lcd_clear()
{
	Lcd_write_cmd(Display_clear);//???????? ??????? ??????? ???????
}

void Return_home()
{
	Lcd_write_cmd(0b0000001);//??????? ????????? ? ?????? ???????
}

void Lcd_definechar(const uint8_t *pc,uint8_t char_code)//???????? ???????????? ???????
{
	uint8_t a;//?????? ????? ??? ???????
	uint16_t i;//?????????? ?????
	a=(char_code<<3)|0x40;//?????????? ??? ???????
	for (i=0; i<8; i++)
	{
		Lcd_write_cmd(a++);//???????? ??? ? ??????
		Lcd_write_data(pc[i]);//?????????? ??????
	}
}
