#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    if (s[0] != s[(int)s.size() - 1]) s[0] = s[(int)s.size() - 1];
    cout << s << '\n';
  }
  return 0;
}
