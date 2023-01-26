#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
template <class T>
using vi2 = vector<vector<T>>;
using ll = long long;
using pii = pair<int, int>;
template <class T>
struct Sgt {
  struct Node {
    int l, r, lc, rc;
    T sum, tag;
    Node(int l, int r) : l(l), r(r) {
      lc = rc = -1;
      tag = T(0);
      sum = T(0);
    }
  };
  vector<Node> v;
  int create(int l, int r) {
    int res = v.size();
    v.emplace_back(l, r);
    return res;
  }
  inline int lc(int x) {
    if (v[x].lc != -1)
      return v[x].lc;
    else
      return v.emplace_back(v[x].l, v[x].l + v[x].r >> 1),
             v[x].lc = v.size() - 1;
  }
  inline int rc(int x) {
    if (v[x].rc != -1)
      return v[x].rc;
    else
      return v.emplace_back((v[x].l + v[x].r >> 1) + 1, v[x].r),
             v[x].rc = v.size() - 1;
  }
  void cover(int x, T del) {
    v[x].tag += del;
    v[x].sum += del;
  }
  void pushdown(int x) {
    if (v[x].tag != T(0)) {
      cover(lc(x), v[x].tag);
      cover(rc(x), v[x].tag);
      v[x].tag = T(0);
    }
  }
  inline T get(T x, T y) { return min(x, y); }
  T query(int x, int l, int r) {
    if (l <= v[x].l && v[x].r <= r)
      return v[x].sum;
    else if (l > v[x].r || r < v[x].l)
      return T(INT_MAX);
    else
      return pushdown(x), get(query(lc(x), l, r), query(rc(x), l, r));
  }
  void modify(int x, int l, int r, T del) {
    if (l <= v[x].l && v[x].r <= r)
      cover(x, del);
    else if (l > v[x].r || r < v[x].l)
      return;
    else
      pushdown(x), modify(lc(x), l, r, del), modify(rc(x), l, r, del),
          v[x].sum = get(v[lc(x)].sum, v[rc(x)].sum);
  }
  int rank(int x, int k) {
    if (k > v[x].sum || k < 1) return -1;
    if (v[x].l == v[x].r) return v[x].l;
    int sz = (pushdown(x), v[lc(x)].sum);
    if (k <= sz)
      return rank(lc(x), k);
    else
      return rank(rc(x), k - sz);
  }
  int merge(int l, int r) {
    if (l == -1) return r;
    if (r == -1) return l;
    v[l].sum = get(v[l].sum, v[r].sum);
    v[l].tag = get(v[l].tag, v[r].tag);
    v[l].lc = merge(v[l].lc, v[r].lc);
    v[l].rc = merge(v[l].rc, v[r].rc);
    return l;
  }
};
ll invs(vector<int>::iterator begin, vector<int>::iterator end) {
  if (begin == end || next(begin) == end) return 0;
  vector<int>::iterator mid = begin + (end - begin) / 2;
  ll res = 0;
  res += invs(begin, mid);
  res += invs(mid, end);
  vector<int> od;
  auto itx = begin, ity = mid;
  while (itx != mid && ity != end) {
    if (*itx > *ity)
      od.push_back(*ity), res += mid - itx, ity++;
    else
      od.push_back(*itx), itx++;
  }
  while (itx != mid) od.push_back(*itx), itx++;
  while (ity != end) od.push_back(*ity), ity++;
  copy(od.begin(), od.end(), begin);
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  auto solve = [&]() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    vector<int> b(m + 1);
    for (int i = 1, _i = int(n); i <= _i; i++) cin >> a[i];
    for (int i = 1, _i = int(m); i <= _i; i++) cin >> b[i];
    vector<pii> p(n + 1);
    sort(b.begin() + 1, b.end());
    for (int i = 1, _i = int(n); i <= _i; i++) p[i] = make_pair(a[i], i);
    sort(p.begin() + 1, p.end());
    int cnt1 = 1, cnt2 = 1;
    ll ans = invs(a.begin() + 1, a.end());
    Sgt<int> sgt;
    int sr = sgt.create(0, n);
    for (int i = 1, _i = int(n); i <= _i; i++) sgt.modify(sr, i, n, 1);
    for (int i = 1, _i = int(m); i <= _i; i++) {
      while (cnt1 <= n && p[cnt1].first <= b[i])
        sgt.modify(sr, p[cnt1++].second, n, -1);
      while (cnt2 <= n && p[cnt2].first < b[i])
        sgt.modify(sr, 0, p[cnt2++].second - 1, 1);
      ans += sgt.query(sr, 0, n);
    }
    cout << ans << endl;
  };
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
