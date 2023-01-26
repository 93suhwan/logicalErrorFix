#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 2e18;
vector<string> power2;
int solve(const string& s, const string& t) {
  int p1 = 0, p2 = 0;
  int cnt = 0;
  while (p1 < (int)s.length() && p2 < (int)t.length()) {
    if (s[p1] == t[p2]) {
      p2++;
      cnt++;
    }
    p1++;
  }
  return s.length() + t.length() - 2 * cnt;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < 62; ++i) {
    power2.push_back(to_string((1LL << i)));
  }
  while (t--) {
    string s;
    cin >> s;
    int ans = 100;
    for (int i = 0; i < (int)power2.size(); ++i) {
      ans = min(ans, solve(s, power2[i]));
    }
    cout << ans << '\n';
  }
  return 0;
}
