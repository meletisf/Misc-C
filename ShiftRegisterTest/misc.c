void flush_display_registers()
{
	for (int i = 0; i < 32; i++)
	{
		display_registers[i] = 0x0;
	}
}

void flush_bargraph_registers()
{
	for (int i = 0; i < 16; i++)
	{
		bargraph_registers[i] = 0x0;
	}
}

int ascii_to_integer(int number)
{	
	int i = 0;
	
	for(int x = 48; x < number; x++) {
		i++;
	}
	
	return i;
}

int return_fuel_as_int()
{
	unsigned int fuel = 0;
	
	fuel += (ascii_to_integer(buffer[0]) * 1000);
	fuel += (ascii_to_integer(buffer[1]) * 100);
	fuel += (ascii_to_integer(buffer[2]) * 10);
	fuel += (ascii_to_integer(buffer[3]));
	
	return fuel;
}

int return_max_fuel_as_int()
{
	unsigned int max_fuel = 0;
	
	max_fuel += (ascii_to_integer(buffer[4]) * 1000);
	max_fuel += (ascii_to_integer(buffer[5]) * 100);
	max_fuel += (ascii_to_integer(buffer[6]) * 10);
	max_fuel += (ascii_to_integer(buffer[7]));
	
	return max_fuel;
}


void reset_input_buffer()
{
	for (int i = 0; i < 8; i++)
	{
		buffer[i] = 0;
	}
}