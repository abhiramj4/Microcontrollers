#include  <stdint.h>

int main(void){

	//make it easier to toggle bits
	#define BIT0 0x01 //0000 0001
	#define BIT1 0x02 //0000 0010
	#define BIT2 0x04 //0000 0100
	#define BIT3 0x08 //0000 1000
	#define BIT4 0x10 //0001 0000
	#define BIT5 0x20 //0000 0010 0000
	#define BIT6 0x40 //0000 0100 0000
	#define BIT7 0x80 //0000 1000 0000
	//for 16bit
	#define BIT8 0x100 //0000 0001 0000 0000
	#define BIT9 0x200
	#define BIT10 0x400
	#define BIT11 0x800
	#define BIT12 0x1000
	#define BIT13 0x2000
	#define BIT14 0x4000
	#define BIT15 0x8000
	
	//step 1
	uint8_t aByte = 0x33; //in binary this is 0011 0011
	uint16_t aWord; //nothing right now
	
	aByte |= BIT0 | BIT7; //0011 0011 already set, so still 0x33
												//currently 0x33, toggling the MSB will make it
												//1011 0011 in binary, which is 0xB3
	
	//clear bit 0 and 7 with only &
	//currently aByte is 0xB3 which is 1011 0011,
	//once completley cleared the result should be 0011 0010 (0x32)
	//You can AND aByte with the mask instead
	//of using the ~ , thus to clear the low 
	//and high bits we need to AND
	//aByte with (first the low bit)
	//1111 1110 or 0xFE
	//AND'ing this with aByte will yield 
	//1011 0010 or 0xB2. Now clearing the high bit with
	//the mask will give us 0x7F
	//AND'ing will give us 0x32
	
	aByte &= 0xFE; 
	aByte &= 0x7F;
	
	//clearing bit 1 with ~ and &
	//This is straight forward, aByte is 0x32
	aByte &= ~(BIT1); //0011 0010 will clear to 0011 0000 or 30
	
	//toggle low nibble;
	aByte ^= BIT0 ^ BIT1 ^ BIT2 ^ BIT3; //Toggle entire low nibble
																			//should be 0011 1111 after (0x3F)
	
	aByte <<= 2; //shift left by two places will now be 1111 1100 or 0xFC
	aByte >>= 1;  //shift right by 1 places will now be 0111 1110 or 0x7E
	
	aWord = 0x0000; //init aWord
	//0b1111 1111 0000 0000
	aWord |= BIT15 | BIT14 | BIT13 | BIT12 | BIT11 | BIT10 | BIT9 | BIT8; //will now be 0xFF00
	
	aWord |= aByte; //will be FF7E
	
	aWord &= ~(aByte << 8);
	
	//shift 8 bits left for aByte(0x7E) will give me
	//0111 1110 -> 0111 1110 0000 0000 (0x7E00) inverting it will give 1000 0001 1111 1111 or 0x81FF
	//& with aWord will give me 0x817E
	//What this does is combine the high byte of the shifted and inverted aByte with the low byte of aWord
	
	aWord <<= 8; //shift aWord left, aWord is now 0x007E or 0000 0000 0111 1110
							 //0111 1110 0000 0000 or 0x7E00
	
	return 0;
}