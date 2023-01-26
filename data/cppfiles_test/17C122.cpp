#include <bits/stdc++.h>
using namespace std;
const int maxn = 100500;
const int mod = 1e9 + 7;
const int NIL = -1;
const double eps = 0.0000001;
const double pi = acos(-1.0);
const int N = 100500, M = 2;
int T, n;
struct node {
  int id;
  int a, b, c, d, e;
} peo[maxn];
bool cmp(node x, node y) {
  int cnt1 = 0, cnt2 = 0;
  if (x.a < y.a)
    cnt1++;
  else
    cnt2++;
  if (x.b < y.b)
    cnt1++;
  else
    cnt2++;
  if (x.c < y.c)
    cnt1++;
  else
    cnt2++;
  if (x.d < y.d)
    cnt1++;
  else
    cnt2++;
  if (x.e < y.e)
    cnt1++;
  else
    cnt2++;
  return cnt1 > cnt2;
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      peo[i].id = i + 1;
      scanf("%d%d%d%d%d", &peo[i].a, &peo[i].b, &peo[i].c, &peo[i].d,
            &peo[i].e);
    }
    sort(peo, peo + n, cmp);
    bool flag = true;
    for (int i = 1; i < n; i++) {
      if (!cmp(peo[0], peo[i])) {
        flag = false;
        break;
      }
    }
    if (flag)
      printf("%d\n", peo[0].id);
    else
      puts("-1");
  }
  return 0;
}
