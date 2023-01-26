#include <bits/stdc++.h>
using namespace std;
void SetBasic(char arr[100][100], int n, int m) {
  int i, j;
  for (i = 0; i < n; i += 2) {
    for (j = 0; j < m; j++) {
      if (i % 4 == 0 && j % 2 == 0) {
        arr[i][j] = 'a';
        if (i + 1 < n) arr[i + 1][j] = 'a';
      } else if (i % 4 == 0 && j % 2 == 1) {
        arr[i][j] = 'b';
        if (i + 1 < n) arr[i + 1][j] = 'b';
      } else if (i % 4 == 2 && j % 2 == 0) {
        arr[i][j] = 'd';
        if (i + 1 < n) arr[i + 1][j] = 'd';
      } else {
        arr[i][j] = 'c';
        if (i + 1 < n) arr[i + 1][j] = 'c';
      }
    }
  }
}
void SetAdvanced(char arr[100][100], int n, int m, int k) {
  int i, j;
  if (n % 2 == 0 && m % 2 == 0) {
    i = j = 0;
    while (k > 0) {
      if (i % 2 == 0 && j % 4 == 0) {
        arr[i][j] = arr[i][j + 1] = 'x';
        arr[i + 1][j] = arr[i + 1][j + 1] = 'y';
      } else {
        arr[i][j] = arr[i][j + 1] = 'z';
        arr[i + 1][j] = arr[i + 1][j + 1] = 'w';
      }
      k -= 2;
      j += 2;
      if (j == m) {
        i += 2;
        j = 0;
      }
    }
  } else if (m % 2 == 0) {
    j = 0;
    while (j < m) {
      if (j % 4 == 0)
        arr[n - 1][j] = arr[n - 1][j + 1] = 'g';
      else
        arr[n - 1][j] = arr[n - 1][j + 1] = 'h';
      j += 2;
      k--;
    }
    i = 0;
    j = 0;
    while (k > 0) {
      if (i % 2 == 0 && j % 4 == 0) {
        arr[i][j] = arr[i][j + 1] = 'x';
        arr[i + 1][j] = arr[i + 1][j + 1] = 'y';
      } else {
        arr[i][j] = arr[i][j + 1] = 'z';
        arr[i + 1][j] = arr[i + 1][j + 1] = 'w';
      }
      k -= 2;
      j += 2;
      if (j == m) {
        i += 2;
        j = 0;
      }
    }
  } else {
    i = j = 0;
    while (k > 0) {
      if (i % 2 == 0 && j % 4 == 0) {
        arr[i][j] = arr[i][j + 1] = 'x';
        arr[i + 1][j] = arr[i + 1][j + 1] = 'y';
      } else {
        arr[i][j] = arr[i][j + 1] = 'z';
        arr[i + 1][j] = arr[i + 1][j + 1] = 'w';
      }
      k -= 2;
      i += 2;
      if (i == n) {
        j += 2;
        i = 0;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, k, t, x, i, j, K;
  char c = 'a';
  cin >> t;
  while (t--) {
    cin >> n >> m >> k;
    K = k;
    if (n % 2 == 0 && m % 2 == 0) {
      if (k % 2 == 1)
        cout << "NO\n";
      else {
        cout << "YES\n";
        char arr[100][100];
        SetBasic(arr, n, m);
        SetAdvanced(arr, n, m, K);
        for (i = 0; i < n; i++) {
          for (j = 0; j < m; j++) cout << arr[i][j];
          cout << endl;
        }
      }
    } else if (m % 2 == 0) {
      x = m / 2;
      if (k < x)
        cout << "NO\n";
      else {
        k -= x;
        if (k % 2 == 1)
          cout << "NO\n";
        else {
          cout << "YES\n";
          char arr[100][100];
          SetBasic(arr, n, m);
          SetAdvanced(arr, n, m, K);
          for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) cout << arr[i][j];
            cout << endl;
          }
        }
      }
    } else {
      x = (m * n) / 2;
      if (x - k < n / 2)
        cout << "NO\n";
      else {
        if (k % 2 == 1)
          cout << "NO\n";
        else {
          cout << "YES\n";
          char arr[100][100];
          SetBasic(arr, n, m);
          SetAdvanced(arr, n, m, K);
          for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) cout << arr[i][j];
            cout << endl;
          }
        }
      }
    }
  }
  return 0;
}
