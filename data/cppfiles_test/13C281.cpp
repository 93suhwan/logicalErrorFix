#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  string s;
  cin >> s;
  n = s.length();
  if (n & 1) {
    cout << "NO\n";
    return;
  }
  int cnt = 0;
  for (auto c : s)
    if (c == 'B') cnt++;
  if (cnt == n / 2)
    cout << "YES\n";
  else
    cout << "NO\n";
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}
