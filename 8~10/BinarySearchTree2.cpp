#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

struct Node {
  int key;
  Node *parent, *left, *right;
};

Node *root, *NIL;

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
    if ( z->key < x->key ) {
      x = x->left;
    } else {
      x = x->right;
    }
  }

  z->parent = y;
  if ( y == NIL ) {
    root = z;
  } else {
    if ( z->key < y->key ) {
      y->left = z;
    } else {
      y->right = z;
    }
  }
}

bool find(int k) {
  Node *x = root;

  while ( x != NIL ) {
    if ( k < x->key ) {
      x = x->left;
    } else if ( k > x->key ) {
      x = x->right;
    } else {
      return true;
    }
  }
  return false;
}

void inorder(Node *u) {
  if ( u == NIL ) return;
  inorder(u->left);
  printf(" %d", u->key);
  inorder(u->right);
}

void preorder(Node *u) {
  if ( u == NIL ) return;
  printf(" %d", u->key);
  preorder(u->left);
  preorder(u->right);
}

int main() {
  int n;
  int key;
  string com;

  cin >> n;
  for ( int i = 0; i < n; i++ ) {
    cin >> com;
    if ( com == "insert" ) {
      scanf("%d", &key);
      insert(key);
    } else if ( com == "find" ) {
      scanf("%d", &key);
      if ( find(key) ) {
	printf("yes\n");
      } else {
	printf("no\n");
      }
    } else if ( com == "print" ) {
      inorder(root);
      printf("\n");
      preorder(root);
      printf("\n");
    }
  }

  return 0;
}
