#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
template <typename T>
inline T lowbit(T x) {
  return x & -x;
}
const long long N = 4e5 + 10;
map<char, long long> mp;
void solve() {
  mp.clear();
  string s;
  cin >> s;
  for (long long i = 0; i < 26; i++) {
    mp[s[i]] = i;
  }
  string str;
  cin >> str;
  long long res = 0;
  for (long long i = 1; i < str.size(); i++) {
    res += abs(mp[str[i]] - mp[str[i - 1]]);
  }
  printf("%lld\n", res);
}
signed main() {
  long long _;
  cin >> _;
  while (_--) solve();
  return 0;
}
