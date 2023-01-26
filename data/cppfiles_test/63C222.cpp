#include <bits/stdc++.h>
using namespace std;
void dout() { cerr << endl; }
template <typename Head, typename... Tail>
void dout(Head H, Tail... T) {
  cerr << H << ' ';
  dout(T...);
}
using ll = long long;
using pii = pair<ll, ll>;
using ld = long double;
template <typename T>
void do_uniq(vector<T> &vec) {
  sort((vec).begin(), (vec).end());
  vec.resize(unique((vec).begin(), (vec).end()) - vec.begin());
}
int mod = 500029;
int ml(int a, int b) { return (a * 1ll * b) % mod; }
int add(int a, int b) { return (a + b) % mod; }
int sub(int a, int b) { return add(a, mod - b); }
int sq(int a) { return ml(a, a); }
int b_p(int b, int p) {
  if (p == 0) return 1;
  if (p & 1) return ml(b, b_p(b, p - 1));
  return sq(b_p(b, p >> 1));
}
const int MAXN = 1e5 + 32;
int ai[MAXN];
vector<int> g[MAXN];
int parr[MAXN][2];
int sz[MAXN][2];
void ini(int v, int t) {
  sz[v][t] = 1;
  parr[v][t] = v;
}
int fpar(int v, int t) {
  return v == parr[v][t] ? v : parr[v][t] = fpar(parr[v][t], t);
}
void uni(int u, int v, int t) {
  u = fpar(u, t);
  v = fpar(v, t);
  if (u == v) return;
  if (sz[u][t] < sz[v][t]) swap(u, v);
  sz[u][t] += sz[v][t];
  parr[v][t] = u;
}
void solve() {
  int n, m1, m2;
  cin >> n >> m1 >> m2;
  for (int i = 0; i < n; ++i) {
    ini(i, 0);
    ini(i, 1);
  }
  for (int i = 0; i < m1; ++i) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    uni(u, v, 0);
  }
  for (int i = 0; i < m2; ++i) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    uni(u, v, 1);
  }
  int cnt = 0;
  vector<pair<int, int>> answr;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (fpar(i, 0) != fpar(j, 0) && fpar(i, 1) != fpar(j, 1)) {
        ++cnt;
        uni(i, j, 0);
        uni(i, j, 1);
        answr.push_back({i + 1, j + 1});
      }
    }
  }
  cout << cnt << "\n";
  for (auto e : answr) {
    cout << e.first << " " << e.second << "\n";
  }
}
void multisolve() {
  int t;
  cin >> t;
  int i = 1;
  while (t--) {
    solve();
    i++;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  cout << fixed << setprecision(20);
  solve();
}
