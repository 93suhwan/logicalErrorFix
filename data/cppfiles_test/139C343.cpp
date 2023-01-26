#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  int n = s.size();
  string answer = "";
  if (n & 1 ^ 1) {
    string pref, suff;
    pref = suff = "";
    for (int i = 0; i < n / 2; i++) pref.push_back(s[i]);
    for (int i = n / 2; i < n; i++) suff.push_back(s[i]);
    if (pref == suff)
      answer = "YES";
    else
      answer = "NO";
  } else
    answer = "NO";
  cout << answer << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
