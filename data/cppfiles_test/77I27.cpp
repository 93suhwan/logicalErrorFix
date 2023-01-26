#include <bits/stdc++.h>
using namespace std;
int n, m;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};
multiset<int> room_size;
void search(vector<bool> visited[], vector<int> rooms[], int i, int j,
            int& count) {
  visited[i][j] = true;
  count++;
  for (int x = 0; x < 4; x++) {
    if (((rooms[i][j] >> x) & 1) == 0) {
      int tempx = i + dx[x];
      int tempy = j + dy[x];
      if (tempx >= n || tempx < 0 || tempy >= m || tempy < 0) continue;
      if (visited[tempx][tempy]) continue;
      search(visited, rooms, tempx, tempy, count);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  vector<int> rooms[n];
  vector<bool> visited[n];
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
        search(visited, rooms, i, j, count);
        room_size.insert(count);
      }
    }
  }
  cout << "room_size: " << room_size.size();
  for (auto it = room_size.begin(); it != room_size.end(); it++) {
    cout << *it << " ";
  }
}
