#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7, N = 1e5 + 10;
void test() {
  ll n, k;
  cin >> n >> k;
  vector<array<ll, 4>> a(n);
  ll c = 0;
  for (auto &[x, y, z, idx] : a) {
    cin >> x >> y >> z;
    idx = c++;
  }
  auto can = [&](ll cutoff) {
    auto b = a;
    vector<vector<ll>> g(n);
    sort(begin(b), end(b));
    for (ll i = 0; i + 1 < n; ++i) {
      auto [x, y, timer, idx] = b[i];
      auto [nx, ny, ntimer, nidx] = b[i + 1];
      if (nx == x and ny - y <= k) {
        g[idx].push_back(nidx);
        g[nidx].push_back(idx);
      }
    }
    for (auto &[x, y, timer, idx] : b) {
      swap(x, y);
    }
    sort(begin(b), end(b));
    for (ll i = 0; i + 1 < n; ++i) {
      auto [x, y, timer, idx] = b[i];
      auto [nx, ny, ntimer, nidx] = b[i + 1];
      if (nx == x and ny - y <= k) {
        g[idx].push_back(nidx);
        g[nidx].push_back(idx);
      }
    }
    queue<ll> q;
    vector<ll> vis(n);
    for (auto &[x, y, timer, idx] : b) {
      if (timer <= cutoff) {
        q.push(idx);
        vis[idx] = 1;
      }
    }
    while (!q.empty()) {
      ll u = q.front();
      q.pop();
      for (ll v : g[u]) {
        if (!vis[v]) {
          q.push(v);
          vis[v] = 1;
        }
      }
    }
    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
      if (!vis[i]) {
        q.push(i);
        while (!q.empty()) {
          ll u = q.front();
          q.pop();
          for (ll v : g[u]) {
            if (!vis[v]) {
              q.push(v);
              vis[v] = 1;
            }
          }
        }
        ++ans;
      }
    }
    return ans <= cutoff + 1;
  };
  ll l = 0, r = MOD;
  ll ans = r;
  while (l <= r) {
    ll m = (l + r) / 2;
    if (can(m)) {
      ans = m;
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  cout << ans << '\n';
  return;
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ll tt = 1;
  cin >> tt;
  for (ll t = 1; t <= tt; ++t) {
    test();
  }
  return 0;
}
