#include <bits/stdc++.h>
using namespace std;
const long long oo = 1e18;
const long long maxn = 1e5 + 9;
long long a[maxn];
signed main() {
  cin.tie(0)->sync_with_stdio(0);
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    if (s[0] == s[(long long)s.size() - 1])
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }
  return 0;
}
