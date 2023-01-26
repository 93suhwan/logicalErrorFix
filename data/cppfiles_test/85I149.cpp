#include <bits/stdc++.h>
using namespace std;
long double pi = 3.141592653589793238462643383279;
const long long INF = 1e18 + 10LL;
long long power(long long x, long long y) {
  long long res = 1;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x);
    y = y >> 1;
    x = (x * x);
  }
  return res;
}
void bruteforce() {}
void solve() {
  string s;
  cin >> s;
  long long zero = 0;
  for (long long i = 0; i < s.size(); i++) {
    if (s[i] == '0') {
      zero++;
    }
  }
  cout << min(zero, ((s.size() - zero) ? 2LL : 1LL)) << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
}
