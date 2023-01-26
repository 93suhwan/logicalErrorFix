#include <bits/stdc++.h>
const int N = 500010;
int t, n, c[3];
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
    int ans = (c[1] == 1) + (c[2] == 1);
    if ((int)s.size() == 1) {
      int x = *s.rbegin();
      printf("%d\n", x / 3 + ans);
    } else {
      if (c[1] && c[2]) {
        int x = *s.rbegin();
        if (!(x % 3))
          printf("%d\n", x / 3 + 1);
        else if (x % 3 == 1 && s.find(1) == s.end())
          printf("%d\n", x / 3 + 1);
        else
          printf("%d\n", x / 3 + 2);
      } else {
        int x = *s.rbegin();
        printf("%d\n", x / 3 + ans);
      }
    }
  }
  return 0;
}
