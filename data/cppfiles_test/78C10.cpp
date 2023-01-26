#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int T;
int n, flag, a[N], cnt[33];
int re() {
  int e = 0, f = 1;
  char i = getchar();
  while (i < '0' || i > '9') {
    if (i == '-') f = -1;
    i = getchar();
  }
  while (i >= '0' && i <= '9') e = (e << 3) + (e << 1) + i - '0', i = getchar();
  return e * f;
}
void solve() {
  memset(cnt, 0, sizeof(cnt));
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    int now = a[i];
    int pan = 0;
    while (now) {
      pan++;
      if (now & 1) cnt[pan]++;
      now >>= 1;
    }
  }
  printf("1 ");
  for (int i = 2; i <= n; i++) {
    flag = 0;
    for (int j = 1; j <= 30; j++) {
      if (cnt[j] != 0 && cnt[j] % i != 0) {
        flag = 1;
        break;
      }
    }
    if (!flag) printf("%d ", i);
  }
  printf("\n");
}
int main() {
  scanf("%d", &T);
  while (T--) solve();
}
