#include <bits/stdc++.h>
using namespace std;
int binarySearch(pair<int, int> arr[], int l, int r, int x) {
  if (r >= l) {
    int mid = l + (r - l) / 2;
    if (arr[mid].first == x) return mid;
    if (arr[mid].first > x) return binarySearch(arr, l, mid - 1, x);
    return binarySearch(arr, mid + 1, r, x);
  }
  return -1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  int act[n][m][4];
  bool visited[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int x;
      cin >> x;
      visited[i][j] = false;
      for (int k = 0; k < 4; k++) {
        act[i][j][k] = 0;
      }
      if ((x / 1) % 2 == 1) {
        act[i][j][3] = 1;
      }
      if ((x / 2) % 2 == 1) {
        act[i][j][2] = 1;
      }
      if ((x / 4) % 2 == 1) {
        act[i][j][1] = 1;
      }
      if ((x / 8) % 2 == 1) {
        act[i][j][0] = 1;
      }
      cout << act[i][j][0] << act[i][j][1] << act[i][j][2] << act[i][j][3]
           << " ";
    }
    cout << "\n";
  }
  stack<pair<int, int>> s;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!visited[i][j]) {
        s.push({i, j});
        visited[i][j] = true;
        int roomsize = 1;
        while (!s.empty()) {
          pair<int, int> k = s.top();
          int i1 = k.first;
          int j1 = k.second;
          if (!visited[i1 - 1][j1] && act[i1][j1][0] == 0) {
            s.push({i1 - 1, j1});
            visited[i1 - 1][j1] = true;
            roomsize++;
          } else if (!visited[i1 + 1][j1] && act[i1][j1][2] == 0) {
            s.push({i1 + 1, j1});
            visited[i1 + 1][j1] = true;
            roomsize++;
          } else if (!visited[i1][j1 + 1] && act[i1][j1][1] == 0) {
            s.push({i1, j1 + 1});
            visited[i1][j1 + 1] = true;
            roomsize++;
          } else if (!visited[i1][j1 - 1] && act[i1][j1][3] == 0) {
            s.push({i1, j1 - 1});
            visited[i1][j1 - 1] = true;
            roomsize++;
          } else {
            s.pop();
          }
        }
        v.push_back(roomsize);
      }
    }
  }
  sort(v.begin(), v.end());
  for (int i = v.size() - 1; i >= 0; i--) {
    cout << v[i] << " ";
  }
  return 0;
}
