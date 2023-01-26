#include <bits/stdc++.h>
using namespace std;
void sieve() {
  long long int i, j;
  long long int b[1000009];
  for (i = 2; i < 1000009; i++) {
    if (b[i] == 0) {
      for (j = 2 * i; j < 1000009; j = j + i) b[j] = 1;
    }
  }
}
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int modInverse(long long int n, long long int p) {
  return power(n, p - 2, p);
}
long long int nCrModPFermat(long long int n, long long int r, long long int p) {
  if (n < r) return 0;
  if (r == 0) return 1;
  long long int fac[n + 1];
  fac[0] = 1;
  for (long long int i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % p;
  return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) %
         p;
}
struct piyush {
  long long int height;
  long long int index;
  piyush(long long int x, long long int y) {
    height = x;
    index = y;
  }
};
struct CompareHeight {
  bool operator()(piyush const& p1, piyush const& p2) {
    return p1.height > p2.height;
  }
};
signed main() {
  long long int n, i, j, k, t;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<string> ans;
    for (i = 1; i <= n; i++) {
      string ssp;
      for (j = 1; j <= i; j++) {
        ssp += '(';
      }
      for (j = 1; j <= i; j++) {
        ssp += ')';
      }
      for (j = 1; j <= n; j++) {
        long long int len = ssp.length();
        if (len == 2 * n) {
          break;
        }
        ssp += '(';
        ssp += ')';
      }
      ans.push_back(ssp);
    }
    for (i = 0; i < ans.size(); i++) {
      cout << ans[i] << "\n";
    }
  }
}
