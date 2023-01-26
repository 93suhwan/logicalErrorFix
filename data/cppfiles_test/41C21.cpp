#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int a[N][N], n, k;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> k;
  int ans = 0, v = 1;
  while (v < n) {
    ++ans;
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
        if (i / v % k != j / v % k) a[i][j] = ans;
    v *= k;
  }
  cout << ans << "\n";
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      cout << a[i][j] << " \n"[i == n - 2 && j == n - 1];
  return 0;
}
