#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int T, n, A[maxn];
long long k, SUM[maxn];
int main() {
  scanf("%d", &T);
  while (T--) {
    int pos = 1;
    long long sum = 0, ans = 0;
    scanf("%d%lld", &n, &k);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &A[i]);
      sum += 1ll * A[i];
    }
    if (sum <= k) {
      puts("0");
      continue;
    }
    sort(A + 1, A + 1 + n), SUM[0] = 0;
    for (int i = 1; i <= n; i++) SUM[i] = SUM[i - 1] + 1ll * A[i];
    while (A[pos] == A[1]) pos++;
    for (int i = 1; i <= n; i++) {
      long long s = k - (SUM[i] - SUM[1]);
      if (s > 0)
        s = s / (n - i + 1);
      else
        s = -1ll * (abs(s) / (n - i + 1) + (abs(s) % (n - i + 1) != 0));
      if (s > A[1]) s = A[1];
      if (i == 1) {
        if (A[1] == s)
          ans = n - pos + 1;
        else
          ans = A[1] - s + (n - 1);
      } else {
        if (A[1] == s) {
          if (pos > i)
            ans = min(ans, 1ll * n - pos + 1);
          else
            ans = min(ans, 1ll * n - i);
        } else
          ans = min(ans, A[1] - s + (n - i));
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
