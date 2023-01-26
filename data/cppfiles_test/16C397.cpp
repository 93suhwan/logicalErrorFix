#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    string s;
    cin >> s;
    string ns = s;
    sort(ns.begin(), ns.end());
    long long int ans = 0;
    for (long long int i = 0; i < n; i++) {
      if (s[i] != ns[i]) {
        ans++;
      }
    }
    cout << ans << "\n";
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
