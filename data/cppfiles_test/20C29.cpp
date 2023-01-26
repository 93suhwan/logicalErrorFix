#include <bits/stdc++.h>
using namespace std;
const int NMAX = 400;
int N, M;
string mat[NMAX + 2];
int sp[NMAX + 2][NMAX + 2];
int bound_mistakes[NMAX + 2], fill_mistakes[NMAX + 2];
void solve() {
  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    cin >> mat[i];
    mat[i] = " " + mat[i];
  }
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      if (mat[i][j] == '1') {
        sp[i][j] = 1;
      } else {
        sp[i][j] = 0;
      }
      sp[i][j] = sp[i][j] + sp[i - 1][j] + sp[i][j - 1] - sp[i - 1][j - 1];
    }
  }
  int min_ans = 16;
  for (int l1 = 1; l1 <= N; l1++) {
    for (int l2 = l1 + 4; l2 <= N; l2++) {
      int running_min_dif = N * M;
      for (int c = 1; c <= M; c++) {
        bound_mistakes[c] =
            l2 - l1 - 1 -
            (sp[l2 - 1][c] - sp[l1][c] - sp[l2 - 1][c - 1] + sp[l1][c - 1]);
        fill_mistakes[c] = fill_mistakes[c - 1] + (mat[l1][c] == '0') +
                           (mat[l2][c] == '0') + sp[l2 - 1][c] - sp[l1][c] -
                           sp[l2 - 1][c - 1] + sp[l1][c - 1];
        if (c >= 4) {
          running_min_dif = min(running_min_dif,
                                bound_mistakes[c - 3] - fill_mistakes[c - 3]);
          min_ans = min(min_ans, bound_mistakes[c] + fill_mistakes[c - 1] +
                                     running_min_dif);
        }
      }
    }
  }
  cout << min_ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
