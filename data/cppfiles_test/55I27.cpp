#include <bits/stdc++.h>
using namespace std;
const int mxN = 6e5 + 5;
int tree[4 * mxN];
int lazy[4 * mxN];
void propagate(int x, int lx, int rx) {
  if (lx == rx) return;
  lazy[x << 1] = tree[x << 1] = tree[x];
  lazy[x << 1 | 1] = tree[x << 1 | 1] = tree[x];
  lazy[x] = 0;
}
void update(int x, int lx, int rx, int l, int r, int v) {
  if (lazy[x]) propagate(x, lx, rx);
  if (lx > r || l > rx) return;
  if (l <= lx && r >= rx) {
    tree[x] = v;
    lazy[x] = v;
    return;
  }
  int mx = (lx + rx) >> 1;
  update(x << 1, lx, mx, l, r, v);
  update(x << 1 | 1, mx + 1, rx, l, r, v);
  tree[x] = min(tree[x << 1], tree[x << 1 | 1]);
}
int query(int x, int lx, int rx, int l, int r) {
  if (lazy[x]) propagate(x, lx, rx);
  if (lx > r || l > rx) return 1e9;
  if (l <= lx && r >= rx) return tree[x];
  int mx = (lx + rx) >> 1;
  return min(query(x << 1, lx, mx, l, r), query(x << 1 | 1, mx + 1, rx, l, r));
}
int mxt[4 * mxN];
int lmx[4 * mxN];
void prop(int x, int lx, int rx) {
  if (lx == rx) return;
  mxt[x << 1] = lmx[x << 1] = mxt[x];
  mxt[x << 1 | 1] = lmx[x << 1 | 1] = mxt[x];
  lmx[x] = 0;
}
void updat(int x, int lx, int rx, int l, int r, int v) {
  if (lmx[x]) prop(x, lx, rx);
  if (lx > r || l > rx) return;
  if (l <= lx && r >= rx) {
    mxt[x] = v;
    lmx[x] = v;
    return;
  }
  int mx = (lx + rx) >> 1;
  updat(x << 1, lx, mx, l, r, v);
  updat(x << 1 | 1, mx + 1, rx, l, r, v);
  mxt[x] = max(mxt[x << 1], mxt[x << 1 | 1]);
}
int quer(int x, int lx, int rx, int l, int r) {
  if (lmx[x]) prop(x, lx, rx);
  if (lx > r || l > rx) return 0;
  if (l <= lx && r >= rx) return mxt[x];
  int mx = (lx + rx) >> 1;
  return max(quer(x << 1, lx, mx, l, r), quer(x << 1 | 1, mx + 1, rx, l, r));
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> v[n + 5];
  vector<int> all;
  for (int i = 0; i < m; i++) {
    int j, l, r;
    cin >> j >> l >> r;
    v[j].push_back({l, r});
    all.push_back(l);
    all.push_back(r);
  }
  map<int, int> mp;
  int id = 1;
  sort(all.begin(), all.end());
  for (int x : all) {
    if (!mp[x]) mp[x] = id++;
  }
  for (int i = 1; i <= n; i++) {
    for (auto &[l, r] : v[i]) l = mp[l], r = mp[r];
  }
  vector<int> rdp(n + 5);
  update(1, 1, 2 * m, 1, 2 * m, n + 5);
  vector<int> rnxt(n + 5);
  for (int i = n; i >= 1; i--) {
    int mn = n + 5;
    for (auto [l, r] : v[i]) mn = min(mn, query(1, 1, 2 * m, l, r));
    for (auto [l, r] : v[i]) update(1, 1, 2 * m, l, r, i);
    rdp[i] = (mn == n + 5 ? n - i : mn - i - 1 + rdp[mn]);
    rnxt[i] = mn;
  }
  vector<int> ldp(n + 5);
  vector<int> lnxt(n + 5);
  updat(1, 1, 2 * m, 1, 2 * m, 0);
  for (int i = 1; i <= n; i++) {
    int mx = 0;
    for (auto [l, r] : v[i]) mx = max(mx, quer(1, 1, 2 * m, l, r));
    for (auto [l, r] : v[i]) updat(1, 1, 2 * m, l, r, i);
    ldp[i] = (mx == 0 ? i - 1 : i - mx - 1 + ldp[mx]);
    lnxt[i] = mx;
  }
  int ans = 1e9;
  for (int i = 1; i <= n; i++) ans = min(ans, ldp[i] + rdp[i]);
  set<int> st;
  cout << ans << "\n";
  for (int i = 1; i <= n; i++) st.insert(i);
  for (int i = 1; i <= n; i++) {
    if (ans == ldp[i] + rdp[i]) {
      st.erase(i);
      int ii = lnxt[i];
      while (ii > 0) st.erase(ii), ii = lnxt[ii];
      ii = rnxt[i];
      while (ii <= n) st.erase(ii), ii = rnxt[ii];
      break;
    }
  }
  for (int x : st) cout << x << " ";
  cout << "\n";
  return 0;
}
