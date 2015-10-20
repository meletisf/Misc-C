/*
* |DP|A |B |C |D |E |F |G |DP|A |B |C |D |E |F |G |DP|A |B |C |D |E |F |G |DP|A |B |C |D |E |F |G | (segment)
* |0 |1 |2 |3 |4 |5 |6 |7 |8 |9 |10|11|12|13|14|15|16|17|18|19|20|21|22|23|24|25|26|27|28|29|30|31| (position)
* |[]|[]|[]|[]|[]|[]|[]|[]|[]|[]|[]|[]|[]|[]|[]|[]|[]|[]|[]|[]|[]|[]|[]|[]|[]|[]|[]|[]|[]|[]|[]|[]| (value)
* |0 |0 |0 |0 |0 |0 |0 |0 |1 |1 |1 |1 |1 |1 |1 |1 |2 |2 |2 |2 |2 |2 |2 |2 |3 |3 |3 |3 |3 |3 |3 |3 | (digit)
*/

void print_digit(int get_digit, int get_digit_value)
{
	start_point = get_digit * 8;
	
	end_point = start_point + 8;
	get_rp = return_pins(get_digit_value);
	int rp_counter = 0;
	for(int i = start_point; i < end_point; i++)
	{
		if(*(get_rp + rp_counter) == 1)
		{
			display_registers[i] = 0x1;
			writereg();
			rp_counter++;
		}
		else {
			display_registers[i] = 0x0;
			writereg();
			rp_counter++;
		}
	}
	
}

// Available chars: 0123456789ACFEPHro-.
int * return_pins(int get_number)
{
	static int rp[8];
	switch(get_number)
	{
				     //DP, A, B, C, D, E, F, G
		case 48: //0
			//rp[8] = {0, 1, 1, 1, 1, 1, 1, 0};
			rp[0] = 0;
			rp[1] = 1;
			rp[2] = 1;
			rp[3] = 1;
			rp[4] = 1;
			rp[5] = 1;
			rp[6] = 1;
			rp[7] = 0;	
			break;
		case 49: //1
			//rp[8] = {0, 0, 1, 1, 0, 0, 0, 0};
			rp[0] = 0;
			rp[1] = 0;
			rp[2] = 1;
			rp[3] = 1;
			rp[4] = 0;
			rp[5] = 0;
			rp[6] = 0;
			rp[7] = 0;
			break;
		case 50: //2
			//rp[8] = {0, 1, 1, 0, 1, 1, 0, 1};
			rp[0] = 0;
			rp[1] = 1;
			rp[2] = 1;
			rp[3] = 0;
			rp[4] = 1;
			rp[5] = 1;
			rp[6] = 0;
			rp[7] = 1;
			break;
		case 51: //3
			//rp[8] = {0, 1, 1, 1, 1, 0, 0, 1};
			rp[0] = 0;
			rp[1] = 1;
			rp[2] = 1;
			rp[3] = 1;
			rp[4] = 1;
			rp[5] = 0;
			rp[6] = 0;
			rp[7] = 1;
			break;
		case 52: //4
			//rp[8] = {0, 0, 1, 1, 0, 0, 1, 1};
			rp[0] = 0;
			rp[1] = 0;
			rp[2] = 1;
			rp[3] = 1;
			rp[4] = 0;
			rp[5] = 0;
			rp[6] = 1;
			rp[7] = 1;
			break;
		case 53: //5
			//rp[8] = {0, 1, 0, 1, 1, 0, 1, 1};
			rp[0] = 0;
			rp[1] = 1;
			rp[2] = 0;
			rp[3] = 1;
			rp[4] = 1;
			rp[5] = 0;
			rp[6] = 1;
			rp[7] = 1;
			break;
		case 54: //6
			//rp[8] = {0, 1, 0, 1, 1, 1, 1, 1};
			rp[0] = 0;
			rp[1] = 1;
			rp[2] = 0;
			rp[3] = 1;
			rp[4] = 1;
			rp[5] = 1;
			rp[6] = 1;
			rp[7] = 1;
			break;
		case 55: //7
			//rp[8] = {0, 1, 1, 1, 0, 0, 0, 0};
			rp[0] = 0;
			rp[1] = 1;
			rp[2] = 1;
			rp[3] = 1;
			rp[4] = 0;
			rp[5] = 0;
			rp[6] = 0;
			rp[7] = 0;
			break;
		case 56: //8
			//rp[8] = {0, 1, 1, 1, 1, 1, 1, 1};
			rp[0] = 0;
			rp[1] = 1;
			rp[2] = 1;
			rp[3] = 1;
			rp[4] = 1;
			rp[5] = 1;
			rp[6] = 1;
			rp[7] = 1;
			break;
		case 57: //9
			//rp[8] = {0, 1, 1, 1, 1, 0, 1, 1};
			rp[0] = 0;
			rp[1] = 1;
			rp[2] = 1;
			rp[3] = 1;
			rp[4] = 1;
			rp[5] = 0;
			rp[6] = 1;
			rp[7] = 1;
			break;
		case 65: //A
			//rp[8] = {0, 1, 1, 1, 0, 1, 1, 1};
			rp[0] = 0;
			rp[1] = 1;
			rp[2] = 1;
			rp[3] = 1;
			rp[4] = 0;
			rp[5] = 1;
			rp[6] = 1;
			rp[7] = 1;
			break;
		case 67: //C
			//rp[8] = {0, 1, 0, 0, 1, 1, 1, 0};
			rp[0] = 0;
			rp[1] = 1;
			rp[2] = 0;
			rp[3] = 0;
			rp[4] = 1;
			rp[5] = 1;
			rp[6] = 1;
			rp[7] = 0;
			break;
		case 70: //F
			//rp[8] = {0, 1, 0, 0, 0, 1, 1, 1};
			rp[0] = 0;
			rp[1] = 1;
			rp[2] = 0;
			rp[3] = 0;
			rp[4] = 0;
			rp[5] = 1;
			rp[6] = 1;
			rp[7] = 1;
			break;
		case 69: //E
			//rp[8] = {0, 1, 0, 0, 1, 1, 1, 1};
			rp[0] = 0;
			rp[1] = 1;
			rp[2] = 0;
			rp[3] = 0;
			rp[4] = 1;
			rp[5] = 1;
			rp[6] = 1;
			rp[7] = 1;
			break;
		case 80: //P
			//rp[8] = {0, 1, 1, 0, 0, 1, 1, 1};
			rp[0] = 0;
			rp[1] = 1;
			rp[2] = 1;
			rp[3] = 0;
			rp[4] = 0;
			rp[5] = 1;
			rp[6] = 1;
			rp[7] = 1;
			break;
		case 114: //r
			//rp[8] = {0, 0, 0, 0, 0, 1, 0, 1};
			rp[0] = 0;
			rp[1] = 0;
			rp[2] = 0;
			rp[3] = 0;
			rp[4] = 0;
			rp[5] = 1;
			rp[6] = 0;
			rp[7] = 1;
			break;
		case 72: //H
			//rp[8] = {0, 0, 1, 1, 0, 1, 1, 1};
			rp[0] = 0;
			rp[1] = 0;
			rp[2] = 1;
			rp[3] = 1;
			rp[4] = 0;
			rp[5] = 1;
			rp[6] = 1;
			rp[7] = 1;
			break;
		case 32: //(space)
			//rp[8] = {0, 0, 0, 0, 0, 0, 0, 0};
			rp[0] = 0;
			rp[1] = 0;
			rp[2] = 0;
			rp[3] = 0;
			rp[4] = 0;
			rp[5] = 0;
			rp[6] = 0;
			rp[7] = 0;
			break;
		case 46: //.
			//rp[8] = {1, 0, 0, 0, 0, 0, 0, 0};
			rp[0] = 1;
			rp[1] = 0;
			rp[2] = 0;
			rp[3] = 0;
			rp[4] = 0;
			rp[5] = 0;
			rp[6] = 0;
			rp[7] = 0;
			break;
		case 111: //o
			//rp[8] = {0, 0, 0, 1, 1, 1, 0, 1};
			rp[0] = 0;
			rp[1] = 0;
			rp[2] = 0;
			rp[3] = 1;
			rp[4] = 1;
			rp[5] = 1;
			rp[6] = 0;
			rp[7] = 1;
			break;
		case 45: //-
		default:
			//rp[8] = {0, 0, 0, 0, 0, 0, 0, 1};
			rp[0] = 0;
			rp[1] = 0;
			rp[2] = 0;
			rp[3] = 0;
			rp[4] = 0;
			rp[5] = 0;
			rp[6] = 0;
			rp[7] = 1;
			break;
		            //DP, A, B, C, D, E, F, G
	}
	return rp;
}
