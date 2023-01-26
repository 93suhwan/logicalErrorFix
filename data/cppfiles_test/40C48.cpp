#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 5;
const int MXN = 2e5 + 5;
const long long LMXN = 1e14;
const int MOD = 1e9 + 7;
const int N = 2e6 + 5;
long long cs = 0;
long long pw(long long a, long long b, long long m) {
  a %= m;
  long long ans = 1;
  while (b > 0) {
    if (b & 1) ans = ans * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return ans;
}
void solve() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < (n); i++) cin >> a[i];
  int b[n];
  for (int i = 0; i < (n); i++) cin >> b[i];
  int ans = INF;
  int s1 = 0, s2 = 0;
  for (int i = 0; i < (n); i++) s1 += a[i];
  for (int i = 0; i < (n); i++) {
    s1 -= a[i];
    ans = min(ans, max(s1, s2));
    s2 += b[i];
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cout << fixed;
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
