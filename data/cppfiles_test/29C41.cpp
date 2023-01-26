#include <bits/stdc++.h>
using namespace std;
const long long maxx = 300005;
long long n;
long long a[200005];
long long lowbit(long long x) { return x & (-x); }
long long tree1[maxx], tree2[maxx];
void add1(long long x, long long v) {
  while (x <= maxx) {
    tree1[x] += v;
    x += lowbit(x);
  }
}
void add2(long long x, long long v) {
  while (x <= maxx) {
    tree2[x] += v;
    x += lowbit(x);
  }
}
long long query1(long long x) {
  long long result = 0;
  while (x) {
    result += tree1[x];
    x -= lowbit(x);
  }
  return result;
}
long long query2(long long x) {
  long long result = 0;
  while (x) {
    result += tree2[x];
    x -= lowbit(x);
  }
  return result;
}
long long per, ans;
signed main() {
  scanf("%lld", &n);
  for (long long i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    ans += per;
    per += a[i];
    for (long long j = a[i]; j <= maxx; j += a[i]) {
      ans -= (query1(min(j + a[i] - 1, maxx)) - query1(j - 1)) * j;
    }
    add1(a[i], 1);
    ans += (i - 1) * a[i] - query2(a[i]);
    for (long long j = a[i]; j <= maxx; j += a[i]) {
      add2(j, a[i]);
    }
    printf("%lld ", ans);
  }
  return 0;
}
