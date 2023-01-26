#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;
int Bit(int mask, int b) { return (mask >> b) & 1; }
template <class T>
bool ckmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
bool ckmax(T &a, const T &b) {
  if (b > a) {
    a = b;
    return true;
  }
  return false;
}
const int INFi = 2e9;
struct FSegTree {
  struct Node {
    int value;
    Node(int _val = 0) : value(_val) {}
    void combine(const Node &a, const Node &b) {
      value = max(a.value, b.value);
    }
    void apply(int x) { value = x; }
  };
  Node combine(const Node &a, const Node &b) {
    Node res;
    res.combine(a, b);
    return res;
  }
  vector<Node> t;
  int n;
  void build(int k) {
    n = k;
    t.resize(n * 2 + 2);
  }
  template <typename T>
  void build(vector<T> &v) {
    n = v.size();
    t.resize(n * 2 + 2);
    for (int i = 0; i < (n); ++i) {
      t[i + n].apply(v[i]);
    }
    for (int i = n - 1; i >= 0; --i) t[i].combine(t[i << 1], t[i << 1 | 1]);
  }
  void upd(int i, int x) {
    for (t[i += n].apply(x); i > 1; i >>= 1) t[i >> 1].combine(t[i], t[i ^ 1]);
  }
  Node get(int l, int r) {
    Node result;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) result = combine(result, t[l++]);
      if (r & 1) result = combine(result, t[--r]);
    }
    return result;
  }
};
struct fenwick {
  int n{};
  vector<ll> fenw{};
  void build(int k) {
    n = k;
    fenw.resize(n);
  }
  void upd(int i, ll x) {
    for (; i < n; i = i | (i + 1)) fenw[i] += x;
  }
  ll get(int i) {
    ll res = 0;
    for (; i >= 0; i = (i & (i + 1)) - 1) res += fenw[i];
    return res;
  }
  ll get(int l, int r) {
    if (l > r) return 0;
    return get(r) - get(l - 1);
  }
};
void solve() {
  int n, d;
  cin >> n >> d;
  int ans = 0;
  vector<pair<int, int>> a;
  for (int i = 0; i < (n); ++i) {
    int x, y;
    cin >> x >> y;
    if (x < d) continue;
    if (y <= d) {
      ans++;
      continue;
    }
    a.emplace_back(y, x);
  }
  sort((a).begin(), (a).end());
  n = a.size();
  if (n == 0) {
    cout << ans << '\n';
    return;
  }
  vector<int> nw(n);
  {
    vvi add(n);
    vvi sub(n);
    for (int i = 0; i < (n); ++i) {
      auto [aa, s] = a[i];
      pair<int, int> tmp = {s, INFi};
      int j = upper_bound((a).begin(), (a).end(), tmp) - a.begin();
      j = min(j, i);
      if (j < i) {
        add[i].push_back(i);
        sub[j].push_back(i);
      }
    }
    vector<int> xx;
    for (int i = 0; i < (n); ++i) xx.push_back(a[i].second);
    sort((xx).begin(), (xx).end());
    xx.resize(unique((xx).begin(), (xx).end()) - xx.begin());
    fenwick f;
    int sz = xx.size();
    f.build(sz);
    for (int i = 0; i < (n); ++i) {
      for (auto &j : sub[i]) {
        int x = a[j].first;
        int w = lower_bound((xx).begin(), (xx).end(), x) - xx.begin();
        nw[j] -= f.get(w, sz - 1);
      }
      for (auto &j : add[i]) {
        int x = a[j].first;
        int w = lower_bound((xx).begin(), (xx).end(), x) - xx.begin();
        nw[j] += f.get(w, sz - 1);
      }
      {
        int x = a[i].second;
        int w = lower_bound((xx).begin(), (xx).end(), x) - xx.begin();
        f.upd(w, 1);
      }
    }
  }
  FSegTree dp;
  dp.build(n);
  for (int i = 0; i < (n); ++i) {
    auto [aa, s] = a[i];
    pair<int, int> tmp = {s, INFi};
    int j = upper_bound((a).begin(), (a).end(), tmp) - a.begin();
    j = min(j, i);
    int value = 1;
    if (j != 0) {
      value += dp.get(0, j).value;
    }
    if (j < i) {
      value += nw[i];
    }
    dp.upd(i, value);
  }
  cout << dp.get(0, n).value + ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  for (int i = 0; i < (t); ++i) {
    solve();
  }
  return 0;
}
