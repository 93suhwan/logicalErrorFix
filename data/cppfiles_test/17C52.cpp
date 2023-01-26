#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
vector<int> tree;
void build(int n) { tree.assign(n + 1, 0); }
void add(int idx) {
  for (; idx < tree.size(); idx = idx | (idx + 1)) {
    tree[idx]++;
  }
}
int get(int idx) {
  int res = 0;
  for (; idx >= 0; idx = (idx & (idx + 1)) - 1) {
    res += tree[idx];
  }
  return res;
}
void solve() {
  int n;
  cin >> n;
  vector<int> ar(n);
  vector<int> tmp;
  for (auto& v : ar) {
    cin >> v;
    tmp.push_back(v);
  }
  tmp.push_back(-2e9);
  sort(tmp.begin(), tmp.end());
  tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
  for (auto& v : ar) {
    v = lower_bound(tmp.begin(), tmp.end(), v) - tmp.begin();
  }
  build(n);
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    int more = i - get(ar[i]);
    int less = get(ar[i] - 1);
    if (less < more) {
      ans += less;
    } else {
      ans += more;
    }
    add(ar[i]);
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    solve();
  }
}
