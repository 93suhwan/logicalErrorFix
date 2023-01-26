#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int k, n;
char str[N];
int num[N], ans[N];
int digit[10];
int c[5] = {1, 4, 6, 8, 9}, p[4] = {2, 3, 5, 7};
bool dfs(int l, int s, int cl) {
  if (l == cl) {
    int tmp = 0;
    for (int i = 0; i < l; i++) tmp = tmp * 10 + ans[i];
    for (int i = 2; i * i <= tmp; i++)
      if (tmp % i == 0) return true;
    return false;
  }
  for (int i = s + 1; i < k; i++) {
    ans[cl] = num[i];
    if (dfs(l, i, cl + 1)) return true;
  }
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(digit, 0, sizeof digit);
    scanf("%d", &k);
    scanf("%s", str);
    for (int i = 0; i < k; i++) {
      int t = str[i] - '0';
      num[i] = t;
      digit[t]++;
    }
    n = 0;
    for (int i = 0; i < 5; i++)
      if (digit[c[i]] >= 1) {
        ans[n++] = c[i];
        break;
      }
    if (!n) {
      for (int i = 0; i < 4; i++)
        if (digit[p[i]] >= 2) {
          ans[0] = p[i];
          ans[1] = p[i];
          n += 2;
          break;
        }
      if (!n) {
        for (int l = 2; l <= k; l++)
          if (dfs(l, -1, 0)) {
            n = l;
            break;
          }
      }
    }
    printf("%d\n", n);
    for (int i = 0; i < n; i++) printf("%d", ans[i]);
    printf("\n");
  }
  return 0;
}
