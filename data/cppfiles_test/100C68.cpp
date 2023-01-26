#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
long long fac[200010], infact[200010];
long long qmi(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b % 2) {
      res = res * a % mod;
    }
    b >>= 1;
    a = a * a % mod;
  }
  return res;
}
void init() {
  fac[0] = 1;
  infact[0] = 1;
  for (int i = 1; i <= 200000; i++) {
    fac[i] = i * fac[i - 1] % mod;
    infact[i] = qmi(fac[i], mod - 2) % mod;
  }
}
int main() {
  int t;
  cin >> t;
  init();
  while (t--) {
    int fir[2] = {0}, sec[2] = {0};
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      int num;
      cin >> num;
      if (sec[0] == num) {
        sec[1]++;
      } else if (fir[0] == num) {
        fir[1]++;
      } else if (fir[0] < num) {
        sec[0] = fir[0];
        sec[1] = fir[1];
        fir[0] = num;
        fir[1] = 1;
      } else if (num > sec[0]) {
        sec[0] = num;
        sec[1] = 1;
      }
    }
    if (fir[1] > 1) {
      cout << fac[n] << endl;
      continue;
    } else if (fir[0] - sec[0] >= 2) {
      cout << 0 << endl;
      continue;
    } else {
      long long ans;
      ans = (fac[n] * infact[n - sec[1] - 1] % mod * infact[sec[1] + 1] % mod +
             mod) %
            mod;
      int k =
          fac[sec[1]] * (sec[1]) % mod * fac[n - sec[1] - 1] % mod * ans % mod;
      cout << k % mod << endl;
    }
  }
  return 0;
}
