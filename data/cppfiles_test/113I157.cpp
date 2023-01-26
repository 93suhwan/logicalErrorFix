#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
long long se[maxn];
long long x;
long long y;
int main() {
  int n1, n2;
  long long sum = 0;
  scanf("%d", &n1);
  for (int i = 0; i < n1; i++) {
    scanf("%lld", &se[i]);
    sum += se[i];
  }
  sort(se, se + n1);
  scanf("%d", &n2);
  for (int i = 1; i <= n2; i++) {
    scanf("%lld%lld", &x, &y);
    int l = 0, r = n1 - 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (se[mid] > x)
        r = mid - 1;
      else
        l = mid + 1;
    }
    long long ans1 = 0, ans2 = 0;
    if (se[l] < x) ans1 += x - se[l];
    if (sum - se[l] < y) ans1 += y - (sum - se[l]);
    if (se[l - 1] < x) ans2 += x - se[l - 1];
    if (sum - se[l - 1] < y) ans2 += y - (sum - se[l - 1]);
    printf("%lld\n", min(ans1, ans2));
  }
}
