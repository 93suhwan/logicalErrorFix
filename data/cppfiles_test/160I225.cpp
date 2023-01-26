#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else if (a == 0)
    return b;
  else
    return gcd(b % a, a);
}
string toBinary(long long num) {
  string out = "";
  while (num > 0) {
    long long rem = num % 2;
    out = to_string(rem) + out;
    num = num / 2;
  }
  return out;
}
int fact(int num) {
  if (num <= 1) return 1;
  int ans = 1;
  for (int i = 1; i <= num; i++) ans *= i;
  return ans;
}
int main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    int n, m;
    cin >> n >> m;
    int r1, c1, rf, cf;
    cin >> r1 >> c1 >> rf >> cf;
    if (r1 == rf || c1 == cf) {
      cout << "0\n";
      continue;
    }
    int incr = 1, inc = 1;
    int ans = 0;
    while (r1 != rf || c1 != cf) {
      if (incr > 0 && inc > 0) {
        int mn = min(n - r1, m - c1);
        if ((rf >= r1 && rf <= r1 + mn)) {
          ans += rf - r1;
          break;
        } else if (cf >= c1 && cf <= c1 + mn) {
          ans += cf - c1;
          break;
        } else {
          r1 = r1 + mn;
          c1 = c1 + mn;
          ans += mn;
          if (r1 == n) incr = -1;
          if (c1 == m) inc = -1;
        }
      } else if (incr < 0 && inc > 0) {
        int mn = min(r1 - 1, m - c1);
        if (rf >= r1 - mn && rf <= r1) {
          ans += r1 - rf;
          break;
        } else if (cf >= c1 && cf <= c1 + mn) {
          ans += cf - c1;
          break;
        } else {
          ans += mn;
          r1 = r1 - mn;
          c1 = c1 + mn;
          if (r1 == 1) incr = 1;
          if (c1 == m) inc = -1;
        }
      } else if (inc < 0 && incr > 0) {
        int mn = min(n - r1, c1 - 1);
        if ((rf >= r1 && rf <= r1 + mn)) {
          ans += rf - r1;
          break;
        } else if (cf <= c1 && cf >= c1 - mn) {
          ans += c1 - cf;
          break;
        } else {
          ans += mn;
          r1 = r1 + mn;
          c1 = c1 - mn;
          if (r1 == n) incr = -1;
          if (c1 == 1) inc = +1;
        }
      } else if (incr < 0 && inc < 0) {
        int mn = min(r1 - 1, c1 - 1);
        if (rf >= r1 - mn && rf <= r1) {
          ans += r1 - rf;
          break;
        } else if (cf <= c1 && cf >= c1 - mn) {
          ans += c1 - cf;
          break;
        } else {
          ans += mn;
          r1 = r1 - mn;
          c1 = c1 - mn;
          if (r1 == 1) incr = 1;
          if (c1 == 1) inc = 1;
        }
      }
    }
    cout << ans << "\n";
  }
}
