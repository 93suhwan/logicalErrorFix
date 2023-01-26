#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int ii = 0; ii < t; ii++) {
    long long n;
    cin >> n;
    long long A[200000];
    for (long long i = 0; i < n; i++) {
      cin >> A[i];
    }
    long long mmax = A[0];
    for (long long i = 1; i < n; i++) {
      mmax = max(mmax, A[i]);
    }
    long long b = 0;
    for (long long i = 0; i < n; i++) {
      if (A[i] == mmax) b++;
    }
    if (b > 1) {
      long long c = 1;
      for (long long i = 2; i <= n; i++) {
        c *= i;
        c %= 998244353;
      }
      cout << c << endl;
      continue;
    }
    b = 0;
    for (long long i = 1; i < n; i++) {
      if (A[i] == mmax - 1) b++;
    }
    if (b > 0) {
      {
        n--;
        int k = b;
        long long N[200000], B[200000];
        long long c = 1;
        for (long long i = 0; i <= n; i++) {
          c *= (i + 1);
          c %= 998244353;
          N[i] = c;
        }
        c = 1;
        for (long long i = k; i >= 1; i--) {
          c *= i;
          c %= 998244353;
          B[i - 1] = c;
        }
        long long s = N[n - 1];
        long long h;
        for (long long i = 0; i <= k; i++) {
          h = (B[k - i] * N[n - 1 - i]) % 998244353;
          s += h;
          s %= 998244353;
        }
        cout << (N[n] - s) % 998244353 << endl;
      }
      continue;
    } else {
      cout << 0 << endl;
    }
  }
  return 0;
}
