#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, MAX = 3e5 + 1, SQRT = 550;
int n, a[N], cnt = 0;
int visSmall[SQRT];
long long sumMod[SQRT];
int num[MAX];
long long sum[MAX];
int lowbit(int x) { return x & (-x); }
void add(int x) {
  int t = x;
  for (; x < MAX; x += lowbit(x)) ++num[x], sum[x] += t;
}
int getnum(int x) {
  int s = 0;
  for (; x; x -= lowbit(x)) s += num[x];
  return s;
}
long long getsum(int x) {
  long long s = 0;
  for (; x; x -= lowbit(x)) s += sum[x];
  return s;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  memset(num, 0, sizeof(num));
  memset(sum, 0, sizeof(sum));
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j < SQRT; ++j)
      if (visSmall[j]) ans += a[i] % j + j % a[i];
    if (a[i] < SQRT) {
      ans += 1LL * a[i] * (i - 1 - cnt);
      ans += sumMod[a[i]];
      visSmall[a[i]] = 1;
      ++cnt;
    } else {
      ans += getsum(a[i] - 1);
      ans += 1LL * (getnum(MAX - 1) - getnum(a[i])) * a[i];
      for (int j = 1; a[i] * j < MAX; ++j) {
        int L = a[i] * j, R = min(MAX - 1, a[i] * (j + 1) - 1);
        ans += getsum(R) - getsum(L - 1);
        ans -= 1LL * (getnum(R) - getnum(L - 1)) * a[i] * j;
      }
      for (int j = 1; a[i] / j >= SQRT; ++j) {
        int R = a[i] / j, L = max(SQRT, a[i] / (j + 1) + 1);
        int num = (getnum(R) - getnum(L - 1));
        ans += 1LL * num * (a[i] % L);
        ans += (1LL * num * L - (getsum(R) - getsum(L - 1))) * j;
      }
      add(a[i]);
      for (int j = 1; j < SQRT; ++j) sumMod[j] += a[i] % j;
    }
    printf("%lld ", ans);
  }
}
