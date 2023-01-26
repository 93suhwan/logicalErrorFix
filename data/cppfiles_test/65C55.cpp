#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  std::vector<int> a(n);
  for (int i = 0; i < (int)(n); ++i) scanf("%d", &a[i]);
  static char target[200005];
  scanf("%s", target);
  std::sort(a.begin(), a.end());
  int ch = 0;
  for (int i = 0; i < (int)(n - 1); ++i)
    if (target[i] != target[i + 1]) ++ch;
  static int ans[200005];
  static bool dir[200005];
  int l = n - ch - 1, r = l - 1;
  bool d = target[0] == 'R';
  for (int i = 0; i < (int)(n); ++i) {
    if (i == 0 || target[i] != target[i - 1]) {
      ++r;
      ans[i] = a[r];
      dir[i] = target[i] == 'R';
    } else {
      --l;
      d ^= 1;
      ans[i] = a[l];
      dir[i] = d;
    }
  }
  for (int i = 0; i < (int)(n); ++i) printf("%d %c\n", ans[i], "LR"[dir[i]]);
  return 0;
}
