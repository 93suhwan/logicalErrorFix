#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int arr[n];
    for (long long int i = 0; i < n; i++) cin >> arr[i];
    long long int i = 0;
    while (true) {
      if (is_sorted(arr, arr + n) == true) break;
      i++;
      if (i % 2 != 0) {
        for (long long int j = 0; j < n - 1; j = j + 2)
          if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
      } else {
        for (long long int j = 1; j < n; j = j + 2)
          if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
      }
    }
    cout << i << "\n";
  }
}
