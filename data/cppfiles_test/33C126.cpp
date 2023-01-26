#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
const long long mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n;
int a[N];
int d[N][555];
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j < 555; j++) {
      d[i][j] = 1e9;
    }
  }
  d[1][a[1]] = a[1];
  d[1][0] = 0;
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j < 555; j++) {
      d[i][j] = min(d[i][j], d[i - 1][j]);
      if (d[i - 1][j] < a[i]) {
        d[i][(j ^ a[i])] = min(d[i][(j ^ a[i])], a[i]);
      }
    }
    d[i][a[i]] = min(d[i][a[i]], a[i]);
  }
  int ans = 0;
  for (int i = 0; i < 555; i++) {
    if (d[n][i] != 1e9) {
      ans++;
    }
  }
  cout << ans << "\n";
  for (int i = 0; i < 555; i++) {
    if (d[n][i] != 1e9) {
      cout << i << " ";
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--) {
    solve();
  }
}
