#include <bits/stdc++.h>
int n;
std::vector<std::pair<int, int> > A[3];
inline bool chk(int x) {
  int p[3] = {0, 1, 2};
  do {
    for (int oo = 0; oo < 2; oo++) {
      for (int o = 0; o < 2; o++) {
        std::sort(A[p[0]].begin(), A[p[0]].end());
        int u = A[p[0]][x - 1].first + 1;
        std::sort(A[p[1]].begin(), A[p[1]].end());
        int y = x, v = 0x3f3f3f3f;
        for (auto [i, j] : A[p[1]])
          if (i >= u && !--y) v = i + 1;
        std::sort(A[p[2]].begin(), A[p[2]].end());
        y = x;
        for (auto [i, j] : A[p[2]])
          if (i >= v && !--y) return 1;
        std::sort(A[p[1]].begin(), A[p[1]].end(),
                  [&](std::pair<int, int> i, std::pair<int, int> j) {
                    return i.second < j.second;
                  });
        y = x, v = 0x3f3f3f3f;
        for (auto [i, j] : A[p[1]])
          if (i >= u && !--y) v = j + 1;
        std::sort(A[p[2]].begin(), A[p[2]].end(),
                  [&](std::pair<int, int> i, std::pair<int, int> j) {
                    return i.second < j.second;
                  });
        y = x;
        for (auto [i, j] : A[p[2]])
          if (i >= u && j >= v && !--y) return 1;
        for (int i = 0; i < 3; i++)
          for (int j = 0; j < n / 3; j++)
            std::swap(A[i][j].first, A[i][j].second);
      }
      for (int i = 0; i < 3; i++)
        for (int j = 0; j < n / 3; j++) A[i][j].first *= -1;
    }
  } while (std::next_permutation(p, p + 3));
  return 0;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int x, y, c;
    scanf("%d%d%d", &x, &y, &c);
    A[c - 1].emplace_back(x, y);
  }
  int L = 1, R = n / 3, res = L;
  while (L <= R) {
    int mid = (L + R) >> 1;
    if (chk(mid))
      res = mid, L = mid + 1;
    else
      R = mid - 1;
  }
  printf("%d\n", 3 * res);
}
