#include <bits/stdc++.h>
using namespace std;
int f[200010];
void pre_cal() {
  f[0] = 1;
  int i = 1;
  while (i <= 200002) {
    f[i] = f[i - 1] * 2 % 1000000007;
    i++;
  }
}
int power(int a, int b) {
  int res = 1 % 1000000007;
  while (b) {
    if (b & 1) res = (1ll) * res * a % 1000000007;
    a = (1ll) * a * a % 1000000007;
    b >>= 1;
  }
  return res;
}
int main() {
  pre_cal();
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    if (k == 0) {
      cout << 1 << endl;
      continue;
    }
    if (n & 1) {
      cout << power(f[n - 1] + 1, k) << endl;
      continue;
    }
    int ans = power(f[n - 1] - 1, k);
    for (int i = 0; i < k; i++) {
      int res = (long long)power(f[n - 1] - 1, i) * power(f[n], k - i - 1) %
                1000000007;
      ans = (ans + res) % 1000000007;
    }
    cout << ans << endl;
  }
}
