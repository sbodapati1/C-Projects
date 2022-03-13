#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct customers {
  char *name;
  char *fav_food;
  char *email_address;
  int shoe_size;
  struct customers *next;
} customers;

#define NUM_BUCKETS 100

unsigned long hash(char *str) {
  unsigned long hash = 5381;
  int c;
  while (*str != '\0') {
    c = *str;
    hash = ((hash << 5) + hash) + (unsigned char)c;
    str++;
  }
  return hash;
}

customers *RootNode = NULL;
customers *currentNode = NULL;

customers *add_customer(char *email_address, char *name, char *fav_food, int shoesize, customers *bucket) {
  customers* new_customer;

  new_customer = malloc(sizeof(customers));
  new_customer->email_address = strdup(email_address);
  new_customer->name = strdup(name);
  new_customer->fav_food = strdup(fav_food);
  new_customer->shoe_size = shoesize;
  new_customer->next = bucket;

  if(RootNode == NULL){
	  RootNode = new_customer;
	  currentNode = new_customer;
  }
  else{
	  currentNode->next = new_customer;
	  currentNode = new_customer;
  }
  return new_customer;
}

void add_to_hashtable(char *email_address, char *name, char *food, int shoe_size, customers **buckets, size_t num_buckets) {
  size_t which_bucket = hash(email_address) % num_buckets;
  buckets[which_bucket] = add_customer(email_address, name, food, shoe_size, buckets[which_bucket]);
}

char *fav_food_customer(char *email_address, customers **buckets,
    size_t num_buckets) {

  size_t which_bucket = hash(email_address) % num_buckets;

  char *result = NULL;
  customers* node;
  node = buckets[which_bucket];

  while(node != NULL) {
    if (strcmp(node->email_address, email_address) == 0) {
      result = node->fav_food;
    }
    node = node->next;
  }
  return result;
}

char *customer_name(char *email_address, customers **buckets,
    size_t num_buckets) {

  size_t which_bucket = hash(email_address) % num_buckets;

  char *result = NULL;
  customers* node;
  node = buckets[which_bucket];

  while(node != NULL) {
    if (strcmp(node->email_address, email_address) == 0) {
      result = node->name;
    }
    node = node->next;
  }
  return result;
}

char *customer_email_address(char *name, customers **buckets,
    size_t num_buckets) {

  size_t which_bucket = hash(name) % num_buckets;

  char *result1 = NULL;
  customers* node;
  node = buckets[which_bucket];

  while(node != NULL) {
    if (strcmp(node->name, name) == 0) {
      result1 = node->email_address;
    }
    node = node->next;
  }
  return result1;
}

int *customer_shoe_size(char *email_address, customers **buckets,
    size_t num_buckets) {

  size_t which_bucket = hash(email_address) % num_buckets;

  int *result2 = NULL;
  customers* node;
  node = buckets[which_bucket];

  while(node != NULL) {
    if (strcmp(node->email_address, email_address) == 0) {
      result2 = &node->shoe_size;
    }
    node = node->next;
  }
  return result2;
}

void delete_customer(char *email_address, customers **buckets, size_t num_buckets) {
	
  size_t which_bucket = hash(email_address) % num_buckets;
  customers* node;
  customers* prev_node;
  node = buckets[which_bucket];
  if (node != NULL){
     if(strcmp(node->email_address, email_address) != 0){	  
     node = RootNode;
     prev_node = node;
     do {
       if (strcmp(node->email_address, email_address) != 0){
	       prev_node = node;
	       node = node->next;
       }
       else {
	       prev_node->next = node->next;
	       free(node->email_address);
	       free(node->name);
	       free(node->fav_food);
	       free(node);
	       node = NULL;
	       buckets[which_bucket] = NULL;
      }
  }while(node != NULL);
}
}
}
int main(void) {
  FILE* fp = fopen("customers.tsv", "r");
  customers* buckets[NUM_BUCKETS] = {NULL};
  char *name;
  char *food;
  char *email;
  int shoesize = 0;
  customers* node = NULL;
  const size_t line_size = 100;
  char* line = malloc(line_size);
  while(fgets(line, line_size, fp) != NULL){
      line[strcspn(line, "\n")] = 0;
      email = strtok(line, "\t");
      if (email != NULL){
              name = strtok(NULL, "\t");
      }
      else{
	      continue;
      }
      if (name != NULL){
              shoesize = atoi(strtok(NULL, "\t"));
      }
      if (shoesize != 0){
              food = strtok(NULL, "\t");
      }
      add_to_hashtable(email, name, food, shoesize, buckets, NUM_BUCKETS);
  }
  fclose(fp);
  char command[7];
  char names[100];
  char favfood[100];
  char email_address[100];

  char add[7] = "add";
  char lookup[7] = "lookup";
  char delete[7] = "delete";
  char list[7] = "list";
  char save[7] = "save";
  char quit[7] = "quit";

  do{
	 printf("Enter command: ");
  	 scanf("%s", command);
 	 if(strcmp(command, add) == 0){
		printf("Enter customer's email address: ");
                scanf("%s", email_address);
                printf("Enter customer name: ");
		scanf(" %[^\n]", names);
		getchar();
		printf("Enter customer's favorite food: ");
        	scanf(" %[^\n]", favfood);
		printf("Enter customer's shoe size: ");
		scanf("%d", &shoesize);
	  	add_to_hashtable(email_address, names, favfood, shoesize, buckets, NUM_BUCKETS);
	  }
 	 else if(strcmp(command, lookup) == 0){
		printf("Enter customer's email address: ");
		scanf("%s", email_address);
		char *fav_food = NULL;
		char *name = NULL;
		fav_food = fav_food_customer(email_address, buckets, NUM_BUCKETS);
		if (fav_food == NULL){
			printf("Customer not found.\n");
		}
		else{
			int *shoe_size = customer_shoe_size(email_address, buckets, NUM_BUCKETS);
			name = customer_name(email_address, buckets, NUM_BUCKETS);
			printf("Customer's name: %s\n", name);
  			printf("%s's favorite food: %s\n", name, fav_food);
			printf("%s's email address: %s\n", name, email_address);
			printf("%s's shoe size: %d\n", name, *shoe_size);
		}
	  }
	 else if(strcmp(command, delete) == 0){
		printf("Enter customer's email address: ");
		scanf("%s", email_address);
                char *fav_food = NULL;
		fav_food = fav_food_customer(email_address, buckets, NUM_BUCKETS);
                if (fav_food == NULL){
                        printf("Customer not found.\n");
                }
                else{
	        	delete_customer(email_address, buckets, NUM_BUCKETS);
			printf("Customer is deleted.\n");
		}
	 }
	 else if(strcmp(command, list) == 0){
		node = RootNode;
		char *name;
		char *food;
		char *email;
    		int shoesize = 0;
     		while (node != NULL) {
			email = node->email_address;
			name = node->name;
			shoesize = node->shoe_size;
			food = node->fav_food;
			
			printf("email: %s \n", email);
			printf("name: %s \n", name);
			printf("shoesize: %d \n", shoesize);
			printf("food: %s \n", food);
			printf("---------------------------------\n");
 
       			node = node->next;
 
     		}
 
   	   }	
	  else if(strcmp(command, save) == 0){
		  node = RootNode;
		  if (node == NULL) {
       			printf("Nothing to save");
     		  } 
		  else {
      			FILE *fptr=fopen("customers.tsv","w");
 
       			do {
		         email = node->email_address;
		         name = node->name;
        		 shoesize = node->shoe_size;
		         food = node->fav_food;
		         fprintf(fptr, "%s\t%s\t%d\t%s\n", email, name, shoesize, food);
	        	 node = node->next;
		        } while (node != NULL);
 
		       fclose(fptr);
  		       printf("Database is saved. \n");
    		 }
  	 }
  }while (strcmp(command, quit) != 0);

  if(strcmp(command, quit) == 0){
	  exit(0);
  }
  fclose(fp);
  return 0;
}

