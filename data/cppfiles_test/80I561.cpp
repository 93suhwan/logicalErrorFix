#include <bits/stdc++.h>
using namespace std;
long long f(long long n, string s) {
  long long res = 0;
  long long mult = 1;
  for (long long i = n - 1; i >= 0; i--) {
    if (s[i] == '1') res += mult;
    mult *= 2;
  }
  return res;
}
void solve() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  for (long long i = n / 2; i < n; i++) {
    if (s[i] == '0') {
      cout << 1 << ' ' << i << ' ' << 1 << ' ' << (i + 1) << '\n';
      return;
    }
  }
  if (s[n / 2 - 1] == '0') {
    cout << n / 2 << ' ' << n << ' ' << n / 2 + 1 << n << ' ' << '\n';
  } else {
    cout << n / 2 << ' ' << n - 1 << ' ' << n / 2 + 1 << ' ' << n << '\n';
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
