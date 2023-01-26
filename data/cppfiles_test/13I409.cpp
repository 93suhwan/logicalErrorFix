#include <bits/stdc++.h>
using namespace std;
void printGrid(int n, int m, int k) {
  char ans[n + 1][m + 1];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) ans[i][j] = '0';
  int cnt = 0, j = 0;
  while (cnt < k) {
    for (int i = 0; i < n; i++) {
      if (cnt >= k) break;
      if (i > 0) {
        if (ans[i - 1][j] == 'a')
          ans[i][j] = 'b';
        else
          ans[i][j] = 'a';
        ans[i][j + 1] = ans[i][j];
      } else if (j > 0) {
        if (ans[i][j - 1] == 'a')
          ans[i][j] = 'b';
        else
          ans[i][j] = 'a';
        ans[i][j + 1] = ans[i][j];
      } else
        ans[i][j] = 'a', ans[i][j + 1] = ans[i][j];
      cnt++;
    }
    j += 2;
  }
  int x = k % n;
  int row = x;
  int col = (k / n) * 2;
  x = n - x;
  x %= n;
  for (int j = col; j <= col + 1 && j < m; j++) {
    for (int i = row; i < n; i++) {
      if (x == 0) break;
      if (ans[i][j] == '0') {
        x--;
        if (i > 0) {
          if (ans[i - 1][j] == 'e') {
            ans[i][j] = 'f', ans[i + 1][j] = ans[i][j];
            continue;
          } else if (ans[i - 1][j] == 'f') {
            ans[i][j] = 'e', ans[i + 1][j] = ans[i][j];
            continue;
          }
        }
        if (j > 0) {
          if (ans[i][j - 1] == 'e') {
            ans[i][j] = 'f', ans[i + 1][j] = ans[i][j];
            continue;
          } else if (ans[i][j - 1] == 'f') {
            ans[i][j] = 'e', ans[i + 1][j] = ans[i][j];
            continue;
          }
        }
        ans[i][j] = 'e', ans[i + 1][j] = ans[i][j];
      }
    }
    if (x == 0) break;
  }
  for (int j = 0; j < m; j++) {
    for (int i = 0; i < n; i++) {
      if (ans[i][j] == '0') {
        if (i > 0) {
          if (ans[i - 1][j] == 'c')
            ans[i][j] = 'd';
          else
            ans[i][j] = 'c';
          ans[i + 1][j] = ans[i][j];
        } else if (j > 0) {
          if (ans[i][j - 1] == 'c')
            ans[i][j] = 'd';
          else
            ans[i][j] = 'c';
          ans[i + 1][j] = ans[i][j];
        } else
          ans[i][j] = 'c', ans[i + 1][j] = ans[i][j];
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cout << ans[i][j];
    cout << "\n";
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int test = 1;
  cin >> test;
  while (test--) {
    int n, m, k;
    cin >> n >> m >> k;
    int ans[n][m];
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) ans[i][j] = 0;
    if (m & 1) {
      if (k > ((n * m) / 2 - n / 2))
        cout << "NO\n";
      else {
        if (k & 1)
          cout << "NO\n";
        else {
          cout << "YES\n";
          printGrid(n, m, k);
        }
      }
    } else if (n & 1) {
      k = (n * m) / 2 - k;
      if (k > ((n * m) / 2 - m / 2))
        cout << "NO\n";
      else {
        if (k & 1)
          cout << "NO\n";
        else {
          cout << "YES\n";
          k = (n * m) / 2 - k;
          printGrid(n, m, k);
        }
      }
    } else {
      if ((k & 1) || (((n * m) / 2 - k) & 1))
        cout << "NO\n";
      else {
        cout << "YES\n";
        printGrid(n, m, k);
      }
    }
  }
  return 0;
}
