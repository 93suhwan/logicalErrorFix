#include <bits/stdc++.h>
using namespace std;
struct FenwickTree {
  vector<int> bit;
  int n;
  FenwickTree(int n) {
    this->n = n;
    bit.assign(n, 0);
  }
  FenwickTree(vector<int> a) : FenwickTree(a.size()) {
    for (size_t i = 0; i < a.size(); i++) add(i, a[i]);
  }
  int sum(int r) {
    int ret = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1) ret += bit[r];
    return ret;
  }
  int sum(int l, int r) { return sum(r) - sum(l - 1); }
  void add(int idx, int delta) {
    for (; idx < n; idx = idx | (idx + 1)) bit[idx] += delta;
  }
};
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> tem = a;
  sort(begin(tem), end(tem));
  tem.erase(unique(begin(tem), end(tem)), tem.end());
  map<int, int> comp;
  int nn = tem.size();
  for (int i = 0; i < nn; i++) {
    comp[tem[i]] = i;
  }
  FenwickTree ft(nn + 1);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int v = comp[a[i]];
    int left = ft.sum(v + 1, nn);
    int right = ft.sum(v - 1);
    ans += (long long)min(left, right);
    ft.add(v, 1);
  }
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
