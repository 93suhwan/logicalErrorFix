#include <bits/stdc++.h>
using namespace std;
const int MAXL = 1 << 22;
char i_str[MAXL], o_str[MAXL], *i_s, *i_t;
int o_t;
inline char gc() {
  if (i_s == i_t) {
    i_s = i_str;
    i_t = i_s + fread(i_str, 1, MAXL, stdin);
    return i_s == i_t ? EOF : *i_s++;
  } else
    return *i_s++;
}
inline int read() {
  int x = 0, f = 0;
  char ch = gc();
  for (; ch < '0' || ch > '9'; ch = gc())
    if (ch == '-') f = 1;
  for (; ch >= '0' && ch <= '9'; ch = gc()) x = x * 10 + (ch ^ 48);
  return f ? -x : x;
}
inline void pc(char x) {
  o_str[o_t++] = x;
  if (o_t == MAXL) fwrite(o_str, 1, o_t, stdout), o_t = 0;
}
void write(int x) {
  if (x < 0) pc('-'), x = -x;
  if (x > 9) write(x / 10);
  pc(x % 10 ^ 48);
}
const int N = 2e5 + 5, mod = 998244353;
int n, f[N], a[N], s[N], g[N];
int main() {
  n = read();
  for (register int i = 1; i <= n; ++i) a[i] = read();
  f[0] = s[0] = 1;
  for (register int i = 1; i <= n; ++i) {
    int st[N], top;
    while (top && a[i] <= a[st[top]]) --top;
    st[++top] = i;
    g[top] =
        (g[top - 1] +
         1LL * a[i] * (s[i - 1] - (top == 1 ? 0 : s[st[top - 1] - 1]) + mod)) %
        mod;
    f[i] = (i & 1 ? g[top] : mod - g[top]);
    s[i] = (s[i - 1] + (i & 1 ? mod - f[i] : f[i])) % mod;
  }
  printf("%d\n", f[n] % mod);
  return 0;
}
