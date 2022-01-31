/* All of your code goes in here. You need to finish these functions.*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


/* Helper Functions */

int helper_max(int int1, int int2){
   if(int1 > int2){
	  return int1;
	          }
   else{
          return int2;
   }
}

int helper_pos(int int1, int int2){
  if(int2 > 0){
     int1 = int2 + int1;
  }
  return int1;
}

int helper_neg(int int1, int int2){
  if(int2 < 0){
     int1++;
  }
  return int1;
}


// Main Functions

int maximum(int *nums, int len) {
 int max = nums[0];
 for(int i = 0; i < len; i++){
    if(max < nums[i]){
      max = nums[i];
    }
  }
 return max;
}

int sum_positive(int *nums, int len) {
  int sum = 0;
  for(int i = 1; i < len; i++){
     if((nums[i] > 0)){
        sum = sum + nums[i];
     }
  }
  return sum;
}

int reduce(int *nums, int len, int (*f)(int,int), int initial){
  initial = 0;
  for(int i = 0; i < len; i++){
      initial = f(initial, nums[i]);
  }
  return initial;
}

int maximum_with_reduce(int *nums, int size) {
	return reduce(nums, size, helper_max, 0);
}

int sum_positive_with_reduce(int *nums, int size) {
	return reduce(nums, size, helper_pos, 0);
}

int count_negative_with_reduce(int *nums, int size) {
	return reduce(nums, size, helper_neg, 0);
}

