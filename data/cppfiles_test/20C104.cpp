#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int> > A, S;
int getSum(int i1, int j1, int i2, int j2) {
  return S[i2][j2] - S[i2][j1 - 1] - S[i1 - 1][j2] + S[i1 - 1][j1 - 1];
}
int vertSum(int j, int i1, int i2) { return getSum(i1, j, i2, j); }
int horizSum(int i, int j1, int j2) { return getSum(i, j1, i, j2); }
void run() {
  cin >> n >> m;
  A = S = vector<vector<int> >(1 + n, vector<int>(1 + m, 0));
  int res = 16;
  for (int i = 1; i <= n; i++) {
    string k;
    cin >> k;
    for (int j = 1; j <= m; j++) {
      A[i][j] = (k[j - 1] == '1');
      S[i][j] = S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1] + A[i][j];
    }
  }
  for (int i1 = 1; i1 + 5 - 1 <= n; i1++) {
    for (int i2 = i1 + 5 - 1; i2 <= n; i2++) {
      for (int j1 = 1; j1 + 4 - 1 <= m; j1++) {
        for (int j2 = j1 + 4 - 1; j2 <= m; j2++) {
          int X = (j2 - j1 - 1 - horizSum(i1, j1 + 1, j2 - 1)) +
                  (i2 - i1 - 1 - vertSum(j1, i1 + 1, i2 - 1)) +
                  (j2 - j1 - 1 - horizSum(i2, j1 + 1, j2 - 1)) +
                  getSum(i1 + 1, j1 + 1, i2 - 1, j2 - 1);
          if (X > 16) break;
          res = min(res, X + i2 - i1 - 1 - vertSum(j2, i1 + 1, i2 - 1));
        }
      }
    }
  }
  cout << res << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) run();
}
