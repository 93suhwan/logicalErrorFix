#include <bits/stdc++.h>
using namespace std;
int binarySearch(int a[], int l, int r, int x) {
  if (r >= l) {
    int m = (l + r) / 2;
    if (a[m] == x) return m;
    if (a[m] > x)
      return binarySearch(a, l, m - 1, x);
    else
      return binarySearch(a, m + 1, r, x);
  }
  return -1;
}
void Swap(int *P, int *N) {
  int t = *P;
  *P = *N;
  *N = t;
}
void ReadArray(int a[], int n) {
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
}
void PrintArray(int a[], int n) {
  for (int i = 0; i < n; ++i) {
    cout << a[i] << " ";
  }
  cout << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    ReadArray(a, n);
    int num = a[0];
    for (int i = 1; i < n; ++i) {
      num = num & a[i];
    }
    cout << num << endl;
  }
}
