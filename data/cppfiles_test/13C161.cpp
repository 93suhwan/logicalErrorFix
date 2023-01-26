#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int TC;
  cin >> TC;
  while (TC--) {
    int n, m, k;
    cin >> n >> m >> k;
    int l = n * m / 2 - k;
    if (!((k % 2 == n % 2 && n % 2 == 0 && (k + n - 1) / n * 2 < m) ||
          (l % 2 == m % 2 && m % 2 == 0 && (l + m - 1) / m * 2 < n))) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    vector<vector<char>> answer(n, vector<char>(m, '\0'));
    auto get_next_c = [&answer, n, m](int y, int x) -> char {
      char neighbors[4]{'\0', '\0', '\0', '\0'};
      if (y != 0) neighbors[0] = answer[y - 1][x];
      if (x != 0) neighbors[1] = answer[y][x - 1];
      if (x != 0 && y + 1 != n) neighbors[2] = answer[y + 1][x - 1];
      if (y != 0 && x + 1 != m) neighbors[3] = answer[y - 1][x + 1];
      sort(neighbors, neighbors + 4);
      char next_c = 'a';
      for (int i = 0; i < 4; ++i)
        if (neighbors[i] == next_c) ++next_c;
      return next_c;
    };
    int y, x;
    if (k % 2 == n % 2 && n % 2 == 0 && (k + n - 1) / n * 2 < m) {
      for (int i = 0; i < k; ++i) {
        x = i / n * 2;
        y = i % n;
        char next_c = get_next_c(y, x);
        answer[y][x] = next_c;
        answer[y][x + 1] = next_c;
      }
      x = (k + 1) / n * 2;
      for (; x < answer[0].size(); ++x) {
        for (y = 0; y < answer.size(); y += 2) {
          if (answer[y][x]) continue;
          char next_c = get_next_c(y, x);
          answer[y][x] = next_c;
          answer[y + 1][x] = next_c;
        }
      }
    } else {
      for (int i = 0; i < l; ++i) {
        x = i % m;
        y = i / m * 2;
        char next_c = get_next_c(y, x);
        answer[y][x] = next_c;
        answer[y + 1][x] = next_c;
      }
      y = (l + 1) / m * 2;
      for (; y < answer.size(); ++y) {
        for (x = 0; x < answer[0].size(); x += 2) {
          if (answer[y][x]) continue;
          char next_c = get_next_c(y, x);
          answer[y][x] = next_c;
          answer[y][x + 1] = next_c;
        }
      }
    }
    for (int y = 0; y < answer.size(); ++y) {
      for (int x = 0; x < answer[y].size(); ++x) {
        if (answer[y][x])
          cout << answer[y][x];
        else
          cout << ' ';
      }
      cout << '\n';
    }
  }
}
