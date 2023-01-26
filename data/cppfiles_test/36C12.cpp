#include <bits/stdc++.h>
using namespace std;
bool prime(long long int n) {
  for (long long int i = 2; i < n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
signed main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int a[n];
    long long int sum = 0;
    for (long long int i = 0; i < (n); ++i) {
      cin >> a[i];
      sum += a[i];
    }
    long long int ans = -1;
    if (prime(sum)) {
      cout << n - 1 << "\n";
      long long int cnt = 0;
      for (long long int i = 0; i < (n); ++i) {
        if (a[i] % 2 == 0)
          cout << i + 1 << " ";
        else if (cnt >= 1)
          cout << i + 1 << " ";
        else
          cnt++;
      }
      cout << "\n";
    } else {
      cout << n << "\n";
      for (long long int i = 0; i < (n); ++i) cout << i + 1 << " ";
      cout << "\n";
    }
  }
  return 0;
}
