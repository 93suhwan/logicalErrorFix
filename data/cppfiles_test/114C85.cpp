#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> c[n];
  for (int i = 0; i < n; i++) {
    int cx;
    cin >> cx;
    c[i].resize(cx);
    for (int j = 0; j < cx; j++) {
      cin >> c[i][j];
    }
  }
  int m;
  cin >> m;
  set<vector<int>> b;
  for (int i = 0; i < m; i++) {
    vector<int> thing(n);
    for (int j = 0; j < n; j++) {
      cin >> thing[j];
      thing[j]--;
    }
    b.insert(thing);
  }
  priority_queue<pair<int, vector<int>>> q;
  int strtcost = 0;
  vector<int> bestv(n);
  vector<int> strtvec(n);
  for (int i = 0; i < n; i++) {
    strtcost += c[i][(int)(c[i]).size() - 1];
    strtvec[i] = (int)(c[i]).size() - 1;
  }
  int worstcost = strtcost;
  q.push(make_pair(strtcost, strtvec));
  set<vector<int>> seen;
  seen.insert(strtvec);
  while (!q.empty()) {
    pair<int, vector<int>> qtop = q.top();
    q.pop();
    vector<int> &topv = qtop.second;
    int topcost = qtop.first;
    if (b.count(topv) == 0) {
      for (int x : topv) {
        cout << x + 1 << ' ';
      }
      cout << endl;
      return 0;
    }
    for (int i = 0; i < n; i++) {
      if (topv[i] == 0) continue;
      vector<int> newv = topv;
      newv[i]--;
      int newcost = topcost - c[i][topv[i]] + c[i][newv[i]];
      if (seen.count(newv) != 0) continue;
      seen.insert(newv);
      worstcost = min(worstcost, newcost);
      if ((int)(q).size() <= m + 5 || newcost > worstcost)
        q.push(make_pair(newcost, newv));
    }
  }
}
