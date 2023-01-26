#include <bits/stdc++.h>
using namespace std;
int del_x[] = {-1, 0, 1, 0}, del_y[] = {0, 1, 0, -1};
int arr[105][105];
bool check(int i, int j, int n, int m) {
  if (i >= 1 && i <= n && j >= 1 && j <= m) return true;
  return false;
}
void ShowAns(int n, int m) {
  int i, j;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      char c = arr[i][j] + 'a';
      cout << c;
    }
    cout << endl;
  }
}
void clr(int n, int m) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) arr[i][j] = -1;
  }
}
bool IsItPossible(int n, int m) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (arr[i][j] == -1) return false;
    }
  }
  return true;
}
void MarkTheRest(int n, int m) {
  int i, j, k, value, a, b;
  for (i = 1; i < n; i++) {
    for (j = 1; j <= m; j++) {
      if (arr[i][j] == -1) {
        value = -1;
        map<int, bool> mmap;
        for (k = 0; k < 4; k++) {
          a = del_x[k] + i;
          b = del_y[k] + j;
          if (check(a, b, n, m) && arr[a][b] != -1) mmap[arr[a][b]] = true;
        }
        for (k = 0; k < 4; k++) {
          a = del_x[k] + i;
          b = del_y[k] + j - 1;
          if (check(a, b, n, m) && arr[a][b] != -1) mmap[arr[a][b]] = true;
        }
        for (k = 0;; k++) {
          if (!mmap[k]) {
            value = k;
            break;
          }
        }
        arr[i][j] = arr[i + 1][j] = value;
      }
    }
  }
}
int main() {
  int test;
  cin >> test;
abar:
  while (test--) {
    int i, j, dominoes1, dominoes2, k, a, b, value, n, m;
    cin >> n >> m >> dominoes1;
    dominoes2 = dominoes1;
    clr(n, m);
    i = 1;
    j = 2;
    while (dominoes1--) {
      if (!check(i, j, n, m)) break;
      value = -1;
      map<int, bool> mmap;
      for (k = 0; k < 4; k++) {
        a = del_x[k] + i;
        b = del_y[k] + j;
        if (check(a, b, n, m) && arr[a][b] != -1) mmap[arr[a][b]] = true;
      }
      for (k = 0; k < 4; k++) {
        a = del_x[k] + i;
        b = del_y[k] + j - 1;
        if (check(a, b, n, m) && arr[a][b] != -1) mmap[arr[a][b]] = true;
      }
      for (k = 0;; k++) {
        if (!mmap[k]) {
          value = k;
          break;
        }
      }
      arr[i][j] = arr[i][j - 1] = value;
      i++;
      if (i > n) {
        i = 1;
        j += 2;
      }
    }
    if (dominoes1 == -1) MarkTheRest(n, m);
    if (IsItPossible(n, m)) {
      cout << "YES" << endl;
      ShowAns(n, m);
      goto abar;
    }
    clr(n, m);
    i = 1, j = 2;
    while (dominoes2--) {
      if (!check(i, j, n, m)) break;
      value = -1;
      map<int, bool> mmap;
      for (k = 0; k < 4; k++) {
        a = del_x[k] + i;
        b = del_y[k] + j;
        if (check(a, b, n, m) && arr[a][b] != -1) mmap[arr[a][b]] = true;
      }
      for (k = 0; k < 4; k++) {
        a = del_x[k] + i;
        b = del_y[k] + j - 1;
        if (check(a, b, n, m) && arr[a][b] != -1) mmap[arr[a][b]] = true;
      }
      for (k = 0;; k++) {
        if (!mmap[k]) {
          value = k;
          break;
        }
      }
      arr[i][j] = arr[i][j - 1] = value;
      j += 2;
      if (j > m) {
        j = 2;
        i++;
      }
    }
    if (dominoes2 >= 0) {
      cout << "NO" << endl;
      goto abar;
    }
    MarkTheRest(n, m);
    if (IsItPossible(n, m)) {
      cout << "YES" << endl;
      ShowAns(n, m);
      goto abar;
    }
    cout << "NO" << endl;
  }
}
