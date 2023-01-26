#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int t, n;
int a[maxn];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    if (!(n & 1)) {
      for (int i = 1; i <= n; i += 2) printf("%d %d ", -a[i + 1], a[i]);
    } else {
      printf("%d %d %d ", a[3], a[3], -a[1] - a[2]);
      for (int i = 4; i <= n; i += 2) printf("%d %d ", -a[i + 1], a[i]);
    }
    puts("");
  }
}
