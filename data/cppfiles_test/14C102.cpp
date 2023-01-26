#include <bits/stdc++.h>
const int len = 1e9 + 7;
using namespace std;
void precision(int a) { cout << setprecision(a) << fixed; }
void solve() {
  long long n, k = 0;
  cin >> n;
  vector<long long> a(n), b;
  for (long long i = 0; i < n; i++) cin >> a[i];
  b = a;
  if (is_sorted(a.begin(), a.end())) {
    cout << 0 << "\n";
    return;
  }
  sort(b.begin(), b.end());
  vector<vector<long long>> ans;
  for (long long i = 1; i < n; i++) {
    long long x = a[i];
    long long j = i - 1;
    while (j >= 0 and a[j] > x) {
      a[j + 1] = a[j];
      j = j - 1;
    }
    a[j + 1] = x;
    if (i - (j + 1) > 0) {
      ans.push_back({j + 2, i + 1, i - (j + 1)});
    }
  }
  cout << ans.size() << endl;
  for (auto x : ans) {
    for (auto y : x) cout << y << " ";
    cout << endl;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  precision(1);
  long long t;
  cin >> t;
  while (t--) solve();
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
