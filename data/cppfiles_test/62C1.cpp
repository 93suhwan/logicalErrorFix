#include <bits/stdc++.h>
using namespace std;
int n, m, q;
int total;
int n_to_end(int row_start, int col_start, int dir, int dir_next,
             vector<vector<int> >& field) {
  if (row_start < 0 || row_start >= n) return 0;
  if (col_start < 0 || col_start >= m) return 0;
  int next_row = row_start;
  int next_col = col_start;
  if (dir == 1) {
    next_row -= 1;
  }
  if (dir == 2) {
    next_col += 1;
  }
  if (dir == 3) {
    next_row += 1;
  }
  if (dir == 4) {
    next_col -= 1;
  }
  if (next_row < 0 || next_row >= n) return 1;
  if (next_col < 0 || next_col >= m) return 1;
  if (field[next_row][next_col] == 1) return 1;
  return 1 + n_to_end(next_row, next_col, dir_next, dir, field);
}
int n_length_2_up(int length) { return ((length - 1) * length) / 2; }
int main() {
  cin >> n >> m >> q;
  vector<vector<int> > field(n, vector<int>(m, 0));
  int total = 0;
  for (int i = 0; i < n - 1; i++) {
    int length = n_to_end(i, 0, 3, 2, field);
    total += n_length_2_up(length);
  }
  for (int k = 0; k < m - 1; k++) {
    int length = n_to_end(0, k, 2, 3, field);
    total += n_length_2_up(length);
  }
  total += n * m;
  for (int i = 0; i < q; i++) {
    int row, col;
    cin >> row >> col;
    row--;
    col--;
    int length1 = n_to_end(row, col, 1, 4, field);
    int length2 = n_to_end(row, col, 2, 3, field);
    int length3 = n_to_end(row, col, 3, 2, field);
    int length4 = n_to_end(row, col, 4, 1, field);
    int sum = ((length1 * length2) - 1) + ((length3 * length4) - 1) + 1;
    if (field[row][col]) {
      total += sum;
    } else {
      total -= sum;
    }
    cout << total << '\n';
    field[row][col] ^= 1;
  }
}
