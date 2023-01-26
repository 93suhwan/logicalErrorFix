#include <bits/stdc++.h>
using namespace std;
int func(int arr[], int n) {
  int h = 1;
  h = h + arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] == 0 && arr[i - 1] == 0) return -1;
    if (arr[i - 1] == 1 && arr[i] == 1) {
      h = h + 5;
    } else
      h = h + arr[i];
  }
  return h;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    cout << func(arr, n) << "\n";
  }
  return 0;
}
