#include <bits/stdc++.h>
using namespace std;
int T[2005];
int S[2005][2005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      T[i] = i - x;
    }
    for (int i = 1; i <= n; i++) {
      S[i][0] = S[i - 1][0] + (T[i] == 0);
      for (int j = 1; j < i; j++) {
        S[i][j] = max(S[i - 1][j] + (T[i] == j), S[i - 1][j - 1]);
      }
      S[i][i] = 0;
    }
    int p = 0;
    while (S[n][p] < k and p != n + 1) p++;
    if (p == n + 1)
      cout << "-1\n";
    else
      cout << p << "\n";
  }
  return 0;
}
