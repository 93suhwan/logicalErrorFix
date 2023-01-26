#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
const long long mod = 998244353;
long long f[N], num[N];
long long ppow(long long x, int i) {
  long long ans = 1, res = x % mod;
  while (i) {
    if (i & 1) ans = (res * ans) % mod;
    res = (res * res) % mod;
    i >>= 1;
  }
  return ans;
}
void init() {
  f[0] = 1;
  for (int i = 1; i < N; i++) {
    f[i] = (f[i - 1] * i) % mod;
  }
}
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> num[i];
  sort(num + 1, num + 1 + n);
  if (num[n] == num[n - 1]) {
    cout << f[n] << endl;
  } else {
    if (num[n] != num[n - 1] + 1) {
      cout << 0 << endl;
      return;
    }
    int cnt = 1;
    for (int i = n - 1; i >= 2; i--) {
      if (num[i - 1] == num[i]) cnt++;
    }
    cnt++;
    long long ans = f[n] * ppow(cnt, mod - 2) % mod;
    ans = (f[n] - ans + mod) % mod;
    cout << ans << endl;
  }
}
int main() {
  init();
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}
