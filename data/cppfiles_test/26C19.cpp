#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int T;
long long ksm(long long a, long long k, long long mod) {
  long long x = a, ans = 1;
  while (k) {
    if (k & 1) {
      ans = ans * a % mod;
    }
    k >>= 1;
    a = a * a % mod;
  }
  return ans;
}
int main() {
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    long long ans = 1;
    for (int i = 1; i <= 2 * n; i++) {
      ans = ans * i % mod;
    }
    long long y = ksm(2, mod - 2, mod);
    cout << ans * y % mod << endl;
  }
}
