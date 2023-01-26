#include <bits/stdc++.h>
using namespace std;
const long long inf = 0x3f3f3f3f3f3f3f3f;
const int Inf = 0x3f3f3f3f;
const int p = 107;
const int P = 100007;
const int Mod = 1e9 + 7;
const long double eps = 1e-14;
int n, m;
int a[2000005];
void work() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  int ans = a[1];
  for (int i = 2; i <= n; i++) ans &= a[i];
  cout << ans << endl;
}
signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);
  int T = 1;
  cin >> T;
  while (T--) {
    work();
  }
  return 0;
}
