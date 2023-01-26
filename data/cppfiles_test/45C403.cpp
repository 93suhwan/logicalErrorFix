#include <bits/stdc++.h>
using namespace std;
long long mul(long long a, long long b) {
  a %= 1000000007;
  b %= 1000000007;
  a *= b;
  a += 1000000007;
  return a % 1000000007;
}
long long po(long long a, long long b) {
  if (b == 0) return 1;
  if (b % 2 == 0) return po(mul(a, a), b / 2);
  return mul(a, po(mul(a, a), (b - 1) / 2));
}
void solve() {
  long long n, ans = 1;
  cin >> n;
  vector<long long> v(n);
  for (long long i = 0; i < n; i += 1) cin >> v[i];
  for (long long i = 0; i < n; i += 1) {
    if (v[i] == 0) {
      if (i != 0 && v[i - 1] == 0) {
        cout << -1 << "\n";
        return;
      }
    }
    if (v[i] == 1) {
      if (i != 0 && v[i - 1] == 1)
        ans += 5;
      else
        ans++;
    }
  }
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
