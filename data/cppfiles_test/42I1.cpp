#include <bits/stdc++.h>
using namespace std;
long long read() {
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
const long long maxn = 2e5 + 100;
const long long mode = 1e9 + 7;
typedef struct ta {
  long long a, b, id;
  bool operator<(const ta& o) const { return b < o.b; }
} per;
typedef struct tb {
  long long l, r, sum;
} node;
node shu[maxn * 4 * 2];
per si[maxn], se[maxn];
long long t, n, dp[maxn], vis[maxn], z[maxn], sum[maxn];
void update(long long p) {
  shu[p].sum = (shu[p * 2].sum + shu[p * 2 + 1].sum) % mode;
}
void build(long long p, long long l, long long r) {
  shu[p].l = l;
  shu[p].r = r;
  if (l == r) return;
  build(p * 2, l, (shu[p].l + shu[p].r) / 2);
  build(p * 2 + 1, (shu[p].l + shu[p].r) / 2 + 1, r);
}
void change(long long p, long long pos, long long num) {
  if (shu[p].l == shu[p].r) {
    shu[p].sum = num;
    return;
  }
  if (pos <= (shu[p].l + shu[p].r) / 2)
    change(p * 2, pos, num);
  else
    change(p * 2 + 1, pos, num);
  update(p);
}
long long query(long long p, long long l, long long r) {
  if (shu[p].l >= l && shu[p].r <= r) return shu[p].sum;
  long long temp = 0;
  if (l <= (shu[p].l + shu[p].r) / 2) temp += query(p * 2, l, r);
  if (r > (shu[p].l + shu[p].r) / 2) temp += query(p * 2 + 1, l, r);
  return temp % mode;
}
signed main() {
  n = read();
  for (long long i = 1; i <= n; ++i) {
    si[i].a = read();
    si[i].b = read();
    si[i].id = i;
  }
  t = read();
  long long cnt = t;
  for (long long i = 1; i <= t; ++i) {
    se[i].id = read();
    vis[se[i].id] = 1;
    se[i].a = si[se[i].id].a;
    se[i].b = si[se[i].id].b;
  }
  sort(se + 1, se + 1 + t);
  sort(si + 1, si + 1 + n);
  build(1, 1, n * 2);
  change(1, si[1].a, 1);
  long long ans = 1;
  dp[1] = 1;
  if (vis[si[1].id]) cnt--;
  if (cnt == 0) {
    cout << 1;
    return 0;
  }
  sum[1] = 1;
  for (long long i = 2; i <= n; ++i) {
    if (si[i].id == se[t].id) {
      long long tcnt = 0;
      for (long long j = 1; j < i; ++j) {
        if (si[j].a > si[i].a && vis[si[j].id]) {
          z[++tcnt] = j;
        }
      }
      reverse(z + 1, z + 1 + tcnt);
      long long temp = 0;
      for (long long j = 1; j <= tcnt; ++j) {
        if (si[z[j]].a < temp) continue;
        ans = (ans + sum[z[j] - 1] + 1) % mode;
        temp = si[z[j]].a;
      }
      break;
    }
    dp[i] = (query(1, si[i].a + 1, 2 * n) + 1) % mode;
    sum[i] = (sum[i - 1] + dp[i]) % mode;
    ans = (ans + dp[i]) % mode;
    change(1, si[i].a, dp[i]);
  }
  cout << ans + 1;
}
