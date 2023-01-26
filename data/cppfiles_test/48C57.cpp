#include <bits/stdc++.h>
using namespace std;
long long ans = 0, A[500000];
int partition(long long arr[], int low, int high) {
  int r = low + rand() % (high - low + 1);
  if (r != high) {
    swap(arr[r], arr[high]);
    ans++;
  }
  int pivot = arr[high];
  int i = (low - 1);
  for (int j = low; j <= high - 1; j++) {
    if (arr[j] < pivot) {
      i++;
      swap(arr[i], arr[j]);
      if (i != j) ans++;
    }
  }
  swap(arr[i + 1], arr[high]);
  if (i + 1 != high) ans++;
  return (i + 1);
}
void quickSort(long long arr[], int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}
int main() {
  long long T, i, j, n, m, k;
  cin >> T;
  while (T--) {
    cin >> n;
    for (i = 0; i < n; ++i) {
      cin >> A[i];
    }
    ans = 0;
    quickSort(A, 0, n - 1);
    for (i = 1; i < n; ++i)
      if (A[i] == A[i - 1]) break;
    if (i < n)
      cout << "YES\n";
    else if (ans % 2)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
}
