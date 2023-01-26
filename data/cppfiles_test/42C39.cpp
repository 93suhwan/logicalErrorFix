#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 99, mod = 1e9 + 7;
int n, t, q, a[N], ps[N], vis[N], mark[N], Ft[N];
pair<pair<int, int>, int> b[N];
int Fen[N];
void update(int x, int val) {
  x++;
  while (x < N) {
    Fen[x] = (Fen[x] + val) % mod;
    x += (x & -x);
  }
}
int query(int x) {
  x++;
  int res = 0;
  while (x > 0) {
    res = (res + Fen[x]) % mod;
    x -= (x & -x);
  }
  return res;
}
void read() {
  cin >> n;
  for (int i = 1; i < n + 1; i++) {
    int u, v;
    cin >> u >> v;
    b[i] = make_pair(make_pair(u, v), i);
    vis[v] = 1;
  }
  for (int i = 1; i < 2 * n + 1; i++) vis[i] += vis[i - 1];
  sort(b + 1, b + 1 + n);
  for (int i = 1; i < n + 1; i++) {
    Ft[b[i].second] = i;
    a[i] = vis[b[i].first.second];
  }
  cin >> q;
  for (int i = 0; i < q; i++) {
    int u;
    cin >> u;
    u = Ft[u];
    mark[u] = 1;
  }
  int mx = 0;
  for (int i = n; i >= 1; i--) {
    if (mark[i]) mx = max(mx, a[i]);
    if (a[i] < mx) mark[i] = 1;
  }
}
void solve() {
  int ans = 0, mn = n;
  fill(ps, ps + N, -1);
  for (int i = 1; i < n + 1; i++) {
    if (mark[i]) {
      int copy = mn;
      mn = min(mn, a[i]);
      ps[i + 1] = mn - 1;
      mn = copy;
    } else {
      mn = min(mn, a[i]);
    }
  }
  update(0, 1);
  for (int i = n; i >= 1; i--) {
    update(a[i], query(a[i]));
    if (ps[i] != -1) ans = (ans + query(ps[i])) % mod;
  }
  cout << ans + mark[n];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  read();
  solve();
}
