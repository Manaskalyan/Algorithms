#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define ALGO_ERROR -1
#define NUM_ITERATIONS 100

// compute x*y each of has digits. X & Y doesn't have to be same digits.
uint32_t karatsuba_multiplication(uint16_t x, uint16_t y, uint8_t digits)
{
	if (x == 0 || y == 0) {
		return 0;
	}
	else if (digits == 2 || digits == 1) {
		return x * y;
	}
	else {
		// Think of  x = x1.10^(digits/2) + x0 y= y1.10^(digits /2) + y0
		uint16_t x1, x0, y1, y0; /*some could become 9 bits??*/
		uint8_t half_digits;
		double ten_pow;
		half_digits = (digits / 2);

		ten_pow = pow(10, half_digits);
		x1 = (uint16_t) (x / ten_pow);
		x0 = (uint16_t) (x % (int)ten_pow);

		y1 = (uint16_t)(y / ten_pow);
		y0 = (uint16_t)(y % (int)ten_pow);

		uint32_t x1y1, x1y0, x0y1, x0y0;

		x1y1 = karatsuba_multiplication(x1, y1, (digits % 2 == 0) ? half_digits : half_digits + 1);
		x1y0 = karatsuba_multiplication(x1, y0, (digits % 2 == 0) ? half_digits : half_digits + 1);
		x0y1 = karatsuba_multiplication(x0, y1, (digits % 2 == 0) ? half_digits : half_digits + 1);
		x0y0 = karatsuba_multiplication(x0, y0, half_digits);

		return ( x0y0 + ((x1y0 + x0y1)* ten_pow) + (x1y1 * ten_pow * ten_pow) );
	}
}

//Driver code
int main() {
	uint32_t multiply_value;
	uint16_t x, y, temp_x, temp_y;
	uint8_t digits, digits_x, digits_y;
	int iter;

	for (iter = 0; iter < NUM_ITERATIONS; iter++)
	{
		//digits = rand() % 255; //something wrong here.
		//digits were computed in the driver code. 
        x = rand() % 32767;
		y = rand() % 32767;

		temp_x = x;
		temp_y = y;
		digits_x = 0;
		digits_y = 0;

		//compute the max number of digits of X & Y.
		/*There is an error here. I am not finding the right number of digits in X & Y*/
		for (;;) {
			temp_x = temp_x / 10;
			temp_y = temp_y / 10;

			if (temp_x != 0) {
				digits_x++;
			}

			if (temp_y != 0) {
				digits_y++;
			}

			if (temp_x == 0 && temp_y == 0) {
				break;
			}

		}
		digits_x++;
		digits_y++;

		if (digits_x <= digits_y) {
			digits = digits_y;
		}
		else {
			digits = digits_x;
		}

		//printf("x : %d y : %d digits : %d \n", x, y, digits);

		
		multiply_value = karatsuba_multiplication(x, y, digits);

		if (multiply_value != (x * y) ) {
			printf("Something is wrong \n");
			return ALGO_ERROR;
		}
	}

	multiply_value = karatsuba_multiplication(311, 203, 3);
	printf("Multiply value of 311 , 203: %d \n", multiply_value);
	return 0;
}

