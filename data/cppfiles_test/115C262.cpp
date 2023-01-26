#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 100, maxm = 2e7 + 100;
int n;
long long H;
long long A[maxn];
bool check(long long K) {
  long long res = 0;
  for (int i = 2; i <= n; i++) {
    res += min(K, A[i] - A[i - 1]);
  }
  res += K;
  return res >= H;
}
signed main() {
  int QuQ = 1;
  cin >> QuQ;
  while (QuQ--) {
    cin >> n >> H;
    for (int i = 1; i <= n; i++) scanf("%lld", &A[i]);
    long long l = 1, r = H, ans = -1;
    while (l <= r) {
      long long mid = l + r >> 1;
      if (check(mid)) {
        ans = mid;
        r = mid - 1;
      } else
        l = mid + 1;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
