#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 7;
const long long MOD = 998244353;
const long long inf = INF * INF;
const long long mod = MOD;
const long long MAX = 100010;
const long double PI = acos(-1.0);
long long cnt;
long long dfs(long long i, long long p, vector<vector<long long> >& G) {
  long long ma = -1;
  for (auto e : G[i]) {
    if (e == p) continue;
    ma = max(ma, dfs(e, i, G));
  }
  if (ma == 0) {
    if (p != -1) cnt--;
    ma = -1;
  } else {
    ma = 0;
    cnt++;
  }
  return ma;
}
void solve() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    cnt = 0;
    vector<vector<long long> > G(n);
    for (long long i = (0); i < (n - 1); i++) {
      long long a, b;
      cin >> a >> b;
      a--;
      b--;
      G[a].push_back(b);
      G[b].push_back(a);
    }
    long long ans = 0;
    for (long long i = (0); i < (n); i++) {
      if (i != 0 && G[i].size() == 1) ans++;
    }
    dfs(0, -1, G);
    cout << cnt << '\n';
  }
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
}
