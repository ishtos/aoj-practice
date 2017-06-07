#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
#include <cstdlib>
#include <cstdio>
using namespace std;

int top, S[1000];

void push(int x) {
  S[++top] = x;
}

int pop() {
  top--;
  return S[top+1];
}

int main() {
  int a, b;
  top = 0;
  char s[100];

  while ( scanf("%s", s) != EOF ) {
    if ( s[0] == '+' ) {
      a = pop();
      b = pop();
      push(b + a);
    } else if ( s[0] == '-' ) {
      a = pop();
      b = pop();
      push(b - a);
    } else if ( s[0] == '*' ) {
      a = pop();
      b = pop();
      push(b * a);
    } else if ( s[0] == '/' ) {
      a = pop();
      b = pop();
    } else {
      push(atoi(s));
    }
  }

  printf("%d\n", pop());

  return 0;
}
