#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 10;
long long t, n;
long long tree[N];
long long a1[N], a2[N];
long long lowbit(long long x) { return x & -x; }
void add(long long pos, long long x) {
  while (pos <= n) {
    tree[pos] += x;
    pos += lowbit(pos);
  }
}
long long cal(long long pos) {
  long long res = 0;
  while (pos >= 1) {
    res += tree[pos];
    pos -= lowbit(pos);
  }
  return res;
}
signed main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    cin >> n;
    for (long long i = 1; i <= n; i++) tree[i] = 0;
    for (long long i = 1; i <= n; i++) {
      cin >> a1[i];
      a2[i] = a1[i];
    }
    sort(a1 + 1, a1 + 1 + n);
    long long len = unique(a1 + 1, a1 + 1 + n) - a1 - 1;
    for (long long i = 1; i <= n; i++) {
      a2[i] = lower_bound(a1 + 1, a1 + 1 + len, a2[i]) - a1;
    }
    long long cnt = 0;
    long long res = 0;
    for (long long i = 1; i <= n; i++) {
      long long tmp = a2[i];
      add(tmp, 1);
      long long check1 = cal(n) - cal(tmp);
      long long check2 = cal(tmp - 1);
      res += min(check1, check2);
    }
    cout << res << endl;
  }
  return 0;
}
