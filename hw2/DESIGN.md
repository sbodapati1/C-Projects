# HW 2: Functions, Arrays, and Pointers

## Purpose

The purpose of this assignment is to use functions, arrays, and pointers to look at an array of integers given by the user, find it's length, and return the maximum element of that array. We will also be looking at the sum of all the positive elements of an array and will have the find all the negative numbers in an array to fulfill the purpose of this assignment.

### Layout/Structure and Pseudocode

Function names for this assignment were already given, so I will need to finish these functions to finish the assignment. I will also need three helper functions to correspond with the last three fiven functions.

These are helper functions.

int helper_0(value of integers){
	if (integer is greater than value(second number) and its index is less than length of list){
		return integer;
	}
	else{
		return value;
	}

int helper_1(value of integers){
	if (integer is greater than 0){
	   sum = add first int to second int;
	return sum;
}

int helper_2(value of integers){
        if (integer is less than 0){
           return int;
        }
        else{
           return 0;
        }       
}

These are the given functions.

int maximum(int *nums, int len) {
       for(int i = 0, i < len, i++):
	if i is greatest in the array:
	  return i;
}

int sum_positive(int *nums, int len) {
	int sum = 0
	if(int is positive):
	   add int to sum;
	return sum;
}

int reduce(int *nums, int len, int (*f)(int,int), int initial){
       int value = initial value;
       for(int i = 0, i < len, i++):
	   int val = i + value using *f magic function;
	return val;

}

int maximum_with_reduce(int *nums, int size) {
	call reduce with nums, size, helper function, and initial value;
}

int sum_positive_with_reduce(int *nums, int size) {
	call reduce with nums, size, helper function, and initial value;
}

int count_negative_with_reduce(int *nums, int size) {
  	call reduce to return count of negative numbers;
}
