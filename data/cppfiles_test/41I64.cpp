#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int n, k;
int ans[N][N];
void solve(int l, int r, int c) {
  if (l >= r) return;
  int now = (r - l + k) / k;
  for (int i = l; i <= r; i += now) {
    for (int j = i; j < i + now; ++j) {
      for (int k = l; k <= r; ++k)
        if (k != j) ans[j][k] = c;
    }
    solve(i, i + now - 1, c + 1);
  }
}
int main() {
  cin >> n >> k;
  int now = 1, c = 0;
  while (now < n) {
    ++c;
    now = now * k;
  }
  cout << c << endl;
  solve(1, n, 1);
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) printf("%d ", ans[i][j]);
  }
}
