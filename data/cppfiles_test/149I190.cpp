#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2001;
char s[MAXN];
long long a[MAXN];
int main() {
  int tn, n, k, m;
  long long x, cur, t;
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  scanf("%d", &tn);
  while (tn--) {
    scanf("%d%d%lld%s", &n, &k, &x, s);
    --x;
    m = 0;
    memset(a, 0, sizeof(int) * n);
    for (int i = 0; i < n; ++i)
      if (i > 0 && s[i] == s[i - 1] && s[i] == '*')
        a[m - 1] += k;
      else
        a[m++] = (s[i] == '*' ? k + 1 : 0);
    cur = 1;
    for (int i = m - 1; i >= 0; --i)
      if (a[i] > 0) t = a[i], a[i] = cur, cur *= t;
    for (int i = 0; i < m; ++i)
      if (a[i] == 0)
        printf("a");
      else {
        for (int j = 0; j < x / a[i]; ++j) printf("b");
        x %= a[i];
      }
    printf("\n");
  }
  return 0;
}
