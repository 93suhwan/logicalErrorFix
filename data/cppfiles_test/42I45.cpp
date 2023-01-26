#include <bits/stdc++.h>
using namespace std;
bool inset[200010], undo[200010];
int n, m, x, lim = 0;
int suf[200010];
long long ans = 0;
long long t1[200010 << 1], t2[200010 << 1];
struct Task {
  int a, b, id;
} t[200010], s[200010];
bool cmpa(Task x, Task y) { return x.a < y.a; }
bool cmpb(Task x, Task y) { return x.b < y.b; }
void add1(int x, long long k) {
  for (; x <= n << 1; x += x & -x) t1[x] = (t1[x] + k) % 1000000007;
}
void add2(int x, long long k) {
  for (; x <= n << 1; x += x & -x) t2[x] = (t2[x] + k) % 1000000007;
}
long long ask1(int x) {
  long long res = 0;
  for (; x; x -= x & -x) res = (res + t1[x]) % 1000000007;
  return res;
}
long long ask2(int x) {
  long long res = 0;
  for (; x; x -= x & -x) res = (res + t2[x]) % 1000000007;
  return res;
}
int main() {
  scanf("%d", &n);
  for (register int i = 1; i <= n; i++) {
    scanf("%d%d", &t[i].a, &t[i].b);
    t[i].id = i;
  }
  scanf("%d", &m);
  for (register int i = 1; i <= m; i++) {
    scanf("%d", &x);
    s[i] = t[x];
    inset[x] = 1;
  }
  sort(s + 1, s + m + 1, cmpa);
  for (register int i = m; i; i--) {
    suf[s[i].id] = max(suf[s[i + 1].id], s[i + 1].b);
    lim = max(lim, s[i].b);
  }
  sort(t + 1, t + n + 1, cmpa);
  for (register int i = 1, pre = n << 1; i <= n; i++) {
    if (pre < t[i].b || lim < t[i].b) undo[i] = 1;
    if (inset[t[i].id]) pre = min(pre, suf[t[i].id]);
  }
  sort(t + 1, t + n + 1, cmpb);
  for (register int i = 1; i <= n && t[i].b <= lim; i++) {
    long long res = ask2(t[i].b) - ask1(t[i].a);
    ans += res % 1000000007 + (undo[i] ^ 1);
    ans %= 1000000007;
    add1(t[i].a, res + 1);
    add2(t[i].b, res + 1);
  }
  printf("%lld\n", (ans % 1000000007 + 1000000007) % 1000000007);
  return 0;
}
