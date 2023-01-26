#include <bits/stdc++.h>
using namespace std;
void write(vector<int> &v) {
  for (auto i : v) cout << i << " ";
  cout << "\n";
}
void read(vector<int> &v) {
  for (auto &i : v) cin >> i;
}
const int INF = 1e9;
const int64_t INFF = 1e18;
const int N = 1e6 + 69;
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  char mat[n][m];
  if (n & 1) {
    int min_v = m / 2;
    if (k < min_v) {
      cout << "NO"
           << "\n";
      return;
    }
    k -= min_v;
    if (k & 1) {
      cout << "NO"
           << "\n";
      return;
    }
    int flag = 0;
    string ch = "ab";
    for (int i = 0; i < m; i += 2) {
      mat[0][i] = ch[flag];
      mat[0][i + 1] = ch[flag];
      flag ^= 1;
    }
    string chh = "cd";
    string chv = "ef";
    for (int i = 1; i < n; i += 2) {
      int flag1 = 0;
      for (int j = 0; j < m; j += 2) {
        if (k > 0) {
          mat[i][j] = chh[flag1];
          mat[i][j + 1] = chh[flag1];
          mat[i + 1][j] = chh[flag1 ^ 1];
          mat[i + 1][j + 1] = chh[flag1 ^ 1];
          flag1 ^= 1;
          k -= 2;
        } else {
          mat[i][j] = chv[flag1];
          mat[i][j + 1] = chv[flag1];
          mat[i + 1][j] = chv[flag1 ^ 1];
          mat[i + 1][j + 1] = chv[flag1 ^ 1];
          flag1 ^= 1;
        }
      }
    }
  }
  if (m & 1) {
    int min_v = n / 2;
    int v = (n * m) / 2 - k;
    if (v < min_v) {
      cout << "NO"
           << "\n";
      return;
    }
    v -= min_v;
    if (v & 1) {
      cout << "NO"
           << "\n";
      return;
    }
    int flag = 0;
    string ch = "ab";
    for (int i = 0; i < n; i += 2) {
      mat[i][0] = ch[flag];
      mat[i + 1][0] = ch[flag];
      flag ^= 1;
    }
    string chh = "cd";
    string chv = "ef";
    for (int i = 0; i < n; i += 2) {
      int flag1 = 0;
      for (int j = 1; j < m; j += 2) {
        if (k > 0) {
          mat[i][j] = chh[flag1];
          mat[i][j + 1] = chh[flag1];
          mat[i + 1][j] = chh[flag1 ^ 1];
          mat[i + 1][j + 1] = chh[flag1 ^ 1];
          flag1 ^= 1;
          k -= 2;
        } else {
          mat[i][j] = chv[flag1];
          mat[i][j + 1] = chv[flag1];
          mat[i + 1][j] = chv[flag1 ^ 1];
          mat[i + 1][j + 1] = chv[flag1 ^ 1];
          flag1 ^= 1;
        }
      }
    }
  }
  if (n % 2 == 0 & m % 2 == 0) {
    if (k & 1) {
      cout << "NO"
           << "\n";
      return;
    }
    string chh = "cd";
    string chv = "ef";
    for (int i = 0; i < n; i += 2) {
      int flag1 = 0;
      for (int j = 0; j < m; j += 2) {
        if (k > 0) {
          mat[i][j] = chh[flag1];
          mat[i][j + 1] = chh[flag1];
          mat[i + 1][j] = chh[flag1 ^ 1];
          mat[i + 1][j + 1] = chh[flag1 ^ 1];
          flag1 ^= 1;
          k -= 2;
        } else {
          mat[i][j] = chv[flag1];
          mat[i][j + 1] = chv[flag1];
          mat[i + 1][j] = chv[flag1 ^ 1];
          mat[i + 1][j + 1] = chv[flag1 ^ 1];
          flag1 ^= 1;
        }
      }
    }
  }
  cout << "YES"
       << "\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << mat[i][j];
    }
    cout << "\n";
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
