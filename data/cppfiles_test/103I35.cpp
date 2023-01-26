#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> a;
vector<string> arr;
set<pair<int, int>> curr;
int traverse(int i, int j) {
  if (curr.find({i, j}) != curr.end()) return 0;
  if (a[i][j] != -1) return a[i][j];
  curr.insert({i, j});
  if (arr[i][j] == 'L') {
    if (j == 0)
      return 1;
    else
      a[i][j] = traverse(i, j - 1) + 1;
  }
  if (arr[i][j] == 'R') {
    if (j == arr[0].size() - 1)
      return 1;
    else
      a[i][j] = traverse(i, j + 1) + 1;
  }
  if (arr[i][j] == 'U') {
    if (i == 0)
      return 1;
    else
      a[i][j] = traverse(i - 1, j) + 1;
  }
  if (arr[i][j] == 'D') {
    if (i == arr[0].size() - 1)
      return 1;
    else
      a[i][j] = traverse(i + 1, j) + 1;
  }
  return a[i][j];
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    arr.resize(n);
    a.assign(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    int mt = -1, mi = 1, mj = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        curr.clear();
        int val = traverse(i, j);
        if (val > mt) {
          mt = val;
          mi = i;
          mj = j;
        }
      }
    }
    cout << mi + 1 << " " << mj + 1 << " " << mt << '\n';
  }
}
