#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
const int INF = 1e9;
int n;
int a[MAXN];
char str[MAXN];
int solve(int c) {
  int mid1, mid2;
  int ret = 0;
  for (int l = 1, r = n; l <= r; l++, r--) {
    while (a[l] == c) l++;
    while (a[r] == c) r--;
    ret += 2;
    mid1 = l, mid2 = r;
    if (a[l] != a[r]) {
      return 0;
    }
  }
  if (mid1 == mid2) {
    ret--;
    for (int l = 1, r = n; l <= r; l++, r--) {
      int sum1 = 0, sum2 = 0;
      while (a[l] == c) sum1++, l++;
      while (a[r] == c) sum2++, r--;
      ret += 2 * min(sum1, sum2);
      if (l == mid1) break;
    }
  } else {
    ret += (mid2 - mid1 - 1);
    for (int l = 1, r = n; l <= r; l++, r--) {
      int sum1 = 0, sum2 = 0;
      while (a[l] == c) sum1++, l++;
      while (a[r] == c) sum2++, r--;
      ret += 2 * min(sum1, sum2);
      if (l == mid1) break;
    }
  }
  return ret;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    scanf("%s", str + 1);
    for (int i = 1; i <= n; ++i) {
      a[i] = str[i] - 'a';
    }
    int ans = 0;
    for (int i = 0; i < 26; ++i) {
      ans = max(ans, solve(i));
    }
    printf("%d\n", ans == 0 ? -1 : n - ans);
  }
}
