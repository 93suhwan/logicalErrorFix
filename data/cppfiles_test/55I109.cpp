#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int N = 6e5 + 10;
int n, m;
vector<vector<int>> inp;
map<int, int> conv;
int mx;
vector<pii> vec[N];
pii t[4 * N];
pii lazy[4 * N];
void push(int v) {
  if (lazy[v].first == 0) return;
  lazy[v * 2] = max(lazy[v * 2], lazy[v]);
  lazy[v * 2 + 1] = max(lazy[v * 2 + 1], lazy[v]);
  t[v * 2] = max(t[v * 2], lazy[v]);
  t[v * 2 + 1] = max(t[v * 2 + 1], lazy[v]);
  lazy[v] = make_pair(0, 0);
}
void update(int v, int tl, int tr, int l, int r, pii val) {
  if (l > r || tr < l || r < tl) return;
  if (l <= tl && tr <= r) {
    t[v] = max(t[v], val);
    lazy[v] = max(lazy[v], val);
    return;
  }
  int tm = (tl + tr) / 2;
  push(v);
  update(v * 2, tl, tm, l, r, val);
  update(v * 2 + 1, tm + 1, tr, l, r, val);
}
pii ask(int v, int tl, int tr, int l, int r) {
  if (l > r || tr < l || r < tl) return make_pair(0, 0);
  if (l <= tl && tr <= r) return t[v];
  int tm = (tl + tr) / 2;
  push(v);
  return max(ask(v * 2, tl, tm, l, r), ask(v * 2 + 1, tm + 1, tr, l, r));
}
int dp[N], par[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  inp.resize(m);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < 3; j++) {
      int a;
      cin >> a;
      inp[i].push_back(a);
      if (j) conv[a] = 1;
    }
  }
  {
    mx = 0;
    for (auto& x : conv) {
      x.second = ++mx;
    }
    for (auto& x : inp) {
      for (int i = 1; i < 3; i++) {
        x[i] = conv[x[i]];
      }
      vec[x[0]].push_back(make_pair(x[1], x[2]));
    }
  }
  int ans = 0;
  int cur = 0;
  for (int i = 1; i <= n; i++) {
    pii p = make_pair(0, 0);
    for (auto& x : vec[i]) {
      p = max(p, ask(1, 1, mx, x.first, x.second));
    }
    dp[i] = p.first + 1;
    par[i] = p.second;
    for (auto& x : vec[i]) {
      update(1, 1, mx, x.first, x.second, make_pair(dp[i], i));
    }
    if (dp[i] > dp[cur]) cur = i;
  }
  vector<bool> msk(n + 1, 0);
  int len = n;
  while (cur != 0) {
    msk[cur] = 1;
    cur = par[cur];
    len--;
  }
  cout << len << '\n';
  if (len) {
    for (int i = 1; i <= n; i++) {
      if (msk[i]) continue;
      cout << i << ' ';
    }
    cout << '\n';
  }
  return 0;
}
