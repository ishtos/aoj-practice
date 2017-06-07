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

Node* find(Node *u, int k) {
  while ( u != NIL && u->key != k) {
    if ( k < u->key ) {
      u = u->left;
    } else if ( k > u->key ) {
      u = u->right;
    }
  }
  return u;
}

Node* treeMinimum(Node *x) {
  while ( x->left != NIL ) x = x->left;
  return x;
}

Node* treeSuccessor(Node *x) {
  if ( x->right != NIL ) return treeMinimum(x->right);
  Node *y = x->parent;
  while ( y != NIL && x == y->right ) {
    x = y;
    y = y->parent;
  }
  return y;
}

void deleteNode(Node *z) {
  Node *y;
  Node *x;

  if ( z->left == NIL || z->right == NIL ) y = z;
  else y = treeSuccessor(z);

  if ( y->left != NIL ) {
    x = y->left;
  } else {
    x = y->right;
  }

  if ( x != NIL ) {
    x->parent = y->parent;
  }

  if ( y->parent == NIL ) {
    root = x;
  } else {
    if ( y == y->parent->left ) {
      y->parent->left = x;
    } else {
      y->parent->right = x;
    }
  }

  if ( y != z ) {
    z->key = y->key;
  }

  free(y);
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
      Node *t = find(root, key);
      if ( t != NIL ) {
	printf("yes\n");
      } else {
	printf("no\n");
      }
    } else if ( com == "delete" ) {
      scanf("%d", &key);
      deleteNode(find(root, key));
    } else if ( com == "print" ) {
      inorder(root);
      printf("\n");
      preorder(root);
      printf("\n");
    }
  }

  return 0;
}
