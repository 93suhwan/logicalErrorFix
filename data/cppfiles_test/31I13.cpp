#include <bits/stdc++.h>
using namespace std;
int a[1000009];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int minn = 19999999;
    int mpos = 0;
    int f = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      if (a[i] > 0) {
        f = 1;
        minn = min(minn, a[i]);
        if (a[i] <= minn) mpos = i;
      }
    }
    if (f == 0) mpos = 1, minn = a[1];
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
      if (i == mpos) continue;
      sum += a[i];
    }
    {
      for (int i = 1; i < mpos; i++) {
        printf("%d ", minn);
      }
      printf("%lld ", -sum);
      for (int i = mpos + 1; i <= n; i++) {
        printf("%d ", minn);
      }
      printf("\n");
    }
  }
  return 0;
}
