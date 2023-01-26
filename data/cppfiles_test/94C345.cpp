#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long MX = 3e5 + 10;
const long long INF = 1e9;
void solve() {
  string s;
  cin >> s;
  int n = s.length(), a[n];
  for (int i = 0; i < n; ++i) a[i] = s[i] - '0';
  if (n == 1) {
    int ans = 0, _n = stoi(s);
    for (int i = 0; i < 100; ++i)
      for (int j = 0; j < 100; ++j)
        if (i + j == _n) ++ans;
    ans -= 2;
    cout << ans << '\n';
    return;
  }
  long long ans = 0;
  for (int mask = 0; mask < (1 << n); ++mask) {
    long long ans1 = 1;
    for (int i = 0; i < n; ++i) {
      int d = a[i];
      if (mask & (1 << i)) {
        if (i == n - 1 || i == n - 2) {
          ans1 = 0;
          break;
        }
        --d;
      }
      if (i >= 2 && (mask & (1 << (i - 2)))) d += 10;
      if (d < 0) {
        ans1 = 0;
        break;
      }
      int l = max(0, d - 9), r = min(9, d);
      if (l <= r)
        ans1 *= (r - l + 1);
      else {
        ans1 = 0;
        break;
      }
    }
    ans += ans1;
  }
  ans -= 2;
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
