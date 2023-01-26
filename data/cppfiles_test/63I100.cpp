#include <bits/stdc++.h>
using namespace std;
std::map<long long, long long> mp, love, mp1, fucklove;
std::vector<long long> v[1000001], v1[1000001];
void dfs(long long a, long long c) {
  love[a] = c;
  mp[a] = 1;
  for (long long i = 0; i < v[a].size(); ++i) {
    if (mp[v[a][i]] == 0) dfs(v[a][i], c);
  }
}
void dfs1(long long a, long long c) {
  fucklove[a] = c;
  mp1[a] = 1;
  for (long long i = 0; i < v1[a].size(); ++i) {
    if (mp1[v1[a][i]] == 0) dfs1(v1[a][i], c);
  }
}
int main() {
  long long n, m1, m2, a, b;
  cin >> n >> m1 >> m2;
  for (long long i = 0; i < m1; ++i) {
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  for (long long i = 0; i < m2; ++i) {
    cin >> a >> b;
    v1[a].push_back(b);
    v1[b].push_back(a);
  }
  long long c = 1, d = 1;
  for (long long i = 1; i <= n; ++i) {
    if (mp[i] == 0) dfs(i, c++);
  }
  for (long long i = 1; i <= n; ++i) {
    if (mp1[i] == 0) dfs1(i, d++);
  }
  std::vector<pair<long long, long long>> ans;
  c = 0;
  d = 0;
  map<long long, long long> map;
  for (long long i = 1; i <= n; ++i) {
    for (long long j = i + 1; j <= n; ++j) {
      if ((love[i] != love[j] && fucklove[i] != fucklove[j]) &&
          ((map[love[i]] + map[love[j]] == 0 &&
            map[fucklove[i]] + map[fucklove[j]] == 0) ||
           map[love[i]] != map[love[j]] &&
               map[fucklove[i]] != map[fucklove[j]])) {
        if (map[love[i]] + map[love[j]] == 0)
          map[love[i]] = ++c, map[love[j]] = c;
        else {
          map[love[i]] = max(map[love[i]], map[love[j]]);
          map[love[j]] = max(map[love[i]], map[love[j]]);
        }
        if (map[fucklove[i]] + map[fucklove[j]] == 0)
          map[fucklove[i]] = ++d, map[fucklove[j]] = d;
        else {
          map[fucklove[i]] = max(map[fucklove[i]], map[fucklove[j]]);
          map[fucklove[j]] = max(map[fucklove[i]], map[fucklove[j]]);
        }
        ans.push_back({i, j});
      }
    }
  }
  cout << ans.size() << endl;
  for (long long i = 0; i < ans.size(); ++i)
    cout << ans[i].first << " " << ans[i].second << endl;
}
