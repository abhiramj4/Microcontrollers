#include <stdint.h>
#include <time.h>

//Abhiram Santhosh, 101055288
//Mohammed Tanvir Hossain, 101058988
/**
	init the seed
*/
int randomInit(){

	time_t seconds;
	seconds = time(NULL);
	
	//this is the time since 1970, subtracting this with 
	
	return seconds - 1514000000; //
}

/**
	return a random number given a seed
*/
int random(int initSeed){

	
	uint32_t M = initSeed; //passed seed
	uint32_t a = 1664525; //constants provided
	uint32_t c = 1013904223;
	uint64_t m = 4294967296;
	//2^32
	
	M = (a * M + c) % m; //Linear congruent generator 
	
	return M; //this should return a random number
}

int main (void) {

	//basically the random number will be calculated
	//using the LCG, where M(n+1) will be the random number
	//where M1, M2, M3... are random numbers
	
	//M0 is a seed
	//a, c and m are all constants
	//the LCG is M(n+1) = a * M(n) + c % m
	//set M0 to be the origonal seed
	
	//calculate the seed via current time
	//comes from randomInit
	
	uint32_t M = randomInit(); //called once to init
	uint64_t storedNumbers[1000];
	
	//go for 1000 turns
	for(int i = 0; i < 1000; i ++){
		
		M = random(M); //this will change M every time
		storedNumbers[i] = M;
	}
	
	uint64_t sum = 0;
	uint64_t average = 0;
	
	for(int i = 0; i < 1000; i++){
		sum = sum + storedNumbers[i];
	}
	
	average = sum/1000;
	
	return 0;
}