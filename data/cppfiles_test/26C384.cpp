#include <bits/stdc++.h>
using namespace std;
char a[15];
bool check(int i) {
  for (int j = 0; j < 10; j++) {
    int Win = (i >> j) & 1;
    if (a[j] != '?' && Win + '0' != a[j]) {
      return 0;
    }
  }
  return 1;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%s", a);
    int res(10);
    for (int i = 0; i < (1 << 10); i++) {
      int op = 10;
      int cnt[2] = {};
      if (!check(i)) continue;
      for (int j = 0; j < 10; j++) {
        if ((i >> j) & 1) cnt[j & 1]++;
        if (cnt[j & 1] + (10 - j - 1) / 2 < cnt[j & 1 ^ 1] ||
            cnt[j & 1 ^ 1] + (10 - j) / 2 < cnt[j & 1]) {
          op = j + 1;
          break;
        }
      }
      res = min(res, op);
    }
    printf("%d\n", res);
  }
}
