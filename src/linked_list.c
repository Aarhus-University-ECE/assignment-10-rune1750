#include <assert.h> /* assert */
#include <stdio.h>  /* printf */
#include <stdlib.h> /* malloc, free */
#include "linked_list.h"
#include <math.h>

/* functions to create lists */
node *make_node(int v, node *q) {
  node *p = malloc(sizeof(node));
  p->value = v;
  p->next = q;
  return p;
}

/* free all nodes in the list p */
void free_list(node *p) {
  node *q;
  while (p != NULL) {
    q = p->next;
    free(p);
    p = q;
  }
}

// Prints data to console and runs the void again 
// with the node *p updated to be the next element in the array
void print_list(node *p) {
if(p != NULL){
printf("%d \n", p->value);  
print_list(p->next);  
}
}

// Uses <math.h> pow function to calculate the square of numbers
// the sum of the numbers is returned
int sum_squares(node *p) {
  // Add your code for excercise 2
  // You can find the tests in tests.cpp
  if(p==NULL){
    return 0; 
  }
  else{
  return square(p->value) + sum_squares(p->next);
  }
}

typedef int (*fn_int_to_int)(int);

// Function to take a linked list and create a new linked list
// With integer values squared from the previous linked list
node *map(node *p, fn_int_to_int f) { 
  if (p == NULL){
    return NULL; 
  }else{
    return make_node(f(p->value), map(p->next, f)); 
  }
  return NULL; 
}

int square(int x) { return x * x; }

// example of another function that can be passed to map
// returns the sign of the number
// -1 if negative, 0 if zero, 1 if positive
int sign(int x) { return x == 0 ? 0 : (x < 0 ? -1 : 1); }
