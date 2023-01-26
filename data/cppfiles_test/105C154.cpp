#include <bits/stdc++.h>
using namespace std;
const int maxN = 3e3;
int A[maxN + 1], DP[maxN + 1][maxN + 1], n;
vector<int> P[maxN + 1];
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> A[i], P[A[i]].push_back(i);
  for (int d = 1; d < n; d++)
    for (int i = 1; i <= n - d; i++) {
      int j = i + d;
      DP[i][j] = DP[i + 1][j];
      for (int k : P[A[i]])
        if (i < k && k <= j)
          DP[i][j] = max(DP[i][j], DP[i + 1][k - 1] + DP[k][j] + 1);
    }
  cout << n - DP[1][n] - 1 << '\n';
}
void clear() {
  for (int i = 1; i <= n; i++) {
    P[i].clear();
    for (int j = i + 1; j <= n; j++) DP[i][j] = 0;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
    clear();
  }
}
