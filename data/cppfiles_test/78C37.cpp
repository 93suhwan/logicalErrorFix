#include <bits/stdc++.h>
using namespace std;
int n, cnt[32];
int num[200020], mark[200020], cntm;
void divid(int x) {
  int i = 1;
  for (; i * i < x; i++) {
    if (x % i == 0) {
      if (mark[i] != cntm) mark[i] = cntm, num[i] = 0;
      ++num[i];
      if (mark[x / i] != cntm) mark[x / i] = cntm, num[x / i] = 0;
      ++num[x / i];
    }
  }
  if (i * i == x) {
    if (mark[i] != cntm) mark[i] = cntm, num[i] = 0;
    ++num[i];
  }
  return;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    memset(cnt, 0, sizeof(cnt));
    bool flag = 1;
    ++cntm;
    scanf("%d", &n);
    for (int j = 1, x; j <= n; j++) {
      scanf("%d", &x);
      if (x) flag = 0;
      for (int i = 0, t = 1; i <= 30; i++, t <<= 1)
        if (t & x) ++cnt[i];
    }
    if (flag) {
      for (int i = 1; i <= n; i++) printf("%d ", i);
      printf("\n");
      continue;
    }
    for (int i = 0; i <= 30; i++) divid(cnt[i]);
    int cntt = 0, st = 0;
    for (int i = 0; i <= 30; i++)
      if (cnt[i]) ++cntt, st = cnt[i];
    for (int i = 1; i <= st; i++)
      if (mark[i] == cntm && num[i] == cntt) printf("%d ", i);
    printf("\n");
  }
  return 0;
}
