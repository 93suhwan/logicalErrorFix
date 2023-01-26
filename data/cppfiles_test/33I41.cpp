#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, a[N];
int mn[550];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  memset(mn, 0x3f, sizeof(mn));
  mn[0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= 512; ++j)
      if (mn[j ^ a[i]] <= a[i]) mn[j] = min(mn[j], a[i]);
  }
  int ans = 0;
  for (int i = 0; i <= 512; ++i)
    if (mn[i] != 0x3f3f3f3f) ++ans;
  printf("%d\n", ans);
  for (int i = 0; i <= 512; ++i)
    if (mn[i] != 0x3f3f3f3f) printf("%d ", i);
  return 0;
}
