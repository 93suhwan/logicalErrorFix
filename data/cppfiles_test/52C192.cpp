#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int add(int a, int b) { return a + b - (a + b >= mod) * mod; }
int sub(int a, int b) { return a - b + (a - b < 0) * mod; }
int mul(int a, int b) { return (1ll * a * b) % mod; }
int powM(int n, int p) {
  return (!p ? 1 : (p & 1) ? mul(n, powM(n, p - 1)) : powM(mul(n, n), p / 2));
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k, ans = 0;
    cin >> n >> k;
    for (int i = 29; i >= 0; i--)
      if ((1 << i) <= k) k -= (1 << i), ans = add(ans, powM(n, i));
    cout << ans << '\n';
  }
}
