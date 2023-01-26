#include <bits/stdc++.h>
using namespace std;
string ans = "-1";
void recurse(string& a, string& s, long long ia, long long is, string& num) {
  if (ia < 0 and is < 0) {
    ans = num;
    return;
  }
  if (ia < 0) {
    long long digS = s[is] - '0';
    num.push_back(s[is]);
    recurse(a, s, ia, is - 1, num);
    return;
  }
  long long digA = a[ia] - '0';
  long long digS = s[is] - '0';
  long long prevDig = (is > 0) ? s[is - 1] - '0' : -1;
  bool canContain = digA < 9 and (prevDig == 1 or is == 0);
  if (digA > digS) {
    if (canContain == false) return;
    long long dig = ((prevDig * 10 + digS) - digA);
    num.push_back(dig + '0');
    recurse(a, s, ia - 1, is - 2, num);
  } else {
    long long dig = (digS - digA);
    num.push_back(dig + '0');
    recurse(a, s, ia - 1, is - 1, num);
  }
}
void solve() {
  string a, s;
  cin >> a >> s;
  ans = "-1";
  string num;
  recurse(a, s, a.size() - 1, s.size() - 1, num);
  if (ans == "-1") {
    cout << ans << "\n";
    return;
  }
  while (ans.back() == '0') ans.pop_back();
  reverse((ans).begin(), (ans).end());
  if (ans.size() > 0)
    cout << ans << "\n";
  else
    cout << -1 << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
