#include <bits/stdc++.h>
using namespace std;
int map1[111][111];
const int M = 200005;
int main() {
  int t;
  cin >> t;
  while (t--) {
    bool f = true;
    memset(map1, -1, sizeof(map1));
    int n, m, k;
    cin >> n >> m >> k;
    int z = n * m / 2 - k;
    if (n % 2 == 1) {
      int l = m / 2;
      if (k < l)
        cout << "NO\n";
      else {
        if ((k - l) % 2 == 1) {
          cout << "NO\n";
        } else {
          cout << "YES\n";
          f = false;
          bool flag = true;
          for (int i = 1; i <= l; i++) {
            if (flag) {
              map1[1][i * 2 - 1] = map1[1][i * 2] = 24;
              flag = false;
            }
            if (!flag) {
              map1[1][i * 2 - 1] = map1[1][i * 2] = 25;
              flag = true;
            }
          }
          k -= l;
          bool flag1 = true;
          for (int i = 1; i <= n / 2; i++) {
            if (i % 2 == 1) flag1 = false;
            if (i % 2 == 0) flag1 = true;
            for (int j = 1; j <= m / 2; j++) {
              if (z) {
                z -= 2;
                if (flag1) {
                  map1[i * 2][j * 2 - 1] = map1[i * 2 + 1][j * 2 - 1] = 0;
                  map1[i * 2][j * 2] = map1[i * 2 + 1][j * 2] = 1;
                } else {
                  map1[i * 2][j * 2 - 1] = map1[i * 2 + 1][j * 2 - 1] = 1;
                  map1[i * 2][j * 2] = map1[i * 2 + 1][j * 2] = 0;
                }
              } else {
                if (j % 2 == 1) {
                  map1[i * 2][j * 2 - 1] = map1[i * 2][j * 2] = 2;
                  map1[i * 2 + 1][j * 2 - 1] = map1[i * 2 + 1][j * 2] = 3;
                } else {
                  map1[i * 2][j * 2 - 1] = map1[i * 2][j * 2] = 3;
                  map1[i * 2 + 1][j * 2 - 1] = map1[i * 2 + 1][j * 2] = 2;
                }
              }
            }
          }
        }
      }
    } else if (m % 2 == 1) {
      int l = n / 2;
      if (z < l)
        cout << "NO\n";
      else {
        if ((z - l) % 2 == 1)
          cout << "NO\n";
        else {
          cout << "YES\n";
          f = false;
          bool flag = true;
          for (int i = 1; i <= l; i++) {
            if (flag) {
              map1[i * 2 - 1][1] = map1[i * 2][1] = 24;
              flag = false;
            }
            if (!flag) {
              map1[i * 2 - 1][1] = map1[i * 2][1] = 25;
              flag = true;
            }
          }
          z -= l;
          bool flag1 = true;
          for (int i = 1; i <= n / 2; i++) {
            if (i % 2 == 1) flag1 = false;
            if (i % 2 == 0) flag1 = true;
            for (int j = 1; j <= m / 2; j++) {
              if (z) {
                z -= 2;
                if (flag1) {
                  map1[i * 2][j * 2] = map1[i * 2 - 1][j * 2] = 0;
                  map1[i * 2][j * 2 + 1] = map1[i * 2 - 1][j * 2 + 1] = 1;
                } else {
                  map1[i * 2][j * 2] = map1[i * 2 - 1][j * 2] = 1;
                  map1[i * 2][j * 2 + 1] = map1[i * 2 - 1][j * 2 + 1] = 0;
                }
              } else {
                k -= 2;
                if (j % 2 == 1) {
                  map1[i * 2][j * 2] = map1[i * 2][j * 2 + 1] = 2;
                  map1[i * 2 - 1][j * 2] = map1[i * 2 - 1][j * 2 + 1] = 3;
                } else {
                  map1[i * 2][j * 2] = map1[i * 2][j * 2 + 1] = 3;
                  map1[i * 2 - 1][j * 2] = map1[i * 2 - 1][j * 2 + 1] = 2;
                }
              }
            }
          }
        }
      }
    } else {
      if (k % 2 == 1)
        cout << "NO\n";
      else {
        cout << "YES\n";
        f = false;
        int z = n * m / 2 - k;
        bool flag = true;
        for (int i = 1; i <= n / 2; i++) {
          if (i % 2 == 1) flag = false;
          if (i % 2 == 0) flag = true;
          for (int j = 1; j <= m / 2; j++) {
            if (z) {
              z -= 2;
              if (flag) {
                map1[i * 2 - 1][j * 2 - 1] = map1[i * 2][j * 2 - 1] = 0;
                map1[i * 2 - 1][j * 2] = map1[i * 2][j * 2] = 1;
              } else {
                map1[i * 2 - 1][j * 2 - 1] = map1[i * 2][j * 2 - 1] = 1;
                map1[i * 2 - 1][j * 2] = map1[i * 2][j * 2] = 0;
              }
            } else {
              k -= 2;
              if (j % 2 == 1) {
                map1[i * 2 - 1][j * 2 - 1] = map1[i * 2 - 1][j * 2] = 2;
                map1[i * 2][j * 2 - 1] = map1[i * 2][j * 2] = 3;
              } else {
                map1[i * 2 - 1][j * 2 - 1] = map1[i * 2 - 1][j * 2] = 3;
                map1[i * 2][j * 2 - 1] = map1[i * 2][j * 2] = 2;
              }
            }
          }
        }
      }
    }
    if (!f) {
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
          char p = 'a' + map1[i][j];
          cout << p;
        }
        cout << endl;
      }
    }
  }
}
