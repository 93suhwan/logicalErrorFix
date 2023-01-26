#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
char dp[105][105];
bool touch[105][105];
void hori(int i, int j, int x) {
  if (x == 0) {
    touch[i][j] = true;
    dp[i][j] = 'a';
    dp[i][j + 1] = 'a';
    dp[i + 1][j] = 'b';
    dp[i + 1][j + 1] = 'b';
  } else {
    touch[i][j] = true;
    dp[i][j] = 'c';
    dp[i][j + 1] = 'c';
    dp[i + 1][j] = 'd';
    dp[i + 1][j + 1] = 'd';
  }
}
void vert(int i, int j, int x) {
  if (x == 0) {
    touch[i][j] = true;
    dp[i][j] = 'e';
    dp[i + 1][j] = 'e';
    dp[i][j + 1] = 'f';
    dp[i + 1][j + 1] = 'f';
  } else {
    touch[i][j] = true;
    dp[i][j] = 'g';
    dp[i + 1][j] = 'g';
    dp[i][j + 1] = 'h';
    dp[i + 1][j + 1] = 'h';
  }
}
void printX(int t) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      touch[i][j] = false;
    }
  }
  long long lim = k;
  if (t == 1) {
    for (int i = 0; i < m && lim > 0; i += 2, lim--) {
      if (i % 4 == 0) {
        hori(0, i, 0);
      } else {
        hori(0, i, 1);
      }
    }
    for (int i = 1; i < n && lim > 0; i += 2) {
      for (int j = 0; j < m && lim > 0; j += 2, lim -= 2) {
        if (i % 4 == 1) {
          hori(i, j, 1);
        } else {
          hori(i, j, 0);
        }
      }
    }
    for (int i = 1; i < n; i += 2) {
      for (int j = 0; j < m; j += 2) {
        if (touch[i][j] == true) {
          ;
        } else {
          if (i % 4 == 1) {
            vert(i, j, 0);
          } else {
            vert(i, j, 1);
          }
        }
      }
    }
  } else if (t == 2) {
    for (int i = 0; i < n && lim > 0; i++) {
      for (int j = 0; j < m && lim > 0; j += 2, lim -= 2) {
        if (j % 2 != 0 && j == m - 1) {
          if (i % 4 == 0) {
            vert(i, j, 0);
          } else {
            vert(i, j, 1);
          }
        } else if (j % 2 == 0) {
          if (j % 4 == 0) {
            hori(i, j, 0);
          } else {
            hori(i, j, 1);
          }
        }
      }
    }
    for (int i = 0; i < n; i += 2) {
      for (int j = 0; j < m; j += 2) {
        if (touch[i][j] == true) {
          ;
        } else {
          if (j % 2 != 0 && j == m - 1) {
            if (i % 4 == 0) {
              vert(i, j, 0);
            } else {
              vert(i, j, 1);
            }
          } else if (j % 2 == 0) {
            if (i % 4 == 0) {
              vert(i, j, 0);
            } else {
              vert(i, j, 1);
            }
          }
        }
      }
    }
  } else {
    for (int i = 0; i < n && lim > 0; i += 2) {
      for (int j = 0; j < m && lim > 0; j += 2, lim -= 2) {
        if (i % 4 == 0) {
          hori(i, j, 0);
        } else {
          hori(i, j, 1);
        }
      }
    }
    for (int i = 0; i < n; i += 2) {
      for (int j = 0; j < m; j += 2) {
        if (touch[i][j] == true) {
          ;
        } else {
          if (i % 4 == 0) {
            vert(i, j, 0);
          } else {
            vert(i, j, 1);
          }
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << dp[i][j];
    }
    cout << '\n';
  }
}
void solve() {
  cin >> n >> m >> k;
  if (n % 2 != 0) {
    if (k < m / 2)
      cout << "NO\n";
    else {
      k -= m / 2;
      n--;
      if (k % 2 != 0)
        cout << "NO\n";
      else {
        cout << "YES\n";
        n++;
        k += m / 2;
        printX(1);
      }
    }
  } else if (m % 2 != 0) {
    long long x = m / 2;
    x = x * 2;
    if (k % 2 != 0 || 2 * k > n * x)
      cout << "NO\n";
    else {
      cout << "YES\n";
      printX(2);
    }
  } else {
    if (k % 2 != 0)
      cout << "NO\n";
    else {
      cout << "YES\n";
      printX(3);
    }
  }
}
int main() {
  int t = 1;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    solve();
  }
  return 0;
}
