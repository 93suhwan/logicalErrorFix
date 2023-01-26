#include <bits/stdc++.h>
using namespace std;
pair<pair<int, int>, int> p[1000];
vector<int> v[1000];
bool flag[1000];
void dfs(int param) {
  if (v[param].empty()) {
    cout << p[param].first.first << ' ' << p[param].first.second << ' '
         << p[param].first.first << endl;
    flag[p[param].first.first] = true;
  } else {
    for (int i : v[param]) {
      dfs(i);
    }
    cout << p[param].first.first << ' ' << p[param].first.second << ' ';
    for (int i = p[param].first.first; i <= p[param].first.second; ++i) {
      if (!flag[i]) {
        cout << i << endl;
        flag[i] = true;
      }
    }
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < 1000; ++i) {
      v[i].clear();
      flag[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
      int l, r;
      cin >> l >> r;
      p[i] = {{l, r}, i};
    }
    for (int i = 0; i < n; ++i) {
      int l0 = p[i].first.first, r0 = p[i].first.second;
      for (int j = 0; j < n; ++j) {
        if (i == j) continue;
        int l1 = p[j].first.first, r1 = p[j].first.second;
        if (l0 <= l1 and r1 <= r0) {
          if (p[j].second == j) {
            p[j].second = i;
          } else {
            int parent = p[j].second;
            if (p[parent].first.first <= l0 and r0 <= p[parent].first.second) {
              p[j].second = i;
            }
          }
        }
      }
    }
    vector<int> source;
    for (int i = 0; i < n; ++i) {
      if (p[i].second == i) {
        source.push_back(i);
      } else {
        v[p[i].second].push_back(i);
      }
    }
    for (int i : source) {
      dfs(i);
    }
    cout << endl;
  }
}
