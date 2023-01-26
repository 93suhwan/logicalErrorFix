#include <bits/stdc++.h>
using namespace std;
const long long MAX = 310;
const long long INF = 2e9;
const long long MOD = 1e9 + 7;
long long t;
long long n, m;
long long a, b;
long long x, y;
map<long long, long long> mp;
long long id = 1;
long long arr[MAX * MAX];
long long pos[MAX * MAX];
long long mat[MAX][MAX];
vector<long long> ucit;
vector<pair<long long, long long> > v[MAX * MAX];
bool compare(pair<long long, long long> a, pair<long long, long long> b) {
  if (a.first < b.first) return true;
  if (a.first > b.first) return false;
  if (a.second > b.second) return true;
  if (a.second < b.second) return false;
}
void clean() {
  mp.clear();
  ucit.clear();
  id = 1;
  for (long long i = 0; i < n * m; i++) {
    arr[i] = 0;
    pos[i] = 0;
    v[i].clear();
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      mat[i][j] = 0;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> t;
  while (t--) {
    cin >> n >> m;
    clean();
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < m; j++) {
        cin >> x;
        arr[i * m + j] = x;
        if (!mp.count(x)) {
          mp[x] = id;
          id++;
        }
        ucit.push_back(x);
      }
    }
    sort(ucit.begin(), ucit.end());
    long long bla = 0;
    for (auto e : ucit) {
      a = mp[e];
      x = bla / m;
      y = bla % m;
      bla++;
      v[a].push_back({x, y});
    }
    for (long long i = 1; i < id; i++) {
      sort(v[i].begin(), v[i].end(), compare);
    }
    long long sol = 0;
    for (long long i = 0; i < n * m; i++) {
      a = arr[i];
      a = mp[a];
      x = v[a][pos[a]].first;
      y = v[a][pos[a]].second;
      pos[a]++;
      mat[x][y] = 1;
      for (long long j = 0; j < y; j++) {
        if (mat[x][j]) sol++;
      }
    }
    cout << sol << "\n";
  }
  return 0;
}
