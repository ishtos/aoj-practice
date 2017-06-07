#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <string>
using namespace std;
// 実行結果がおかしい merge

#define MAX 100000
#define INF 2000000000

typedef struct {
  char suit;
  int value;
} Card;

Card L[MAX / 2 + 2], R[MAX / 2 + 2];

int partition(Card A[], int p, int r) {
  Card x;
  x = A[r];
  int i = p - 1;
  for ( int j = p; j < r; j++ ) {
    if ( A[j].value <= x.value ) {
      i++;
      swap(A[i], A[j]);
    }
  }
  swap(A[i + 1], A[r]);
  return i + 1;
}

void quickSort(Card A[], int p, int r) {
  if ( p < r ) {
    int q = partition(A, p, r);
    quickSort(A, p, q - 1);
    quickSort(A, q + 1, r);
  }
}

void merge(Card B[], int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  for ( int i = 0; i < n1; i++ ) L[i] = B[left + i];
  for ( int i = 0; i < n2; i++ ) R[i] = B[mid + 1];
  L[n1].value = R[n2].value = INF;
  int i, j;
  i = j = 0;
  for ( int k = left; k < right; k++ ) {
    if ( L[i].value <= R[j].value ) B[k] = L[i++];
    else B[k] = R[j++];
  }
}

void mergeSort(Card B[], int left, int right) {
  if ( left + 1 < right ) {
    int mid = (left + right) / 2;
    mergeSort(B, left, mid);
    mergeSort(B, mid, right);
    merge(B, left, mid, right);
  }
}


int main() {
  int n;
  Card A[MAX];
  Card B[MAX];
  char S[10];
  int v;
  int stable = 1;
  
  cin >> n;
  for ( int i = 0; i < n; i++ ) {
    scanf("%s %d", S, &v);
    B[i].suit = A[i].suit = S[0];
    B[i].value = A[i].value = v;
  }

  quickSort(A, 0, n - 1);
  mergeSort(B, 0, n);

  for ( int i = 0; i < n; i++ ) {
    if ( A[i].suit != B[i].suit ) {
      stable = 0;
      break;
    }
  }

  if ( stable == 1 ) printf("Stable\n");
  else printf("Not stable\n");
  for ( int i = 0; i < n; i++ ) {
    cout << A[i].suit << " " << A[i].value << endl;
  }

  cout << endl << endl;
  for ( int i = 0; i < n; i++ ) {
    cout << B[i].suit << " " << B[i].value << endl;
  } 
  return 0;
}
