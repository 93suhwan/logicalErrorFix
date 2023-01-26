#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
int getfa(int fa[], int x) { return fa[x] == x ? x : fa[x] = getfa(fa, fa[x]); }
int q, n;
int num[N], fa[N];
int a[N];
int main() {
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int op, x, y;
    scanf("%d", &op);
    if (op == 1) {
      scanf("%d", &x);
      n++;
      if (num[x] == 0) {
        a[n] = x;
        num[x] = n;
        fa[n] = n;
      } else {
        fa[n] = num[x];
      }
    } else {
      scanf("%d%d", &x, &y);
      if (x != y && num[x] != 0) {
        if (num[y] == 0) {
          a[num[x]] = y;
          num[y] = num[x];
          num[x] = 0;
        } else {
          fa[num[x]] = num[y];
          a[num[x]] = y;
          num[x] = 0;
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    printf("%d ", a[getfa(fa, i)]);
  }
  return 0;
}
