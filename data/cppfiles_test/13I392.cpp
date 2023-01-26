#include <bits/stdc++.h>
using namespace std;
void printGrid(int n, int m, int k) {
  int ans[n + 1][m + 1];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) ans[i][j] = 0;
  int cnt = 0, j = 0;
  while (cnt < k) {
    for (int i = 0; i < n; i++) {
      if (cnt >= k) break;
      if (i > 0)
        ans[i][j + 1] = max(1, (ans[i - 1][j + 1] + 1) % 6),
                   ans[i][j] = ans[i][j + 1];
      else if (j > 0)
        ans[i][j + 1] = max(1, (ans[i][j - 1] + 1) % 6),
                   ans[i][j] = ans[i][j + 1];
      else
        ans[i][j] = 1, ans[i][j + 1] = ans[i][j];
      cnt++;
    }
    j += 2;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (ans[i][j] == 0) {
        if (j > 0)
          ans[i][j] = max(10, (ans[i][j - 1] + 2) % 16),
          ans[i + 1][j] = ans[i][j];
        else if (i > 0)
          ans[i][j] = max(10, (ans[i - 1][j] + 2) % 16),
          ans[i + 1][j] = ans[i][j];
        else
          ans[i][j] = 10, ans[i + 1][j] = ans[i][j];
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c = 'a' + ans[i][j] - 1;
      cout << c;
    }
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
