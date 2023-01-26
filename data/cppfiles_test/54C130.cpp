#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
const int maxn = 1e5 + 5;
long long int imposters = 0, controversy = 0;
void dfs(vector<pair<long long int, int>> vec[], vector<long long int> &team,
         vector<long long int> &count, int indx) {
  count[team[indx]]++;
  for (int i = 0; i < vec[indx].size(); i++) {
    int adjacent = vec[indx][i].first;
    int weight = vec[indx][i].second;
    if (team[adjacent] == -1) {
      team[adjacent] = team[indx] ^ weight;
      dfs(vec, team, count, adjacent);
    } else if (team[adjacent] != (team[indx] ^ weight)) {
      controversy = 1;
    }
  }
}
void solve() {
  long long int n, m;
  cin >> n >> m;
  imposters = 0;
  controversy = 0;
  long long int i, j;
  string str;
  vector<pair<long long int, int>> vec[n + 1];
  while (m--) {
    cin >> i >> j >> str;
    i--;
    j--;
    if (str == "imposter") {
      vec[i].push_back({j, 1});
      vec[j].push_back({i, 1});
    } else {
      vec[i].push_back({j, 0});
      vec[j].push_back({i, 0});
    }
  }
  vector<long long int> team(n + 1, -1);
  vector<long long int> count(2, 0);
  for (int i = 0; i < n; i++) {
    if (team[i] == -1) {
      team[i] = 0;
      count[0] = 0, count[1] = 0;
      dfs(vec, team, count, i);
      imposters += max(count[0], count[1]);
    }
  }
  if (controversy == 1) {
    imposters = -1;
  }
  cout << imposters << endl;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
