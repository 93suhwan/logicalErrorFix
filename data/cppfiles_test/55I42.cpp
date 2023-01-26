#include <bits/stdc++.h>
using namespace std;
long long n, k;
long long pw(long long x, long long y) {
  if (y == 0) return 1;
  long long pp = pw(x, y / 2);
  if (y & 1) return pp * pp % 1000000007 * x % 1000000007;
  return pp * pp % 1000000007;
}
int main() {
  cin >> k;
  long long p = pw(2, k);
  p -= 2;
  p %= 1000000007;
  if (p < 0) p += 1000000007;
  p = pw(4, p);
  p = p * 6 % 1000000007;
  cout << p << endl;
  return 0;
}
