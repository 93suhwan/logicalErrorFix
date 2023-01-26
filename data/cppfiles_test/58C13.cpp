#include <bits/stdc++.h>
using namespace std;
bool isSafe(string v[2], int i, int j, int r, int c) {
  if ((i >= 0) && (i < r) && (j >= 0) && (j < c) && (v[i][j] == '0')) {
    return true;
  }
  return false;
}
bool isPossible(string v[2], int i, int j, int r, int c) {
  int flag = 0;
  while (j < (c - 1)) {
    if (i == 0) {
      if (isSafe(v, i + 1, j + 1, r, c)) {
        i++;
        j++;
      } else if (isSafe(v, i, j + 1, r, c)) {
        j++;
      } else {
        flag = 1;
        break;
      }
    } else {
      if (isSafe(v, i, j + 1, r, c)) {
        j++;
      } else if (isSafe(v, i - 1, j + 1, r, c)) {
        i--;
        j++;
      } else {
        flag = 1;
        break;
      }
    }
  }
  if (flag == 1) {
    return false;
  } else {
    if (i == r - 1 && j == c - 1) {
      return true;
    } else {
      return false;
    }
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string v[2];
    for (int i = 0; i < 2; i++) {
      cin >> v[i];
    }
    if (isPossible(v, 0, 0, 2, n)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
