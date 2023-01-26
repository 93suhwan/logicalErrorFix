#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, a[N];
int mn[550], tmp[550];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  memset(mn, 0x3f, sizeof(mn));
  mn[0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= 511; ++j) tmp[j] = mn[j];
    for (int j = 0; j <= 511; ++j)
      if (mn[j ^ a[i]] <= a[i]) tmp[j] = min(tmp[j], a[i]);
    for (int j = 0; j <= 511; ++j) mn[j] = tmp[j];
  }
  int ans = 0;
  for (int i = 0; i <= 511; ++i)
    if (mn[i] != 0x3f3f3f3f) ++ans;
  printf("%d\n", ans);
  for (int i = 0; i <= 511; ++i)
    if (mn[i] != 0x3f3f3f3f) printf("%d ", i);
  return 0;
}
