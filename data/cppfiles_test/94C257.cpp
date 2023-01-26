#include <bits/stdc++.h>
using namespace std;
const long long N = 15;
long long n, k;
long long a[N];
vector<long long> vec;
long long power(long long x, long long n) {
  long long res = 1;
  while (n) {
    if (n & 1) res = res * x;
    x = x * x;
    n >>= 1;
  }
  return res;
}
void solve() {
  vec.clear();
  scanf("%lld %lld", &n, &k);
  for (long long i = 1; i <= n; i++)
    scanf("%lld", a + i), a[i] = power(10, a[i]);
  long long sum = 0;
  for (long long i = 1; i < n; i++) {
    long long cnt = (a[i + 1] - 1 - sum) / a[i];
    if (cnt > k) break;
    vec.push_back(cnt);
    k -= cnt;
  }
  vec.push_back(k + 1);
  for (long long i = (long long)vec.size() - 1; ~i; i--)
    printf("%lld%s", vec[i], !i ? "\n" : "");
}
signed main() {
  long long _;
  scanf("%lld", &_);
  while (_--) solve();
  return 0;
}
