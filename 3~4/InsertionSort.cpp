#include <iostream>
#include <vector>
using namespace std;

#define MAX 1000

void show(int A[], int N) {
  for ( int i = 0; i < N - 1; i++ ) {
    cout << A[i] << " " << flush;
  }
  cout << A[N - 1] << endl;
}

void insertionSort(int A[], int N) {
  show(A, N);
  
  for ( int i = 1; i < N; i++ ) {
    int v = A[i];
    int j = i - 1;
    while ( j >= 0 && A[j] > v ) {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = v;
    show(A, N);
  }
}

int main() {
  int N;
  int A[MAX];

  cin >> N;
  for ( int i = 0; i < N; i++ ) {
    cin >> A[i];
  }

  insertionSort(A, N);

  return 0;
}
