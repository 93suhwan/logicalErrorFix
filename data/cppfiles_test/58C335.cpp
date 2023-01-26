#include <bits/stdc++.h>
using namespace std;
void solveTestCase();
const int maxn = 105;
char a[3][maxn];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solveTestCase();
  return ~~(0 ^ 0 ^ 0);
}
void solveTestCase() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[1][i];
  for (int i = 1; i <= n; i++) cin >> a[2][i];
  for (int i = 1; i <= n; i++) {
    if (a[1][i] == '1' && a[2][i] == '1') {
      puts("NO");
      return;
    }
  }
  puts("YES");
}
