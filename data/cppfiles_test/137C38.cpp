#include <bits/stdc++.h>
using namespace std;
long long t;
long long X, Y, x1, x2;
long long mxbit(long long x) {
  long long cnt = 0;
  while (x > 0) {
    cnt++;
    x >>= 1;
  }
  return cnt - 1;
}
long long rev(long long x) {
  long long k = mxbit(x), re = 0;
  for (long long i = 0; i <= k; i++) {
    re |= (1LL << i) * bool((1LL << (k - i)) & x);
  }
  return re;
}
bool ck(long long x) {
  long long tmp = mxbit(x);
  long long tmp2 = mxbit(Y);
  if (tmp > tmp2) return false;
  for (long long i = 0; i < tmp2 - tmp; i++) {
    x <<= 1LL;
    x |= 1LL;
  }
  if (x == Y) return true;
  for (long long i = tmp2; i > tmp; i--) {
    x >>= 1;
    x |= 1LL << tmp2;
    if (x == Y) return true;
  }
  return false;
}
int main() {
  t = 1;
  while (t--) {
    cin >> X >> Y;
    if (X == Y)
      cout << "YES\n";
    else {
      if (mxbit(X) < mxbit(Y)) {
        x1 = (X << 1) | 1;
        x2 = rev(x1);
        if (ck(x1) || ck(x2)) {
          cout << "YES\n";
          continue;
        }
      }
      x1 = X;
      while (!(x1 & 1)) x1 >>= 1;
      x2 = rev(x1);
      if (ck(x1) || ck(x2)) {
        cout << "YES\n";
        continue;
      }
      cout << "NO\n";
    }
  }
}
