#include <bits/stdc++.h>
using namespace std;
long long f[25 - 1][200005];
long long cur[200005];
long long a[200005], b[200005], len[200005];
signed main() {
  long long n, m, k;
  cin >> n >> m >> k;
  for (long long i = 0; i < n; i++) scanf("%lld", &a[i]);
  b[0] = a[0];
  f[0][b[0]]++;
  for (long long i = 1; i < n; i++) {
    b[i] = (b[i - 1] + a[i]) % k;
    f[0][b[i] % k]++;
    f[0][b[i] % k] %= 1000000007;
  }
  long long tmp = b[n - 1];
  for (long long i = 0; i < 25; i++) {
    len[i] = tmp;
    tmp *= 2;
    tmp %= k;
  }
  for (long long i = 1; i < 25; i++) {
    for (long long j = 0; j < k; j++) {
      f[i][(j - len[i - 1] + k) % k] =
          (f[i - 1][(j - len[i - 1] + k) % k] + f[i - 1][j]) % 1000000007;
    }
  }
  tmp = 0;
  for (long long i = 25 - 1; i >= 0; i--) {
    if (!(m & (1ll << i))) continue;
    for (long long j = 0; j < k; j++) {
      cur[j] += f[i][(j - tmp + k) % k];
      cur[j] %= 1000000007;
    }
    tmp += len[i];
    tmp %= k;
  }
  long long ans = 0;
  if (tmp == 0) {
    cur[0]--;
    cur[0] += 1000000007;
    cur[0] %= 1000000007;
    ans += cur[0];
    ans %= 1000000007;
    cur[tmp]++;
    cur[tmp] %= 1000000007;
    for (long long i = 1; i < n; i++) {
      cur[b[i]]--;
      cur[b[i]] += 1000000007;
      cur[b[i]] %= 1000000007;
      ans += cur[b[i]];
      ans %= 1000000007;
      cur[(tmp + b[i]) % k]++;
      cur[(tmp + b[i]) % k] %= 1000000007;
    }
    ans = ans * m % 1000000007;
    ans++;
  } else {
    cur[0]--;
    cur[0] += 1000000007;
    cur[0] %= 1000000007;
    ans += cur[0];
    ans %= 1000000007;
    cur[tmp]++;
    cur[tmp] %= 1000000007;
    for (long long i = 1; i < n; i++) {
      cur[b[i]]--;
      cur[b[i]] += 1000000007;
      cur[b[i]] %= 1000000007;
      ans += cur[b[i]];
      ans %= 1000000007;
      cur[(tmp + b[i]) % k]++;
      cur[(tmp + b[i]) % k] %= 1000000007;
    }
    ans = ans * m % 1000000007;
  }
  cout << ans << endl;
}
