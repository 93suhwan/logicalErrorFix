#include <bits/stdc++.h>
using namespace std;
long long add(long long x, long long y) {
  long long res = x + y;
  return (res >= 1000000007 ? res - 1000000007 : res);
}
long long mul(long long x, long long y) {
  long long res = x * y;
  return (res >= 1000000007 ? res % 1000000007 : res);
}
long long sub(long long x, long long y) {
  long long res = x - y;
  return (res < 0 ? res + 1000000007 : res);
}
long long power(long long x, long long y) {
  long long res = 1;
  x %= 1000000007;
  while (y) {
    if (y & 1) res = mul(res, x);
    y >>= 1;
    x = mul(x, x);
  }
  return res;
}
long long mod_inv(long long x) { return power(x, 1000000007 - 2); }
long long floorSqrt(long long x) {
  if (x == 0 || x == 1) return x;
  unsigned long long start = 1, end = x, ans;
  while (start <= end) {
    unsigned long long mid = start + (end - start) / 2;
    if (mid * mid == x) return mid;
    if (mid * mid < x) {
      start = mid + 1;
      ans = mid;
    } else
      end = mid - 1;
  }
  return ans;
}
string tobinary(long long n, long long length) {
  string s;
  for (long long i = 0; i < length; i++) {
    if (n & 1)
      s.push_back('1');
    else
      s.push_back('0');
    n = n >> 1;
  }
  reverse(s.begin(), s.end());
  return s;
}
void solve() {
  int n, s;
  cin >> n >> s;
  cout << (s) / (n / 2 + 1) << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, i = 1;
  ;
  cin >> t;
  while (t--) {
    solve();
    ++i;
  }
}
