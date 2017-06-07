#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100

int cnt;

void SelectionSort(int A[], int N) {
  for ( int i = 0; i < N; i++ ) {
    int min = i;
    for ( int j = i; j < N; j++) {
      if (A[j] < A[min]) {
	min = j;
      }
    }
    if (A[i] != A[min]) {
      swap(A[i], A[min]);
      cnt++;
    }
  }
}

int main() {
  int N;
  int A[MAX];

  cin >> N;

  for ( int i = 0; i < N; i++ ) {
    cin >> A[i];
  }

  SelectionSort(A, N);

  for ( int i = 0; i < N - 1; i++) {
    cout << A[i] << " " << flush;
  }
  cout << A[N - 1] << endl;
  cout << cnt << endl;

  return 0;
}
