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
    while (r1 != rf && c1 != cf) {
      if (r1 == 1) incr = 1;
      if (c1 == 1) inc = 1;
      if (r1 == n) incr = -1;
      if (c1 == m) inc = -1;
      r1 += incr;
      c1 += inc;
      ans++;
    }
    cout << ans << "\n";
  }
}
