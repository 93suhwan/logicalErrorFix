#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<vector<long long int>> v(n);
  for (int i = 0; i < n; i++) {
    long long int x;
    cin >> x;
    v[i].resize(x);
    for (int j = 0; j < x; j++) {
      cin >> v[i][j];
    }
  }
  set<vector<long long int>> visited, banned;
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    vector<long long int> temp;
    for (int j = 0; j < n; j++) {
      long long int y;
      cin >> y;
      temp.push_back(y);
    }
    banned.insert(temp);
  }
  priority_queue<pair<long long int, vector<long long int>>> pq;
  vector<long long int> ans;
  for (int i = 0; i < n; i++) {
    ans.push_back(v[i].size());
  }
  pq.push({0, ans});
  while (!pq.empty()) {
    pair<long long int, vector<long long int>> p = pq.top();
    pq.pop();
    if (banned.count(p.second) == 0) {
      for (int i = 0; i < n; i++) {
        cout << p.second[i] << " ";
      }
      cout << endl;
      exit(0);
    }
    for (int i = 0; i < n; i++) {
      if (p.second[i] > 1) {
        p.second[i]--;
        if (visited.count(p.second) == 0) {
          pq.push(
              {p.first - v[i][p.second[i]] + v[i][p.second[i] - 1], p.second});
          visited.insert(p.second);
        }
        p.second[i]++;
      }
    }
  }
  return 0;
}
