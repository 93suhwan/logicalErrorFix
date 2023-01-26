#include <bits/stdc++.h>
using namespace std;
int a[100005];
bool dp[100005][512];
int lw[512];
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n, m = 512;
  cin >> n;
  memset(lw, -1, sizeof(lw));
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (lw[a[i]] == -1)
      lw[a[i]] = a[i];
    else
      lw[a[i]] = min(lw[a[i]], a[i]);
    for (int j = 0; j < m; j++) {
      if (lw[j] != -1 && lw[j] < a[i]) {
        if (lw[j ^ a[i]] == -1)
          lw[j ^ a[i]] = a[i];
        else
          lw[j ^ a[i]] = min(a[i], lw[j ^ a[i]]);
      }
    }
  }
  int cnt = 0;
  lw[0] = 1;
  for (int i = 0; i < m; i++)
    if (lw[i] != -1) cnt++;
  cout << cnt << '\n';
  for (int i = 0; i < m; i++)
    if (lw[i] != -1) cout << i << ' ';
  return 0;
}
