#include <iostream>
using namespace std;

#define MAX 100

int cnt;
int n;

void BubbleSort(int A[]) {
  for ( int i = 0; i < n; i++ ) {
    for ( int j = n - 1;  j > 0; j--) {
      if (A[j] < A[j - 1]) {
	swap(A[j], A[j- 1]);
	cnt++;
      }
    }
  }
}

int main() {
  int A[MAX];

  cin >> n;

  for ( int i = 0; i < n; i++ ) {
    cin >> A[i];
  }
  
  BubbleSort(A);

  for ( int i = 0; i < n - 1; i++ ) {
    cout << A[i] << " " << flush;
  }
  cout << A[n - 1] << endl;
  cout << cnt << endl;
  
  return 0;
}
