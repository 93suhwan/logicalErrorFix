#include <bits/stdc++.h>
using namespace std;
int T, n, s[200005], cnt[35], q[35], cans, ans;
int gcd(int x, int y) {
  if (!y) return x;
  return gcd(y, x % y);
}
int main() {
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 1; i <= n; i++) scanf("%d", &s[i]);
    ans = 0;
    for (int i = 0; i < 30; i++) {
      cnt[i] = 0;
      for (int j = 1; j <= n; j++)
        if (s[j] & (1 << i)) cnt[i]++;
      ans = gcd(ans, cnt[i]);
    }
    cans = 0;
    for (int i = 1; i <= n; i++)
      if (ans % i == 0) q[++cans] = i;
    for (int i = 1; i <= cans; i++) printf("%d ", q[i]);
    puts("");
  }
  return 0;
}
