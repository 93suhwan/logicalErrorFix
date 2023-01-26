#include <bits/stdc++.h>
using namespace std;
long long powm(long long a, long long b, long long m) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res *= a;
    b /= 2;
    a *= a;
    res %= m;
    a %= m;
  }
  return res;
}
long long modinv(long long a, long long m = 1000000007) {
  return powm(a, m - 2, m);
}
const long long d4i[4] = {-1, 0, 1, 0}, d4j[4] = {0, 1, 0, -1};
const long long d8i[8] = {-1, -1, 0, 1, 1, 1, 0, -1},
                d8j[8] = {0, 1, 1, 1, 0, -1, -1, -1};
void FASTIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
void solve() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long ans = LLONG_MAX;
  for (char ch = 'a'; ch <= 'z'; ch++) {
    long long l = 0, r = n - 1;
    long long cost = 0;
    while (l < r) {
      if (s[l] != s[r]) {
        if (s[l] != ch && s[r] != ch) {
          cost = LLONG_MAX;
          break;
        } else {
          if (s[l] == ch)
            l++;
          else
            r--;
          cost++;
        }
      } else {
        l++, r--;
      }
    }
    ans = min(ans, cost);
  }
  if (ans == LLONG_MAX) {
    cout << -1 << '\n';
  } else
    cout << ans << '\n';
}
int32_t main() {
  FASTIO();
  long long t;
  cin >> t;
  for (long long i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
