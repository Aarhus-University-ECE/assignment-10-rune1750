#include "btree.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>   

// Function to create a new node
struct tree_node* create_node(int x)
{
  struct tree_node* branch = (struct tree_node*)malloc(sizeof(struct tree_node));
  branch->data = x;
  branch->left = NULL;
  branch->right = NULL;

  return branch;
}

// Function to insert data into tree
struct tree_node* Insert(int x, struct tree_node* t) {
  if (t == NULL) {
    // if the tree is empty, a new node is made as the root. 
    t = create_node(x);
  }
  else if (x <= t->data) {
    // The place to store the data in the tree is checked recursively
    t->left = Insert(x, t->left);
  }
  else {
    t->right = Insert(x, t->right);
  }
  return t;
}

struct tree_node* Remove(int x, struct tree_node* t) {
  if (t == NULL) {
    return t;
    // Looking for input x  
  }
  else if (x < t->data) {
    t->left = Remove(x, t->left);
  }
  else if (x > t->data) {
    t->right = Remove(x, t->right);
  }
  else
    // If the input is not greater nor lesser than the data of the left/right
    // There are a two different options to consider
  {
    // Temporary node for storing the tree
    struct node* temp = t;
    // 1: In case there is no right/left child
    if (t->left == NULL && t->right == NULL) {
      free(t);
      t = NULL;
      // 2: There are children
    }
    else if (t->right == NULL) {
      t = t->left;
      free(temp);
    }
    else if (t->left == NULL) {
      t = t->right;
      free(temp);
      // 2.1 there are two children
    }
    else {
      if (t->left->data > t->right->data) {
        t = t->right;
        free(temp);
      }
      else {
        t = t->left;
        free(temp);
      }
    }
  }
  return t;
}

int Contains(int x, struct tree_node* t) {
  if (t == NULL) {
    return false;
    // recursive search for the input
  }
  else if (t->data == x) {
    return true;
  }
  else if (x <= t->data) {
    return Contains(x, t->left);
  }
  else {
    return Contains(x, t->right);
  }
}

struct tree_node* Initialize(struct tree_node* t) {
  t = NULL;

  return t;
}

// Function to check if tree is empty
int Empty(struct tree_node* t) {
  if (t == NULL) {
    return true;
  }
  else {
    return false;
  }
}

// Tree cant be full, since it is based off singly linked lists
/*
int Full(struct tree_node *t) {
  // Test if full
  return 0;
} */
