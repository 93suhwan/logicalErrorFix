#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2015;
int a[MAXN];
int ans[MAXN * 5], cnt;
int n;
void reserve(int x, int y) {
  while (x < y) swap(a[x++], a[y--]);
}
void deal(int x) {
  if (a[x] == x && a[x - 1] == x - 1) return;
  for (int i = 1; i <= x; i += 2) {
    if (a[i] != x) continue;
    ans[cnt++] = i;
    reserve(1, i);
    for (int j = 2; j <= x; j += 2) {
      if (a[j] == x - 1) {
        ans[cnt++] = j - 1;
        reserve(1, j - 1);
        ans[cnt++] = j + 1;
        reserve(1, j + 1);
        ans[cnt++] = 3;
        reserve(1, 3);
        ans[cnt++] = x;
        reserve(1, x);
        break;
      }
    }
    break;
  }
}
void solve() {
  cnt = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++)
    if ((a[i] & 1) != (i & 1)) {
      printf("-1\n");
      return;
    }
  for (int i = n; i >= 3; i -= 2) deal(i);
  printf("%d\n", cnt);
  for (int i = 0; i < cnt; i++)
    printf("%d%c", ans[i], i == cnt - 1 ? '\n' : ' ');
}
int main() {
  int T = 1;
  scanf("%d", &T);
  for (int i = 1; i <= T; i++) solve();
  return 0;
}
