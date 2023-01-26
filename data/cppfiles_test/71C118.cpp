#include <bits/stdc++.h>
using namespace std;
const long long INF = 5e9;
int t, n, k, lg10[10];
int digit(int num, int pos) { return (num / lg10[pos]) % 10; }
int logarithm(int num) {
  int ret = 0;
  while (num > 0) {
    num /= 10;
    ret++;
  }
  return ret - 1;
}
long long memo[11][1 << 10][2];
long long rek(int pos, int mask, int f) {
  if (__builtin_popcount(mask) > k) return INF;
  if (pos == -1) return 0LL;
  long long &ret = memo[pos][mask][f];
  if (ret != -1) return ret;
  int dig = digit(n, pos);
  if (f) {
    for (int i = 0; i < 10; i++) {
      if (rek(pos - 1, mask | (1 << i), 1) < INF)
        return ret =
                   rek(pos - 1, mask | (1 << i), 1) + (long long)i * lg10[pos];
    }
    return ret = INF;
  }
  if (rek(pos - 1, mask | (1 << dig), 0) < INF)
    return ret =
               rek(pos - 1, mask | (1 << dig), 0) + (long long)dig * lg10[pos];
  for (int i = dig + 1; i < 10; i++) {
    if (rek(pos - 1, mask | (1 << i), 1) < INF)
      return ret = rek(pos - 1, mask | (1 << i), 1) + (long long)i * lg10[pos];
  }
  return ret = INF;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  lg10[0] = 1;
  for (int i = 1; i < 10; i++) lg10[i] = lg10[i - 1] * 10;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    memset(memo, -1LL, sizeof memo);
    cout << rek(logarithm(n), 0, 0) << '\n';
  }
  return 0;
}
