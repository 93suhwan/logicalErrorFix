#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 1000;
int t;
int main() {
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d%d", &n, &m);
    m++;
    int ans = 0;
    for (int i = 30; i >= 0; i--) {
      if (((n >> i) & 1) == ((m >> i) & 1)) continue;
      if ((m >> i) & 1)
        ans |= (1 << i), n |= (1 << i);
      else
        break;
    }
    printf("%d\n", ans);
  }
  return 0;
}
