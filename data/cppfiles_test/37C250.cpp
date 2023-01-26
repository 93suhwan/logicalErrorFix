#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int n, m;
int tag[maxn], tim;
void solve() {
  ++tim;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    tag[b] = tim;
  }
  for (int i = 1; i <= n; i++)
    if (tag[i] != tim) {
      for (int j = 1; j <= n; j++)
        if (i != j) printf("%d %d\n", i, j);
      break;
    }
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}
