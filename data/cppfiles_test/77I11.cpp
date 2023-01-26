#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, M;
  cin >> N >> M;
  int dx[4] = {0, 1, 0, -1};
  int dy[4] = {1, 0, -1, 0};
  int masksSrc[4] = {0b0010, 0b0100, 0b1000, 0b0001};
  int masksDest[4] = {0b1000, 0b0001, 0b0010, 0b0100};
  int grid[N][M];
  for (int n = 0; n < N; n++) {
    for (int m = 0; m < M; m++) {
      cin >> grid[n][m];
    }
  }
  stack<pair<int, int> > s;
  int visited[N][M];
  for (int n = 0; n < N; n++)
    for (int m = 0; m < M; m++) visited[n][m] = 0;
  vector<int> res;
  for (int n = 0; n < N; n++) {
    for (int m = 0; m < M; m++) {
      if (visited[n][m] == 0) {
        s.push({n, m});
        int size = 0;
        while (s.size() > 0) {
          auto [row, col] = s.top();
          s.pop();
          size++;
          visited[row][col] = 1;
          for (int dir = 0; dir < 4; dir++) {
            int newR = row + dy[dir];
            int newC = col + dx[dir];
            if (newR >= 0 && newC >= 0 && newR < N && newC < M &&
                !visited[newR][newC]) {
              if ((grid[row][col] & masksSrc[dir]) == 0 &&
                  (grid[newR][newC] & masksDest[dir]) == 0) {
                s.push({newR, newC});
              }
            }
          }
        }
        res.push_back(-1 * size);
      }
    }
  }
  sort(res.begin(), res.end());
  for (int a : res) cout << -1 * a << " ";
  cout << endl;
  return 0;
}
