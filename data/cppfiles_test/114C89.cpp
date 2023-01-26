#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> v;
  v.resize(n);
  set<pair<int, vector<int>>> s;
  set<vector<int>> s1;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    while (x--) {
      int u;
      cin >> u;
      v[i].push_back(u);
    }
  }
  vector<int> v1;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    int x = v[i].size();
    x--;
    v1.push_back(x);
    sum += v[i][x];
  }
  int m;
  cin >> m;
  while (m--) {
    vector<int> tp;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      tp.push_back(x - 1);
    }
    s1.insert(tp);
  }
  s.insert(make_pair(sum, v1));
  while (s.size()) {
    auto it = s.end();
    it--;
    int val = it->first;
    vector<int> tp = it->second;
    if (s1.find(tp) == s1.end()) {
      for (int i = 0; i < n; i++) {
        cout << tp[i] + 1 << " ";
      }
      return 0;
    }
    s.erase(it);
    for (int i = 0; i < n; i++) {
      if (tp[i] != 0) {
        vector<int> temp;
        for (int i = 0; i < n; i++) temp.push_back(tp[i]);
        int val1 = val - v[i][tp[i]] + v[i][tp[i] - 1];
        temp[i]--;
        s.insert(make_pair(val1, temp));
      }
    }
  }
  return 0;
}
