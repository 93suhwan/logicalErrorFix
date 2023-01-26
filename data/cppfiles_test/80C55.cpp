#include <bits/stdc++.h>
using namespace std;
const double pi = 3.14159265358979323846, eps = 1e-9;
const long long M = 1e9 + 7, I = 1e18;
const int mxn = 1e6, mxn1 = 2e6, lg = 20;
int t, n, m, a[mxn], b[mxn], sml[mxn + 1], smr[mxn + 1], tree[mxn1 * 4],
    pos[mxn];
vector<int> v, cur;
unordered_map<int, int> mp;
void build(int v, int l, int r) {
  if (r - l == 1) {
    tree[v] = 0;
    return;
  }
  build(v * 2 + 1, l, (r + l) / 2);
  build(v * 2 + 2, (r + l) / 2, r);
  tree[v] = 0;
}
void upd(int v, int l, int r, int pos) {
  if (l > pos or r <= pos) return;
  if (r - l == 1) {
    tree[v]++;
    return;
  }
  upd(v * 2 + 1, l, (r + l) / 2, pos);
  upd(v * 2 + 2, (r + l) / 2, r, pos);
  tree[v] = tree[v * 2 + 1] + tree[v * 2 + 2];
}
int get(int v, int l, int r, int ql, int qr) {
  if (l >= qr or r <= ql) return 0;
  if (l >= ql and r <= qr) return tree[v];
  return get(v * 2 + 1, l, (r + l) / 2, ql, qr) +
         get(v * 2 + 2, (r + l) / 2, r, ql, qr);
}
void f(int al, int ar, int bl, int br) {
  if (bl == br) return;
  int cur = b[(bl + br) / 2], ind = -1, mn = M, curl = -1, curr = -1;
  sml[al] = 0;
  for (int i = al + 1; i <= ar; i++) {
    sml[i] = sml[i - 1];
    if (a[i - 1] > cur) sml[i]++;
  }
  smr[ar] = 0;
  for (int i = ar - 1; i >= al; i--) {
    smr[i] = smr[i + 1];
    if (cur > a[i]) smr[i]++;
  }
  for (int i = al; i <= ar; i++) {
    if (smr[i] + sml[i] < mn) {
      mn = smr[i] + sml[i];
      curl = sml[i];
      curr = smr[i];
      ind = i;
    }
  }
  pos[(bl + br) / 2] = ind;
  f(al, ind, bl, (bl + br) / 2);
  f(ind, ar, (bl + br) / 2 + 1, br);
}
void solve() {
  v.clear();
  mp.clear();
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    v.push_back(a[i]);
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
    v.push_back(b[i]);
  }
  sort(v.begin(), v.end());
  int ln = (int)(unique(v.begin(), v.end()) - v.begin());
  for (int i = 0; i < ln; i++) {
    mp[v[i]] = i;
  }
  for (int i = 0; i < n; i++) a[i] = mp[a[i]];
  for (int i = 0; i < m; i++) b[i] = mp[b[i]];
  sort(b, b + m);
  f(0, n, 0, m);
  long long ans = 0;
  build(0, 0, ln);
  int ind = 0;
  for (int i = 0; i < n; i++) {
    while (ind < m and pos[ind] == i) {
      ans += (long long)get(0, 0, ln, b[ind] + 1, ln);
      ind++;
    }
    ans += (long long)get(0, 0, ln, a[i] + 1, ln);
    upd(0, 0, ln, a[i]);
  }
  while (ind < m) {
    ans += (long long)get(0, 0, ln, b[ind] + 1, ln);
    ind++;
  }
  build(0, 0, ln);
  ind = m - 1;
  while (pos[ind] == n) ind--;
  for (int i = n - 1; i >= 0; i--) {
    upd(0, 0, ln, a[i]);
    while (ind >= 0 and pos[ind] == i) {
      ans += (long long)get(0, 0, ln, 0, b[ind]);
      ind--;
    }
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  cin >> t;
  while (t--) solve();
}
