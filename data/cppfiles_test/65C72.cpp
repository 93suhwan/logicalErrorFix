#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
const long long N = 200010;
inline long long read() {
  long long s = 0, w = 1;
  register char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    s = (s << 3) + (s << 1) + (ch ^ 48), ch = getchar();
  return s * w;
}
long long n, a[N], op[N], w[N];
char s[N];
signed main() {
  n = read();
  for (register long long i = 1; i <= n; i++) a[i] = read();
  sort(a + 1, a + 1 + n);
  scanf("%s", s + 1);
  for (register long long i = 1; i <= n; i++)
    if (s[i] == 'L')
      op[i] = 1;
    else
      op[i] = -1;
  w[n] = op[n];
  for (register long long i = n - 1; i; i--) w[i] = -w[i + 1];
  long long l = 1, r = n;
  vector<long long> g;
  for (register long long i = n - 1; i; i--) {
    if (op[i] * w[r] > 0)
      g.emplace_back(l), l++;
    else
      g.emplace_back(r), r--;
  }
  g.emplace_back(l);
  reverse(g.begin(), g.end());
  long long nl, nr;
  nl = nr = 0;
  long long now = 1;
  for (auto i : g) {
    if (w[i] == 1)
      nl += a[i];
    else
      nr += a[i];
    if (nl == nr || (nl > nr && op[now] < 0) || (nl < nr && op[now] > 0))
      return puts("-1") & 0;
    now++;
  }
  for (auto i : g) {
    printf("%d ", a[i]);
    if (w[i] == 1)
      puts("L");
    else
      puts("R");
  }
  return 0;
}
