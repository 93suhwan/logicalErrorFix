#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << H;
  debug_out(T...);
}
const int N = 10010;
char s[N];
int x[N], y[N], sa[N], height[N], rk[N], c[N];
int n, m;
void get_sa() {
  for (int i = 1; i <= n; ++i) ++c[x[i] = s[i]];
  for (int i = 1; i <= m; ++i) c[i] += c[i - 1];
  for (int i = n; i >= 1; --i) sa[c[x[i]]--] = i;
  for (int k = 1; k <= n; k <<= 1) {
    int num = 0;
    for (int i = n - k + 1; i <= n; ++i) y[++num] = i;
    for (int i = 1; i <= n; ++i)
      if (sa[i] > k) y[++num] = sa[i] - k;
    for (int i = 1; i <= m; ++i) c[i] = 0;
    for (int i = 1; i <= n; ++i) ++c[x[i]];
    for (int i = 1; i <= m; ++i) c[i] += c[i - 1];
    for (int i = n; i >= 1; --i) sa[c[x[y[i]]]--] = y[i], y[i] = 0;
    swap(x, y), num = 1, x[sa[1]] = 1;
    for (int i = 2; i <= n; ++i)
      x[sa[i]] = (y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k])
                     ? num
                     : ++num;
    if (num == n) break;
    m = num;
  }
}
void get_height() {
  for (int i = 1; i <= n; ++i) rk[sa[i]] = i;
  for (int i = 1, k = 0; i <= n; ++i) {
    if (rk[i] == 1) continue;
    if (k) --k;
    int j = sa[rk[i] - 1];
    while (i + k <= n && j + k <= n && s[i + k] == s[j + k]) ++k;
    height[rk[i]] = k;
  }
}
ll d[N];
int f[N][20], loog[N];
void init() {
  for (int j = 0; 1 << j <= n; j++) {
    for (int i = 1; i + (1 << j) - 1 <= n; i++) {
      if (!j)
        f[i][j] = height[i];
      else
        f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
    }
  }
  loog[1] = 0;
  for (int i = 2; i <= n; i++) loog[i] = loog[i / 2] + 1;
}
int query(int l, int r) {
  int len = r - l + 1, k = loog[len];
  return min(f[l][k], f[r - (1 << k) + 1][k]);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> (s + 1);
    m = 300;
    for (int i = 0; i <= max(m, 2 * n); i++) x[i] = y[i] = c[i] = 0;
    for (int i = 1; i <= n; i++) d[i] = n - i + 1;
    get_sa();
    get_height();
    init();
    ll res = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j < i; j++) {
        int l = rk[i], r = rk[j];
        if (l > r) swap(l, r);
        int len = query(l + 1, r);
        if (len != n - i + 1 && s[i + len] > s[j + len])
          d[i] = max(d[i], d[j] + n - i + 1 - len);
      }
      res = max(res, d[i]);
    }
    cout << res << '\n';
  }
  return 0;
}
