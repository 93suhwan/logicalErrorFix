#include <bits/stdc++.h>
using namespace std;
const int N = 20;
char a[N][N];
bool used[N][N], fixed_[N][N];
int n, m, k;
void clear(int I, int R, int d) {
  int cnt = 0;
  for (; cnt <= d; cnt++) {
    if (I + cnt >= n || R + cnt >= m) {
      return;
    }
    if (a[I + cnt][R + cnt] == '*') used[I + cnt][R + cnt] = false;
  }
  cnt--;
  int cnt1 = cnt;
  for (; cnt >= 0; cnt1++, cnt--) {
    if (I + cnt >= n || R + cnt1 >= m) {
      return;
    }
    if (a[I + cnt][R + cnt1] == '*') used[I + cnt][R + cnt1] = false;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
        if (a[i][j] == '*') {
          used[i][j] = false;
          fixed_[i][j] = false;
        } else {
          used[i][j] = true;
          fixed_[i][j] = true;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        for (int d = k; d <= n; d++) {
          int cnt = 0;
          bool flag = true;
          for (; cnt <= d; cnt++) {
            if (i + cnt >= n || j + cnt >= m) {
              flag = false;
              clear(i, j, n);
              break;
            }
            if (a[i + cnt][j + cnt] == '*') {
              used[i + cnt][j + cnt] = true;
            } else {
              clear(i, j, d);
              flag = false;
              break;
            }
          }
          if (!flag) {
            continue;
          }
          cnt--;
          int cnt1 = cnt;
          for (; cnt >= 0; cnt--, cnt1++) {
            if (i + cnt >= n || j + cnt1 >= m) {
              flag = false;
              clear(i, j, n);
              break;
            }
            if (a[i + cnt][j + cnt1] == '*') {
              used[i + cnt][j + cnt1] = true;
            } else {
              clear(i, j, d);
              flag = false;
              break;
            }
          }
          if (flag) {
            for (int ii = 0; ii < n; ii++) {
              for (int jj = 0; jj < m; jj++) {
                if (!fixed_[ii][jj]) fixed_[ii][jj] = used[ii][jj];
              }
            }
          }
        }
      }
    }
    bool flag_ = true;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!fixed_[i][j]) {
          flag_ = fixed_[i][j];
          break;
        }
      }
      if (!flag_) {
        break;
      }
    }
    if (flag_) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
  return 0;
}
