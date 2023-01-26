#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vvi = vector<vector<int>>;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &e : a) {
    cin >> e;
    e = abs(e);
  }
  sort(begin(a), end(a));
  if (find(begin(a), end(a), 0) != end(a)) {
    cout << "YES\n";
    return;
  }
  for (int i = 1; i < n; ++i) {
    if (a[i] == a[i - 1]) {
      cout << "YES\n";
      return;
    }
  }
  unordered_set<int> sums;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      sums.insert(a[i] + a[j]);
    }
  }
  unordered_set<int> new_sums;
  for (auto e : a) {
    new_sums = sums;
    for (auto s : sums) {
      new_sums.insert(s + e);
    }
    sums.swap(new_sums);
  }
  for (auto s : sums) {
    if (find(begin(a), end(a), s) != end(a)) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
