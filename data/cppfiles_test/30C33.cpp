#include <bits/stdc++.h>
using namespace std;
template <class A, class B>
ostream& operator<<(ostream& out, const pair<A, B>& p) {
  return out << "(" << p.first << ", " << p.second << ")";
}
template <class A>
ostream& operator<<(ostream& out, const vector<A>& v) {
  out << "[";
  for (int i = 0; i < v.size(); ++i) {
    if (i) out << ", ";
    out << v[i];
  }
  return out << "]";
}
void sol() {}
const int N = 150000 + 6;
const int M = 1e6 + 6;
vector<int> f(M), fac[M];
int Find(int v) { return f[v] == v ? v : f[v] = Find(f[v]); }
void dsu(int u, int v) {
  u = Find(u), v = Find(v);
  if (u < v) swap(u, v);
  f[u] = v;
}
int main(int argc, char const* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, q;
  cin >> n >> q;
  iota(f.begin(), f.end(), 0);
  bool vis[M] = {false}, has[M] = {false};
  vector<int> a(n);
  for (int i = (0); i < (n); ++i) {
    cin >> a[i];
    has[a[i]] = true;
  }
  for (int i = (2); i < (M); ++i) {
    if (vis[i] == false) {
      for (int j = i; j < M; j += i) {
        if (has[j] == true) {
          dsu(j, i);
        }
        vis[j] = true;
        fac[j].push_back(i);
      }
    }
  }
  set<pair<int, int> > add1;
  for (int i = (0); i < (n); ++i) {
    for (int e1 : fac[a[i]]) {
      for (int e2 : fac[a[i] + 1]) {
        int fi = Find(e1), se = Find(e2);
        if (fi == se) continue;
        if (fi > se) swap(fi, se);
        add1.emplace(fi, se);
      }
    }
    for (int e1 : fac[a[i] + 1]) {
      for (int e2 : fac[a[i] + 1]) {
        int fi = Find(e1), se = Find(e2);
        if (fi == se) continue;
        if (fi > se) swap(fi, se);
        add1.emplace(fi, se);
      }
    }
  }
  for (; q; --q) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    x = Find(a[x]);
    y = Find(a[y]);
    if (x > y) swap(x, y);
    if (x == y) {
      cout << 0 << endl;
    } else if (add1.count({x, y}) == 1) {
      cout << 1 << endl;
    } else {
      cout << 2 << endl;
    }
  }
  return 0;
}
