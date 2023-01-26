#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n;
int a[N];
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  if (n % 2 == 0) {
    for (int i = 1; i < n; i += 2) printf("%d %d ", a[i + 1], -a[i]);
  } else {
    int x, y, z;
    if (a[1] + a[2] != 0) x = a[3], y = a[3], z = -a[1] - a[2];
    if (a[1] + a[3] != 0) x = a[2], y = -a[1] - a[3], z = a[2];
    if (a[2] + a[3] != 0) x = -a[2] - a[3], y = a[1], z = a[1];
    printf("%d %d %d ", x, y, z);
    for (int i = 4; i < n; i += 2) printf("%d %d ", a[i + 1], -a[i]);
  }
  puts("");
}
int main() {
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
