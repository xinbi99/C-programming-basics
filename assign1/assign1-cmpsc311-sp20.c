////////////////////////////////////////////////////////////////////////////////
//
//  File           : cmpsc311-f16-assign1.c
//  Description    : This is the main source code for for the first assignment
//                   of CMPSC311, Spring 2020, at Penn State.
//                   assignment page for details.
//
//   Author        : Xin Bi
//   Last Modified : 2/5/2020
//
// Include Files
#include <stdio.h>
#include <string.h>
#include <math.h>
#define NUM_TEST_ELEMENTS 100

// Functions
////////////////////////////////////////////////////////////////////////////////
//
// Function     : round311
// Description  : Rounds numbers to their nearest integer
//
// Inputs       : src[] the array that contains the numbers that need to be rounded
//                out[] the outpur array that is passed as a parameter to store the rounded numbers
//                size  the size of the arrays
// Outputs      : None


void round311(float src[], int out[], int size){
	int i;
	double integer;
	float frac;
	int dec;
	for (i = 0; i<size; i++){
		frac = modf(src[i], &integer);
		dec = src[i] - frac;
		if (frac >= 0.5){
			out[i] = dec + 1;
		}
		else {
			out[i] = dec;
		}
	}
}
////////////////////////////////////////////////////////////////////////////////
//
// Function     : printfloatArr311
// Description  : Prints a array of floating point numbers to 2 decimal places
//
// Inputs       : *f_arr a reference to an array of floating point numbers
//                size   the size of the array
// Outputs      : None


void printfloatArr311(float *f_arr, int size){
	int i;
	for(i=0; i<size; i++){
		if(i != size -1){
			printf("%.2f, ", f_arr[i]);	
		}
		else{
			printf("%.2f\n",f_arr[i]);
		}
	}	
}
////////////////////////////////////////////////////////////////////////////////
//
// Function     : printIntArr311
// Description  : Prints an array of integers
//
// Inputs       : *i_arr a reference to an array of integers
//                size   the size of the array
// Outputs      : None


void printIntArr311(int *i_arr, int size){
	int i;
	for(i=0; i<size; i++){
		if(i != size -1){
			printf("%i, ", i_arr[i]);
		}
		else{
			printf("%i\n", i_arr[i]);
		}
	}
}
////////////////////////////////////////////////////////////////////////////////
//
// Function     : bubbleSort311
// Description  : Sorts an array of integers with the bubble sort techinique
//
// Inputs       : *i_arr a reference to an array of integers
//                size   the size of the array
// Outputs      : 


void bubbleSort311(int *i_arr, int size){
	int i;
	int j;
	int p;
	for(i=0; i < size; i++){
		for(j=0; j<size-1; j++){
			if(i_arr[j]>i_arr[j+1]){
				p = i_arr[j];
				i_arr[j] = i_arr[j+1];
				i_arr[j+1] = p;
			}
		}
	}
}
////////////////////////////////////////////////////////////////////////////////
//
// Function     : toBinary
// Description  : Turns a char into a binary with a space separating every nibble
//
// Inputs       : char the input character
//                
// Outputs      : 


void toBinary(char in){
	int a = in;
	int bit = 0;
	for (int i = 7; i >= 0; i--){
		int div = 1;
		for(int j=0; j < i; j++){
			div = div *2;
		}
		float quo = a / div;
		if(quo >= 1) {
			bit = 1;
			a = a - div;
		}	
		else {
			bit = 0;
		}
		printf("%d", bit);
		if(i == 4){
			printf(" ");
		}
	}			
	printf("\n");
}
////////////////////////////////////////////////////////////////////////////////
//
// Function     : countRange311
// Description  : counts how many numbers are in the given range
//
// Inputs       : *f_arr a reference to an array of floating point numbers
//                size   the size of the array
//                min, max the bounds of the given range
// Outputs      : count  the number of numbers in the given range


int countRange311(float *f_arr, int size, int min, int max){
	int i;
	int count = 0;
		for(i=0; i<size; i++){
			if(f_arr[i] <= max+0.5 && f_arr[i] >= min-0.5){
				count = count + 1;
			}
		}
		return count;
}
////////////////////////////////////////////////////////////////////////////////
//
// Function     : histogram311
// Description  : draws the graph according to the array given
//
// Inputs       : in a reference to an array of integers


void histogram311(int *in){
	printf("   +----------------------------------------+\n");
	for(int i = 19; i >=0; i--){
		printf("%02d |", i);
		for(int j = 0; j<40; j++){
			int count = j / 4;
			int rem = j % 4;
			if(in[count]>=i && (rem == 1 || rem == 2)){
				printf("x");
			}
			else if (i % 5 == 0){
			printf(".");
			}
			else{
			printf(" ");
			}
		}
	
		printf("|\n");	
	}
	printf("   +----------------------------------------+\n");
	printf("      00  10  20  30  40  50  60  70  80  90\n");
			
}
////////////////////////////////////////////////////////////////////////////////
//
// Function     : main
// Description  : The main function for the CMPSC311 assignment #1
//
// Inputs       : argc - the number of command line parameters
//                argv - the parameters
// Outputs      : 0 if successful test, -1 if failure

int main(int argc, char **argv) {

    /* Local variables */
    float f_array[NUM_TEST_ELEMENTS];
    int i_array[NUM_TEST_ELEMENTS], i;
    int hist_array[10];

    /* Preamble inforamtion */
    printf( "CMPSC311 - Assignment #1 - Spring 2020\n\n" );

    /* Step #1 - read in the float numbers to process */
    for (i=0; i<NUM_TEST_ELEMENTS; i++) {
        scanf("%f", &f_array[i]);
    }

    /* Step #2 - Alter the values of the float array as follows: all 
    even numbered indices of the array should be multiplied by 0.78 
    if the value is greater than 50 and 1.04 otherwise.  All odd valued
    indices should multiplied by 0.92 if the value is greater than 50 
    and 1.15 otherwise */
    for (i=0; i<NUM_TEST_ELEMENTS; i++) {
	    if(i % 2 == 0){
		    if(f_array[i] > 50) {
			    f_array[i] = f_array[i]*0.78;
		    }
		    else {
			    f_array[i] = f_array[i]*1.04;
		    }
	    }
	    else {
		    if(f_array[i]>50) {
			    f_array[i] = f_array[i]*0.92;
		    }
		    else {
			    f_array[i] = f_array[i]*1.15;
		    }
	    }
    }
	
    /* Step  #3 Round all of the values to integers and assign them 
    to i_array using the round311 function */
    round311(f_array, i_array,NUM_TEST_ELEMENTS);

    /* Step #4 - Print out all of the floating point numbers in the 
    array in order on a SINGLE line.  Each value should be printed 
    with 2 digits to the right of the decimal point. */
    printf( "Testing printfloatArr311 (floats): " );
    printfloatArr311(f_array, NUM_TEST_ELEMENTS );
    printf("\n\n");

     /* Step #5 - Print out all of the integer numbers in the array in order on a SINGLE line. */
    printf( "Testing printIntArr311 (integers): " );
    printIntArr311(i_array, NUM_TEST_ELEMENTS );
    printf("\n\n");

    /* Step #6 - sort the integer values, print values */
    printf( "Testing bubbleSort311 (integers): " );
    bubbleSort311( i_array, NUM_TEST_ELEMENTS );
    printIntArr311( i_array, NUM_TEST_ELEMENTS );
    printf("\n\n");

    /* Step #7 - print out the last 5 values of the integer array in binary. */
    printf( "Testing toBinary:\n" );
    for (i=NUM_TEST_ELEMENTS-6; i<NUM_TEST_ELEMENTS; i++) {
        toBinary(i_array[i]);
    }
    printf("\n\n");

    /* Declare an array of integers.  Fill the array with a count (times three) of the number of values for each 
    set of tens within the floating point array, i.e. index 0 will contain the count of rounded values in the array 0-9, the sec    ond will be 10 - 19 etc. */
    for (i = 0; i < 10 ; i++) {
    	hist_array[i] = countRange311(f_array, NUM_TEST_ELEMENTS, 10*i, 9+10*i);
    }
    histogram311(hist_array);
    
    /* Exit the program successfully */
    printf( "\n\nCMPSC311 - Assignment #1 - Spring 2020 Complete.\n" );
    return( 0 );
}
