#include <bits/stdc++.h>
const int N = 500010;
int t, n, x, c[3];
std::set<int> s;
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    s.clear();
    for (int i = 0; i < 3; ++i) c[i] = 0;
    for (int i = 1; i <= n; ++i) {
      int x;
      scanf("%d", &x);
      s.insert(x);
      c[x % 3] = 1;
    }
    if ((int)s.size() == 1) {
      int x = *s.rbegin();
      printf("%d\n", x / 3 + (x % 3 != 0));
    } else {
      int ans = (c[1] == 1) + (c[2] == 1);
      int x = *s.rbegin();
      s.erase(x);
      int y = *s.rbegin();
      if (c[1] && c[2])
        printf("%d\n", x / 3 + 1);
      else
        printf("%d\n", x / 3 + ans);
    }
  }
  return 0;
}
