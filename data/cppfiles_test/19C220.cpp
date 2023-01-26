#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int t, ac, n, a[N];
void dfs(int p, int sum1, int sum2) {
  if (p > n) {
    if (sum1 != 0 && sum1 == sum2) ac = 1;
    return;
  }
  dfs(p + 1, sum1 + a[p], sum2);
  dfs(p + 1, sum1, sum2 + a[p]);
  dfs(p + 1, sum1, sum2);
}
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    ac = 0;
    int ok = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      a[i] = abs(a[i]);
      if (a[i] == 0) {
        ok = 1;
      }
    }
    dfs(1, 0, 0);
    if (ok) {
      cout << "YES\n";
    } else {
      if (ac == 1) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }
}
