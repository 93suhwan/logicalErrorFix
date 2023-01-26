#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
struct Comparator {
  bool operator()(const pair<long long, long long>& lhs,
                  const pair<long long, long long>& rhs) const {
    if (lhs.first == rhs.first) return lhs.second < rhs.second;
    return lhs.first < rhs.first;
  }
  bool operator()(long long a, long long b) const { return a > b; }
};
long long n, m;
char grid[505][505];
long long val[505][505];
vector<vector<long long> > graph(300005);
vector<long long> colors(300005, -1);
void init() {
  long long counter = 0;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      val[i][j] = counter++;
    }
  }
}
void input() {
  cin >> n >> m;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      cin >> grid[i][j];
    }
  }
}
bool checkOdd() {
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (grid[i][j] == 'X') {
        long long count = (grid[i - 1][j] == '.') + (grid[i + 1][j] == '.') +
                          (grid[i][j + 1] == '.') + (grid[i][j - 1] == '.');
        if (count % 2) {
          return false;
        }
      }
    }
  }
  return true;
}
void initGraph() {
  for (long long i = 1; i < n - 1; i++) {
    for (long long j = 1; j < m - 1; j++) {
      if (grid[i][j] == 'X') {
        vector<pair<long long, long long> > dots;
        if (grid[i - 1][j] == '.') dots.push_back({i - 1, j});
        if (grid[i + 1][j] == '.') dots.push_back({i + 1, j});
        if (grid[i][j + 1] == '.') dots.push_back({i, j + 1});
        if (grid[i][j - 1] == '.') dots.push_back({i, j - 1});
        if (dots.size() == 2) {
          long long first = val[dots[0].first][dots[0].second];
          long long second = val[dots[1].first][dots[1].second];
          graph[first].push_back(second);
          graph[second].push_back(first);
        }
        if (dots.size() == 4) {
          long long first = val[dots[0].first][dots[0].second];
          long long second = val[dots[1].first][dots[1].second];
          long long third = val[dots[2].first][dots[2].second];
          long long fourth = val[dots[3].first][dots[3].second];
          graph[first].push_back(third);
          graph[first].push_back(fourth);
          graph[second].push_back(third);
          graph[second].push_back(fourth);
          graph[third].push_back(first);
          graph[third].push_back(second);
          graph[fourth].push_back(first);
          graph[fourth].push_back(second);
        }
      }
    }
  }
}
bool checkBipartite(long long vertex, long long color = 0) {
  if (colors[vertex] == color) return true;
  if (colors[vertex] == -1) colors[vertex] = color;
  if (colors[vertex] != color) return false;
  for (long long i = 0; i < graph[vertex].size(); i++) {
    long long next = graph[vertex][i];
    if (colors[next] == colors[vertex]) return false;
    checkBipartite(next, 1 - color);
  }
  return true;
}
void solve() {
  input();
  init();
  if (!checkOdd()) {
    cout << "NO\n";
    return;
  }
  initGraph();
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (colors[val[i][j]] == -1) {
        if (!checkBipartite(val[i][j])) {
          cout << "NO\n";
          return;
        }
      }
    }
  }
  long long answ[n + 1][m + 1];
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (grid[i][j] != 'X') {
        answ[i][j] = colors[val[i][j]] * 3 + 1;
      }
    }
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (grid[i][j] == 'X') {
        answ[i][j] = 0;
        if (grid[i + 1][j] != 'X') answ[i][j] += answ[i + 1][j];
        if (grid[i - 1][j] != 'X') answ[i][j] += answ[i - 1][j];
        if (grid[i][j + 1] != 'X') answ[i][j] += answ[i][j + 1];
        if (grid[i][j - 1] != 'X') answ[i][j] += answ[i][j - 1];
      }
    }
  }
  cout << "YES\n";
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      cout << answ[i][j] << ' ';
    }
    cout << '\n';
  }
}
signed main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  ;
  solve();
  return 0;
}
