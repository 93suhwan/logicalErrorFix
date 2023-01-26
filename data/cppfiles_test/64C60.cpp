#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using ll = long long int;
using namespace std;
vector<int> par, par1;
int find_par(int n) {
  if (n == par[n]) return n;
  return par[n] = find_par(par[n]);
}
void mer(int a, int b) {
  int x = find_par(a);
  int y = find_par(b);
  par[x] = par[y];
}
int find_par1(int n) {
  if (n == par1[n]) return n;
  return par1[n] = find_par1(par1[n]);
}
void mer1(int a, int b) {
  int x = find_par1(a);
  int y = find_par1(b);
  par1[x] = par1[y];
}
void solve() {
  int n, e1, e2;
  cin >> n >> e1 >> e2;
  par.resize(n + 1), par1.resize(n + 1);
  for (int i = 1; i <= n; ++i) par[i] = par1[i] = i;
  while (e1--) {
    int a, b;
    cin >> a >> b;
    mer(a, b);
  }
  while (e2--) {
    int a, b;
    cin >> a >> b;
    mer1(a, b);
  }
  vector<pair<int, int>> ans;
  for (int i = 1; i <= n; ++i) {
    if (find_par(i) != find_par(1) && find_par1(i) != find_par1(1)) {
      mer(1, i);
      mer1(1, i);
      ans.push_back({1, i});
    }
  }
  int l = 1, r = 1;
  while (l <= n && r <= n) {
    int f = l, s = r;
    while (f <= n && find_par(1) == find_par(f)) ++f;
    while (s <= n && find_par1(1) == find_par1(s)) ++s;
    l = f, r = s;
    if (l <= n && r <= n && find_par(l) != find_par(r) &&
        find_par1(l) != find_par1(r)) {
      ans.push_back({l, r});
      mer(l, r);
      mer1(l, r);
    }
  }
  cout << ans.size() << "\n";
  for (auto i : ans) {
    cout << i.first << " " << i.second << "\n";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
