#include <bits/stdc++.h>
using namespace std;
long long max2(long long x, long long y) {
  if (x > y)
    return x;
  else
    return y;
}
long long min2(long long x, long long y) {
  if (x < y)
    return x;
  else
    return y;
}
unsigned long long min3(unsigned long long x, unsigned long long y) {
  if (x < y)
    return x;
  else
    return y;
}
long double min(long double x, long double y) {
  if (x < y)
    return x;
  else
    return y;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long parent(long long i) { return (i - 1) / 2; }
long long left(long long i) { return i * 2 + 1; }
long long right(long long i) { return 2 * i + 2; }
bool within(long long x, long long l, long long r) {
  return ((x >= l) && (x <= r)) || ((x <= l) && (x >= r));
}
void solve(long long t) {
  unsigned long long l, r;
  cin >> l >> r;
  long long ans = ceil((double)r / 2.00) - 1;
  if (ans < l) ans = r % l;
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  int q = 0;
  cin >> t;
  while (t--) {
    q++;
    solve(q);
  }
  return 0;
}
