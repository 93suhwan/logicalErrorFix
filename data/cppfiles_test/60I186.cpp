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
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      sum += a[i];
      cnt[a[i]]++;
    }
    if ((sum * (n - 2)) % n != 0) {
      printf("0\n");
      continue;
    }
    long long sum2 = sum;
    sum *= (n - 2);
    sum /= n;
    long long ans = 0;
    for (auto it : cnt) {
      int val = it.first;
      int c1 = it.second, c2 = 0;
      long long check = sum2 - val - sum;
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
