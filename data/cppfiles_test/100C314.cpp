#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 9;
const long long M = 5e5 + 9;
const long long mod = 1e9 + 7;
long long Max(long long a, long long b) { return a > b ? a : b; }
long long Min(long long a, long long b) { return a > b ? b : a; }
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a * (b / gcd(a, b)); }
long long Abs(long long x) { return x < 0 ? -x : x; }
void updata(long long &a, long long b) {
  if (b > a) a = b;
}
void lowdata(double &a, double b) {
  if (b < a) a = b;
}
void swapp(long long &a, long long &b) {
  long long t = a;
  a = b;
  b = t;
}
long long roundd(double number) {
  return (number > 0.0) ? (number + 0.5) : (number - 0.5);
}
long long multi(long long a, long long b, long long modd) {
  long long res = 0;
  while (b) {
    if (b & 1) res = (res + a) % modd;
    a = (a + a) % modd;
    b /= 2;
  }
  return res;
}
long long a[N];
int main() {
  long long t;
  scanf("%lld", &t);
  ;
  while (t--) {
    long long n;
    scanf("%lld", &n);
    ;
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    ;
    sort(a + 1, a + 1 + n);
    long long ans = a[1], maxn = a[1], add = 0;
    for (int i = 2; i <= n; i++) {
      long long tmp = ans;
      ans = a[i] - ans - add;
      add += tmp;
      updata(maxn, ans);
    }
    printf("%lld", maxn);
    ;
    printf("\n");
    ;
  }
  return 0;
}
