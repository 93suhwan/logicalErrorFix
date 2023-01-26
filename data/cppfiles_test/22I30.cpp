#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7, N = 2e5 + 10;
const ll M = 810;
ll st[N];
ll seg[M][M];
ll strt[N];
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, m;
  cin >> n >> m;
  vector<array<ll, 2>> a(n);
  for (ll i = 0, x, y; i < n; ++i) {
    cin >> x >> y;
    a[i] = {x, y};
  }
  auto update = [&](ll x, ll y, ll inc) {
    st[x] += inc;
    st[y + 1] -= inc;
  };
  ll ans = 0;
  for (ll i = 0; i < m; ++i) {
    if (i) st[i] += st[i - 1];
    ll op, k;
    cin >> op >> k;
    --k;
    auto [x, y] = a[k];
    ll inc = (op == 1 ? 1 : -1);
    if (op == 1) {
      strt[k] = i;
    }
    ll s = x + y;
    if (x + y < M) {
      for (ll j = strt[k] + x; j < strt[k] + x + y; ++j) {
        seg[s][j % s] += inc;
      }
    } else {
      for (ll j = strt[k] + x; j < m; j += s) {
        if (j + y - 1 < i) continue;
        update(j, min(j + y - 1, m - 1), inc);
      }
    }
    ll ans = st[i];
    for (ll j = 2; j < M; ++j) {
      ans += seg[j][i % j];
    }
    cout << ans << '\n';
  }
  return 0;
}
