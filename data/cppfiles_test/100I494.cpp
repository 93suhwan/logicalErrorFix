#include <bits/stdc++.h>
#pragma pack(1)
#pragma GCC target("avx,avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
long long int fact(long long int n) {
  if (n == 0) return 1;
  return ((n % 998244353) * (fact(n - 1)) % 998244353) % 998244353;
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int a[n];
    for (long long int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    long long int cmax = 0;
    long long int csecmax = 0;
    long long int x = a[n - 1];
    for (long long int i = n - 1; i >= 0; --i) {
      if (a[i] != a[n - 1]) {
        x = a[i];
        break;
      }
    }
    for (long long int i = 0; i < n; ++i) {
      if (a[i] == a[n - 1])
        ++cmax;
      else if (a[i] == x)
        ++csecmax;
    }
    if (cmax > 1) {
      cout << fact(n) << endl;
    } else if ((a[n - 1] - x) > 1) {
      cout << "0" << endl;
    } else {
      long long int ans = fact(n);
      long long int dns =
          ((fact(n) % 998244353) * (fact(csecmax) % 998244353)) % 998244353;
      long long int fin = fact(cmax + csecmax) % 998244353;
      long long int amit =
          ((ans % 998244353) - (((dns) / (fin)) % 998244353) + 998244353) %
          998244353;
      cout << amit << endl;
    }
  }
  return 0;
}
