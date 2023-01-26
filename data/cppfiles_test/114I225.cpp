#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, M = 2e5 + 5, mod = 998244353, INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long qpow(long long a, long long b) {
  long long c = 1;
  while (b) {
    if (b & 1) c = (c * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return c % mod;
}
long long inv(long long x) { return qpow(x, mod - 2); }
int a[15][N];
int c[N];
int n, m;
pair<int, int> p[15];
int cnt[15];
map<vector<int>, int> mp;
vector<int> res;
int ans = 0;
void dfs(int k, vector<int> g, int sum) {
  if (k == n + 1) {
    if (sum > ans) {
      if (!mp.count(g)) {
        if (sum > ans) {
          ans = sum;
          res = g;
        }
      }
    }
    return;
  }
  for (int i = c[k]; i >= c[k] - cnt[k] + 1; i--) {
    sum += a[k][i];
    g.push_back(i);
    dfs(k + 1, g, sum);
    sum -= a[k][i];
    g.pop_back();
  }
}
int main() {
  int _ = 1;
  for (int qq = 1; qq <= _; qq++) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> c[i];
      p[i] = {c[i], i};
      for (int j = 1; j <= c[i]; j++) cin >> a[i][j];
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
      vector<int> g;
      g.clear();
      for (int j = 1; j <= n; j++) {
        int a;
        scanf("%d", &a);
        g.push_back(a);
      }
      mp[g] = 1;
    }
    sort(p + 1, p + n + 1);
    for (int i = 1; i <= n; i++) {
      long long cur = 1;
      int k = 1;
      for (int j = 1; j <= m; j++) {
        cur = qpow(j, n - i + 1);
        if (cur >= m) {
          k = j;
          break;
        }
      }
      if (p[i].first >= k) {
        cnt[p[i].second] = k;
        m = ceil(m * 1.0 / p[i].first);
      } else
        cnt[p[i].second] = p[i].first, m = ceil(m * 1.0 / p[i].first);
    }
    vector<int> g;
    g.clear();
    dfs(1, g, 0);
    for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
  }
  return 0;
}
