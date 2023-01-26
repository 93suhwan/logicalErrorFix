#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n = 2e5 + 1;
int sz = 1;
string ans = "";
bool rec(string& n, string& s, int i = 0, int j = 0) {
  if (i == n.size()) {
    if (j == s.size()) return 1;
    return 0;
  }
  if (j == s.size()) {
    return 0;
  }
  if (s[j] >= n[i]) {
    ans += to_string(s[j] - n[i]);
    if (rec(n, s, i + 1, j + 1)) return 1;
    ans.pop_back();
  }
  if (s.size() > j + 1 && s[j + 1] - n[i] + 10 <= 9 && s[j] == '1') {
    ans += to_string(s[j + 1] - n[i] + 10);
    if (rec(n, s, i + 1, j + 2)) return 1;
    ans.pop_back();
  }
  return 0;
}
void solve() {
  ans = "";
  string n, s;
  cin >> n >> s;
  if (n.size() == 1 && s.size() == 2) {
    if (n[0] == s[1]) {
      cout << s[0] << "0\n";
      return;
    }
  }
  rec(n, s);
  if (ans.empty())
    cout << -1 << endl;
  else
    cout << ans << endl;
}
int main() {
  int tc;
  cin >> tc;
  while (tc--) solve();
  return 0;
}
