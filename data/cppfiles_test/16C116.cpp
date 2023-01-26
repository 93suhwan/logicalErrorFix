#include <bits/stdc++.h>
using namespace std;
const int N = 45;
int T, n;
char s[N], t[N];
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%s", &n, s + 1);
    for (int i = 1; i <= n; i++) t[i] = s[i];
    sort(t + 1, t + 1 + n);
    int ans = 0;
    for (int i = 1; i <= n; i++) ans += (t[i] != s[i]);
    printf("%d\n", ans);
  }
  return 0;
}
