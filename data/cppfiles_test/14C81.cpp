#include <bits/stdc++.h>
using namespace std;
int64_t getMin(vector<int64_t>& a, int64_t i) {
  int64_t res = i;
  while (i < a.size()) {
    if (a[i] < a[res]) res = i;
    i++;
  }
  return res;
}
void shiftArr(vector<int64_t>& a, int64_t i, int64_t j) {
  int64_t last = a[j];
  while (j > i) {
    a[j] = a[j - 1];
    j--;
  }
  a[j] = last;
}
void solve() {
  int64_t n;
  cin >> n;
  vector<int64_t> a(n);
  for (int64_t i = 0; i < n; i++) cin >> a[i];
  vector<vector<int64_t>> res;
  for (int64_t i = 0; i < n; i++) {
    int64_t j = getMin(a, i);
    if (j > i) {
      res.push_back({i + 1, j + 1, j - i});
      shiftArr(a, i, j);
    }
  }
  cout << res.size() << "\n";
  for (vector<int64_t> v : res) {
    for (int64_t i = 0; i < 3; i++) cout << v[i] << " ";
    cout << "\n";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int64_t t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
