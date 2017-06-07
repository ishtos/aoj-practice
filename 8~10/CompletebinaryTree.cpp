#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define MAX 1000

struct Node {
  Node *parent, *left, *right;
  int key;
  int id;
};

Node *root, *NIL; 
int n;

void insert(int k) {
  Node *y = NIL;
  Node *x = root;
  Node *z;

  z = (Node *)malloc(sizeof(Node));
  z->key = k;
  z->left = NIL;
  z->right = NIL;
  
  while ( x != NIL ) {
    y = x;
    if ( x->left != NIL && x->right == NIL ) {
      x = x->right;
    } else {
      x = x->left;
    }
  }

  z->parent = y;
  if ( y == NIL ) {
    root = z;
  } else {
    if ( y->left == NIL ) {
      y->left = z;
    } else {
      y->right = z;
    }
  }
}

int i = 1;

void print(Node *N) {
  if ( N == NIL) return;
  printf("node %d: ", N->id);
  printf("key = %d, ", N->key);
  if ( N->parent != NIL ) {
    printf("parent key = %d, ", N->parent->key);
  }
  if ( N->left != NIL ) {
    printf("left key = %d, ", N->left->key);
  }
  if ( N->right != NIL ) {
    printf("right key = %d, ", N->right->key);
  }
  printf("\n");
  print(N->left);
  print(N->right);
}

  
int main() {
  int key;
  cin >> n;

  for ( int i = 0; i < n; i++ ) {
    scanf("%d", &key);
    insert(key);
  }

  print(root);
  return 0;
}
