/*------INCLUDES-----------*/
#include <stdio.h>
#include <conio.h>
#include <stdint.h>
#include <stdlib.h>

/*To change array size and number of iterations 
 * to run change these pre-processor defines
 */
 
/*------DEFINES-----------*/
#define ARR_SIZE 510
#define NUM_ITERATIONS 100


int32_t temp_arr[ARR_SIZE];
int arr[ARR_SIZE];

/* \brief   Sorts a global array defined by arr
 *
 * \param   Lower_Index Lower_Index of array. \Fixed at 0
 * \param   Upper_Index Upper Index of array. \Fixed at ARR_SIZE - 1
 * 
 */
int32_t Merge_Sort(uint16_t Lower_Index, uint16_t Upper_index);


int32_t Merge_Sort(uint16_t Lower_Index, uint16_t Upper_index)
{
    int32_t ret, i;
	int32_t curr_index_left, curr_index_right, temp_index, left_bound, right_bound;
    uint16_t size;
    int index = 0;
	

    size = Upper_index - Lower_Index + 1;

    if (size == 1){
        return 0;
    }
    else if (size == 2){
        //swap if 1st element is greater than second element
        if (arr[Lower_Index] > arr[Upper_index]){
            int temp;
            temp = arr[Lower_Index];
            arr[Lower_Index] = arr[Upper_index];
            arr[Upper_index] = temp;
        }
        return 0;
    }
    else {
        //split array into Left and right  halves
        
        ret = Merge_Sort(Lower_Index, Lower_Index + (Upper_index - Lower_Index)/2);
        ret = Merge_Sort(Lower_Index + (Upper_index - Lower_Index)/2 + 1, Upper_index);

        //arrange the stuff here
        curr_index_left  = Lower_Index; 
        curr_index_right = Lower_Index + (Upper_index - Lower_Index)/2 + 1;
		left_bound       = Lower_Index + (Upper_index - Lower_Index) / 2;
		right_bound = Upper_index;
        
        while (curr_index_left <= left_bound && curr_index_right <= right_bound){
            
			if (arr[curr_index_left] <= arr[curr_index_right]){
                temp_arr[index++] = arr[curr_index_left++];

				/*Left side index enters right half. Bring all rigt side elements*/
				if (curr_index_left > left_bound) {
					while (curr_index_right <= right_bound) {
						temp_arr[index++] = arr[curr_index_right++];
					}
				}
            }
            else{
                temp_arr[index++] = arr[curr_index_right++];
				/*Right side index reaches end. Bring all Left side elements*/
				if (curr_index_right > right_bound) {
					while (curr_index_left <= left_bound) {
						temp_arr[index++] = arr[curr_index_left++];
					}
				}
            }            
        }
        temp_index = Lower_Index;
        for (i= Lower_Index; i<= Upper_index; i++)
        {
            arr[temp_index++] = temp_arr[i - Lower_Index];
        }
        
    }
	return 0;

}

int main(void)
{
    
    
	int i, prev, iter;
	/*Iterate it for NUM_ITERATIONS times*/
	for (iter = 0; iter < NUM_ITERATIONS; iter++) {

		/*For every iter, generate array values randomly*/
		for (i = 0; i < ARR_SIZE; i++)
		{
			arr[i] = rand();

		}
		Merge_Sort(0, ARR_SIZE - 1);
		prev = -1;
		for (i = 0; i < ARR_SIZE; i++)
		{
			//printf("sorted array element %d : %d \n", i, arr[i]);
			if (arr[i] < prev) {
				printf("something not correct");
				return -1;
			}
			else {
				prev = arr[i];
			}



		}
	}
	printf("Algorithm is working well Manas \n");
    return 0;
}