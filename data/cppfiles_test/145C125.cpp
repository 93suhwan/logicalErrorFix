#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
int p[N], sz[N];
int get(int v) {
  if (p[v] == v) {
    return v;
  }
  return p[v] = get(p[v]);
}
void upd(int a, int b) {
  a = get(a), b = get(b);
  if (a == b) {
    return;
  }
  if (sz[a] > sz[b]) {
    swap(a, b);
  }
  p[a] = b;
  sz[b] += sz[a];
}
void solve() {
  int n, k;
  cin >> n >> k;
  fill(sz, sz + n, 1);
  iota(p, p + n, 0);
  vector<int> tm(n);
  vector<array<int, 3>> x;
  for (int i = 0; i < n; i++) {
    int xx, yy, t;
    cin >> xx >> yy >> t;
    x.push_back({xx, yy, i});
    tm[i] = t;
  }
  sort((x).begin(), (x).end(),
       [](const array<int, 3>& a, const array<int, 3>& b) {
         return make_pair(a[0], a[1]) < make_pair(b[0], b[1]);
       });
  for (int j = 0; j < (int)(x).size() - 1; j++) {
    if (x[j][0] == x[j + 1][0] && x[j + 1][1] - x[j][1] <= k) {
      upd(x[j][2], x[j + 1][2]);
    }
  }
  sort((x).begin(), (x).end(),
       [](const array<int, 3>& a, const array<int, 3>& b) {
         return make_pair(a[1], a[0]) < make_pair(b[1], b[0]);
       });
  for (int j = 0; j < (int)(x).size() - 1; j++) {
    if (x[j][1] == x[j + 1][1] && x[j + 1][0] - x[j][0] <= k) {
      upd(x[j][2], x[j + 1][2]);
    }
  }
  map<int, int> mn;
  for (int i = 0; i < n; i++) {
    if (mn.count(get(i))) {
      mn[get(i)] = min(mn[get(i)], tm[i]);
    } else {
      mn[get(i)] = tm[i];
    }
  }
  vector<int> y;
  for (auto& [_, i] : mn) {
    y.push_back(i);
  }
  int l = -1, r = 1e9 + 100;
  while (r - l > 1) {
    int m = (l + r) / 2;
    int cn = 0;
    for (int i : y) {
      if (i > m) {
        cn++;
      }
    }
    if (cn <= m + 1) {
      r = m;
    } else {
      l = m;
    }
  }
  cout << r << "\n";
}
signed main() {
  ios_base::sync_with_stdio();
  cin.tie(nullptr);
  int q;
  cin >> q;
  while (q--) {
    solve();
  }
  return 0;
}
