#include <bits/stdc++.h>
using namespace std;
int _ = (cout << fixed << setprecision(9), cin.tie(0), ios::sync_with_stdio(0));
using Int = long long;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int N, M;
    cin >> N >> M;
    vector<string> A(N);
    for (auto &a : A) cin >> a;
    vector<vector<int>> sum(N + 1, vector<int>(M + 1));
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        sum[i + 1][j + 1] = A[i][j] - '0';
      }
    }
    for (int i = 0; i < N; i++) {
      for (int j = 0; j <= M; j++) {
        sum[i + 1][j] += sum[i][j];
      }
    }
    for (int j = 0; j < M; j++) {
      for (int i = 0; i <= N; i++) {
        sum[i][j + 1] += sum[i][j];
      }
    }
    auto getrect = [&](int i0, int j0, int i1, int j1) {
      return sum[i0][j0] + sum[i1][j1] - sum[i0][j1] - sum[i1][j0];
    };
    int ans = 1e9;
    for (int i = 0; i + 5 <= N; i++) {
      for (int j = 0; j + 4 <= M; j++) {
        for (int a = 5; i + a <= N; a++) {
          for (int b = 4; j + b <= M; b++) {
            int up = b - 2 - getrect(i, j + 1, i + 1, j + b - 1);
            int down = b - 2 - getrect(i + a - 1, j + 1, i + a, j + b - 1);
            int left = a - 2 - getrect(i + 1, j, i + a - 1, j + 1);
            int right = a - 2 - getrect(i + 1, j + b - 1, i + a - 1, j + b);
            int inside = getrect(i + 1, j + 1, i + a - 1, j + b - 1);
            if (up + left + inside > ans) {
              break;
            }
            ans = min(ans, up + down + left + right + inside);
          }
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
