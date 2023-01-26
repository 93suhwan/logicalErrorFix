#include <bits/stdc++.h>
using namespace std;
int cnt[26];
void Solve() {
  memset(cnt, 0, sizeof(cnt));
  string s;
  int ans = 0, n;
  cin >> s;
  n = s.size();
  for (int i = 0; i < n; i++) cnt[s[i] - 'a']++;
  for (int i = 0; i < 26; i++) ans += min(cnt[i], 2);
  cout << ans / 2 << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) Solve();
}
