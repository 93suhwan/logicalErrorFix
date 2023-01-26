#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<vector<int>> matrix(n, vector<int>(m, 0));
    vector<int> index(n, 0);
    for (int i = 0; i < n; ++i) {
      index[i] = i;
      for (int j = 0; j < m; ++j) {
        scanf("%d", &matrix[i][j]);
      }
    }
    sort(index.begin(), index.end(),
         [&](int x, int y) -> bool { return matrix[x][0] < matrix[y][0]; });
    sort(matrix.begin(), matrix.end(),
         [&](vector<int>& x, vector<int>& y) -> bool { return x[0] < y[0]; });
    vector<vector<int>> left_up(matrix);
    vector<vector<int>> left_down(matrix);
    vector<vector<int>> right_up(matrix);
    vector<vector<int>> right_down(matrix);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (i - 1 >= 0) {
          left_up[i][j] = max(left_up[i][j], left_up[i - 1][j]);
        }
        if (j - 1 >= 0) {
          left_up[i][j] = max(left_up[i][j], left_up[i][j - 1]);
        }
      }
    }
    for (int i = n - 1; i >= 0; --i) {
      for (int j = 0; j < m; ++j) {
        if (i + 1 < n) {
          left_down[i][j] = min(left_down[i][j], left_down[i + 1][j]);
        }
        if (j - 1 >= 0) {
          left_down[i][j] = min(left_down[i][j], left_down[i][j - 1]);
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = m - 1; j >= 0; --j) {
        if (i - 1 >= 0) {
          right_up[i][j] = min(right_up[i][j], right_up[i - 1][j]);
        }
        if (j + 1 < m) {
          right_up[i][j] = min(right_up[i][j], right_up[i][j + 1]);
        }
      }
    }
    for (int i = n - 1; i >= 0; --i) {
      for (int j = m - 1; j >= 0; --j) {
        if (i + 1 < n) {
          right_down[i][j] = max(right_down[i][j], right_down[i + 1][j]);
        }
        if (j + 1 < m) {
          right_down[i][j] = max(right_down[i][j], right_down[i][j + 1]);
        }
      }
    }
    int x = -1, y = -1;
    for (int i = 0; i < n - 1; ++i) {
      for (int j = 0; j < m - 1; ++j) {
        if (left_up[i][j] < left_down[i + 1][j] &&
            right_down[i + 1][j + 1] < right_up[i][j + 1]) {
          x = i, y = j;
        }
      }
    }
    vector<char> col(n, 'R');
    for (int i = 0; i <= x; ++i) {
      col[index[i]] = 'B';
    }
    if (x == -1) {
      puts("NO");
    } else {
      puts("YES");
      for (char ch : col) {
        printf("%c", ch);
      }
      printf(" %d\n", y + 1);
    }
  }
  return 0;
}
