#include <bits/stdc++.h>
const int N = 1e7 + 7;
const long long mod = 1e9 + 7;
const double eps = 1e-10;
const long long inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
using namespace std;
int t;
string s;
int main() {
  cin >> t;
  while (t--) {
    map<char, int> mp;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
      mp[s[i]]++;
      if (mp[s[i]] > 2) ans++;
    }
    int res = (s.size() - ans) / 2;
    cout << res << endl;
  }
  return 0;
}
