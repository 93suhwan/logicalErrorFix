#include <bits/stdc++.h>
using namespace std;
string subs(string s, char x) {
  for (int i = 0; i < (int)s.length(); ++i) {
    if (s[i] == 'X') s[i] = x;
  }
  return s;
}
long long dp[12];
long long solve(string s, int indx) {
  if (indx == (int)s.length()) {
    int x = (s[indx - 2] - '0') * 10 + (s[indx - 1] - '0');
    if (x % 25 == 0) return 1;
    return 0;
  }
  char st = '0';
  if (indx == 2 && s[indx] == '_') st = '1';
  long long &ans = dp[indx];
  if (ans != -1) return ans;
  ans = 0;
  if (s[indx] != '_')
    ans = ans + solve(s, indx + 1);
  else {
    for (char x = st; x <= '9'; ++x) {
      string ns = s;
      ns[indx] = x;
      ans = ans + solve(ns, indx + 1);
    }
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  long long ans = 0;
  for (char x = '0'; x <= '9'; ++x) {
    memset(dp, -1, sizeof(dp));
    string ns = "00" + subs(s, x);
    if (ns == "000" || ns == "00_")
      ans = ans + 1;
    else if (ns[2] == '0')
      continue;
    else
      ans = ans + solve(ns, 2);
    if (ns == "00" + s) break;
  }
  cout << ans << '\n';
  return 0;
}
