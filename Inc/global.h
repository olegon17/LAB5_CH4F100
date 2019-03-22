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

int second = 55;//??????? ?????
int minute = 44;
int hours = 8;

const 

void clockTime(int x)//?????????? ????? ????? ???????
{
	switch(x)
	{
		case 0:
		{
			lcdPuts("0");
			break;
		}
		case 1:
		{
			lcdPuts("1");
			break;
		}
		case 2:
		{
			lcdPuts("2");
			break;
		}
		case 3:
		{
			lcdPuts("3");
			break;
		}
		case 4:
		{
			lcdPuts("4");
			break;
		}
		case 5:
		{
			lcdPuts("5");
			break;
		}
		case 6:
		{
			lcdPuts("6");
			break;
		}
		case 7:
		{
			lcdPuts("7");
			break;
		}
		case 8:
		{
			lcdPuts("8");
			break;
		}
		case 9:
		{
			lcdPuts("9");
			break;
		}
	}
}
