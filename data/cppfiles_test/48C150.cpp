#include <bits/stdc++.h>
using namespace std;
const long long sz = 5e5 + 10;
long long y[sz];
inline long long read() {
  long long f = 1, x = 0;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') f = -1;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - 48;
  return f * x;
}
long long ans, n;
long long c[sz], a[sz];
void msort(long long b, long long e) {
  if (b == e) return;
  long long mid = (b + e) / 2, i = b, j = mid + 1, k = b;
  msort(b, mid), msort(mid + 1, e);
  while (i <= mid && j <= e)
    if (a[i] <= a[j])
      c[k++] = a[i++];
    else
      c[k++] = a[j++], ans += mid - i + 1;
  while (i <= mid) c[k++] = a[i++];
  while (j <= e) c[k++] = a[j++];
  for (long long l = b; l <= e; l++) a[l] = c[l];
}
bool z[sz];
void solve() {
  long long n = read();
  memset(z, 0, sizeof(bool) * (n + 2));
  bool f = 0;
  for (long long i = 1; i <= n; i++) {
    a[i] = read();
    if (!z[a[i]])
      z[a[i]] = 1;
    else
      f = 1;
  }
  ans = 0;
  msort(1, n);
  if (ans & 1) {
    if (f)
      puts("YES");
    else
      puts("NO");
  } else
    puts("YES");
}
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
