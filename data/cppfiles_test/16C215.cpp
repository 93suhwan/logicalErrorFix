#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, ans = 0;
  string s;
  cin >> n >> s;
  string t = s;
  sort(t.begin(), t.end());
  for (int i = 0; i < n; i++) {
    if (s[i] != t[i]) ans++;
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
