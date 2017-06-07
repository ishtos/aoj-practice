#include <iostream>
#include <cstdio>
using namespace std;

#define MAX 500005
#define INF 2000000000

int L[MAX/2 + 2], R[MAX/2 + 2];
int cnt;

void merge(int A[], int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;

  for ( int i = 0; i < n1; i++ ) L[i] = A[left + i];
  for ( int i = 0; i < n2; i++ ) R[i] = A[mid + i];
  L[n1] = R[n2] = INF;
  int i = 0, j = 0;
  for ( int k = left; k < right; k++ ) {
    cnt++;
    if ( L[i] <= R[j] ) A[k] = L[i++];
    else A[k] = R[j++];
  }
}

void mergeSort(int A[], int left, int right) {
  if ( left + 1 < right ) {
    int mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main() {
  int n;
  int A[MAX];
  
  cin >> n;
  for ( int i = 0; i < n; i++ ) {
    cin >> A[i];
  }

  mergeSort(A, 0, n);

  for ( int i = 0; i < n; i++ ) {
    if ( i > 0 ) printf(" ");
    printf("%d", A[i]);
  }
  cout << endl << cnt << endl;

  return 0;
}


