#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using ld = long double;
template <typename T>
int sz(T &x) {
  return (int)(x.size());
}
int power(int x, int y, int mod) {
  if (y == 0) {
    return 1;
  }
  int z = power(x, y >> 1, mod);
  z = z * 1ll * z % mod;
  if (y & 1) {
    z = z * 1ll * x % mod;
  }
  return z;
}
const int mod = 998244353;
const int inf = 1000000007;
void solve() {
  int n, m;
  cin >> n >> m;
  set<int> s;
  for (int i = 1; i <= n; ++i) {
    s.insert(i);
  }
  for (int i = 1; i <= m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    s.erase(c);
  }
  for (int i = 1; i <= n; ++i) {
    if (i == *s.begin()) {
      continue;
    }
    cout << i << " " << *s.begin() << "\n";
  }
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
