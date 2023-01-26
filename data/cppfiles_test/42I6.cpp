#include <bits/stdc++.h>
using namespace std;
char buf[1 << 20], *p1, *p2;
inline int read() {
  int s = 0, f = 1;
  char x = getchar();
  while (!isdigit(x)) f = (x == '-' ? -1 : 1), x = getchar();
  while (isdigit(x)) s = s * 10 + x - '0', x = getchar();
  return s * f;
}
pair<int, int> a[200005];
int s[200005];
int c[400005];
const int p = 1e9 + 7;
int n;
void mdf(int x, int k) {
  for (int i = x; i <= 2 * n; i += (i & -i)) c[i] = (c[i] + k) % p;
}
int query(int x) {
  int ans = 0;
  for (int i = x; i; i -= (i & -i)) ans = (ans + c[i]) % p;
  return ans;
}
bool ins[400005];
int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    int x = read(), y = read();
    a[i] = make_pair(x, y);
  }
  int m = read();
  for (int i = 1; i <= m; i++) s[i] = read(), ins[a[s[i]].first] = 1;
  sort(s + 1, s + m + 1,
       [](int x, int y) { return a[x].second < a[y].second; });
  int las = a[s[1]].first, mx = a[s[n]].second;
  sort(a + 1, a + n + 1,
       [](pair<int, int> x, pair<int, int> y) { return x.second < y.second; });
  for (int i = n; i >= 1; i--) {
    if (!ins[a[i].first]) {
      if (query(2 * n - a[i].first + 1)) ins[a[i].first] = 1;
    } else
      mdf(2 * n - a[i].first + 1, 1);
  }
  memset(c, 0, sizeof(c));
  for (int i = 1; i <= n; i++) {
    int f = query(2 * n) - query(a[i].first);
    if (!f && ins[a[i].first]) las = a[i].first;
    mdf(a[i].first, (f + 1) % p);
  }
  int ans = 0;
  for (int i = 1; i <= 2 * n; i++)
    if (ins[i]) ans = (ans + query(i) - query(i - 1)) % p, ans = (ans + p) % p;
  printf("%d\n", ans);
}
