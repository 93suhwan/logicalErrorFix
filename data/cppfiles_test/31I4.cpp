#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int nmax = 1000500;
int ans[nmax];
int a[nmax];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  int m = (1 << k);
  for (int i = 0; i < m; i++) ans[i] = 1e9;
  for (int i = 0; i < n; i++) cin >> a[i];
  while (clock() * 1.0 / CLOCKS_PER_SEC < 2.5) {
    int i = rand() % n;
    int j = rand() % n;
    if (i != j) {
      for (int x = 0; x < m; x++)
        ans[x] = min(ans[x], abs((x ^ a[i]) - (x ^ a[j])));
    }
  }
  for (int i = 0; i < m; i++) cout << ans[i] << " ";
  cout << "\n";
}
