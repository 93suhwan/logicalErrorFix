#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int a[N];
int n;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int num[2] = {0};
    for (int i = 1; i <= n; i++) {
      if (a[i] == 0) num[0]++;
      if (a[i] == 1) num[1]++;
    }
    printf("%lld\n", (1ll << num[0]) * num[1]);
  }
  return 0;
}
