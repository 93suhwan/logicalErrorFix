#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize(2, 3)
int n;
int a[200010];
void work() {
  cin >> n;
  for (register int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + 1 + n);
  int len = (n >> 1);
  for (register int i = 2; i <= len + 1; i++) {
    cout << a[i] << " " << a[1] << endl;
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) work();
  return 0;
}
