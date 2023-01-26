#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int fac[200050] = {1, 1};
void init() {
  for (int i = 1; i < 200002; i++) {
    fac[i] = fac[i - 1] * i % mod;
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
      int k = fac[sec[1]] * (sec[1]) % mod * fac[n - sec[1] - 1] % mod *
              ((long long)fac[n] /
               (long long)(fac[n - sec[1] - 1] * fac[sec[1] + 1]) % mod) %
              mod;
      cout << k << endl;
    }
  }
  return 0;
}
