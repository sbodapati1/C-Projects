#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// PROBLEM 1

long long *fibonacci_numbers(int n) {
  // You're going to have to allocate an array, fill it in, and return it.
  // The array should be of length n.
  // Recall the first few entries should be 1, 1, 2, 3, 5, 8, ...
  long long* output = NULL;
  int f1 = 1;
  int f2 = 1;
  output[0] = f2;
  while(sizeof output < n){
	  for(int i=1; i<n ;i++){
		output[i] = f1 + f2;
		f1 = f2;
		f2 = output[i];
	  }
  }
  return output;
}


// PROBLEM 2

typedef struct {
  int shoe_size;
  int customer_id;
  int num_purchases;
} ShoeCustomer;

void bubble_sort_customers(ShoeCustomer* customers, int n_customers) {
  // Your code here! Make them sorted!
  int i, j;
  while(1){
	  for(i = 0; i < n_customers-1; i++){
		  for(j = 1; j < n_customers-1; j++){
			  if(customers[i].shoe_size>customers[j].shoe_size){
				  int place = customers[i].shoe_size;
				  customers[i].shoe_size = customers[j].shoe_size;
				  customers[j].shoe_size = place;
				  //printf("s%", customers);
			  }
		  }
	  }
	  if(customers[i].shoe_size < customers[j].shoe_size){
		  break;
	  } 
  }					  
}

// PROBLEM 3

// A linked list of floating point numbers.
typedef struct LLfloat {
  float val;
  struct LLfloat *next;
} LLfloat;

LLfloat *map_floats(float (*f)(float), LLfloat *numbers)  {
  // finish this function.
  // Should it be recursive? It's up to you, but it could be recursive!
  LLfloat* old = numbers;
  while(old != NULL){
		struct LLfloat *new =(struct LLfloat*)malloc(sizeof(struct LLfloat));
		new->val=f(old->val);
		new->next=&(*new);
		new = pow((new->next), 2);
		return new;
	}
}

void node_free(struct node **new) {
  // your code here
  free(*new);
  *new = NULL;
}

// PROBLEM 4

unsigned long compute_availability(unsigned long *calendars, int num_users) {
  unsigned long availability = 0;
  unsigned long total[64];
  for(int i = 0; i < 64; i++){
	  for(int j = 1; j > num_users; j++){
		  if((*(&calendars + i)+j) == 0){
			  total[i] = 0;
		  }
		  else{
			  total[i] = 1;
			  break;
		  }
		  availability = availability | ((unsigned long total[i] < (i*64));
  }
  return availability;
}

// put examples for testing your functions in the main! You're going to have to
// figure out how to test these.
int main(void) {
  // Question1
  //long long result = *fibonacci_numbers(int 10);
  //printf("%lld", result);
  // Question2
  //void bubble_sort_customers(ShoeCustomer* customers, int n_customers);
  // Question3
  //LLfloat result1 = LLfloat *map_floats(float (*f)(float), LLfloat *numbers=[1, 2, 3, 4]);
  //printf("%lld", result1);  
  //node_free(*new);
  //return 0;
  // Question4
  //unsigned long compute_availability(unsigned long *calendars, int num_users);

}
