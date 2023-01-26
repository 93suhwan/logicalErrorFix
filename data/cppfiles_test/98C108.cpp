#include <bits/stdc++.h>
using namespace std;
int t, pre[114514];
char s[114514];
int main() {
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    for (int i = (1); i <= (n); i++)
      pre[i] = pre[i - 1] + (s[i] == 'a' ? 1 : -1);
    int al, ar;
    al = ar = -1;
    for (int l = (1); l <= (n); l++) {
      for (int r = (l); r <= (n); r++) {
        if (pre[r] - pre[l - 1] == 0) al = l, ar = r;
      }
    }
    printf("%d %d\n", al, ar);
  }
  return 0;
}
