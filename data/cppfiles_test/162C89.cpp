#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void read(T& x) {
  long long f = 0;
  x = 0;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = 1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  x = f ? -x : x;
}
const long long MAXN = 2e5 + 5;
long long a[MAXN];
long long b[MAXN];
long long n;
bool check(long long x) {
  for (long long i = 1; i <= n; ++i) b[i] = a[i];
  for (long long i = n; i >= 3; --i) {
    long long d = min((b[i] - x) / 3, a[i] / 3);
    if (d < 0) d = 0;
    b[i] -= 3 * d;
    b[i - 1] += d;
    b[i - 2] += 2 * d;
  }
  for (long long i = 1; i <= n; ++i) {
    if (b[i] < x) return 0;
  }
  return 1;
}
inline void solve() {
  long long T;
  cin >> T;
  while (T--) {
    cin >> n;
    for (long long i = 1; i <= n; ++i) cin >> a[i];
    long long l = 1, r = 1e9;
    while (l <= r) {
      long long mid = (l + r) >> 1;
      if (check(mid))
        l = mid + 1;
      else
        r = mid - 1;
    }
    cout << l - 1 << endl;
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  solve();
}
