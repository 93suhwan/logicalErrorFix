#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template <typename V>
using uset = unordered_set<V>;
template <typename K, typename V>
using umap = unordered_map<K, V>;
const int INF = 1e9 + 7;
const ll LINF = 1e18 + 14;
void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto& a : v) {
    cin >> a;
  }
  vector<pair<pii, int>> ans;
  for (int i = 0; i < n - 1; i++) {
    int mn = INF;
    int id = 0;
    for (int j = i; j < n; j++) {
      if (mn > v[j]) {
        mn = v[j];
        id = j;
      }
    }
    if (id - i > 0) {
      rotate(v.begin() + i, v.begin() + id, v.end());
      ans.push_back({{i + 1, n}, id - i});
    }
  }
  cout << ans.size() << '\n';
  for (auto a : ans) {
    cout << a.first.first << ' ' << a.first.second << ' ' << a.second << '\n';
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  while (n--) {
    solve();
  }
  return 0;
}
