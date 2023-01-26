#include <bits/stdc++.h>
using namespace std;
long long n, a, b, flag;
void dfs(long long x, long long y, long long ans, long long sum) {
  if (flag) return;
  if (x == y) {
    cout << ans << endl;
    flag = 1;
  }
  if (y % 10 >= x % 10)
    dfs(x / 10, y / 10, ans + (y % 10 - x % 10) * pow(10, sum), sum + 1);
  if (y % 100 - x % 10 >= 0 && y % 100 - x % 10 <= 9)
    dfs(x / 10, y / 100, ans + (y % 100 - x % 10) * pow(10, sum), sum + 1);
}
signed main() {
  cin >> n;
  while (n--) {
    cin >> a >> b;
    flag = 0;
    dfs(a, b, 0, 0);
    if (!flag) puts("-1");
  }
}
