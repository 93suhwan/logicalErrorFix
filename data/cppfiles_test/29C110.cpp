#include <bits/stdc++.h>
using namespace std;
long long n, sum, ans;
const long long N = 3e5 + 5;
struct tree {
  long long s[N];
  void add(long long x, long long num) {
    while (x < N) {
      s[x] += num;
      x += x & -x;
    }
  }
  long long que(long long x) {
    long long ret = 0;
    while (x) {
      ret += s[x];
      x -= x & -x;
    }
    return ret;
  }
};
tree a, b;
signed main() {
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    long long x;
    cin >> x;
    ans += sum + x * (i - 1) - a.que(x);
    for (long long j = x; j < N; j += x) {
      long long y = min(N - 1, j + x - 1);
      ans -= j * (b.que(y) - b.que(j - 1));
      a.add(j, j);
      a.add(y + 1, -j);
    }
    b.add(x, 1);
    sum += x;
    cout << ans << " ";
  }
  return 0;
}
