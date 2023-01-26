#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y) {
  if (x == 0)
    return 0;
  else if (y == 0)
    return 1;
  long long temp = power(x, y / 2) % 998244353;
  if (y & 1)
    return (((temp * temp) % 998244353) * x) % 998244353;
  else
    return (temp * temp) % 998244353;
}
void solve() {
  long long n, m, i, j;
  long long a, b, s;
  cin >> a >> s;
  string s1 = to_string(a), s2 = to_string(s);
  if (s2.size() < s1.size()) {
    cout << "-1\n";
    return;
  }
  string ans;
  j = s1.size() - 1;
  for (i = s2.size() - 1; i >= 0; i--) {
    if (s2[i] >= s1[j]) {
      string tmp;
      tmp += s2[i];
      long long x = stoi(tmp);
      tmp.clear();
      tmp += s1[j];
      long long y = stoi(tmp);
      ans += to_string(x - y);
    } else {
      if (i == 0) {
        cout << "-1\n";
        return;
      }
      i--;
      string tmp;
      tmp += s2[i];
      tmp += s2[i + 1];
      long long x = stoi(tmp);
      if (x > 18) {
        cout << "-1\n";
        return;
      }
      tmp.clear();
      tmp += s1[j];
      long long y = stoi(tmp);
      ans += to_string(x - y);
    }
    j--;
    if (j < 0) break;
  }
  if (j >= 0) {
    cout << "-1\n";
    return;
  }
  if (i >= 0) {
    string tmp = s2.substr(0, i);
    reverse(tmp.begin(), tmp.end());
    ans += tmp;
  }
  while (ans[ans.size() - 1] == '0') ans.pop_back();
  reverse(ans.begin(), ans.end());
  cout << ans << "\n";
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long _t;
  cin >> _t;
  while (_t--) solve();
}
