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
int n, m, k, le[MAX], ri[MAX], x[MAX], c, st, cnt[MAX], nx[MAX], ls[MAX], hit,
    nw;
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
    for (int i = (1); i <= (k); ++i) cin >> x[i];
    for (int i = (2); i <= (k); ++i) {
      if ((nx[x[i - 1]] && nx[x[i - 1]] != x[i]) ||
          (ls[x[i]] && ls[x[i]] != x[i - 1]) || x[i] == x[i - 1])
        return cout << "0\n", 0;
      nx[x[i - 1]] = x[i];
      ls[x[i]] = x[i - 1];
    }
  }
  for (int i = (1); i <= (c); ++i)
    if (!ls[i]) {
      if (!nx[i])
        ++cnt[1];
      else {
        nw = i, hit = 1;
        while (nx[nw]) nw = nx[nw], ++hit;
        ++cnt[hit];
      }
    }
  for (int i = (1); i <= (m); ++i)
    if (cnt[i]) v.push_back({i, cnt[i]});
  memset(&dp, -1, sizeof dp);
  cout << f(m) << '\n';
  return 0;
}
