#include <bits/stdc++.h>
using namespace std;
char buf[1 << 21], *p1 = buf, *p2 = buf;
int read() {
  char c = (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin)),
            p1 == p2 ? EOF : *p1++);
  int x = 0;
  while (c < 48 || c > 57)
    c = (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin)),
         p1 == p2 ? EOF : *p1++);
  do
    x = (x << 1) + (x << 3) + (c ^ 48),
    c = (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin)),
         p1 == p2 ? EOF : *p1++);
  while (c >= 48 && c <= 57);
  return x;
}
const int _ = 1000003;
int n, m, tp;
int a[_], b[_], c[_ << 1], d[_ << 1];
void dvs(int l, int r, int L, int R) {
  if (l > r) {
    for (int i = L; i < R; i++) c[++tp] = a[i];
    return;
  }
  if (L >= R) {
    for (int i = l; i <= r; i++) c[++tp] = b[i];
    return;
  }
  int mid = (l + r) >> 1, sm = 0;
  for (int i = L; i < R; i++) sm += a[i] > b[mid];
  int mx = sm, p = R;
  for (int i = R - 1; i >= L; i--) {
    if (a[i] < b[mid]) sm++;
    if (a[i] > b[mid]) sm--;
    if (sm < mx) mx = sm, p = i;
  }
  dvs(l, mid - 1, L, p);
  c[++tp] = b[mid];
  dvs(mid + 1, r, p, R);
}
long long srt(int *e, int l, int r) {
  if (l == r) return 0;
  int mid = (l + r) >> 1;
  long long res = 0;
  res += srt(e, l, mid);
  res += srt(e, mid + 1, r);
  int s1 = l, s2 = mid + 1, s3 = l;
  while (s1 <= mid && s2 <= r) {
    if (c[s1] <= c[s2])
      d[s3++] = e[s1++];
    else
      res += mid - s1 + 1, d[s3++] = e[s2++];
  }
  for (int i = s1; i <= mid; i++) d[s3++] = e[i];
  for (int i = s2; i <= r; i++) d[s3++] = e[i];
  for (int i = l; i <= r; i++) e[i] = d[i];
  return res;
}
void solve() {
  while (tp) c[tp--] = 0;
  n = read();
  m = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 1; i <= m; i++) b[i] = read();
  sort(b + 1, b + m + 1);
  dvs(1, m, 1, n + 1);
  printf("%lld\n", srt(c, 1, n + m));
}
int main() {
  int T = read();
  while (T--) solve();
  return 0;
}
