#include <bits/stdc++.h>
using namespace std;
long long a[65];
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long sum = 0;
    long long z = 0, o = 0;
    for (long long i = 1; i <= n; i++) {
      cin >> a[i], sum += a[i];
      if (a[i] == 0) z++;
      if (a[i] == 1) o++;
    }
    long long k = pow(2, z);
    cout << k * o << endl;
  }
}
