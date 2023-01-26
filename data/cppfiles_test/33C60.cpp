#include <bits/stdc++.h>
using namespace std;
int n;
long long a[100005];
long long ans = 0;
void work() {
  ans = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
  }
  for (int i = 2; i <= n; i++) {
    ans = max(ans, a[i] * a[i - 1]);
  }
  printf("%lld\n", ans);
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    work();
  }
  return 0;
}
