#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
int div(int x) {
  int res = 0;
  while (x) x /= 10, res++;
  return res;
}
long long power10(int n) {
  long long res = 1;
  long long a = 10;
  while (n) {
    if (n & 1) res *= a;
    a *= a;
    n >>= 1;
  }
  return res;
}
void solve() {
  long long x1, p1, x2, p2;
  cin >> x1 >> p1 >> x2 >> p2;
  int len1 = 0, len2 = 0;
  len1 = div(x1), len2 = div(x2);
  if (len1 > len2) {
    x2 = x2 * power10(len1 - len2);
    p2 -= len1 - len2;
  } else if (len1 < len2) {
    x1 *= power10(len2 - len1);
    p1 -= len2 - len1;
  }
  if (p1 == p2) {
    if (x1 > x2) {
      puts(">");
    } else if (x1 < x2) {
      puts("<");
    } else
      puts("=");
  } else if (p1 > p2) {
    puts(">");
  } else
    puts("<");
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
