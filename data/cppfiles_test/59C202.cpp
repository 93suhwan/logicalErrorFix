#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<vector<int> > adj(n, vector<int>(5, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 5; j++) cin >> adj[i][j];
  }
  for (int i = 0; i < 5; i++) {
    for (int j = i + 1; j < 5; j++) {
      int t = 0, l = 0, r = 0;
      bool ctr = 1;
      for (int k = 0; k < n; k++) {
        if (adj[k][i] == 0 && adj[k][j] == 0) {
          ctr = 0;
          break;
        } else if (adj[k][i] == 0)
          r++;
        else if (adj[k][j] == 0)
          l++;
        else
          t++;
      }
      if (ctr) {
        if (l <= n / 2 && r <= n / 2) {
          cout << "Yes \n";
          return;
        }
      }
    }
  }
  cout << "No \n";
}
int main(void) {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
