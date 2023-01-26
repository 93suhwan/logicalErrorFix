#include <bits/stdc++.h>
using namespace std;
const int Maxn = 51;
int n, T;
int suma[Maxn], sumb[Maxn];
bool flag = 0;
char s[Maxn];
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%s", &n, s);
    flag = 0;
    memset(suma, 0, sizeof(suma));
    memset(sumb, 0, sizeof(sumb));
    for (int i = 1; i <= n; ++i) {
      suma[i] = suma[i - 1];
      sumb[i] = sumb[i - 1];
      if (s[i - 1] == 'a') ++suma[i];
      if (s[i - 1] == 'b') ++sumb[i];
    }
    for (int k = n - 1; k >= 1; --k) {
      for (int l = 1; l <= n - k; ++l) {
        int r = l + k;
        if (suma[r] - suma[l - 1] == sumb[r] - sumb[l - 1]) {
          printf("%d %d\n", l, r);
          flag = true;
          break;
        }
      }
      if (flag) break;
    }
    if (!flag) printf("-1 -1\n");
  }
  return 0;
}
