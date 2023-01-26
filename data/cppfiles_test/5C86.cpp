#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  int answer = 0;
  vector<bool> used(n);
  for (int i = 0; i < n; i++) {
    if (t[i] == '0') {
      continue;
    }
    if (i - 1 >= 0 && s[i - 1] == '1' && !used[i - 1]) {
      answer++;
      used[i - 1] = true;
      continue;
    }
    if (s[i] == '0') {
      answer++;
      used[i] = true;
      continue;
    }
    if (i + 1 < n && s[i + 1] == '1' && !used[i + 1]) {
      answer++;
      used[i + 1] = true;
    }
  }
  cout << answer << "\n";
}
int32_t main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
}
