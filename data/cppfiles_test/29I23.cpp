#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int c0 = 0;
    long long int c1 = 0;
    long long int arr[n];
    for (long long int i = 0; i < n; i++) {
      cin >> arr[i];
      if (arr[i] == 0) c0++;
      if (arr[i] == 1) c1++;
    }
    cout << c1 * (pow(2, c0)) << "\n";
  }
  return 0;
}
