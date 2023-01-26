#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int test = 1;
  while (test--) {
    int n;
    cin >> n;
    pair<int, vector<int>> curr;
    curr.first = 0;
    curr.second.clear();
    vector<int> v[n];
    for (int i = 0; i < n; i++) {
      int c;
      cin >> c;
      curr.second.push_back(c - 1);
      int x;
      v[i].clear();
      while (c--) {
        cin >> x;
        v[i].push_back(x);
      }
      curr.first += x;
    }
    int m;
    cin >> m;
    map<vector<int>, int> ban;
    while (m--) {
      vector<int> temp;
      temp.clear();
      for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x--;
        temp.push_back(x);
      }
      ban[temp] = 1;
    }
    set<pair<int, vector<int>>> s;
    s.insert(curr);
    bool done = false;
    while (!done) {
      curr = *s.rbegin();
      s.erase(curr);
      if (ban[curr.second] == 0) {
        for (auto u : curr.second) cout << u + 1 << " ";
        done = true;
      }
      pair<int, vector<int>> temp;
      temp = curr;
      for (int i = 0; i < n; i++) {
        int idx = curr.second[i];
        if (!idx) continue;
        int diff = v[i][idx] - v[i][idx - 1];
        temp.first -= diff;
        temp.second[i]--;
        s.insert(temp);
        temp = curr;
      }
    }
  }
  return 0;
}
