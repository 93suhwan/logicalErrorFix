#include <bits/stdc++.h>
using namespace std;
int sort(int arr[], int n, int i, int arr1[], int m) {
  if (i == n) {
    return 0;
  }
  int smallest = arr[i];
  int index = i;
  for (int j = i + 1; j < n; j++) {
    if (arr[j] < smallest) {
      smallest = arr[j];
      index = j;
    }
  }
  int l = i;
  int r = index;
  int d = index - i;
  arr1[m] = l;
  arr1[m + 1] = r;
  arr1[m + 2] = d;
  return 1 + sort(arr, n, i + 1, arr1, m + 3);
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    int arr[n];
    int arr1[3 * n];
    for (int f = 0; f < n; f++) {
      cin >> arr[f];
    }
    int a = sort(arr, n, 0, arr1, 0);
    cout << a << endl;
    for (int j = 0; j < 3 * n; j += 3) {
      cout << arr1[j] << " " << arr1[j + 1] << " " << arr1[j + 2] << endl;
    }
  }
}
