#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> v;
  map<int, vector<int>> m;
  while (n--) {
    int t;
    cin >> t;
    int x;
    int y;
    if (t == 1) {
      cin >> x;
      v.push_back(x);
      m[x].push_back(v.size() - 1);
    } else {
      cin >> x;
      cin >> y;
      if (x != y) {
        for (int i = 0; i < m[x].size(); i++) {
          v[m[x][i]] = y;
          m[y].push_back(i);
        }
        m[x].clear();
      }
    }
  }
  for (auto j : v) {
    cout << j << " ";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long test = 1;
  while (test--) {
    solve();
  }
  return 0;
}
