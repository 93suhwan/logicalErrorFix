#include <bits/stdc++.h>
using namespace std;
int a[200005];
map<int, int> cnt;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    cnt.clear();
    int n;
    scanf("%d", &n);
    unsigned long long int sum = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      sum += a[i];
      cnt[a[i]]++;
    }
    long double check = sum;
    check *= (n - 2);
    if (abs(round(check / n * n) - check) > 1e-9) {
      printf("0\n");
      continue;
    }
    long long sum2 = round(check / n);
    long long ans = 0;
    for (auto it : cnt) {
      int val = it.first;
      int c1 = it.second, c2 = 0;
      long long check = sum - val - sum2;
      if (check > val) {
        if (cnt.count(check)) {
          c2 = cnt[check];
          ans += c1 * 1ll * c2;
        }
      } else if (check == val) {
        ans += c1 * 1ll * (c1 - 1) / 2;
      }
    }
    printf("%lld\n", ans);
  }
}
