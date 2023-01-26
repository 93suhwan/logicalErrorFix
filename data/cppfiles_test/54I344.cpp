#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
long long fact[200010];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  fact[0] = 1;
  for (int i = 1; i < 200010; i++) fact[i] = (i * fact[i - 1]) % MOD;
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    int m = n / 2 + 1;
    long long A[m + 10];
    for (int i = 0; i < m; i++) {
      int p = 2 * i;
      A[i] = fact[n] / fact[p];
      A[i] /= fact[n - p];
    }
    if (n % 2) {
      m++;
      A[m - 1] = 1;
    }
    long long t = 0;
    for (int i = 0; i < m; i++) {
      t += A[i];
      t %= MOD;
    }
    long long ans = 1;
    for (int i = 0; i < k; i++) {
      ans *= t;
      ans %= MOD;
    }
    cout << ans << endl;
  }
  return 0;
}
