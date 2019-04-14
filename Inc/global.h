

int second = 0;//??????? ?????
int minute = 0;
int hours = 0;



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
