#include <bits/stdc++.h>
using namespace std;
void work() {
  int n;
  char ap[105], bp[105];
  scanf("%d", &n);
  scanf("%s", ap);
  scanf("%s", bp);
  bool f = false;
  for (int i = 0; i < n; ++i) {
    if (ap[i] == '1' && bp[i] == '1') f = true;
  }
  if (f)
    puts("YES");
  else
    puts("NO");
}
signed main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    work();
  }
  return 0;
}
