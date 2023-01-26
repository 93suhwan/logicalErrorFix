#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<int> adj[200005], adj_rev[200005];
int xMove[] = {0, 1, 0, -1, 1, 1, -1, -1, 2, 2, -2, -2, 1, 1, -1, -1};
int yMove[] = {1, 0, -1, 0, 1, -1, 1, -1, 1, -1, 1, -1, 2, -2, 2, -2};
int arr[100 + 1][100 + 1];
int check(char c, int x, int y, int n, int m) {
  for (int k = 0; k < 4; k++) {
    int xn = x + xMove[k], yn = y + yMove[k];
    if (xn >= 1 and xn <= n and yn >= 1 and yn <= m and arr[xn][yn] == c)
      return false;
  }
  return true;
}
int main() {
  cin.tie(0), cout.tie(0);
  ios_base::sync_with_stdio(0);
  cout.setf(ios::fixed);
  cout.precision(10);
  int TC = 1;
  int n, m, k, q;
  cin >> TC;
  for (int t1 = 1; t1 <= TC; t1++) {
    cin >> n >> m >> k;
    memset(arr, 0, sizeof arr);
    int i = 1, pos = 1;
    if (n & 1) {
      for (int j = 1; j < m; j += 2) {
        arr[i][j] = 1;
        arr[i][j + 1] = 1;
        k--;
        if (k == 0) {
          if (j + 1 < m) pos = 0;
          break;
        }
      }
      i += 1;
    }
    while (pos and k > 0 and i < n) {
      for (int j = 1; j < m; j += 2) {
        arr[i][j] = 1;
        arr[i][j + 1] = 1;
        k--;
        if (k == 0) {
          pos = 0;
          break;
        }
        arr[i + 1][j] = 1;
        arr[i + 1][j + 1] = 1;
        k--;
        if (k == 0) break;
      }
      i += 2;
    }
    if (pos and k == 0) {
      cout << "YES\n";
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
          if (arr[i][j] == 1 and arr[i][j + 1] == 1) {
            for (int k = 1; k <= 26; k++) {
              if (check(96 + k, i, j, n, m) && check(96 + k, i, j + 1, n, m)) {
                arr[i][j] = 96 + k;
                arr[i][j + 1] = 96 + k;
                break;
              }
            }
          }
        }
      }
      for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
          if (arr[j][i] == 0 and arr[j + 1][i] == 0) {
            for (int k = 1; k <= 26; k++) {
              if (check(96 + k, j, i, n, m) && check(96 + k, j + 1, i, n, m)) {
                arr[j][i] = 96 + k;
                arr[j + 1][i] = 96 + k;
                break;
              }
            }
          }
        }
      }
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
          cout << char(arr[i][j]);
        }
        cout << "\n";
      }
    } else
      cout << "NO\n";
  }
  return 0;
}
