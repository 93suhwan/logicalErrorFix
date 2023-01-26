#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  string s;
  cin >> s;
  long long int mainans = LLONG_MAX;
  for (long long int i = 0; i < 26; i++) {
    long long int cnt = 0;
    string newstr = "";
    map<long long int, long long int> m;
    for (long long int j = 0; j < n; j++) {
      if (s[j] - 'a' == i) {
        m[cnt] += 1;
      } else {
        cnt += 1;
        newstr += s[j];
      }
    }
    string chk = newstr;
    reverse(chk.begin(), chk.end());
    if (chk == newstr) {
      long long int ans = 0;
      long long int red = 0;
      for (auto it = m.begin(); it != m.end(); ++it) {
        ans += (it->second);
        long long int req = cnt - (it->first);
        if (req == it->first) {
          red += ((it->second / 2) * 2);
        } else {
          if (m[req] > 0) {
            red += (min(it->second, m[req]));
          }
        }
      }
      mainans = min(mainans, ans - red);
    }
  }
  if (mainans == LLONG_MAX) {
    cout << -1 << "\n";
  } else {
    cout << mainans << "\n";
  }
}
int main() {
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
