#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1001 + 10;
long long mod = 998244353;
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
#pragma GCC optimize("unroll-loops")
long long n;
vector<long long> v;
long long pos(long long val) {
  long long dep[n], i;
  memset(dep, 0, sizeof(dep));
  for (i = n - 1; i >= 2; --i) {
    long long cur = v[i];
    long long max_rem = min(cur + dep[i] - val, cur);
    if (max_rem < 0) {
      return (0);
    }
    long long d = max_rem / 3;
    dep[i - 1] += d;
    dep[i - 2] += 2 * d;
  }
  if (v[0] + dep[0] < val || dep[1] + v[1] < val) return (0);
  return (1);
}
int main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(0);
  cout.tie(0);
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  long long t;
  cin >> t;
  while (t--) {
    long long i;
    long long max1 = 0;
    cin >> n;
    v.clear();
    for (i = 0; i < n; ++i) {
      long long x;
      cin >> x;
      max1 = max(max1, x);
      v.push_back(x);
    }
    long long l = 0, r = max1;
    while (r - l > 1) {
      long long m = (l + r) / 2;
      if (pos(m))
        l = m;
      else
        r = m - 1;
    }
    if (pos(r))
      cout << r << "\n";
    else
      cout << l << "\n";
  }
  return (0);
}
