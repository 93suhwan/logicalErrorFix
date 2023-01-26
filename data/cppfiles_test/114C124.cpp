#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> c[12], b[200021];
struct build {
  int sum;
  vector<int> b;
  bool operator<(const build b) const { return sum < b.sum; }
};
priority_queue<build> q;
vector<build> nxt;
map<vector<int>, bool> ban;
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  int num, x;
  for (int i = (1); i <= (n); i++) {
    cin >> num;
    for (int j = (1); j <= (num); j++) cin >> x, c[i].push_back(x);
    reverse(c[i].begin(), c[i].end());
  }
  cin >> m;
  for (int i = (1); i <= (m); i++) {
    for (int j = (1); j <= (n); j++) cin >> x, b[i].push_back(c[j].size() - x);
    ban[b[i]] = true;
  }
  for (int i = (0); i <= ((int)c[1].size() - 1); i++)
    nxt.push_back({c[1][i], {i}});
  for (int i = (2); i <= (n); i++) {
    while (!q.empty()) q.pop();
    for (build k : nxt) k.b.push_back(0), k.sum += c[i][0], q.push(k);
    nxt.clear();
    while (nxt.size() <= m && !q.empty()) {
      build cur = q.top();
      q.pop();
      nxt.push_back(cur);
      int p = cur.b.back();
      if (p + 1 < c[i].size()) {
        cur.b.back()++, cur.sum += c[i][p + 1] - c[i][p];
        q.push(cur);
      }
    }
  }
  for (build k : nxt)
    if (!ban[k.b]) {
      for (int i = (0); i <= (n - 1); i++)
        cout << c[i + 1].size() - k.b[i] << " ";
      cout << endl;
      break;
    }
  return 0;
}
