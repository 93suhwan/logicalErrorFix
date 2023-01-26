#include <bits/stdc++.h>
using namespace std;
int n, m;
const int maxN = 1e3 + 7;
vector<int> rooms[maxN];
vector<bool> visited[maxN];
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
multiset<int> room_size;
void search(int y, int x, int& count) {
  visited[y][x] = true;
  count++;
  for (int i = 0; i < 4; i++) {
    if (!((rooms[y][x] >> i) & 1)) {
      int tempx = x + dx[i];
      int tempy = y + dy[i];
      if (tempx >= m || tempx < 0 || tempy >= n || tempy < 0) continue;
      if (visited[tempy][tempx]) continue;
      search(tempy, tempx, count);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int temp;
      cin >> temp;
      rooms[i].push_back(temp);
      visited[i].push_back(0);
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (!visited[i][j]) {
        int count = 0;
        search(i, j, count);
        room_size.insert(count);
      }
    }
  }
  for (auto it = room_size.rbegin(); it != room_size.rend(); it++) {
    cout << *it << " ";
  }
}
