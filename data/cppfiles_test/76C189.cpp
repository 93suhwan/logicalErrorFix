#include <bits/stdc++.h>
using namespace std;
const int MAXN = 4e6 + 10;
long long f[MAXN] = {0};
int main() {
  long long N, MOD;
  cin >> N >> MOD;
  f[1] = 1;
  long long sum = 1;
  for (long long i = 2; i <= N; ++i) {
    f[i] = sum % MOD;
    for (long long l = 2, r; l <= i; l = r + 1) {
      r = i / (i / l);
      f[i] = (f[i] + ((r - l + 1) % MOD * f[i / l] % MOD) % MOD) % MOD;
    }
    sum = (sum + f[i] % MOD) % MOD;
  }
  cout << f[N] % MOD;
  return 0;
}
