#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e6;
const long long inf = 1e18;
int t;
long long X, Y, x1, x2;
int mxbit(long long x) {
  int cnt = 0;
  while (x > 0) {
    cnt++;
    x >>= 1;
  }
  return cnt - 1;
}
long long rev(long long x) {
  long long k = mxbit(x), re = 0;
  for (int i = 0; i <= k; i++) {
    re |= (1LL << i) * bool((1LL << (k - i)) & x);
  }
  return re;
}
bool ck(long long x) {
  int tmp = mxbit(x);
  if (tmp > mxbit(Y)) return false;
  for (int i = 0; i < mxbit(Y) - tmp; i++) {
    x <<= 1;
    x |= 1;
  }
  if (x == Y) return true;
  for (int i = mxbit(Y); i > tmp; i--) {
    x >>= 1;
    x |= (1LL << i);
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
