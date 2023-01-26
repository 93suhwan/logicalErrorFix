#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
const int S = 2e5 + 10;
vector<int> g[S];
vector<int> c;
int dfs(int u, int p) {
  int ret = u;
  for (int it : g[u]) {
    if (it != p) {
      int x = dfs(it, u);
      if (c[x] > c[ret]) ret = x;
    }
  }
  c[ret]++;
  return ret;
}
ll f(ll x) { return x / 2 * (x - x / 2); }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n, k;
  cin >> n >> k;
  c.assign(n, 0);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(0, 0);
  sort(c.begin(), c.end(), greater<int>());
  c.erase(lower_bound(c.begin(), c.end(), 0, greater<int>()), c.end());
  ll ans = 0;
  if (k >= c.size()) {
    ans = f(n);
  } else {
    ll w = 0;
    for (int i = 0; i < k; i++) {
      w += c[i] - 1;
    }
    ll b = n - w - k;
    if (b > k) {
      b -= k;
      if (w <= b)
        ans = -w * b;
      else
        ans = -f(w + b);
    } else {
      ans = (k - b) * w;
    }
  }
  cout << ans << '\n';
  return 0;
}
