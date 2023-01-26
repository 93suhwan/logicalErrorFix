#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const long long inf = 1e18;
const long long MOD = 1e9 + 7;
const long long N = 1e5 + 10;
void go() {
  string s;
  cin >> s;
  long long n = s.size();
  long long cnt = 0;
  for (long long i = 0; i < n; i++) {
    if (s[i] == '0' && (i == 0 || s[i - 1] != '0')) cnt++;
  }
  cout << min(2LL, cnt) << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  long long t = 1;
  cout << fixed << setprecision(20);
  cin >> t;
  long long cases = 1;
  while (t--) {
    go();
  }
}
