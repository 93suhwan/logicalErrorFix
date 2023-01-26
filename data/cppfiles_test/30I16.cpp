#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
const int MAXN = 1e6;
int A[N], P[N];
bool vis[N], vsmp[N];
int F(int x) { return x == P[x] ? x : P[x] = F(P[x]); }
int unite(int a, int b) {
  a = F(a);
  b = F(b);
  if (a == b) return 0;
  P[a] = b;
  return 1;
}
int ans[N];
void solve() {
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= MAXN; ++i) P[i] = i;
  for (int i = 1; i <= n; ++i) {
    cin >> A[i];
    vis[A[i]] = 1;
  }
  for (int i = 2; i <= MAXN; ++i) {
    if (!vis[i]) continue;
    int x = i;
    for (int div = 2; div * div <= x; ++div) {
      if (x % div) continue;
      while (x % div == 0) {
        x /= div;
      }
      unite(div, i);
    }
    if (x != 1) unite(x, i);
  }
  map<pair<int, int>, vector<int> > M;
  for (int i = 1; i <= q; ++i) {
    int a, b;
    cin >> a >> b;
    if (F(A[a]) == F(A[b]))
      ans[i] = 0;
    else {
      ans[i] = 2;
      a = F(A[a]), b = F(A[b]);
      if (a > b) swap(a, b);
      M[{a, b}].push_back(i);
    }
  }
  for (int i = 1; i <= n; ++i) {
    long long nextdv = A[i] + 1;
    for (int div = 2; div * div <= nextdv; ++div) {
      if (nextdv % div) continue;
      while (nextdv % div == 0) nextdv /= div;
      int a = F(A[i]), b = F(div);
      if (a > b) swap(a, b);
      if (M.count({a, b})) {
        for (auto to : M[{a, b}]) ans[to] = 1;
        M.erase({a, b});
      }
    }
    if (nextdv != 1) {
      int div = nextdv;
      int a = F(A[i]), b = F(div);
      if (a > b) swap(a, b);
      if (M.count({a, b})) {
        for (auto to : M[{a, b}]) ans[to] = 1;
        M.erase({a, b});
      }
    }
  }
  for (int i = 1; i <= q; ++i) cout << ans[i] << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  t = 1;
  while (t--) solve();
  return 0;
}
