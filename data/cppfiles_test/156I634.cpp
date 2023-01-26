#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long ans = 0;
  char last = ' ', ch = getchar();
  while (ch < '0' || ch > '9') last = ch, ch = getchar();
  while (ch >= '0' && ch <= '9') ans = ans * 10 + ch - '0', ch = getchar();
  if (last == '-') ans = -ans;
  return ans;
}
const int N = 2e5 + 5;
int n;
long long k, sum, tmp, suf[N], a[N], c, ans;
long long accCeil(long long a, long long b) {
  long long res = a / b;
  if (res * b < a) res++;
  return res;
}
int main() {
  int T = read();
  while (T--) {
    n = read(), k = read();
    sum = 0;
    for (int i = 1; i <= n; ++i) {
      a[i] = read();
      sum += a[i];
    }
    if (sum <= k) {
      printf("0\n");
      continue;
    }
    if (n == 1) {
      printf("%lld\n", sum - k);
      continue;
    }
    sort(a + 1, a + n + 1);
    suf[n + 1] = 0;
    ans = 1e18;
    for (int i = n; i > 1; --i) {
      suf[i] = suf[i + 1] + a[i];
      tmp = sum - k - suf[i] + (n - i + 1) * a[1];
      c = accCeil(tmp, n - i + 2);
      ans = min(ans, n - i + 1 + c);
    }
    printf("%lld\n", min(ans, sum - k));
  }
  return 0;
}
