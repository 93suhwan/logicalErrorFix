#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Vi = vector<int>;
using Pii = pair<int, int>;
int uplg(int n) { return 32 - __builtin_clz(n); }
int uplg(ll n) { return 64 - __builtin_clzll(n); }
struct RMQ {
  using T = int;
  T ID = INT_MAX;
  T f(T a, T b) { return min(a, b); }
  vector<vector<T>> s;
  RMQ(const vector<T>& vec = {}) {
    s = {vec};
    for (int h = 1; h <= int((vec).size()); h *= 2) {
      s.push_back({});
      auto& prev = s[int((s).size()) - 2];
      for (int i = (0); i < (int((vec).size()) - h * 2 + 1); i++)
        s.back().push_back(f(prev[i], prev[i + h]));
    }
  }
  T query(int b, int e) {
    if (b >= e) return ID;
    int k = 31 - __builtin_clz(e - b);
    return f(s[k][b], s[k][e - (1 << k)]);
  }
};
struct SegTree {
  using T = Pii;
  T ID = {0, INT_MAX};
  struct Agg {
    int vMax{INT_MIN}, nMax{0}, max2{INT_MIN};
    ll sum{0};
    void leaf() {
      sum = vMax = INT_MAX;
      nMax = 1;
    }
    void merge(const Agg& r) {
      if (r.vMax > vMax) {
        max2 = vMax;
        vMax = r.vMax;
        nMax = r.nMax;
      } else if (r.vMax == vMax) {
        nMax += r.nMax;
      } else if (r.vMax > max2) {
        max2 = r.vMax;
      }
      max2 = max(max2, r.max2);
      sum += r.sum;
    }
    bool apply(T& lazy, T& first, int size) {
      if (max2 != INT_MIN && max2 + first.first >= first.second) return 0;
      lazy.first += first.first;
      sum += first.first * size;
      vMax += first.first;
      if (max2 != INT_MIN) max2 += first.first;
      if (first.second < vMax) {
        sum -= (vMax - first.second) * nMax;
        vMax = first.second;
      }
      lazy.second = vMax;
      return 1;
    }
  };
  vector<Agg> agg;
  vector<T> lazy;
  int len{1};
  SegTree(int n = 0) {
    while (len < n) len *= 2;
    agg.resize(len * 2);
    lazy.resize(len * 2, ID);
    for (int i = (0); i < (n); i++) agg[len + i].leaf();
    for (int i = len; --i;) (agg[i] = agg[i * 2]).merge(agg[i * 2 + 1]);
  }
  void push(int i, int s) {
    if (lazy[i] != ID) {
      agg[i * 2].apply(lazy[i * 2], lazy[i], s / 2);
      agg[i * 2 + 1].apply(lazy[i * 2 + 1], lazy[i], s / 2);
      lazy[i] = ID;
    }
  }
  T update(int vb, int ve, T val, int i = 1, int b = 0, int e = -1) {
    if (e < 0) e = len;
    if (vb >= e || b >= ve) return val;
    if (b >= vb && e <= ve && agg[i].apply(lazy[i], val, e - b)) return val;
    int m = (b + e) / 2;
    push(i, e - b);
    val = update(vb, ve, val, i * 2, b, m);
    val = update(vb, ve, val, i * 2 + 1, m, e);
    (agg[i] = agg[i * 2]).merge(agg[i * 2 + 1]);
    return val;
  }
  Agg query(int vb, int ve, int i = 1, int b = 0, int e = -1) {
    if (e < 0) e = len;
    if (vb >= e || b >= ve) return {};
    if (b >= vb && e <= ve) return agg[i];
    int m = (b + e) / 2;
    push(i, e - b);
    Agg t = query(vb, ve, i * 2, b, m);
    t.merge(query(vb, ve, i * 2 + 1, m, e));
    return t;
  }
};
struct Query {
  int id, len;
};
void run() {
  int n, q, k;
  cin >> n >> q >> k;
  vector<int> arr(n);
  for (auto& first : (arr)) cin >> first;
  RMQ rmq(arr);
  vector<vector<Query>> queries(n);
  vector<ll> res(q);
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    l--;
    res[i] = arr[l];
    int len = r - l;
    if (len <= k) continue;
    int ql = l + 1;
    int queryLen = (len - 1) / k;
    queries[ql].push_back({i, queryLen});
  }
  vector<SegTree> tree(k, {n / k + 2});
  for (int i = n - k; i >= 1; i--) {
    int d = i % k, l = i / k;
    int val = rmq.query(i - 1, i + k);
    tree[d].update(l, n / k + 1, {0, val});
    for (Query qr : queries[i]) {
      res[qr.id] += tree[d].query(l, l + qr.len).sum;
    }
  }
  for (auto& r : (res)) cout << r << "\n";
}
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(18);
  int t = 1;
  for (int i = (0); i < (t); i++) {
    run();
  }
  return 0;
}
