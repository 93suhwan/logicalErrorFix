#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3fffffff;
const double esp = 1e-6;
char mp[105][105];
int n, m;
int f(int n1, int m1, int k) {
  if (k < 0) return 0;
  int min = 0, max = n1 * m1 / 2;
  if (k >= min && k <= max && k % 2 == 0) return 1;
  return 0;
}
void draw(int x, int y, int k) {
  int i, j, c = 0, d = 0;
  for (i = x; i < n; i += 2) {
    c = 0;
    if (k > 0) {
      for (j = 0; j < y; j += 2) {
        if (k > 0) {
          mp[i][j] = mp[i][j + 1] = (char)('a' + c);
          mp[i + 1][j] = mp[i + 1][j + 1] = (char)('a' + (c + 1) % 2);
          c = (c + 1) % 2;
          k -= 2;
        } else
          break;
      }
      if (k == 0) {
        for (; j < y; j++) {
          mp[i][j] = mp[i + 1][j] = (char)('c' + (d + j) % 2);
        }
        d++;
      }
    } else if (k == 0) {
      for (j = 0; j < y; j++) {
        mp[i][j] = mp[i + 1][j] = (char)('c' + (d + j) % 2);
      }
      d++;
    }
  }
}
int main() {
  int t, k;
  cin >> t;
  while (t--) {
    cin >> n >> m >> k;
    int min = 0, max, flag;
    if (n % 2 == 1 && m % 2 == 0) {
      flag = f(n - 1, m, k - m / 2);
      if (flag == 1) {
        for (int j = 0; j < m; j += 2) {
          mp[0][j] = mp[0][j + 1] = (char)('m' + j / 2 % 2);
        }
        draw(1, m, k - m / 2);
      }
    }
    if (n % 2 == 0 && m % 2 == 1) {
      flag = f(n, m - 1, k);
      if (flag == 1) {
        for (int j = 0; j < n; j += 2) {
          mp[j][m - 1] = mp[j + 1][m - 1] = (char)('x' + j / 2 % 2);
        }
        draw(0, m - 1, k);
      }
    }
    if (n % 2 == 0 && m % 2 == 0) {
      flag = f(n, m, k);
      if (flag == 1) {
        draw(0, m, k);
      }
    }
    if (flag == 1) {
      cout << "YES" << endl;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          cout << mp[i][j];
        }
        cout << endl;
      }
    } else
      cout << "NO" << endl;
  }
  return 0;
}
