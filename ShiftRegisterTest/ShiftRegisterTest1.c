
/*
* This is about multiplexing 4 shift register and make them work with 4 7seg displays
* No libraries. All legit as fuck!
*/
#include <math.h>
#include <LedControl.h>

const int bargraph_DS_pin = 5; //blue
const int bargraph_STCP_pin = 6; //orange
const int bargraph_SHCP_pin = 7; //yellow

const int display_DS_pin = 8; //blue
const int display_STCP_pin = 9; //green
const int display_SHCP_pin = 10; //yellow

boolean display_registers[32];
boolean bargraph_registers[16];
boolean play_low_fuel_animation = 0x0;
boolean animation_state = 0x0;

long previousMillis = 0;
long low_fuel_animation_delay = 1000;

#define FLUSH_BUFFER reset_input_buffer()
#define FLUSH_BUFFER_COUNTER buffer_counter = 0
#define FLUSH_DISPLAY_REGISTERS flush_display_registers()
#define FLUSH_BARGRAPH_REGISTERS flush_bargraph_registers()

int counter = 0;
int start_point;
int end_point;
int *get_rp;
int buffer[8];
int buffer_counter = 0;

void setup()
{
	Serial.begin(9600);
	pinMode(display_DS_pin, 0x1);
	pinMode(display_STCP_pin, 0x1);
	pinMode(display_SHCP_pin, 0x1);
	
	pinMode(bargraph_DS_pin, 0x1);
	pinMode(bargraph_STCP_pin, 0x1);
	pinMode(bargraph_SHCP_pin, 0x1);
	writereg();
	Serial.println("Board connected!");
	FLUSH_BUFFER;
	FLUSH_BUFFER_COUNTER;
}


void writebargraph()
{	
	digitalWrite(bargraph_STCP_pin, 0x0);
	for (int i = 15; i >= 0; i--)
	{
		digitalWrite(bargraph_SHCP_pin, 0x0);
		digitalWrite(bargraph_DS_pin, bargraph_registers[i]);
		digitalWrite(bargraph_SHCP_pin, 0x1);
	}
	digitalWrite(bargraph_STCP_pin, 0x1);
}

void writereg()
{
	digitalWrite(display_STCP_pin, 0x0);
	for (int i = 31; i >= 0; i--)
	{
		digitalWrite(display_SHCP_pin, 0x0);
		digitalWrite(display_DS_pin, display_registers[i]);
		digitalWrite(display_SHCP_pin, 0x1);
	}
	digitalWrite(display_STCP_pin, 0x1);
}

void loop()
{
	
	unsigned long currentMillis = millis();
	if (Serial.available() > 0)
	{
		int s_in = Serial.read();
		Serial.println(s_in);

		if (buffer_counter < 8)
		{
			buffer[buffer_counter] = s_in;
			buffer_counter++;
		}
		else
		{
			buffer_counter = 0;
		}
		
		// Hard reset
		if (s_in == 64)
		{
			FLUSH_BUFFER;
			FLUSH_BUFFER_COUNTER;
			FLUSH_DISPLAY_REGISTERS;
			FLUSH_BARGRAPH_REGISTERS;
			print_digit(0, 45);
			print_digit(1, 45);
			print_digit(2, 45);
			print_digit(3, 45);
		}
		// Soft reset
		if (s_in == 33)
		{
			FLUSH_BUFFER;
			FLUSH_BUFFER_COUNTER;
		}
	}
	
	if (play_low_fuel_animation == 0x1)
	{
		if(currentMillis - previousMillis > low_fuel_animation_delay) 
		{
			previousMillis = currentMillis;
			
			animation_state = !animation_state;

			play_fuel_animation(animation_state);
		}
	}
	
	if (buffer_counter == 8)
	{
		for (int i = 0; i < 4; i++)
		{
			print_digit(3 - i, buffer[i]);
		}
		
		int get_current_fuel = return_fuel_as_int();
		int get_max_fuel = return_max_fuel_as_int();
		
		parse_bargraph(get_current_fuel, get_max_fuel);
		FLUSH_BUFFER;
		FLUSH_BUFFER_COUNTER;
	}
	
}