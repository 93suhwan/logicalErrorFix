#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize(2, 3)
const long long mod = 1000000007;
inline long long pw(long long x, long long y) {
  long long r = 1;
  while (y) {
    if (y & 1) r = r * x % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return r;
}
inline void mad(long long &a, long long b) {
  a = (a + b) % mod;
  while (a < 0) a += mod;
}
inline void mmu(long long &a, long long b) {
  a = a * b % mod;
  while (a < 0) a += mod;
}
int n;
int p[200010];
int s[200010];
char ch;
int a[200010], b[200010], c[200010];
void work() {
  cin >> n;
  for (register int i = 1; i <= n; i++) cin >> p[i];
  int cnt = 0;
  for (register int i = 1; i <= n; i++) {
    cin >> ch;
    s[i] = (ch == '1');
    cnt += 1 - s[i];
  }
  int at = 0, bt = 0;
  for (register int i = 1; i <= n; i++) {
    if (s[i] == 0)
      a[++at] = p[i];
    else
      b[++bt] = p[i];
  }
  for (register int i = 1; i <= at; i++) c[i] = a[i];
  sort(c + 1, c + 1 + at);
  for (register int i = 1; i <= at; i++)
    a[i] = lower_bound(c + 1, c + 1 + at, a[i]) - c;
  for (register int i = 1; i <= bt; i++) c[i] = b[i];
  sort(c + 1, c + 1 + bt);
  for (register int i = 1; i <= bt; i++)
    b[i] = lower_bound(c + 1, c + 1 + bt, b[i]) - c;
  at = bt = 0;
  for (register int i = 1; i <= n; i++) {
    if (s[i] == 0)
      cout << a[++at] << " ";
    else
      cout << cnt + b[++bt] << " ";
  }
  cout << endl;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) work();
  return 0;
}
