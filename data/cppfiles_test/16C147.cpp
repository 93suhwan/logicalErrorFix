#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  string a = s;
  sort(a.begin(), a.end());
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] != s[i]) {
      ans++;
    }
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; tt++) {
    solve();
  }
  return 0;
}
