#include <iostream>
using namespace std;

#define MAX   100
#define INFTY (1 << 21)
#define WHITE 0
#define GRAY  1
#define BLACK 2

int n, M[MAX][MAX];

int prim() {
  int d[MAX], p[MAX], color[MAX];
  int u, minv;

  for ( int i = 0; i < n; i++ ) {
    d[i] = INFTY;
    p[i] = -1;
    color[i] = WHITE;
  }

  d[0] = 0;

  while ( 1 ) {
    minv = INFTY;
    u = -1;
    for ( int i = 0; i < n; i++ ) {
      if ( minv > d[i] && color[i] != BLACK ) {
	u = i;
	minv = d[i];
      }
    }
    if ( u == -1 ) break;
    color[u] = BLACK;
    for ( int v = 0; v < n; v++ ) {
      if ( color[v] != BLACK && M[u][v] != INFTY ) {
	if ( d[v] > M[u][v] ) {
	  d[v] = M[u][v];
	  p[v] = u;
	  color[v] = GRAY;
	}
      }
    }
  }
  int sum = 0;
  for ( int i = 0; i < n; i++ ) {
    if ( p[i] != -1 ) sum += M[i][p[i]];
  }

  return sum;
}


int main() {
  cin >> n;
  
  for ( int i = 0; i < n; i++ ) {
    for ( int j = 0; j < n; j++ ) {
      int e;
      cin >> e;
      M[i][j] = (e == -1) ? INFTY : e;
    }
  }
  
  cout << prim() << endl;
  
  return 0;
}
