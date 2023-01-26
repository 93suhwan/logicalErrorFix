#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> a[i][j];
      }
    }
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(),
         [&](int i, int j) { return a[i][0] < a[j][0]; });
    vector<int> cut;
    vector<vector<int>> mx0(n, vector<int>(m)), mx1(n, vector<int>(m));
    for (int j = 0; j < m; ++j) {
      mx0[0][j] = a[ord[0]][j];
      mx1[n - 1][j] = a[ord[n - 1]][j];
    }
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        mx0[i][j] = max(mx0[i - 1][j], a[ord[i]][j]);
      }
    }
    for (int i = n - 2; i >= 0; --i) {
      for (int j = 0; j < m; ++j) {
        mx1[i][j] = max(mx1[i + 1][j], a[ord[i]][j]);
      }
    }
    int no = 1;
    for (int i = 0; i + 1 < n; ++i) {
      int turn = 0, pos = -1, ok = 1;
      for (int j = 0; j < m; ++j) {
        if (turn == 0) {
          if (j + 1 < m && mx0[i][j] < mx1[i + 1][j]) {
          } else {
            if (j > 0 && mx0[i][j] > mx1[i + 1][j]) {
              turn = 1;
              pos = j;
            } else {
              ok = 0;
            }
          }
        } else {
          if (mx0[i][j] > mx1[i + 1][j]) {
          } else {
            ok = 0;
          }
        }
      }
      if (ok && turn) {
        cout << "YES\n";
        assert(pos);
        string color(n, 'R');
        for (int j = 0; j <= i; ++j) color[ord[j]] = 'B';
        cout << color << " " << pos << '\n';
        no = 0;
        break;
      }
    }
    if (no) cout << "NO\n";
  }
}
