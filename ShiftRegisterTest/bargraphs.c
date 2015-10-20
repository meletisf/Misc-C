/*
* |R |R |R |R |R |G |G |G |G |G |G |G |G | (color)
* |0 |1 |2 |3 |4 |5 |6 |7 |8 |9 |10|11|12| (position)
* 
*/

#define NUMBER_OF_LEDS 13
#define RESET_CHECK check=0x1

boolean check = 0x1;
int oled = 1;

void parse_bargraph (int current_fuel_value, int max_fuel_value)
{
	int key = (max_fuel_value / NUMBER_OF_LEDS);
	int open_leds = ceil(((float)current_fuel_value / (float)key));
	int bargraph_end_point = open_leds;
	oled = bargraph_end_point;
	
	FLUSH_BARGRAPH_REGISTERS;
	
	if (current_fuel_value > max_fuel_value - 50) {
		RESET_CHECK;
	}
	
	if (open_leds <= 5 && check)
	{
		play_low_fuel_animation = 0x1;
		check = 0x0;
	}
	else if(open_leds > 5)
	{
		play_low_fuel_animation = 0x0;
	}
	
	for (int i = 0; i < bargraph_end_point; i++)
	{
		bargraph_registers[i] = 0x1;
	}
	
	writebargraph();
}

void play_fuel_animation(boolean state)
{
	for (int i = oled-1; i >= 0; i--)
	{
		bargraph_registers[i] = state;
	}
	writebargraph();
}