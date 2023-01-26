#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 40005;
long long b[N], a[N];
int n;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    long long sum = 0;
    for (int i = 1; i <= n; i++) scanf("%lld", &b[i]);
    for (int i = 1; i <= n; i++) {
      sum += b[i];
    }
    if (sum % ((1 + n) * n / 2)) {
      puts("NO");
      continue;
    }
    sum /= (1 + n) * n / 2;
    int key = 0;
    for (int i = 1; i <= n; i++) {
      if (i == 1)
        a[i] = (sum - (b[i] - b[n])) / n;
      else
        a[i] = (sum - (b[i] - b[i - 1])) / n;
      if (a[i] <= 0) {
        key = 1;
        break;
      }
    }
    if (key == 1) {
      puts("NO");
      continue;
    }
    puts("YES");
    for (int i = 1; i <= n; i++) printf("%lld ", a[i]);
    puts("");
  }
}
