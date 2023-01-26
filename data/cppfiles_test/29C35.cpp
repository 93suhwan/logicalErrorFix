#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const int inf = 1000000000;
long long mod = 1000000007LL;
long long mod2 = 998244353LL;
int t, n, m;
long long bit[2][300005];
int a[300005];
int lowbit(int x) { return x & (-x); }
void update(int id, int pos, long long val) {
  while (pos < 300005) {
    bit[id][pos] += val;
    pos += lowbit(pos);
  }
}
long long query(int id, int pos) {
  long long res = 0LL;
  while (pos) {
    res += bit[id][pos];
    pos -= lowbit(pos);
  }
  return res;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  long long sum = 0LL;
  long long tot = 0LL;
  for (int i = 1; i <= n; ++i) {
    long long res = (long long)(i - 1) * (long long)a[i] - query(1, a[i]);
    res += sum;
    for (int j = 1; j <= 300000 / a[i]; j++) {
      long long det =
          query(0, min(300000, (j + 1) * a[i] - 1)) - query(0, j * a[i] - 1);
      res -= (long long)a[i] * (long long)det * (long long)j;
    }
    tot += res;
    printf("%lld", tot);
    if (i < n)
      cout << " ";
    else
      cout << endl;
    sum += a[i];
    update(0, a[i], 1);
    for (int j = 1; j <= 300000 / a[i]; ++j) {
      update(1, a[i] * j, (long long)j * (long long)a[i]);
      update(1, min(300000 + 1, a[i] * (j + 1)),
             -(long long)j * (long long)a[i]);
    }
  }
  return 0;
}
