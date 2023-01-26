#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,abm,mmx,tune=native")
using namespace std;
long long gcd(long long i, long long j) {
  if (j == 0)
    return i;
  else
    return gcd(j, i % j);
}
template <typename T>
inline T getint() {
  T val = 0;
  char c;
  bool neg = false;
  while ((c = getchar()) && !(c >= '0' && c <= '9')) {
    neg |= c == '-';
  }
  do {
    val = (val * 10) + c - '0';
  } while ((c = getchar()) && (c >= '0' && c <= '9'));
  return val * (neg ? -1 : 1);
}
const long long INF = 1e9 + 100;
const int mod = 998244353;
const double eps = 1e-11, pi = acos(-1);
const long long maxN = 13, maxT = 600100, A = 179, K = 170;
mt19937 mt_rand(time(0));
long long bp(long long et, long long b) {
  b %= mod - 1;
  et %= mod;
  long long res = 1;
  for (int i = 30; i >= 0; --i) {
    res = (res * res) % mod;
    if ((b & (1 << i)) != 0) res = (res * et) % mod;
  }
  return res;
}
void panic() {
  cout << "-1\n";
  exit(0);
}
long long c[maxN][maxN];
long long f[maxN];
void build() {
  f[0] = 1;
  for (int i = 1; i < maxN; ++i) f[i] = f[i - 1] * i;
  for (int i = 0; i < maxN; ++i) {
    c[i][0] = c[0][i] = 1;
  }
  for (int i = 1; i < maxN; ++i) {
    for (int j = 1; j < maxN; ++j) {
      c[i][j] = c[i - 1][j] + c[i][j - 1];
    }
  }
}
long long C(int n, int k) { return c[n - k][k]; }
long long AA(int n, int k) { return f[n] / f[n - k]; }
int g[maxN][maxN];
int n;
int used[maxN];
set<vector<int>> clr[maxN];
vector<pair<int, int>> pr;
vector<int> col;
void rec1(int lvl, int clrr = 1) {
  if (lvl == n / 2) {
    clr[clrr - 1].insert(col);
    return;
  }
  for (int i = 1; i <= clrr; ++i) {
    col[pr[lvl].first - 1] = col[pr[lvl].second - 1] = i;
    rec1(lvl + 1, clrr + (i == clrr));
  }
}
void rec(int lvl) {
  if (lvl == n / 2) {
    vector<int> tmp(n / 2);
    for (int i = 0; i < n / 2; ++i) tmp[i] = i;
    bool gg = 0;
    do {
      bool gd = 1;
      for (int i = 1; i < n / 2; ++i) {
        if (!g[pr[tmp[i - 1]].first][pr[tmp[i]].first] ||
            !g[pr[tmp[i - 1]].second][pr[tmp[i]].second]) {
          if (!g[pr[tmp[i - 1]].first][pr[tmp[i]].second] ||
              !g[pr[tmp[i - 1]].second][pr[tmp[i]].first]) {
            gd = 0;
            break;
          }
        }
      }
      gd &= g[pr[tmp.back()].first][pr[tmp.back()].second];
      if (gd) {
        gg = 1;
        break;
      }
    } while (next_permutation(tmp.begin(), tmp.end()));
    if (!gg) return;
    col.assign(n, 0);
    rec1(0);
    return;
  }
  int st = 1;
  while (used[st]) ++st;
  for (int to = st + 1; to <= n; ++to) {
    if (used[to]) continue;
    used[st] = used[to] = 1;
    pr.push_back({st, to});
    rec(lvl + 1);
    pr.pop_back();
    used[st] = used[to] = 0;
  }
}
void solve() {
  build();
  int m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    g[a][b] = g[b][a] = 1;
  }
  rec(0);
  long long ans = 0;
  for (int i = 1; i <= k; ++i) {
    long long tmp = AA(k, i);
    ans += (long long)clr[i].size() * tmp;
  }
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.precision(20);
  srand(time(0));
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
