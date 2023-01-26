#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
template <typename T>
bool chmax(T &a, T b) {
  return a < b ? (a = b, 1) : 0;
}
template <typename T>
bool chmin(T &a, T b) {
  return a > b ? (a = b, 1) : 0;
}
inline ll ab(ll x) { return x < 0 ? -x : x; }
inline ll cdiv(ll a, ll b) { return (a + b - 1) / b; }
inline ll mpow(ll x, ll e, ll m) {
  ll r = 1;
  for (x %= m; e; e >>= 1, x = x * x % m)
    if (e & 1) r = r * x % m;
  return r;
}
#pragma g++ optimize("Ofast")
#pragma loop_opt(on)
const int inf = 2000000000;
const ll INF = 1000000000000000000;
const ll mod = 1000000007;
const double eps = 1e-9;
const int maxn = 10005;
string s[maxn];
int lef[maxn]{};
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
  }
  bool col[maxn]{};
  for (int i = 1; i <= n; ++i) {
    col[i] = (s[i][0] == '.' ? 1 : 0);
  }
  lef[1] = 1;
  for (int j = 2; j <= m; ++j) {
    bool col2[maxn]{};
    for (int i = 1; i <= n; ++i) {
      if (s[i][j - 1] == '.') {
        col2[i] |= (col[i] | col2[i - 1] | (i == 1));
        if (!col2[i]) {
          lef[j] = j;
          for (int i = 1; i <= n; ++i) {
            col[i] = (s[i][j - 1] == '.' ? 1 : 0);
          }
          break;
        }
      }
      if (i == n) {
        for (int i = 1; i <= n; ++i) {
          col[i] = col2[i];
        }
        lef[j] = lef[j - 1];
      }
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int a, b;
    cin >> a >> b;
    cout << (a >= lef[b] ? "YES\n" : "NO\n");
  }
  return 0;
}
