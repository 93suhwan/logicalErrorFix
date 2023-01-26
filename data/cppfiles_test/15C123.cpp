#include <bits/stdc++.h>
using namespace std;
int n, m, d;
char arr[30][30];
int col[30][30];
bool check(int i, int j) {
  int c1 = j - 1, c2 = j + 1;
  i--;
  int kk = 0;
  while (i >= 0 && c1 >= 0 && c2 < m) {
    if (arr[i][c1] == '*' && arr[i][c2] == '*')
      kk++;
    else {
      if (kk >= d) return true;
      return false;
    }
    if (kk >= d) return true;
    i--, c1--, c2++;
  }
  return false;
}
void mark(int i, int j) {
  col[i][j] = 1;
  int c1 = j - 1, c2 = j + 1;
  i--;
  while (i >= 0 && c1 >= 0 && c2 < m) {
    if (arr[i][c1] == '*' && arr[i][c2] == '*')
      col[i][c1] = 1, col[i][c2] = 1;
    else
      return;
    i--, c1--, c2++;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int test;
  cin >> test;
  while (test--) {
    cin >> n >> m >> d;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> arr[i][j];
        col[i][j] = 0;
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      for (int j = 0; j < m; j++) {
        if (arr[i][j] == '*') {
          if (check(i, j)) {
            mark(i, j);
          }
        }
      }
    }
    bool f = true;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (arr[i][j] == '*' && col[i][j] == 0) {
          f = false;
        }
      }
    }
    if (f) {
      cout << "YES"
           << "\n";
    } else {
      cout << "NO"
           << "\n";
    }
  }
  return 0;
}
