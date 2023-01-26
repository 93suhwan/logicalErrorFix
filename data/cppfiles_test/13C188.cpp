#include <bits/stdc++.h>
using namespace std;
int ipow(int base, int exp) {
  int result = 1;
  for (;;) {
    if (exp & 1) result *= base;
    exp >>= 1;
    if (!exp) break;
    base *= base;
  }
  return result;
}
void show(int a[], int array_size) {
  for (int i = 0; i < array_size; ++i) cout << a[i] << " ";
  cout << '\n';
}
int num(int ar[200005], int n) {
  int o = 0;
  int sum;
  int i;
  for (i = n - 1; i >= 0; i++) {
    sum = sum + ar[i];
    if (sum <= 0) break;
    o++;
  }
  return o;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  int i;
  for (i = 0; i < t; i++) {
    int n, m, k;
    cin >> n >> m >> k;
    int check = 1;
    if ((m % 2) * (n / 2) > (n * m / 2) - k) {
      check = 0;
    }
    if (n % 2 == 1) {
      k = k - m / 2;
    }
    if (k % 2 == 1 || k < 0) {
      check = 0;
    }
    k = k + (m / 2) * (n % 2);
    if (check) {
      cout << "YES" << '\n';
      char c[105][105];
      if (m % 2 == 1) {
        int i1;
        for (i1 = 0; i1 < n; i1++) {
          if (i1 % 4 < 2)
            c[i1][m - 1] = 'x';
          else
            c[i1][m - 1] = 'y';
        }
      }
      if (n % 2 == 1) {
        int i1;
        for (i1 = 0; i1 < m - m % 2; i1++) {
          if (i1 % 4 < 2)
            c[n - 1][i1] = 'x';
          else
            c[n - 1][i1] = 'y';
        }
      }
      int j1, i1;
      k = k - (m / 2) * (n % 2);
      k = k / 2;
      for (i1 = 0; i1 < n - n % 2; i1 += 2) {
        for (j1 = 0; j1 < m - m % 2; j1 += 2) {
          char c1, c2;
          if ((i1 / 2 + j1 / 2) % 2 == 1) {
            c1 = 'a';
            c2 = 'b';
          } else {
            c1 = 'c';
            c2 = 'd';
          }
          if (k > 0) {
            k--;
            c[i1][j1] = c1;
            c[i1][j1 + 1] = c1;
            c[i1 + 1][j1] = c2;
            c[i1 + 1][j1 + 1] = c2;
          } else {
            c[i1][j1] = c1;
            c[i1][j1 + 1] = c2;
            c[i1 + 1][j1] = c1;
            c[i1 + 1][j1 + 1] = c2;
          }
        }
      }
      for (i1 = 0; i1 < n; i1++) {
        for (j1 = 0; j1 < m; j1++) {
          cout << c[i1][j1];
        }
        cout << '\n';
      }
    } else
      cout << "NO" << '\n';
  }
  return 0;
}
