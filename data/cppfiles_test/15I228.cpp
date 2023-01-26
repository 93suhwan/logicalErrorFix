#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long int;
const int maxx = 105;
const int mod = 1000000007;
ll power(ll n, ll first, ll mod) {
  if (first < 0) return 0ll;
  if (first == 0) return 1ll;
  ll cur = power(n, first / 2, mod);
  if (first & 1) return (cur % mod * cur % mod * n) % mod;
  return (cur % mod * cur % mod) % mod;
}
ll mul(ll a, ll b, ll mod) {
  if (b == 0) return 0ll;
  ll cur = mul(a, b / 2, mod);
  if (b & 1) {
    return (2 * cur + a) % mod;
  }
  return (2 * cur) % mod;
}
ll gcd(ll a, ll b, ll& first, ll& second) {
  if (b == 0) {
    first = 1;
    second = 0;
    return a;
  }
  ll x1, y1;
  ll g = gcd(b, a % b, x1, y1);
  first = y1;
  y1 = x1 - a / b * y1;
  return g;
}
vector<int> edge[maxx];
ll f[maxx][maxx], h[maxx], visit[maxx], cnt[maxx];
void solve() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i <= n; ++i) {
    edge[i].clear();
  }
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  if (k == 2) {
    cout << (n * (n - 1) / 2) % mod << '\n';
    return;
  }
  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    memset(visit, 0, sizeof visit);
    visit[i] = 1;
    vector<pair<int, int> > tmp;
    int m = edge[i].size();
    for (int e = 0; e < m; ++e) {
      tmp.push_back({edge[i][e], e});
      cnt[e] = 1;
      visit[edge[i][e]] = 1;
    }
    while (1) {
      if (tmp.empty()) break;
      memset(f, 0, sizeof f);
      f[0][0] = 1;
      for (int j = 1; j <= m; ++j) {
        for (int t = 1; t <= k; ++t) {
          f[j][t] = (f[j][t] + f[j - 1][t]) % mod;
          f[j][t] = (f[j][t] + cnt[j - 1] * f[j - 1][t - 1]) % mod;
        }
      }
      ans += f[m][k];
      vector<pair<int, int> > cur;
      for (auto p : tmp) {
        cnt[p.second]--;
        for (auto second : edge[p.first])
          if (!visit[second]) {
            cur.emplace_back(second, p.second);
            visit[second] = true;
            cnt[p.second]++;
          }
        tmp = cur;
      }
    }
  }
  cout << ans << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
