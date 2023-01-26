#include <bits/stdc++.h>
using namespace std;
int IDX(int a[], int n, int x) {
  while (n >= 0)
    if (a[n--] == x) return n + 1;
}
void solve() {
  int n, i, j, key, idx;
  cin >> n;
  int a[n];
  vector<int> v;
  for (i = 0; i < n; ++i) {
    cin >> a[i];
    v.push_back(a[i]);
  }
  sort(v.begin(), v.end());
  vector<pair<int, int>> res;
  for (i = n - 1; i >= 0; --i) {
    key = v[i];
    idx = IDX(a, i, key);
    if (idx == i) continue;
    j = idx + 1;
    while (j++ <= i) a[j - 2] = a[j - 1];
    a[i] = key;
    res.push_back({idx + 1, i + 1});
  }
  cout << res.size() << endl;
  for (auto x : res) {
    cout << x.first << " ";
    cout << x.second << " ";
    cout << 1 << endl;
  }
}
int main() {
  int TC;
  cin >> TC;
  while (TC--) {
    solve();
  }
  return 0;
}
