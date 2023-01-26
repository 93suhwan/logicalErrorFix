#include <bits/stdc++.h>
using namespace std;
const long long inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const long long mod = 1e9 + 7;
const long long MOD = 998244353;
const long long N = 70;
long long ans;
string s, fj[N];
inline void INIT() {
  long long p = 1;
  for (long long i = 0; i <= 62; i++) {
    long long x = p;
    while (x) {
      long long tmp = x % 10;
      fj[i] = (char)(tmp + '0') + fj[i];
      x /= 10;
    }
    p *= 2;
  }
}
inline void init() { ans = INF; }
inline void solve() {
  cin >> s;
  for (long long i = 0; i <= 62; i++) {
    long long sum = 0;
    for (long long j = 0; j < s.size(); j++) {
      if (fj[i][sum] == s[j]) {
        sum++;
      }
      if (sum > fj[i].size()) {
        break;
      }
    }
    ans = min(ans, (long long)(s.size() + fj[i].size() - 2 * sum));
  }
  cout << ans << endl;
}
signed main() {
  ios::sync_with_stdio(false);
  cout.tie(NULL);
  INIT();
  long long Time = 1;
  cin >> Time;
  while (Time--) {
    init();
    solve();
  }
  return 0;
}
