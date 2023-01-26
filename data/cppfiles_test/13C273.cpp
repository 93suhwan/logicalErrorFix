#include <bits/stdc++.h>
using namespace std;
bool is_possible(const int rows, const int cols, const int ver) {
  const auto rem_cols = cols - (ver % cols);
  if (rem_cols % 2) {
    return false;
  }
  const auto rows_needed = (ver + cols - 1) / cols * 2;
  if (rows_needed > rows) {
    return false;
  }
  return true;
}
vector<vector<int>> build_board(const int rows, const int cols, const int hor,
                                const int ver) {
  vector<vector<int>> board(rows, vector<int>(cols));
  for (auto row = 0, id = hor + ver; row < rows; ++row) {
    for (auto col = 0; col < cols; ++col) {
      if (board[row][col]) {
        continue;
      }
      if (id > hor) {
        board[row][col] = board[row + 1][col] = id;
        --id;
      } else {
        board[row][col] = board[row][col + 1] = id;
        --id;
      }
    }
  }
  return board;
}
vector<vector<int>> transpose(const vector<vector<int>>& board) {
  const auto rows = board.size();
  const auto cols = board[0].size();
  vector<vector<int>> T(cols, vector<int>(rows));
  for (auto row = 0; row < rows; ++row) {
    for (auto col = 0; col < cols; ++col) {
      T[col][row] = board[row][col];
    }
  }
  return T;
}
vector<string> convert_board(const vector<vector<int>>& board) {
  const auto rows = board.size();
  const auto cols = board[0].size();
  vector<string> output(rows, string(cols, ' '));
  for (auto row = 0; row < rows; ++row) {
    for (auto col = 0; col < cols; ++col) {
      if (output[row][col] != ' ') {
        continue;
      }
      vector<pair<int, int>> cells;
      cells.push_back({row, col});
      if (col < cols - 1 and board[row][col] == board[row][col + 1]) {
        cells.push_back({row, col + 1});
      }
      if (row < rows - 1 and board[row][col] == board[row + 1][col]) {
        cells.push_back({row + 1, col});
      }
      set<char> seen;
      for (const auto [cur_row, cur_col] : cells) {
        for (auto dr = -1; dr <= 1; ++dr) {
          for (auto dc = -1; dc <= 1; ++dc) {
            const auto adj_row = cur_row + dr;
            const auto adj_col = cur_col + dc;
            if (adj_row < 0 || rows <= adj_row) {
              continue;
            }
            if (adj_col < 0 || cols <= adj_col) {
              continue;
            }
            seen.insert(output[adj_row][adj_col]);
          }
        }
      }
      for (char c = 'a'; c <= 'z'; ++c) {
        if (seen.count(c)) {
          continue;
        }
        for (const auto [cur_row, cur_col] : cells) {
          output[cur_row][cur_col] = c;
        }
        break;
      }
    }
  }
  return output;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) {
    int rows, cols, hor;
    cin >> rows >> cols >> hor;
    auto ver = (rows * cols) / 2 - hor;
    bool swapped = false;
    if (cols % 2) {
      swap(rows, cols);
      swap(hor, ver);
      swapped = true;
    }
    const bool ans = is_possible(rows, cols, ver);
    cout << (ans ? "YES" : "NO") << '\n';
    if (!ans) {
      continue;
    }
    auto board = build_board(rows, cols, hor, ver);
    if (swapped) {
      board = transpose(board);
      swap(rows, cols);
      swap(hor, ver);
      swapped = true;
    }
    auto output = convert_board(board);
    for (const auto& row : output) {
      cout << row << '\n';
    }
  }
  return 0;
}
