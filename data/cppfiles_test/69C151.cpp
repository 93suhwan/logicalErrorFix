#include <bits/stdc++.h>
using namespace std;
int cum(string s, string t) {
  int ps = 0, pt = 0, num = 0;
  while (ps < s.size() && pt < t.size()) {
    if (s[ps] == t[pt]) {
      num++;
      pt++;
    }
    ps++;
  }
  return s.size() - num - num + t.size();
}
int main() {
  int t;
  ios::sync_with_stdio(false);
  cin >> t;
  vector<string> sz;
  long long int x = 1;
  while (x <= (long long)2e18) {
    sz.push_back(to_string(x));
    x = x * 2;
  }
  while (t--) {
    string n;
    cin >> n;
    int ans = n.length() + 1;
    for (auto t : sz) {
      ans = min(ans, cum(n, t));
    }
    cout << ans << endl;
  }
  return 0;
}
