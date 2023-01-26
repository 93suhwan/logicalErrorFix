#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
void solve() {
  long long n;
  cin >> n;
  long long sum = 0;
  vector<long long> a(n);
  for (long long i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  if (sum == 0) {
    for (long long i = 0; i < n; ++i) {
      cout << 1 << " ";
    }
    cout << '\n';
    return;
  }
  for (long long i = 0; i < n; ++i) {
    long long x = sum - a[i];
    if (x % a[i] == 0) {
      for (long long j = 0; j < n; j++) {
        if (j == i)
          cout << x / a[i] << " ";
        else
          cout << 1 << " ";
      }
      cout << '\n';
      return;
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  for (long long i = 1; i <= t; i++) {
    solve();
  }
}
