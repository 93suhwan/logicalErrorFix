#include <bits/stdc++.h>
using namespace std;
int n, m, tr[1000010];
char s[1000010], ch[1000010];
int lowbit(int x) { return x & -x; }
void ins(int x, int val) {
  for (x; x <= m; x += lowbit(x)) tr[x] += val;
  return;
}
int query(int x) {
  int ret = 0;
  for (; x; x -= lowbit(x)) ret += tr[x];
  return ret;
}
int id(int x, int y) { return (x - 1) * m + y; }
bool check(int x) {
  for (int i = 1; i < n; i++)
    if (s[id(i, x + 1)] == s[id(i + 1, x)] && s[id(i + 1, x)] == 'X') return 1;
  return 0;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%s", ch + 1);
    for (int j = 1; j <= m; j++) s[id(i, j)] = ch[j];
  }
  for (int i = 1; i <= m; i++)
    if (check(i)) ins(i, 1);
  int q;
  scanf("%d", &q);
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    int ans = 0;
    if (l != r && query(r - 1) - query(l - 1) > 0) ans = 1;
    ans ? puts("NO") : puts("YES");
  }
  return 0;
}
