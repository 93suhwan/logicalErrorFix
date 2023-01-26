#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007ll;
long long bn(long long aa, long long n) {
  long long r = 1ll;
  for (; n > 0; n >>= 1ll) {
    if (n & 1) r = (r * aa) % MOD;
    aa = (aa * aa) % MOD;
  }
  return r;
}
const long double pi = 2 * acos(0.0);
int n;
long long f[322222 * 5], c[322222 * 5];
long long get(int i) {
  long long res = 0;
  for (; i <= n; i += (i & -i)) res += f[i];
  return res;
}
void up(int i) {
  for (; i > 0; i -= (i & -i)) f[i]++;
}
void solve() {
  cin >> n;
  for (int i = 0; i <= n; i++) f[i] = c[i] = 0;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    ans += get(x + 1);
    up(x);
    c[x]++;
  }
  for (int i = 1; i <= n; i++)
    if (c[i] > 1) {
      cout << "YES\n";
      return;
    }
  cout << (ans % 2 == 1 ? "NO\n" : "YES\n");
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
