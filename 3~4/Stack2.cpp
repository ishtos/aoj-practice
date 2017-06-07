#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
#include <cstdlib>
#include <cstdio>
using namespace std;

bool isNumeric(char buff[]) {
  int tmp = buff[0] - '0';
  if (tmp >= 0 && tmp <= 9) {
    return true;
  }

  return false;
}

int main() {
  char buff[100];
  int op1;
  int op2;
  int tmp;
  stack<int> st;

  while ( scanf("%s", buff) != EOF ) {
    if (isNumeric(buff)) {
      tmp = atoi(buff);
      st.push(tmp);
    }else {
      switch (buff[0]) {
      case '+':
	op1 = st.top();
	st.pop();
	op2 = st.top();
	st.pop();
	st.push(op2 + op1);
	break;
      case '*':
	op1 = st.top();
	st.pop();
	op2 = st.top();
	st.pop();
	st.push(op2 * op1);
	break;
      case '-':
	op1 = st.top();
	st.pop();
	op2 = st.top();
	st.pop();
	st.push(op2 - op1);
	break;
      case '/':
	op1 = st.top();
	st.pop();
	op2 = st.top();
	st.pop();
	st.push(op2 - op1);
	break;
      case '\n':
	break;
      case ' ':
	break;
      default:
	break;
      }
    }
  }

  tmp = st.top();
  printf("%d\n", tmp);

  return 0;
}
