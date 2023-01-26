#include <bits/stdc++.h>
const int INF = 1e9 + 5;
const int MOD = 1e9 + 7;
const double P = 3.141592;
const int hsh = 29;
using namespace std;
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) {
      res = res * a;
    }
    a = a * a;
    b >>= 1;
  }
  return res;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int ans = 0;
    int start = 0, togsgol = s.size() - 1;
    int barg = s.size();
    while (start < s.size() && togsgol >= 0 && barg > 0) {
      bool plus = false;
      for (start; start < s.size();) {
        if (s[start] == '1' && barg > 0) {
          start++;
          barg--;
        } else
          break;
      }
      for (togsgol; togsgol >= 0;) {
        if (s[togsgol] == '1' && barg > 0) {
          togsgol--;
          barg--;
        } else
          break;
      }
      while (barg > 0 && s[start] == '0') {
        start++;
        barg--;
        plus = true;
      }
      if (plus) ans++;
    }
    ans = min(ans, 2);
    cout << ans << '\n';
  }
}
