#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class C>
void mini(C& a, C b) {
  a = min(a, b);
}
template <class C>
void maxi(C& a, C b) {
  a = max(a, b);
}
double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const ll INF = 1e9;
const double eps = 0.000000001;
struct nodo {
  void upd(int val, int x, int y) { v += val; }
  nodo comb(nodo& izq, nodo& der) {
    v = (izq.v + der.v);
    return *this;
  }
  int v;
};
struct segmentTree {
  segmentTree(int _n) {
    n = _n;
    tree = vector<nodo>(4 * n);
  }
  void build(vector<int>& a) { build(a, 1, 0, n); }
  void build(vector<int>& a, int v, int l, int r) {
    if (l + 1 == r) {
      tree[v].upd(a[l], l, r);
      return;
    }
    int m = (l + r) / 2;
    build(a, 2 * v, l, m);
    build(a, 2 * v + 1, m, r);
    tree[v].comb(tree[2 * v], tree[2 * v + 1]);
  }
  void upd(int i, int val) { upd(i, val, 1, 0, n); }
  void upd(int i, int val, int v, int x, int y) {
    if (i < x or y <= i) return;
    if (x + 1 == y) {
      tree[v].upd(val, x, y);
      return;
    }
    int m = (x + y) / 2;
    upd(i, val, 2 * v, x, m);
    upd(i, val, 2 * v + 1, m, y);
    tree[v].comb(tree[2 * v], tree[2 * v + 1]);
  }
  nodo get(int l, int r) { return get(l, r, 1, 0, n); }
  nodo get(int l, int r, int v, int x, int y) {
    if (r <= x or l >= y) return nodo();
    if (l <= x and r >= y) return tree[v];
    int m = (x + y) / 2;
    nodo izq = get(l, r, 2 * v, x, m);
    nodo der = get(l, r, 2 * v + 1, m, y);
    return nodo().comb(izq, der);
  }
  int trav(int l, int x) { return trav(l, x, 1, 0, n); }
  int trav(int l, int k, int v, int x, int y) {
    if (y <= l) return n;
    if (tree[v].v < k) return n;
    if (x + 1 == y) return x;
    int m = (x + y) / 2;
    int izq = trav(l, k, 2 * v, x, m);
    if (izq != n) return izq;
    return trav(l, k, 2 * v + 1, m, y);
  }
  vector<nodo> tree;
  int n;
};
void sacarrep(vector<int>& v) {
  int j = 0;
  for (int i = 0; i < v.size(); i++) {
    if (i == 0 or v[i] != v[i - 1]) {
      v[j] = v[i];
      j++;
    }
  }
  while (v.size() > j) v.pop_back();
}
void d() {
  int n, d;
  cin >> n >> d;
  vector<int> clave = {d};
  vector<pair<int, int> > a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
    clave.push_back(a[i].first), clave.push_back(a[i].second);
  }
  sort(clave.begin(), clave.end());
  sacarrep(clave);
  map<int, int> trad;
  for (int i = 0; i < clave.size(); i++) trad[clave[i]] = i;
  vector<pair<int, int> > forward, backward;
  vector<int> aux(clave.size());
  for (int i = 0; i < n; i++) {
    if (a[i].first >= a[i].second)
      backward.push_back({trad[a[i].second], trad[a[i].first]});
    else
      forward.push_back({trad[a[i].first], trad[a[i].second]});
  }
  sort(forward.begin(), forward.end()), sort(backward.begin(), backward.end());
  segmentTree st(clave.size());
  vector<int> dp(clave.size() + 1);
  int skill, neat;
  int i1 = (int)forward.size() - 1;
  int i2 = (int)backward.size() - 1;
  for (int(j) = clave.size() - 1; j >= 0; j--) {
    dp[j] = dp[j + 1];
    while (i2 >= 0 and backward[i2].first == j + 1) {
      st.upd(backward[i2].second, 1);
      i2--;
    }
    while (i1 >= 0 and forward[i1].first == j) {
      tie(skill, neat) = forward[i1];
      maxi(dp[j], dp[neat] + 1 - st.get(j + 1, neat).v);
      i1--;
    }
  }
  int res = dp[trad[d]];
  for (auto p : backward) {
    if (p.second >= trad[d]) res++;
  }
  cout << res << '\n';
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  d();
  return 0;
}
