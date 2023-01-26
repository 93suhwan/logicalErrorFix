#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n;
long long m, a[N], b[N], l[N], r[N], c[N];
void work() {
  cin >> n >> m;
  long long sa = 0, sb = 0;
  bool p = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%I64d%I64d", &a[i], &b[i]);
    sa += a[i];
    sb += b[i];
  }
  if (sa < sb) {
    swap(sa, sb);
    p = 1;
    for (int i = 1; i <= n; i++) swap(a[i], b[i]);
  }
  sa -= sb;
  long long sl = 0, sr = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] >= m && b[i] >= m)
      l[i] = -m, r[i] = m;
    else if (a[i] < m)
      l[i] = m - a[i] - a[i], r[i] = min(b[i], m) - (m - min(b[i], m));
    else
      l[i] = m - min(a[i], m) - min(a[i], m), r[i] = b[i] - (m - b[i]);
    sl += l[i];
    sr += r[i];
  }
  if (sl + sa >= 0) {
    for (int i = 1; i <= n; i++) c[i] = l[i];
  } else if (sr + sa <= 0) {
    for (int i = 1; i <= n; i++) c[i] = r[i];
  } else {
    long long t = -(sl + sa);
    t >>= 1;
    for (int i = 1; i <= n; i++) {
      c[i] = l[i];
      if (r[i] - l[i] <= (t << 1))
        c[i] = r[i], t -= ((r[i] - l[i]) >> 1);
      else {
        c[i] = l[i] + (t << 1);
        t = 0;
      }
    }
  }
  for (int i = 1; i <= n; i++) sa += c[i];
  cout << abs(sa) << endl;
  for (int i = 1; i <= n; i++) {
    if (!p)
      printf("%I64d %I64d\n", (m - c[i]) >> 1, (m + c[i]) >> 1);
    else
      printf("%I64d %I64d\n", (m + c[i]) >> 1, (m - c[i]) >> 1);
  }
}
int main() {
  int T;
  cin >> T;
  while (T--) work();
  return 0;
}
