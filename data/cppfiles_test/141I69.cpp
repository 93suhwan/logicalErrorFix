#include <bits/stdc++.h>
using namespace std;
void solve() {
  string a, s;
  cin >> a >> s;
  string ans;
  long long sizeA = a.size(), sizeS = s.size();
  if (sizeA > sizeS) {
    cout << "-1"
         << "\n";
    return;
  }
  long long ia = sizeA - 1, is = sizeS - 1;
  while (ia >= 0 and is >= 0) {
    long long digA = a[ia] - '0';
    long long digS = s[is] - '0';
    long long prevDig = (is > 0) ? s[is - 1] - '0' : 0;
    bool canContain = digA < 9 and prevDig == 1;
    if (digA > digS) {
      if (canContain == false) {
        ans = "-1";
        break;
      }
      long long dig = (prevDig * 10 + digS) - digA;
      ans.push_back(dig + '0');
      is--;
    } else {
      long long dig = (digS - digA);
      ans.push_back(dig + '0');
    }
    ia--, is--;
  }
  if (ans == "-1" or ia >= 0) {
    cout << "-1"
         << "\n";
    return;
  }
  while (is >= 0) ans.push_back(s[is--]);
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
