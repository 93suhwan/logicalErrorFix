#include <bits/stdc++.h>
using namespace std;
using pii = pair<long long, long long>;
const double EPS = 1e-9;
const long long INF = 1e18;
const long long N = 1e6 + 5;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long &x : a) cin >> x;
  string s;
  cin >> s;
  sort(a.begin(), a.end());
  vector<long long> b(n);
  for (long long i = 1; i < n; i++) {
    b[i] = s[i] != s[i - 1];
  }
  vector<pair<long long, char>> ans(n);
  long long p = 0;
  for (long long i = 0; i < n; i++) {
    if (b[i] == 0) ans[i] = {a[p++], s[i]};
  }
  for (long long i = 0; i < n; i++) {
    if (b[i] == 1) ans[i] = {a[p++], s[i]};
  }
  for (auto [v, c] : ans) {
    cout << v << " " << c << "\n";
  }
  return 0;
}
