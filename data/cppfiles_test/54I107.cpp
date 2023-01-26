#include <bits/stdc++.h>
using namespace std;
long long father[1000005];
long long sums[1000005];
void init(long long n) {
  for (long long i = 1; i <= n; i++) {
    father[i] = i;
  }
}
long long find(long long x) {
  if (father[x] == x) return x;
  return father[x] = find(father[x]);
}
void merge(long long x, long long y) {
  long long a = find(x), b = find(y);
  if (a != b) father[a] = find(b);
}
string q;
long long t, n, m, x, y, cnt, flag;
signed main() {
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld %lld", &n, &m);
    init(2 * n);
    while (m--) {
      scanf("%lld %lld", &x, &y);
      cin >> q;
      if (q == "crewmate") {
        merge(x, y);
        merge(x + n, y + n);
      } else {
        merge(x + n, y);
        merge(y + n, x);
      }
    }
    flag = 0;
    for (long long i = 1; i < +n; i++) {
      if (find(i) == find(n + i)) flag = 1;
    }
    if (flag == 1) {
      cout << "-1" << endl;
    } else {
      long long ans = 0;
      for (long long i = 0; i <= n; i++) {
        sums[i] = 0;
      }
      for (long long i = 1; i <= n; i++) {
        sums[find(i)]++;
      }
      for (long long i = 1; i <= n; i++) {
        if (find(n + i) != n + i) {
          ans += max(sums[find(i)], sums[find(n + i)]);
          sums[find(i)] = 0;
          sums[find(n + i)] = 0;
        } else
          ans += sums[find(i)];
      }
      cout << ans << endl;
    }
  }
  return 0;
}
