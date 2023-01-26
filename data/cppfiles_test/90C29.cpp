#include <bits/stdc++.h>
using namespace std;
template <class T>
struct segtree {
  vector<T> tree, lazy;
  function<T(T, T)> func;
  T def;
  int n;
  segtree(int n, T def, function<T(T, T)> f) : n(n), func(f), def(def) {
    tree.resize(4 * n, def);
    lazy.resize(4 * n, def);
  };
  void push(int s, int e, int ind) {
    if (lazy[ind] == def) return;
    tree[ind] = func(tree[ind], lazy[ind]);
    if (s != e) {
      lazy[ind << 1] = func(lazy[ind << 1], lazy[ind]);
      lazy[ind << 1 ^ 1] = func(lazy[ind << 1 | 1], lazy[ind]);
    }
    lazy[ind] = def;
  }
  void update(int l, int r, T x, int s, int e, int ind) {
    push(s, e, ind);
    if (l > e || s > r) return;
    if (s >= l && e <= r) {
      lazy[ind] = x;
      push(s, e, ind);
      return;
    }
    int mid = (s + e) >> 1;
    update(l, r, x, s, mid, ind << 1);
    update(l, r, x, mid + 1, e, ind << 1 | 1);
    tree[ind] = func(tree[ind << 1], tree[ind << 1 | 1]);
  }
  T get(int l, int r, int s, int e, int ind) {
    push(s, e, ind);
    if (s > r || l > e) return def;
    if (s >= l && e <= r) return tree[ind];
    int mid = (s + e) >> 1;
    return func(get(l, r, s, mid, ind << 1),
                get(l, r, mid + 1, e, ind << 1 | 1));
  }
  void update(int l, int r, T x) {
    if (l > r) return;
    update(l, r, x, 0, n - 1, 1);
  }
  T get(int l, int r) { return get(l, r, 0, n - 1, 1); }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), l(m), r(m);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(((a).begin()), ((a).end()));
    vector<int> indices;
    for (int i = 0; i < m; i++) {
      cin >> l[i] >> r[i];
      int k = upper_bound(((a).begin()), ((a).end()), r[i]) -
              upper_bound(((a).begin()), ((a).end()), l[i] - 1);
      if (k == 0) indices.push_back(i);
    }
    sort(((indices).begin()), ((indices).end()), [&](int i, int j) {
      return (l[i] < l[j]) || (l[i] == l[j] && r[i] > r[j]);
    });
    vector<int> I;
    for (int i : indices) {
      while (!I.empty()) {
        int j = I.back();
        if (r[j] >= r[i])
          I.pop_back();
        else
          break;
      }
      I.push_back(i);
    }
    int k = I.size();
    segtree<long long> st1(k + 1, 1e18,
                           [](long long x, long long y) { return min(x, y); });
    segtree<long long> st2(k + 1, 1e18,
                           [](long long x, long long y) { return min(x, y); });
    vector<int> LL(k + 1, -1.5e9), RR(k + 1, -1.5e9);
    for (int i = 0; i < k; i++) LL[i + 1] = l[I[i]], RR[i + 1] = r[I[i]];
    vector<long long> dp(k + 1, 1e18);
    dp[0] = 0;
    for (int i = 0; i <= k; i++) {
      long long val0 = min(st2.get(i, i) + 2 * LL[i], st1.get(i, i) + LL[i]);
      long long val1 = dp[i];
      if (i == 0) val0 = 0;
      if (i == k) {
        cout << min(val0, val1) << '\n';
        break;
      }
      {
        long long val = val0;
        int p = upper_bound(((a).begin()), ((a).end()), RR[i + 1]) - a.begin();
        p--;
        if (p >= 0 && a[p] > RR[i]) {
          int x = a[p];
          st1.update(i + 1, k, val - x);
        }
        p++;
        if (p < n) {
          int x = a[p];
          int h = upper_bound(((LL).begin()), ((LL).end()), x) - LL.begin();
          long long lft = x - RR[i + 1];
          dp[h - 1] = min(dp[h - 1], val + lft);
          int q =
              upper_bound(((LL).begin()), ((LL).end()), x + lft) - LL.begin();
          st1.update(q, k, val + 2 * lft - x);
          st2.update(h, q - 1, val + lft - 2LL * x);
        }
      }
      {
        long long val = val1;
        int p = upper_bound(((a).begin()), ((a).end()), RR[i + 1]) - a.begin();
        p--;
        if (p >= 1 && a[p - 1] > RR[i]) {
          int x = a[p];
          st1.update(i + 1, k, val - x);
        }
        p++;
        if (p >= 1 && p < n && a[p - 1] > RR[i]) {
          int x = a[p];
          int h = upper_bound(((LL).begin()), ((LL).end()), x) - LL.begin();
          long long lft = x - RR[i + 1];
          dp[h - 1] = min(dp[h - 1], val + lft);
          int q =
              upper_bound(((LL).begin()), ((LL).end()), x + lft) - LL.begin();
          st1.update(q, k, val + 2 * lft - x);
          st2.update(h, q - 1, val + lft - 2LL * x);
        }
      }
    }
  }
}
