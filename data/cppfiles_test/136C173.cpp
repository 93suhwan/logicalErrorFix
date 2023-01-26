#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<long long> b(n);
  long long s = 0, sm = 0;
  for (long long i = 0; i < n; i++) {
    cin >> b[i];
    sm += b[i];
    s += (i + 1);
  }
  if (n == 1) {
    cout << "YES\n";
    cout << b[0] << "\n";
    return;
  }
  long long z = s * n;
  vector<long long> ans(n, 0ll);
  bool ok = 1;
  for (long long i = 0; i < n; i++) {
    if (i == 0) {
      long long val = sm - b[0] - b[n - 1];
      val += (s + 1) * b[n - 1];
      val -= (s - 1) * b[0];
      if (val % z || val <= 0) {
        ok = 0;
        break;
      }
      ans[i] = val / z;
    } else {
      long long val = sm - b[i] - b[i - 1];
      val += (s + 1) * b[i - 1];
      val -= (s - 1) * b[i];
      if (val % z || val <= 0) {
        ok = 0;
        break;
      }
      ans[i] = val / z;
    }
  }
  if (ok) {
    cout << "YES\n";
    for (auto x : ans) {
      cout << x << " ";
    }
    cout << "\n";
  } else {
    cout << "NO\n";
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
