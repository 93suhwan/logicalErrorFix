#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
using namespace std;
const long long mod = 998244353;
string s;
void solve() {
  cin >> s;
  long long pow10[11], pow9[11];
  pow9[0] = 1;
  pow10[0] = 1;
  for (int i = 1; i < 11; i++) {
    pow9[i] = pow9[i - 1] * 9;
    pow10[i] = pow10[i - 1] * 10;
  }
  int n = (int)s.size();
  if (n == 1) {
    if (s[0] == '0' || s[0] == 'X' || s[0] == '_') {
      cout << 1 << '\n';
    } else {
      cout << 0 << '\n';
    }
    return;
  }
  string st[] = {"00", "25", "75", "50"};
  if (s[0] == '0') {
    cout << 0 << '\n';
    return;
  }
  bool xgtz, ugtz;
  xgtz = s[0] == 'X';
  ugtz = s[0] == '_';
  long long ans = 0;
  auto notxu = [&](char c) { return c != 'X' && c != '_'; };
  int cntx, cntu;
  cntx = cntu = 0;
  for (int i = 1; i < n - 2; i++) {
    if (s[i] == 'X') cntx++;
    if (s[i] == '_') cntu++;
  }
  int uc = n > 2 ? 9 : 1;
  for (int k = 0; k < 4; k++) {
    if (n == 2 && k == 0) continue;
    if (s[n - 1] != st[k][1] && notxu(s[n - 1])) {
      continue;
    } else if (s[n - 2] != st[k][0] && notxu(s[n - 2])) {
      continue;
    } else if (s[n - 1] == 'X' && s[n - 2] == 'X') {
      if (k != 0 || xgtz) continue;
      ans += (ugtz ? pow10[cntu] * uc : pow10[cntu]);
    } else if (s[n - 1] == 'X') {
      if ((k == 0 || k == 3) && xgtz) continue;
      ans += (ugtz ? pow10[cntu] * uc : pow10[cntu]);
    } else if (s[n - 2] == 'X') {
      if (k == 0 && xgtz) continue;
      ans += (ugtz ? pow10[cntu] * uc : pow10[cntu]);
    } else if (s[n - 1] != st[k][1] && s[n - 1] != '_') {
      continue;
    } else if (s[n - 2] != st[k][0] && s[n - 2] != '_') {
      continue;
    } else {
      ans += 1ll * (xgtz ? 9 : (cntx > 0 ? 10 : 1)) *
             (ugtz ? pow10[cntu] * uc : pow10[cntu]);
    }
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
}
