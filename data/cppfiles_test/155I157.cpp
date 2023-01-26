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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  int n;
  cin >> n;
  vector<int> pos(n + 1), p;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    pos[x] = i;
    p.push_back(i);
  }
  string s;
  cin >> s;
  sort(p.begin(), p.end(), [&](int i, int j) {
    return s[i] != s[j] ? s[i] < s[j] : pos[i] < pos[j];
  });
  for (int i : p) {
    cout << i << " ";
  }
  cout << "\n";
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
