#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long n, i;
    cin >> n;
    if (n == 1) {
      long x;
      cin >> x;
      cout << x << endl;
    } else {
      long arr[n], arr1[n];
      for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr1[i] = arr[i];
      }
      sort(arr, arr + n);
      sort(arr1, arr1 + n);
      for (i = 1; i < n; i++) arr[i] -= arr1[i - 1];
      long m = arr[0];
      for (i = 1; i < n; i++) m = max(m, arr[i]);
      cout << m << endl;
    }
  }
}
