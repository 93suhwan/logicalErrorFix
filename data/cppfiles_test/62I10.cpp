#include <bits/stdc++.h>
using namespace std;
long long denom = 1e9 + 7;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= denom;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % denom;
    a = a * a % denom;
  }
  return res;
}
int main(int argc, const char* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  while (t-- > 0) {
    long long n, m, q;
    cin >> n >> m >> q;
    vector<vector<bool>> isBlocked(n, vector<bool>(m, false));
    vector<pair<long long, long long>> move = {{0, 1}, {1, 0}};
    vector<vector<pair<long long, long long>>> hor;
    unordered_map<long long,
                  unordered_map<long long, vector<pair<long long, long long>>>>
        horIdx;
    for (long long j = (0); j < (m - 1); j++) {
      long long x = 0, y = j, k = 0;
      long long firstIndex = hor.size();
      vector<pair<long long, long long>> path;
      while (x < n && y < m) {
        horIdx[x][y].push_back({firstIndex, path.size()});
        path.push_back({x, y});
        x += move[k].first;
        y += move[k].second;
        k = (k + 1) % 2;
      }
      hor.push_back(path);
    }
    vector<set<long long>> horBlocked(hor.size());
    vector<vector<pair<long long, long long>>> ver;
    unordered_map<long long,
                  unordered_map<long long, vector<pair<long long, long long>>>>
        verIdx;
    for (long long i = (0); i < (n - 1); i++) {
      long long x = i, y = 0, k = 1;
      long long firstIndex = ver.size();
      vector<pair<long long, long long>> path;
      while (x < n && y < m) {
        verIdx[x][y].push_back({firstIndex, path.size()});
        path.push_back({x, y});
        x += move[k].first;
        y += move[k].second;
        k = (k + 1) % 2;
      }
      ver.push_back(path);
    }
    vector<set<long long>> verBlocked(ver.size());
    long long total = 0;
    for (auto& a : hor) {
      long long c = a.size();
      total += c * (c + 1) / 2;
    }
    for (auto& a : ver) {
      long long c = a.size();
      total += c * (c + 1) / 2;
    }
    for (long long i = (0); i < (n); i++)
      for (long long j = (0); j < (m); j++)
        total -= (horIdx[i][j].size() + verIdx[i][j].size() - 1);
    long long curr = total;
    for (long long i = (0); i < (q); i++) {
      long long a, b;
      cin >> a >> b;
      a--;
      b--;
      long long d = 0;
      for (auto p : horIdx[a][b]) {
        long long l = -1, h = hor[p.first].size();
        set<long long>& s_block = horBlocked[p.first];
        if (isBlocked[a][b]) s_block.erase(p.second);
        auto it1 = s_block.lower_bound(p.second);
        if (it1 != s_block.end()) {
          h = *it1;
        }
        if (it1 != s_block.begin()) {
          it1--;
          l = *it1;
        }
        d += (p.second - l) * (h - p.second);
        if (!isBlocked[a][b]) s_block.insert(p.second);
      }
      for (auto p : verIdx[a][b]) {
        long long l = -1, h = ver[p.first].size();
        set<long long>& s_block = verBlocked[p.first];
        if (isBlocked[a][b]) s_block.erase(p.second);
        auto it1 = s_block.lower_bound(p.second);
        if (it1 != s_block.end()) {
          h = *it1;
        }
        if (it1 != s_block.begin()) {
          it1--;
          l = *it1;
        }
        d += (p.second - l) * (h - p.second);
        if (!isBlocked[a][b]) s_block.insert(p.second);
      }
      if (isBlocked[a][b]) {
        curr += d;
        curr -= (horIdx[a][b].size() + verIdx[a][b].size() - 1);
      } else {
        curr -= d;
        curr += (horIdx[a][b].size() + verIdx[a][b].size() - 1);
      }
      isBlocked[a][b] = !isBlocked[a][b];
      cout << curr << endl;
    }
  }
  return 0;
}
