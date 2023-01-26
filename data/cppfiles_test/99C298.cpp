#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e6 + 9;
const long long mod = 1e9 + 7;
const double pi = acos(-1.0);
const long long bas = 13333;
const double eps = 1e-7;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  return x * f;
}
long long a[maxn];
void INIT() {}
void init() {}
void solve() {
  long long x, n;
  cin >> x >> n;
  long long cur = n / 4 * 4 + 1;
  n %= 4;
  for (long long i = 1; i <= n; i++) {
    if (x & 1) {
      x += cur;
    } else
      x -= cur;
    cur++;
  }
  cout << x << '\n';
  return;
}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  init();
  long long T;
  cin >> T;
  while (T--) INIT(), solve();
  return 0;
}
