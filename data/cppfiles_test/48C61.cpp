#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6;
long long t, n, a[N], p[N], A, x, y, z;
void S(long long l, long long r) {
  if (l == r) return;
  long long d = (l + r) / 2;
  S(l, d), S(d + 1, r), x = z = l, y = d + 1;
  while (x <= d && y <= r)
    if (a[x] > a[y])
      p[z++] = a[y++], A += d - x + 1;
    else
      p[z++] = a[x++];
  while (x <= d) p[z++] = a[x++];
  while (y <= r) p[z++] = a[y++];
  for (long long i = l; i <= r; i++) a[i] = p[i];
}
signed main() {
  cin >> t;
  while (t-- && cin >> n) {
    for (long long i = 1; i <= n; i++) cin >> a[i];
    A = 0, S(1, n);
    for (long long i = 1; i < n; i++)
      if (a[i] == a[i + 1]) A = 0;
    if (A & 1)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
}
