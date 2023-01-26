#include <bits/stdc++.h>
using namespace std;
const long long inf = (long long)1e18;
long long MOD = (long long)(1e9 + 7);
long long mod = MOD;
long long mod1 = 998244353;
long long binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long tt = 1;
  cin >> tt;
  while (tt--) {
    long long n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    long long ans = 0;
    for (long long i = 0; i <= n - 1; i++) {
      if (s[i] != t[i]) {
        ans += 2;
      } else {
        if (i < n - 1) {
          if (s[i + 1] != t[i + 1]) {
            if (s[i] == '0') {
              ans++;
            }
          } else {
            if (s[i] != s[i + 1]) {
              ans += 2;
              i++;
            } else {
              if (s[i] == '0') {
                ans++;
              }
            }
          }
        } else {
          if (s[i] == '0') ans++;
        }
      }
    }
    cout << ans << endl;
  }
}
