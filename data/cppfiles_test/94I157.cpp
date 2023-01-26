#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
long long qmi(long long a, long long b, long long p) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % p;
    a = a * a % p;
    b >>= 1;
  }
  return res;
}
long long n;
int cnt, b[20];
long long f[20][20][20][2][2];
long long dp(int pos, int lim1, int lim2, long long sum, bool flag1,
             bool flag2) {
  if (pos >= cnt && (!flag1 || !flag2)) return 0;
  if (pos >= cnt) return sum == n;
  if (sum == n) return 1;
  if (sum > n) return 0;
  long long &res = f[pos][lim1][lim2][flag1][flag2];
  if (res != -1) return res;
  res = 0;
  int up = b[pos] - lim1;
  for (int i = 0; i < 10; ++i)
    for (int j = 0; j < 10; ++j) {
      if (!i && pos == (cnt - 1) && !flag1) continue;
      if (!j && pos == (cnt - 1) && !flag2) continue;
      if ((i + j) % 10 != up) continue;
      if (i + j < 10)
        res += dp(pos + 1, lim2, 0, sum + 1ll * (i + j) * pow(10, pos),
                  flag1 || i, flag2 || j);
      else
        res += dp(
            pos + 1, lim2, 1,
            sum + (i + j) % 10 * 1ll * pow(10, pos) + 1ll * 100 * pow(10, pos),
            1, 1);
    }
  return res;
}
unordered_map<long long, long long> mp;
void solve() {
  memset(f, -1, sizeof f);
  scanf("%lld", &n);
  if (mp[n]) {
    long long sum = 0;
    int t = mp[n] / 2;
    while (t--) sum = sum * 10 + 9;
    printf("%lld\n", sum);
    return;
  }
  cnt = 0;
  long long first = n;
  while (first) b[cnt++] = first % 10, first /= 10;
  long long ans = 0;
  for (int i = 0; i < 10; ++i)
    for (int j = 0; j < 10; ++j) {
      if ((i + j) % 10 == n % 10) {
        if (i + j < 10)
          ans += dp(1, 0, 0, i + j, i, j);
        else
          ans += dp(1, 0, 1, (i + j) % 10 + 100, 1, 1);
      }
    }
  printf("%lld\n", ans);
}
int main() {
  for (long long i = 1, j = 10; i <= 10; ++i, j *= 10) mp[j] = i;
  int _;
  scanf("%d", &_);
  while (_--) {
    solve();
  }
  return 0;
}
