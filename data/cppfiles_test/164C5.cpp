#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
  return x * f;
}
inline void out(int x) {
  if (x > 9) out(x / 10);
  putchar(x % 10 + 48);
}
inline void print(int x) {
  if (x < 0) putchar('-'), x = -x;
  out(x), puts("");
}
const int N = 2e5 + 10;
char s[N];
int son[N][2], ord[N], cpy[N], f[N], n, k, cnt;
void dfs1(int x) {
  if (!x) return;
  dfs1(son[x][0]), ord[cnt++] = x, dfs1(son[x][1]);
}
void dfs2(int x, int cost) {
  if (!x) return;
  if (cost > k) return;
  dfs2(son[x][0], cost + 1);
  if (cpy[son[x][0]])
    cpy[x] = 1;
  else if (f[x])
    cpy[x] = 1, k -= cost;
  if (cpy[x]) dfs2(son[x][1], 1);
}
int main() {
  n = read(), k = read();
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i++) son[i][0] = read(), son[i][1] = read();
  dfs1(1);
  for (int i = n - 1, lst = n - 1; i; i--) {
    if (s[ord[i - 1]] != s[ord[i]]) lst = i;
    if (s[ord[i - 1]] < s[ord[lst]]) f[ord[i - 1]] = 1;
  }
  dfs2(1, 1);
  for (int i = 0; i < n; i++) {
    printf("%c", s[ord[i]]);
    if (cpy[ord[i]]) printf("%c", s[ord[i]]);
  }
}
