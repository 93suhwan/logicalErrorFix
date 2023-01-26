#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 7;
long long a[maxn];
long long k;
void solve() {
  scanf("%lld", &k);
  int fd = upper_bound(a + 1, a + 100005, k) - a;
  fd--;
  int x, y;
  if (k - a[fd] + 1 <= fd) {
    x = k - a[fd] + 1;
    y = fd;
  } else {
    x = fd;
    y = fd - (k - a[fd] - fd + 1);
  }
  printf("%d %d\n", x, y);
}
int main() {
  long long cnt = 1;
  a[1] = 1;
  for (int i = 2; i < maxn; i++) {
    a[i] = a[i - 1] + cnt;
    cnt += 2;
  }
  int T;
  scanf("%d", &T);
  while (T--) {
    solve();
  }
}
