#include <bits/stdc++.h>
using namespace std;
long long f(long long x) {
  if (x <= 1) {
    return 0;
  }
  if (x % 2 == 0) {
    return f(x / 2) + (x % 4 == 2);
  } else {
    return f(x - 1);
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long n;
  cin >> n;
  vector<long long> A(n);
  for (long long i = 0; i < n; i++) {
    cin >> A[i];
  }
  vector<long long> B = A;
  long long ans = 0;
  long long x1 = 0, y1 = 0;
  for (long long _ = 0; _ < 40; _++) {
    long long mxeven = (long long)-1e9, mxodd = (long long)-1e9;
    long long x0 = 0, y0 = 0;
    for (long long i = 0; i < n; i++) {
      long long x = B[i];
      if (x % 2 == 0) {
        if (mxeven < f(x)) {
          mxeven = f(x);
          x0 = i;
        }
      } else {
        if (mxodd < f(x)) {
          mxodd = f(x);
          y0 = i;
        }
      }
    }
    if (ans < mxeven + mxodd + 1) {
      ans = mxeven + mxodd + 1;
      x1 = x0;
      y1 = y0;
    }
    for (auto &x : B) {
      x /= 2;
    }
  }
  cout << x1 + 1 << ' ' << y1 + 1 << ' ' << ans << '\n';
}
