#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using ull = unsigned long long;
using db = long double;
const int N = 2e5 + 5, LG = 18, MOD = 1e9 + 7;
const long double PI = acos(-1);
int fast(int b, int e) {
  int res = 1;
  for (; e; e >>= 1, b = 1ll * b * b % MOD)
    if (e & 1) res = 1ll * res * b % MOD;
  return res;
}
const int DIV100 = fast(100, MOD - 2);
void doWork() {
  vector<vector<bool>> vis[2][2];
  int n, m, p;
  cin >> n >> m;
  int rb, cb, rd, cd;
  cin >> rb >> cb >> rd >> cd >> p;
  int dr = -1, dc = -1;
  const int neg = 1ll * (100 - p) * DIV100 % MOD;
  const int pos = 1ll * p * DIV100 % MOD;
  ll cnt = 0, prop = 1;
  for (int i = 1; i <= 4 * (n - 1) * (m - 1); i++) {
    if (rb + dr < 1 || rb + dr > n) dr = -dr;
    if (cb + dc < 1 || cb + dc > m) dc = -dc;
    cnt = (cnt + 1) % MOD;
    rb += dr;
    cb += dc;
    if (rb == rd || cb == cd) {
      cnt = 1ll * cnt * neg % MOD;
      prop = 1ll * prop * neg % MOD;
    }
  }
  cout << fast((1ll + MOD - prop), MOD - 2) * cnt % MOD << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    doWork();
  }
  return 0;
}
