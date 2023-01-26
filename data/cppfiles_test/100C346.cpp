#include <bits/stdc++.h>
using namespace std;
inline long long gcd(long long x, long long y) { return y ? gcd(y, x % y) : x; }
long long qpow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans *= a;
    b >>= 1;
    a *= a;
  }
  return ans;
}
long long qpow(long long a, long long b, long long mod) {
  long long ans = 1;
  a %= mod;
  while (b) {
    if (b & 1) (ans *= a) %= mod;
    b >>= 1;
    (a *= a) %= mod;
  }
  return ans % mod;
}
inline long long read() {
  long long s = 0, w = 1;
  char ch = getchar();
  while (ch < 48 || ch > 57) {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= 48 && ch <= 57)
    s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar();
  return s * w;
}
const int mod = 1e9 + 7;
const int N = 2e5 + 7;
int n, m;
int nums[N];
void solve() {
  cin >> n;
  int ans = 1e9 + 7;
  for (int i = 1; i <= n; i++) {
    cin >> nums[i];
    ans = min(ans, nums[i]);
  }
  if (n == 1) {
    cout << nums[1] << endl;
    return;
  }
  sort(nums + 1, nums + n + 1);
  for (int i = 2; i <= n; i++) {
    ans = max(ans, nums[i] - nums[i - 1]);
  }
  cout << ans << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
