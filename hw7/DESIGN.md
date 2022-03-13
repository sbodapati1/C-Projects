# Homework 7: Hash tables, I/O, strings

## Purpose
We are building an e-commerce business that sells snacks and shoes, and we will be using hash tables to complete this task. We will need to read a database file from the disk, add customers, delete customers, and save the database back to the file. Every customer has an email address, name, shoe size, and favorite food. The customers will be stored in a hash table. The program prompts the user for commands, which include add, lookup, delete, list, save, and quit. We will also need to free all the memory that we allocated throughout the program.

### Potential Problems
I think a problem I will face for sure is freeing memory. I will need to check that before I submit. Navigating the linked lists and buckets will also be difficult because we don't have much experience with hash tables and buckets, and I wish I had more experience with linked lists. These are broad descriptions of potential broad problems, but I am pretty sure this will be the most difficult part of this assignment.

#### Layout and Psuedocode

As the general layout and beginning of this code, I will be using the Professor's code from the demos. After that, I will add on to it to complete the program. I will also need to make a Makefile to test this program.

```

define struct {
  key for name;
  favorite food;
  email address;
  shoesize;
  struct node;
} node;

def hashtable {
  initialize hash table;
 
  while loop{
    set hash equal to equation;
    increase iterable;
  }
  return hash;
}

function to prompt user for command{
	ask user for prompt
}

```

IF THE COMMAND IS ADD:

```

Function to add customer to list{
  newnode;

  initialize array;
  node for name;
  fav food;
  email address;
  shoe size;
  add to bucket;

  return added customer;
}

Function to add customer to hash table{

  decide which bucket to add customer to;
  add customer to bucket;
}

function to add favorite food to hash table{

  decide which bucket to add it to;
  initialize node;
  while node to check if node is null {
    if (strcmp(node->name, name) == 0) {
      add favorite food;
    }
    node = node->next;
  }
  return result;
}

function to add email address to hash table{

  decide which bucket to add it to;
  initialize node;
  while node to check if node is nul {
    if (strcmp(node->name, name) == 0) {
      add email address;
    }
    node = node->next;
  }
  return result;
}

function to add shoe size to hash table{

  decide which bucket to add it to;
  initialize node;
  while node to check if node is null {
    if (strcmp(node->name, name) == 0) {
      add shoe size;
    }
    node = node->next;
  }
  return result;
}

function to free memory{
	free memory
}

```

IF COMMAND IS LOOKUP:

```

function to show information{
	if customer in hashtable{
		print info
}
	else{
		tell user customer was not found
}}

```

IF COMMAND IS DELETE:

```

function to delete{
        if customer in hashtable{
                delete customer
}
        else{
                tell user customer was not found
}}

```

IF COMMAND IS LIST:

```

function to list{
       print all info in hash table, neatly formatted
}


```

IF COMMAND IS SAVE:

```

function to save{
	write current state of database back to customers.tsv
}

```

IF COMMAND IS QUIT:

```

function to quit{
	free memory and close program
}
```
