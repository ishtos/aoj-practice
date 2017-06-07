#include <iostream>
using namespace std;

int A[1000000], n;

int binarySearch(int key) {
  int left = 0;
  int right = n;
  int mid;

  while ( left < right ) {
    mid = (left + right) / 2;
    if (A[mid] > key) right = mid;
    else if (A[mid] < key) left = mid + 1;
    else if (A[mid] == key) return 1;
  }
  return 0;
}

int main() {
  int q, k, sum = 0;

  cin >> n;
  for ( int i = 0; i < n; i++ ) {
    cin >> A[i];
  }

  cin >> q;
  for ( int i = 0; i < q; i++ ) {
    cin >> k;
    if ( binarySearch(k) ) sum++;
  }
  printf("%d\n", sum);

  return 0;
}
