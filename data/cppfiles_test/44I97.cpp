#include <bits/stdc++.h>
using namespace std;
long long binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
const long long N = 0;
void solve() {
  long long a, b;
  cin >> a >> b;
  long long d = abs(a - b);
  if (d & 1) {
    cout << -1 << "\n";
    return;
  }
  if (a == b) {
    cout << 1 << "\n";
    return;
  }
  cout << 2 << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
