#include <bits/stdc++.h>
const long long MOD = 1000000007;
long long exp(long long b, long long p, long long m) {
  long long res = 1;
  p %= m;
  while (p > 0) {
    if (m & 1) res = res * b % m;
    b = b * b % m;
    p >>= 1;
  }
  return res;
}
using namespace std;
void solve() {
  int n;
  cin >> n;
  int d[n];
  for (int i = 0; i < n; i = i + 1) cin >> d[i];
  bool ok = false;
  if (n & 1) {
    for (int i = 1; i < n; i++) {
      if (d[i - 1] >= d[i]) {
        ok = true;
        break;
      }
    }
  } else
    ok = true;
  if (ok)
    cout << "YES\n";
  else
    cout << "NO\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
