#include <bits/stdc++.h>
using namespace std;
int t, n, q[200005];
int main() {
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    scanf("%d", &n);
    for (int j = 1; j <= n; j++) scanf("%d", &q[j]);
    sort(q + 1, q + 1 + n);
    for (int j = 1; j <= n / 2; j++) printf("%d %d\n", q[j + 1], q[1]);
  }
  return 0;
}
