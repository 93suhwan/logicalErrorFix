#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m;
char s[N];
int b[7][N];
char bb[7][10] = {"", "abc", "acb", "bac", "bca", "cab", "cba"};
int sum[7][N];
void predo() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 6; j++) {
      if (bb[j][(i - 1) % 3] != s[i]) {
        b[j][i] = 1;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 6; j++) {
      sum[j][i] = sum[j][i - 1] + b[j][i];
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n >> m;
  cin >> s + 1;
  predo();
  for (int i = 1; i <= m; i++) {
    int l, r;
    cin >> l >> r;
    int ans = 1e9;
    for (int j = 1; j <= 6; j++) {
      ans = min(ans, sum[j][r] - sum[j][l - 1]);
    }
    cout << ans << endl;
  }
  return 0;
}
