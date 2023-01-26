#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
long long T, n, a[N], tot[2];
template <typename T>
void chkmin(T &x, T y) {
  if (x > y) x = y;
}
template <typename T>
void chkmax(T &x, T y) {
  if (x < y) x = y;
}
vector<long long> pos[2];
long long calc(long long k) {
  long long ans = 0;
  for (long long i = 1; i <= (n + 1) / 2; i++)
    ans += abs(pos[k][i] - 2 * i + 1);
  return ans;
}
int main() {
  for (scanf("%lld", &T); T; T--) {
    tot[0] = tot[1] = 0;
    pos[0].clear();
    pos[1].clear();
    pos[0].push_back(0);
    pos[1].push_back(0);
    scanf("%lld", &n);
    for (long long i = 1; i <= n; i++) {
      scanf("%lld", &a[i]);
      ++tot[a[i] &= 1];
      pos[a[i]].push_back(i);
    }
    if (abs(tot[0] - tot[1]) > 1) {
      puts("-1");
      continue;
    }
    if (n & 1)
      printf("%lld\n", tot[0] > tot[1] ? calc(0) : calc(1));
    else
      printf("%lld\n", min(calc(0), calc(1)));
  }
  return 0;
}
