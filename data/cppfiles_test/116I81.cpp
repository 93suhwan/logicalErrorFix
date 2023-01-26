#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
const int MAX = 1e6 + 5;
const long long MOD = 998244353;
const long long MOD2 = 2010405347;
const long long INF = 2e18;
const int dr[] = {1, 0, -1, 0, 1, 1, -1, -1, 0};
const int dc[] = {0, 1, 0, -1, 1, -1, 1, -1, 0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 315;
inline long long pw(long long x, long long y, long long md = MOD) {
  long long ret = 1;
  x %= md;
  while (y) {
    if (y & 1) ret = ret * x % md;
    x = x * x % md, y >>= 1;
  }
  return ret;
}
inline void add(int &a, int b, int md = MOD) {
  a = a + b >= md ? a + b - md : a + b;
}
int n, m, k, le[MAX], ri[MAX], x[MAX], c, id, pos, st, vis[MAX], idx[MAX],
    cnt[MAX], tmp, a, b;
long long ans, dp[MAX];
vector<pair<int, int> > v;
long long f(int rem) {
  if (!rem) return 1;
  if (dp[rem] != -1) return dp[rem];
  long long ret = 0;
  for (pair<int, int> &i : v) {
    if (i.first > rem) break;
    ret += f(rem - i.first) * i.second;
  }
  return dp[rem] = ret % MOD;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> c;
  for (int i = (1); i <= (n); ++i) {
    cin >> k;
    pos = -1;
    for (int i = (0); i < (k); ++i) {
      cin >> x[i];
      if (vis[x[i]]) {
        if (pos == -1) pos = vis[x[i]];
        if (pos != vis[x[i]]) return cout << "0\n", 0;
        st = idx[x[i]] - i;
      }
    }
    if (pos == -1) {
      ++id;
      for (int i = (0); i < (k); ++i) {
        vis[x[i]] = id;
        idx[x[i]] = i;
      }
      le[id] = 0, ri[id] = k - 1;
      continue;
    }
    a = 0;
    if (le[pos] > st) {
      a = le[pos] - st;
      st += a;
      for (int i = (a - 1); i >= (0); --i) {
        --le[pos];
        if (vis[x[i]]) return cout << "0\n", 0;
        vis[x[i]] = pos;
        idx[x[i]] = le[pos];
      }
    }
    for (int i = (a); i < (k); ++i) {
      if (st <= ri[pos]) {
        ++ri[pos];
        if (vis[x[i]]) return cout << "0\n", 0;
        vis[x[i]] = pos;
        idx[x[i]] = ri[pos];
      } else {
        if (idx[x[i]] != st) return cout << "0\n", 0;
      }
      ++st;
    }
  }
  for (int i = (1); i <= (c); ++i) cnt[1] += !vis[i];
  for (int i = (1); i <= (id); ++i) cnt[ri[i] - le[i] + 1]++;
  for (int i = (1); i <= (m); ++i)
    if (cnt[i]) v.push_back({i, cnt[i]});
  memset(&dp, -1, sizeof dp);
  cout << f(m) << '\n';
  return 0;
}
