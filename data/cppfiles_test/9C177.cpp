#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  int n = s.size();
  int fr[256];
  for (int i = 'a'; i <= 'z'; i++) fr[i] = 0;
  for (int i = 0; i < n; i++) fr[s[i]]++;
  int ans = 0, cnt = 0;
  for (int i = 'a'; i <= 'z'; i++)
    if (fr[i] == 1)
      cnt++;
    else if (fr[i] >= 2)
      ans++;
  ans += cnt / 2;
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) solve();
  return 0;
}
