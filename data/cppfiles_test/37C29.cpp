#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[100010];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    memset(a, 0, sizeof(a));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
      int t1, t2, x;
      cin >> t1 >> x >> t2;
      a[x] = 1;
    }
    int rt = 0;
    for (int i = 1; i <= n; i++)
      if (a[i] == 0) rt = i;
    for (int i = 1; i <= n; i++) {
      if (rt == i) continue;
      cout << rt << " " << i << "\n";
    }
  }
}
