#include <bits/stdc++.h>
using namespace std;
long long n, k;
int LOG2(long long x) {
  long long i = 1, cnt = 0;
  while (i <= x) cnt++, i *= 2;
  return cnt;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  cin >> T;
  while (T--) {
    cin >> n >> k;
    long long res = LOG2(k);
    long long sum = 1LL << res;
    if (sum >= n) {
      cout << (1ll << (res - 1) >= n ? res - 1 : res) << '\n';
      continue;
    }
    res += (n - sum) / k;
    if ((n - sum) % k != 0) res++;
    cout << res << '\n';
  }
  return 0;
}
