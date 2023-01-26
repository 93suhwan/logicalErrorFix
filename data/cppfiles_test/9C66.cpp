#include <bits/stdc++.h>
using namespace std;
int64_t mo = 1000000007;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> map(n);
  vector<int> minis(m, 0);
  vector<int> sol(k);
  for (int i = 0; i < n; ++i) {
    map[i].resize(m);
    for (int j = 0; j < m; ++j) {
      cin >> map[i][j];
    }
  }
  for (int i = 0; i < k; ++i) {
    pair<int, int> pos;
    cin >> pos.first;
    pos.first--;
    pos.second = 0;
    int he = n;
    while (pos.second != n) {
      if (minis[pos.first] >= n - pos.second) {
        break;
      }
      if (map[pos.second][pos.first] == 2) {
        pos.second++;
      } else if (map[pos.second][pos.first] == 1) {
        map[pos.second][pos.first] = 2;
        pos.first++;
        he = n - pos.second;
      } else {
        map[pos.second][pos.first] = 2;
        pos.first--;
        he = n - pos.second;
      }
    }
    minis[pos.first] = max(minis[pos.first], he);
    sol[i] = pos.first + 1;
  }
  for (int i = 0; i < k; ++i) {
    cout << sol[i] << " ";
  }
}
