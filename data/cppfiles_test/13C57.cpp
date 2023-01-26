#include <bits/stdc++.h>
using namespace std;
long long int power(long long int a, long long int b) {
  if (b == 0) return 1LL;
  long long int p = power(a, b / 2);
  p = p * p;
  return (b & 1) ? p * a : p;
}
void check(vector<vector<int> > &mat) {
  int n = mat.size();
  int m = mat[0].size();
  int x = 6;
  for (int j = 0; j < m; j++) {
    for (int i = 0; i < n; i++) {
      if (mat[i][j] != 25) continue;
      if (i + 1 < n && j + 1 < m && mat[i][j] == 25 && mat[i + 1][j] == 25 &&
          mat[i][j + 1] == 25 && mat[i + 1][j + 1] == 25) {
        mat[i][j] = mat[i + 1][j] = x;
        mat[i][j + 1] = mat[i + 1][j + 1] = x + 1;
        if (x == 6)
          x = 8;
        else
          x = 6;
      } else if (i + 1 < n && mat[i][j] == 25 && mat[i + 1][j] == 25) {
        mat[i][j] = mat[i + 1][j] = x;
        if (x == 6)
          x = 8;
        else
          x = 6;
      }
    }
  }
}
void show(vector<vector<int> > mat) {
  int n = mat.size();
  int m = mat[0].size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char ch = 'a' + mat[i][j];
      cout << ch;
    }
    cout << endl;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int> > mat(n, vector<int>(m, 25));
    int r, c;
    if (n % 2 == 0)
      r = n;
    else
      r = n - 1;
    c = m;
    int hor = 0;
    if (n % 2 == 1) {
      hor = m / 2;
      int x = 0;
      for (int j = 0; j < m; j += 2) {
        mat[0][j] = mat[0][j + 1] = x;
        x ^= 1;
      }
    }
    if (k < hor) {
      cout << "NO\n";
      continue;
    } else {
      int need = k - hor;
      if (need == 0) {
        cout << "YES\n";
        check(mat);
        show(mat);
        continue;
      }
      if (need % 2 == 0) {
        if (c % 2 == 1) c--;
        int ver = r * c / 2;
        if (need <= ver && c >= 2) {
          cout << "YES\n";
          int x = 2;
          for (int i = 0; i < n; i++) {
            if (need == 0) break;
            for (int j = 0; j < m; j++) {
              if (need == 0) break;
              if (i + 1 < n && j + 1 < m) {
                if (mat[i][j] == 25 && mat[i + 1][j] == 25 &&
                    mat[i][j + 1] == 25 && mat[i + 1][j + 1] == 25) {
                  mat[i][j] = mat[i][j + 1] = x;
                  mat[i + 1][j] = mat[i + 1][j + 1] = x + 1;
                  if (x == 2)
                    x = 4;
                  else
                    x = 2;
                  need -= 2;
                }
              }
            }
          }
          check(mat);
          show(mat);
        } else
          cout << "NO\n";
        continue;
      }
      cout << "NO\n";
    }
  }
  return 0;
}
