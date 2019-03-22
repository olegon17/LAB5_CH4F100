#define A GPIO_PIN_0
#define B GPIO_PIN_1
#define C GPIO_PIN_2
#define D GPIO_PIN_3
#define E GPIO_PIN_4
#define F GPIO_PIN_5
#define G GPIO_PIN_6
#define DP GPIO_PIN_7
#define GPIOSEG GPIOA
#define SEG1 GPIO_PIN_12
#define SEG2 GPIO_PIN_13
#define SEG3 GPIO_PIN_14
#define SEG4 GPIO_PIN_15

void clearseg(void)
{
  HAL_GPIO_WritePin(GPIOA, A|B|C|D|E|F|G|DP, GPIO_PIN_RESET);
}
void show(int digit) {//????? ?????
	switch(digit)
	{
		case 0:
		{
			//GPIO_SetBits(GPIOSEG, GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7);
			HAL_GPIO_WritePin(GPIOSEG, A|B|C|D|E|F, GPIO_PIN_SET);
                        break;
		}
		case 1:
		{
			//GPIO_SetBits(GPIOSEG, GPIO_Pin_1|GPIO_Pin_2);
                        HAL_GPIO_WritePin(GPIOSEG, B|C, GPIO_PIN_SET);
			break;
		}
		case 2:
		{
			//GPIO_SetBits(GPIOSEG, GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_8);
                        HAL_GPIO_WritePin(GPIOSEG, A|B|G|E|D, GPIO_PIN_SET);
			break;
		}
		case 3:
		{
			//GPIO_SetBits(GPIOSEG, GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_5|GPIO_Pin_8);
			HAL_GPIO_WritePin(GPIOSEG,A|B|C|D|G , GPIO_PIN_SET);
                        break;
		}
		case 4:
		{
			//GPIO_SetBits(GPIOSEG, GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_7|GPIO_Pin_8);
			HAL_GPIO_WritePin(GPIOSEG, F|G|B|C, GPIO_PIN_SET);
                        break;
		}
		case 5:
		{
			//GPIO_SetBits(GPIOSEG, GPIO_Pin_0|GPIO_Pin_2|GPIO_Pin_5|GPIO_Pin_7|GPIO_Pin_8);
			HAL_GPIO_WritePin(GPIOSEG, A|F|G|C|D, GPIO_PIN_SET);
                        break;
		}
		case 6:
		{
			//GPIO_SetBits(GPIOSEG, GPIO_Pin_0|GPIO_Pin_2|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8);
			HAL_GPIO_WritePin(GPIOSEG, A|F|G|C|D|E, GPIO_PIN_SET);
                        break;
		}
		case 7:
		{
			//GPIO_SetBits(GPIOSEG, GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2);
			HAL_GPIO_WritePin(GPIOSEG, A|B|C, GPIO_PIN_SET);
                        break;
		}
		case 8:
		{
			//GPIO_SetBits(GPIOSEG, GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8);
			HAL_GPIO_WritePin(GPIOSEG, A|B|C|D|E|F|G, GPIO_PIN_SET);
                        break;
		}
		case 9:
		{
			//GPIO_SetBits(GPIOSEG, GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_5|GPIO_Pin_7|GPIO_Pin_8);
			HAL_GPIO_WritePin(GPIOSEG, A|B|C|D|G, GPIO_PIN_SET);
                        break;
		}
		case 10:
		{
			//GPIO_SetBits(GPIOSEG, GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8);
			HAL_GPIO_WritePin(GPIOSEG, A|B|C|E|F|G, GPIO_PIN_SET);
                        break;
		}
		case 11:
		{
			//GPIO_SetBits(GPIOSEG, GPIO_Pin_2|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8);
			HAL_GPIO_WritePin(GPIOSEG, C|D|E|F|G, GPIO_PIN_SET);
                        break;
		}
		case 12:
		{
			//GPIO_SetBits(GPIOSEG, GPIO_Pin_0|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7);
			HAL_GPIO_WritePin(GPIOSEG, A|D|E|F, GPIO_PIN_SET);
                        break;
		}
		case 13:
		{
			//GPIO_SetBits(GPIOSEG, GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_8);
			HAL_GPIO_WritePin(GPIOSEG, B|C|D|E|G, GPIO_PIN_SET);
                        break;
		}
		case 14:
		{
			HAL_GPIO_WritePin(GPIOSEG, A|D|E|F|G, GPIO_PIN_SET);
                        break;
		}
		case 15:
		{
			HAL_GPIO_WritePin(GPIOSEG, A|E|F|G, GPIO_PIN_SET);
                        break;
		}
	}
}