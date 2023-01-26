#include <bits/stdc++.h>
using namespace std;
struct Fenwick {
  long long n;
  vector<long long> tree;
  Fenwick(long long N) : n(N + 1) { tree.resize(n); }
  void push(long long x, long long y) {
    for (long long i = x; i < n; i += (i & -i)) tree[i] += y;
  }
  long long get(long long x) {
    long long rv = 0;
    x = min(x, n - 1);
    for (long long i = x; i > 0; i -= (i & -i)) {
      rv += tree[i];
    }
    return rv;
  }
};
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; ++i) {
    cin >> a[i];
  }
  const long long NS = (long long)3e5 + 4;
  Fenwick cnt(NS), sum(NS), lowsum(NS);
  long long ans = 0;
  for (long long i = 0; i < n; ++i) {
    long long lc = cnt.get(a[i] - 1);
    ans += lc * a[i] - lowsum.get(a[i]);
    ans += (cnt.get(NS) - cnt.get(a[i])) * a[i];
    ans += sum.get(NS);
    for (long long j = 1; j * a[i] < NS; ++j) {
      ans -= (cnt.get(a[i] * (j + 1) - 1) - cnt.get(a[i] * j - 1)) * a[i] * j;
      lowsum.push(a[i] * j, a[i]);
    }
    cnt.push(a[i], 1);
    sum.push(a[i], a[i]);
    cout << ans << ' ';
  }
  return 0;
}
