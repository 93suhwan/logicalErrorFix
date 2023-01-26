#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int inf = 2e9 + 2;
long long GCD(long long A, long long B) { return (B == 0) ? A : GCD(B, A % B); }
int LCM(int A, int B) { return A * B / GCD(A, B); }
int power(int a, int n) {
  int res = 1;
  while (n) {
    if (n & 1) res = (res * 1ll * a) % mod;
    n = n >> 1;
    a = (a * 1ll * a) % mod;
  }
  return res;
}
int helper(string &a, string &b, int n) {
  int c10 = 0, c01 = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == '1' && b[i] == '0') c10++;
    if (a[i] == '0' && b[i] == '1') c01++;
  }
  if (c10 == c01) return c10 + c01;
  return inf;
}
int change(string a, string &b, int n, char ch) {
  int idx = -1;
  for (int i = 0; i < n; i++) {
    if (a[i] == '1' && b[i] == ch) {
      idx = i;
      break;
    }
  }
  if (idx == -1) return inf;
  for (int i = 0; i < n; i++) {
    if (idx == i) continue;
    if (a[i] == '1')
      a[i] = '0';
    else
      a[i] = '1';
  }
  return helper(a, b, n);
}
void solve() {
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  if (a == b) {
    cout << 0 << "\n";
    return;
  }
  int ans = inf;
  ans = helper(a, b, n);
  ans = min(ans, 1 + change(a, b, n, '1'));
  ans = min(ans, 1 + change(a, b, n, '0'));
  if (ans == inf)
    cout << -1 << "\n";
  else
    cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
