#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> a;
vector<string> arr;
vector<vector<bool>> curr;
int traverse(int i, int j) {
  int ci = i, cj = j;
  stack<pair<int, int>> s;
  bool cycle = false;
  while (true) {
    if (j >= curr[0].size() || j < 0) break;
    if (i >= curr.size() || i < 0) break;
    if (a[i][j] != -1) {
      break;
    }
    s.push({i, j});
    if (curr[i][j]) {
      cycle = true;
      break;
    }
    curr[i][j] = true;
    if (arr[i][j] == 'L')
      j--;
    else if (arr[i][j] == 'R')
      j++;
    else if (arr[i][j] == 'U')
      i--;
    else if (arr[i][j] == 'D')
      i++;
  }
  int commands = 0;
  if (cycle) {
    stack<pair<int, int>> temp;
    pair<int, int> top = s.top();
    curr[top.first][top.second] = false;
    s.pop();
    while (true) {
      temp.push(s.top());
      if (s.top() == top) {
        curr[s.top().first][s.top().second] = false;
        s.pop();
        break;
      } else {
        curr[s.top().first][s.top().second] = false;
        s.pop();
      }
    }
    commands = temp.size();
    while (!temp.empty()) {
      a[temp.top().first][temp.top().second] = commands;
      temp.pop();
    }
  } else if (0 <= i && i < curr.size() && 0 <= j && j < curr[0].size()) {
    commands = a[i][j];
  } else
    commands = 0;
  while (!s.empty()) {
    curr[s.top().first][s.top().second] = false;
    a[s.top().first][s.top().second] = ++commands;
    s.pop();
  }
  return a[ci][cj];
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    arr.resize(n);
    a.assign(n, vector<int>(m, -1));
    curr.assign(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    int mt = -1, mi = 1, mj = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
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
