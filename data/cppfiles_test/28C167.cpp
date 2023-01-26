#include <bits/stdc++.h>
using namespace std;
int n, m, a[300005], b[300005], ia[300005], f[300005], v[300005];
int main() {
  int tests = 1;
  scanf("%d", &tests);
  while (tests--) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < (n); ++i) b[i] = 0;
    for (int i = 1; i <= (n); ++i)
      scanf("%d", a + i), ++b[(i - a[i] + n) % n], ia[a[i]] = i;
    int d = n - n / 3 * 2;
    vector<int> ans;
    for (int j = 0; j < (n); ++j)
      if (b[j] >= d) {
        for (int i = 1; i <= (n); ++i) f[i] = ia[(i - j + n - 1) % n + 1];
        for (int i = 1; i <= (n); ++i) v[i] = 0;
        int cnt = n;
        for (int i = 1; i <= (n); ++i)
          if (!v[i]) {
            --cnt;
            v[i] = 1;
            for (int x = f[i]; x != i; x = f[x]) v[x] = 1;
          }
        if (cnt <= m) ans.push_back(j);
      }
    printf("%d", (int)ans.size());
    for (int x : ans) printf(" %d", x);
    puts("");
  }
  return 0;
}
