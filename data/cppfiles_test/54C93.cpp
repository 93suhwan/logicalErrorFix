#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;
long long f[1000010];
const long long mod = 1000000007;
void solve() {
  for (int i = 1; i <= 200010; i++) {
    f[i] = f[i - 1] * 2 % mod;
  }
}
long long sol(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) {
      ans = a * ans % mod;
    }
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
int main() {
  int t;
  cin >> t;
  f[0] = 1;
  solve();
  while (t--) {
    int n, k;
    cin >> n >> k;
    if (n & 1) {
      long long ans = sol(f[n - 1] + 1, k);
      cout << ans << endl;
      continue;
    }
    if (k == 0) {
      cout << 1 << endl;
      continue;
    }
    long long ans = sol(f[n - 1] - 1, k);
    for (int i = 1; i <= k; i++) {
      long long k1 = sol(f[n - 1] - 1, i - 1) * sol(f[n], k - i) % mod;
      ans = (ans + k1) % mod;
    }
    cout << ans << endl;
  }
  return 0;
}
