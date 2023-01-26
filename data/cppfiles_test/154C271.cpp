#include <bits/stdc++.h>
const int inf = 0x3f3f3f3f;
using namespace std;
int t, a[10];
int solve() {
  if (a[0] == a[1] && (a[2] % 2 == 0))
    return 1;
  else if (a[2] == a[0] + a[1])
    return 1;
  else if (a[1] == a[2] && (a[0] % 2 == 0))
    return 1;
  return 0;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  while (t--) {
    for (int i = 0; i < 3; i++) cin >> a[i];
    sort(a, a + 3);
    if (solve())
      puts("YES");
    else
      puts("NO");
  }
}
