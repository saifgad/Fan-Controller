// All the preprocessor Libaries and Macros
#define  F_CPU 16000000
#include <util/delay.h>
#include "ADC.h"
#include "DCM.h"

#include "DC_Motor.h"
#include "EXT_Interrupt.h"
#include "LCD.h"
#include "Timer.h"
#include "servoo.h"
// Extern the values of keypad and PC counters
Uint16 Temp=0;
int main(void)
{	
	Timer0_Init();
	DC_Motor1_INIT();
	ADC_Init();
	LCD_Init();
	LCD_Goto(2,1);
	LCD_Write_String("Temp Is : ");
	LCD_Goto(1,1);
	LCD_Write_String("FAN  ");


	while (1)
	
	{		
			Temp=ADC_Read(ADC_PIN4)*.48875;
			LCD_Goto(2,10);
			LCD_Write_Integer(Temp);

		if (Temp<30)
		{
			DC_Motor1_STOP();
			
			LCD_Goto(1,5);
			LCD_Write_String("OFF");
			
		}
		if (Temp>=30 && Temp<60)
		{
			
			LCD_Goto(1,5);
			LCD_Write_String("ON");
			DC_Motor1_START(25,Clock_Wise);
		}
		if (Temp>=60 && Temp<90)
		{
			
			LCD_Goto(1,5);
			LCD_Write_String("ON");
			DC_Motor1_START(50,Clock_Wise);
		}
		if (Temp>=90 && Temp <120)
		{
			
			LCD_Goto(1,5);
			LCD_Write_String("ON");
			DC_Motor1_START(75,Clock_Wise);
		}
		if (Temp>=120)
		{
			
			LCD_Goto(1,5);
			LCD_Write_String("ON");
			DC_Motor1_START(100,Clock_Wise);
		}

	}
	
}
