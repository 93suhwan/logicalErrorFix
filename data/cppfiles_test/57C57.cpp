#include <bits/stdc++.h>
using namespace std;
const int P = 1e9 + 7;
const int maxn = 5e3 + 10;
const int maxm = 2e6 + 10;
const int INF = 0x3f3f3f3f;
template <class T>
T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
template <class T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
long long s, n, k;
void solve() {
  cin >> s >> n >> k;
  if (s == k) {
    cout << "YES\n";
    return;
  }
  long long p = s / k;
  long long r = s % k;
  long long cnt = 2 * ceil((p - 1) / 2.0) + ceil((1 + p) / 2.0) * (r - 1) +
                  ceil(p / 2.0) * (k - r - 1);
  if (cnt >= n - 1)
    cout << "NO\n";
  else
    cout << "YES\n";
}
signed main() {
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
