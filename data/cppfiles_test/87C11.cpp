#include <bits/stdc++.h>
using namespace std;
const int N = 305;
int a[N];
int main() {
  int t, n, m;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) scanf("%d", &a[i]);
    int ans = 0;
    for (int i = m; i > 0; --i) {
      for (int j = i - 1; j > 0; --j) {
        if (a[i] > a[j]) ++ans;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
