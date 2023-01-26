#include <bits/stdc++.h>
using namespace std;
int n, cnt = 0, ch[105];
void DFS(int x, int st) {
  if (cnt >= n) return;
  if (x >= 2 * n) {
    int sum = 0;
    for (int i = 1; i <= 2 * n; i++) {
      sum += (ch[i] == '(' ? 1 : -1);
      if (sum < 0) return;
    }
    if (sum != 0 || cnt >= n) return;
    for (int i = 1; i <= 2 * n; i++) printf("%c", ch[i]);
    printf("\n");
    cnt++;
    return;
  }
  if (st > 0) {
    ch[x + 1] = ')';
    DFS(x + 1, st - 1);
    if (cnt >= n) return;
    ch[x + 1] = '(';
    DFS(x + 1, st + 1);
  } else {
    ch[x + 1] = '(';
    DFS(x + 1, st + 1);
    if (cnt >= n) return;
    ch[x + 1] = ')';
    DFS(x + 1, st - 1);
  }
}
void Solve() {
  scanf("%d", &n);
  cnt = 0;
  ch[1] = '(';
  DFS(1, 1);
}
signed main() {
  signed TT;
  scanf("%d", &TT);
  while (TT--) {
    Solve();
  }
  return 0;
}
