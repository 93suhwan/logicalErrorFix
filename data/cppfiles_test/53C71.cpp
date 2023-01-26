#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e5 + 7;
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  vector<int> id(n);
  iota(id.begin(), id.end(), 0);
  sort(id.begin(), id.end(), [&](int x, int y) {
    if (a[x] == a[y]) return x < y;
    return a[x] < a[y];
  });
  int d = 0;
  for (int i = 0; i < n; ++i) {
    if (i == 0 || id[i] != id[i - 1] + 1) ++d;
  }
  if (d <= k)
    cout << "Yes\n";
  else
    cout << "No\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int test_case = 1; test_case <= T; ++test_case) {
    solve();
  }
  return 0;
}
