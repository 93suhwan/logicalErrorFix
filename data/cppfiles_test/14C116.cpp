#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const long long maxn = 200005;
const long long inf = 1ll << 60;
void yes() { cout << "Yes\n"; }
void no() { cout << "No\n"; }
long long a[maxn];
long long f[2005][2005];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  long long T;
  cin >> T;
  while (T--) {
    long long n, k;
    cin >> n >> k;
    for (long long i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (long long i = 1; i <= n; i++) {
      f[i][0] = f[i - 1][0] + (a[i] == i);
      for (long long j = 1; j <= i; j++) {
        f[i][j] = max(f[i - 1][j] + (i - j - a[i] == 0), f[i - 1][j - 1]);
      }
    }
    for (long long i = 0; i <= n; i++) {
      if (f[n][i] >= k) {
        cout << i << "\n";
        goto loop;
      }
    }
    cout << "-1\n";
  loop:;
  }
}
