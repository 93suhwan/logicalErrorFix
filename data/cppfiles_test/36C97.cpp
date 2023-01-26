#include <bits/stdc++.h>
using namespace std;
bool is_prime(long long int n) {
  bool ans = 1;
  for (long long int i = 2; i <= sqrt(n); ++i) {
    if (n % i == 0) {
      ans = 0;
      break;
    }
  }
  return ans;
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long int T = 1;
  cin >> T;
  while (T--) {
    long long int n;
    cin >> n;
    long long int a[n];
    long long int sum = 0;
    long long int x;
    for (long long int i = 0; i < n; ++i) {
      cin >> a[i];
      if (a[i] & 1) x = i + 1;
      sum += a[i];
    }
    bool b = is_prime(sum);
    if (!b) {
      cout << n << "\n";
      for (long long int i = 1; i <= n; ++i) {
        cout << i << " ";
      }
      cout << "\n";
    } else {
      cout << n - 1 << "\n";
      for (long long int i = 1; i < x; ++i) {
        cout << i << " ";
      }
      for (long long int i = x + 1; i <= n; ++i) {
        cout << i << " ";
      }
      cout << "\n";
    }
  }
  return 0;
}
