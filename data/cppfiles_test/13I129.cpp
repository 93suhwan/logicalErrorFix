#include <bits/stdc++.h>
using namespace std;
const int N = 110;
char a[N][N];
void solve() {
  int n, m, k;
  memset(a, 0, sizeof a);
  bool res;
  cin >> n >> m >> k;
  if ((n % 2 == 1) and (m % 2 == 0)) {
    res = (((k - m / 2) % 2) == 0) and k >= m / 2;
    if (res) {
      int id = 0;
      for (int i = 0; i < m; i += 2)
        a[0][i] = a[0][i + 1] = 'a' + id, id = (id + 1) % 26;
      k -= m / 2;
      for (int i = 0; i < m and k; i += 2)
        for (int j = 1; j < n and k; j++)
          a[j][i] = a[j][i + 1] = 'a' + id, id = (id + 1) % 26;
      for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
          if (!a[i][j]) a[i][j] = a[i + 1][j] = 'a' + id, id = (id + 1) % 26;
    }
  } else if ((n % 2 == 0) and (m % 2 == 1)) {
    res = (((m * n / 2 - k - n / 2) % 2) == 0) and (m * n / 2 - k) >= n / 2;
    if (res) {
      int id = 0;
      for (int i = 0; i < n; i += 2)
        a[i][0] = a[i + 1][0] = 'a' + id, id = (id + 1) % 26;
      k = m * n / 2 - k;
      k -= n / 2;
      for (int i = 0; k; i += 2)
        for (int j = 1; j < m and k; j++)
          a[i][j] = a[i + 1][j] = 'a' + id, id = (id + 1) % 26, k--;
      for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
          if (!a[i][j]) a[i][j] = a[i][j + 1] = 'a' + id, id = (id + 1) % 26;
    }
  } else {
    res = k % 2 == 0;
    if (res) {
      int id = 0;
      for (int i = 0; i < n and k; i++)
        for (int j = 0; j < m and k; j++)
          if (!a[i][j]) {
            a[i][j] = a[i][j + 1] = 'a' + id, id = (id + 1) % 26;
            a[i + 1][j] = a[i + 1][j + 1] = 'a' + id, id = (id + 1) % 26;
            k -= 2;
          }
      for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
          if (!a[i][j]) a[i][j] = a[i + 1][j] = 'a' + id, id = (id + 1) % 26;
    }
  }
  cout << (res ? "YES" : "NO") << endl;
  if (res)
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) cout << a[i][j];
      cout << endl;
    }
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
