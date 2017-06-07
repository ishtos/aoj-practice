#include <iostream>
using namespace std;

#define MAX 100005

int search(int S[], int n, int key) {
  int high, mid, low;
  high = n, low = 0;
  mid = (high + low) / 2;
  
    while ( S[mid] != key && high > low) {
      if (S[mid] > key) high = mid;
      else if (S[mid] < key) low = mid + 1;
      mid = (high + low) / 2;
    }
  
  return S[mid] == key;
}

int main() {
  int n, q;
  int S[MAX];
  int key;
  int cnt = 0;
  
  cin >> n;
  for ( int i = 0; i < n; i++ ) {
    cin >> S[i];
  }

  cin >> q;
  for ( int i = 0; i < q; i++ ) {
    cin >> key;
    if ( search(S, n, key) ) cnt++;
  }

  cout << cnt << endl;

  return 0;
}
