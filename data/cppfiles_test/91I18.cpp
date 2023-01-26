#include <bits/stdc++.h>
#pragma optimize(3)
using namespace std;
const int maxn = 1e5 + 11, maxm = 1e5 + 11, inf_int = 0x3f3f3f3f;
const long long inf_ll = 0x3f3f3f3f3f3f3f, mod = 998244353;
const double eps = 1e-6;
const long long inv2 = (mod + 1) / 2;
struct custom_hash {
  static size_t splitmix64(size_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(size_t x) const {
    static const size_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
unordered_map<int, int, custom_hash> f[2];
int n, a[maxn], pre, cur;
long long ans, en[maxn];
inline long long DP(int x, int v) {
  if (x == 0) return 0;
  if (f[pre].count(v)) return f[pre][v];
  long long res = 0, tv = v;
  for (int i = x; i; i--)
    if (v == 1) {
      res = (res + en[i]) % mod;
      break;
    } else {
      int t0 = (a[i] + v - 1) / v;
      res = (res + 1ll * i * (t0 - 1) % mod) % mod;
      v = a[i] / t0;
    }
  return f[cur][tv] = res;
}
inline void solve() {
  cin >> n, ans = 0, cur = 1, pre = 0;
  for (int i = 1; i <= n; i++) cin >> a[i], en[i] = a[i] - 1 + en[i - 1];
  f[pre].clear();
  for (int i = 1; i < n; i++) {
    f[cur].clear();
    ans = (ans + DP(i, a[i + 1])) % mod;
    swap(cur, pre);
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int TEST = 1;
  cin >> TEST;
  while (TEST--) solve();
}
