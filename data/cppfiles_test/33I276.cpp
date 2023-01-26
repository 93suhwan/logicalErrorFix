#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int arr[n];
    long long int p = 0;
    long long int in = 0;
    for (long long int i = 0; i < n; i++) {
      cin >> arr[i];
      if (arr[i] > p) {
        p = arr[i];
        in = i;
      }
    }
    if (in + 1 == n) {
      cout << arr[in] * arr[in - 1] << endl;
    } else if (in == 0) {
      cout << arr[0] * arr[1] << endl;
    } else {
      long long int k = max(arr[in - 1], arr[in + 1]);
      cout << (arr[in] * k) << endl;
    }
  }
}
