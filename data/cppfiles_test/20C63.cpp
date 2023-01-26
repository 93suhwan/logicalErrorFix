#include <bits/stdc++.h>
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c* x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  template <class c>
  debug& operator<<(const c&) {
    return *this;
  }
};
void test_case() {
  int h, w;
  scanf("%d%d", &h, &w);
  vector<vector<int>> grid(h, vector<int>(w));
  vector<vector<int>> pref(h + 1, vector<int>(w + 1));
  for (int row = 0; row < h; ++row) {
    static char s[405];
    scanf("%s", s);
    for (int col = 0; col < w; ++col) {
      grid[row][col] = (s[col] == '1');
    }
  }
  for (int row = 0; row < h; ++row) {
    for (int col = 0; col < w; ++col) {
      pref[row + 1][col + 1] = grid[row][col] + pref[row][col + 1] +
                               pref[row + 1][col] - pref[row][col];
    }
  }
  auto get = [&](int r1, int c1, int r2, int c2) {
    return pref[r2 + 1][c2 + 1] - pref[r1][c2 + 1] - pref[r2 + 1][c1] +
           pref[r1][c1];
  };
  auto inv = [&](int r1, int c1, int r2, int c2) {
    return (r2 - r1 + 1) * (c2 - c1 + 1) - get(r1, c1, r2, c2);
  };
  int answer = h * w;
  for (int row = 0; row < h; ++row) {
    for (int col = 0; col < w; ++col) {
      for (int r2 = row + 4; r2 < h; ++r2) {
        for (int c2 = col + 3; c2 < w; ++c2) {
          int sure = get(row + 1, col + 1, r2 - 1, c2 - 1);
          if (sure >= answer) {
            break;
          }
          sure += inv(row, col + 1, row, c2 - 1);
          sure += inv(row + 1, col, r2 - 1, col);
          if (sure >= answer) {
            break;
          }
          answer = min(answer, sure + inv(r2, col + 1, r2, c2 - 1) +
                                   inv(row + 1, c2, r2 - 1, c2));
        }
      }
    }
  }
  printf("%d\n", answer);
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    test_case();
  }
}
