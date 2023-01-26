#include <bits/stdc++.h>
using namespace std;
struct STree {
  vector<int> st, lazy;
  int n;
  STree(int n) : st(4 * n + 5, 0), lazy(4 * n + 5, 0), n(n) {}
  void push(int k, int s, int e) {
    if (!lazy[k]) return;
    st[k] += lazy[k];
    if (s + 1 < e) {
      lazy[2 * k] += lazy[k];
      lazy[2 * k + 1] += lazy[k];
    }
    lazy[k] = 0;
  }
  void upd(int k, int s, int e, int a, int b, int v) {
    push(k, s, e);
    if (s >= b || e <= a) return;
    if (s >= a && e <= b) {
      lazy[k] += v;
      push(k, s, e);
      return;
    }
    int m = (s + e) / 2;
    upd(2 * k, s, m, a, b, v);
    upd(2 * k + 1, m, e, a, b, v);
    st[k] = min(st[2 * k], st[2 * k + 1]);
  }
  int query(int k, int s, int e, int a, int b) {
    if (s >= b || e <= a) return 1e9;
    push(k, s, e);
    if (s >= a && e <= b) return st[k];
    int m = (s + e) / 2;
    return min(query(2 * k, s, m, a, b), query(2 * k + 1, m, e, a, b));
  }
  void upd(int a, int b, int v) { upd(1, 0, n, a, b, v); }
  int query(int a, int b) { return query(1, 0, n, a, b); }
};
vector<long long> oc[2000006];
long long cant = 0;
long long n, m;
void upd(long long x, STree &st) {
  for (auto i : oc[x - 1]) {
    st.upd(i, n, -1);
    cant++;
  }
  for (auto i : oc[x]) {
    st.upd(i, n, -1);
  }
}
struct STrees {
  vector<int> t;
  int n;
  STrees(int n) : t(2 * n + 5, 0), n(n) {}
  void upd(int p, int value) {
    for (t[p += n] += value; p > 1; p >>= 1) t[p >> 1] = t[p] + t[p ^ 1];
  }
  int query(int l, int r) {
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) res = res + t[l++];
      if (r & 1) res = res + t[--r];
    }
    return res;
  }
};
STrees str(2000009);
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    vector<long long> a(n), b(m);
    for (int i = 0, ggdem = n; i < ggdem; ++i) cin >> a[i];
    for (int i = 0, ggdem = m; i < ggdem; ++i) cin >> b[i];
    vector<long long> v = {0};
    for (auto i : a) v.push_back(i);
    for (auto i : b) v.push_back(i);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0, ggdem = n; i < ggdem; ++i)
      a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
    for (int i = 0, ggdem = m; i < ggdem; ++i)
      b[i] = lower_bound(v.begin(), v.end(), b[i]) - v.begin();
    sort(b.begin(), b.end());
    for (int i = 0, ggdem = ((int)v.size()) + 1; i < ggdem; ++i) oc[i].clear();
    for (int i = 0, ggdem = n; i < ggdem; ++i) oc[a[i]].push_back(i);
    STree st(n + 10);
    for (int i = 0, ggdem = n; i < ggdem; ++i) st.upd(i, i + 1, i + 1);
    long long ul = 0, res = 0;
    vector<pair<long long, long long>> ao;
    for (int i = 0, ggdem = n; i < ggdem; ++i) ao.push_back({a[i], i});
    sort(ao.begin(), ao.end());
    for (auto i : ao) {
      res += str.query(i.second, ((int)v.size()) + 1);
      str.upd(i.second, 1);
    }
    for (auto i : ao) str.upd(i.second, -1);
    cant = 0;
    for (auto i : b) {
      while (ul < i) {
        ul++;
        upd(ul, st);
      }
      res += cant + min(0, st.query(0, n));
    }
    cout << res << "\n";
  }
  return 0;
}
