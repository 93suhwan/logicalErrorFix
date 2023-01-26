#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, M;
  cin >> N >> M;
  int v[1000][1000];
  int c[1000][1000];
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> v[j][i];
      c[j][i] = 0;
    }
  }
  std::vector<int> sizes;
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      vector<pair<int, int>> stack;
      if (c[i][j] == 0) {
        stack.push_back(make_pair(i, j));
        int counter = 0;
        while (!stack.empty()) {
          auto xy = stack.back();
          int x = xy.first;
          int y = xy.second;
          stack.pop_back();
          if (c[x][y] == 0) {
            int tile = v[x][y];
            if ((tile & 0x8) == 0) {
              if (c[x][y - 1] == 0) stack.push_back(make_pair(x, y - 1));
            }
            if ((tile & 0x4) == 0) {
              if (c[x + 1][y] == 0) stack.push_back(make_pair(x + 1, y));
            }
            if ((tile & 0x2) == 0) {
              if (c[x][y + 1] == 0) stack.push_back(make_pair(x, y + 1));
            }
            if ((tile & 0x1) == 0) {
              if (c[x - 1][y] == 0) stack.push_back(make_pair(x - 1, y));
            }
            c[x][y] = 1;
            counter++;
          }
        }
        sizes.push_back(counter);
      }
    }
  }
  sort(sizes.begin(), sizes.end());
  for (auto it = sizes.rbegin(); it != sizes.rend(); ++it) {
    cout << *it << ' ';
  }
  cout << '\n';
  return 0;
}
