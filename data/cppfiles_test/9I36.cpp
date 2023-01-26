#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 200005;
const long long mod = 1e9 + 7;
const long long MULTI_TESTS = 0;
int n, m, k, last;
int ans = 1;
int a[1005][1005];
void unstoppable() {
  cin >> n >> m >> k;
  for (int i = 0, ThxDem = n; i < ThxDem; i++)
    for (int j = 0, ThxDem = m; j < ThxDem; j++) cin >> a[i][j];
  last = 0;
  int ii = 0, jj = 0;
  while (k--) {
    last++;
    int tmp;
    cin >> tmp;
    if (a[ii][tmp] == 1)
      a[ii][tmp + 1] = a[ii][tmp], ans = tmp + 1;
    else if (a[ii][tmp] == 2)
      a[ii + 1][tmp] = a[ii][tmp], ans = tmp;
    else
      a[ii][tmp - 1] = a[ii][tmp], ans = tmp - 1;
    a[ii][tmp] = 2;
    if (last == m - 1) ii++, last = 0;
    cout << ans + 1 << ' ';
  }
}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  if (MULTI_TESTS) {
    long long Q;
    cin >> Q;
    while (Q--) {
      unstoppable();
    }
  } else {
    unstoppable();
  }
  return 0;
}
