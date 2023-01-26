#include <bits/stdc++.h>
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
template <class T>
ostream& operator<<(ostream& os, vector<T> V) {
  os << "[ ";
  for (auto v : V) os << v << " ";
  return os << "]";
}
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
const long long int mod = 1e9 + 7;
bool sortbysec(const pair<int, int>& a, const pair<int, int>& b) {
  return (a.second < b.second);
}
vector<vector<int>> vis, num, vis1;
vector<vector<char>> v;
long long int n, m, ans = 0, x0, y00, temp;
long long int dfs(long long int x, long long int y) {
  if (vis1[x][y] == 1) return 0;
  if (x > n - 1 || x < 0 || y < 0 || y > m - 1) return 0;
  vis[x][y] = 1;
  vis1[x][y] = 1;
  num[x][y] = 1;
  if (v[x][y] == 'D' && x < n - 1) {
    if (!vis[x + 1][y]) return (num[x][y] += dfs(x + 1, y));
    if (vis1[x + 1][y] == 1) {
      num[x][y] = 2;
      return (1);
    }
    return (num[x][y] += num[x + 1][y]);
  }
  if (v[x][y] == 'U' && x > 0) {
    if (!vis[x - 1][y]) return (num[x][y] += dfs(x - 1, y));
    if (vis1[x - 1][y] == 1) {
      num[x][y] = 2;
      return (1);
    }
    return (num[x][y] += num[x - 1][y]);
  }
  if (v[x][y] == 'L' && y > 0) {
    if (!vis[x][y - 1]) return (num[x][y] += dfs(x, y - 1));
    if (vis1[x][y - 1] == 1) {
      num[x][y] = 2;
      return (1);
    };
    return (num[x][y] += num[x][y - 1]);
  }
  if (v[x][y] == 'R' && y < m - 1) {
    if (!vis[x][y + 1]) return (num[x][y] += dfs(x, y + 1));
    if (vis1[x][y + 1] == 1) {
      num[x][y] = 2;
      return (1);
    }
    return (num[x][y] += num[x][y + 1]);
  }
  return (num[x][y]);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    ans = 0;
    cin >> n >> m;
    vis.clear();
    vis.assign(n + 1, vector<int>(m + 1, 0));
    vis1.clear();
    vis1.assign(n + 1, vector<int>(m + 1, 0));
    num.clear();
    num.assign(n, vector<int>(m, 0));
    v.clear();
    v.resize(n + 1, vector<char>(m + 1, 'o'));
    vector<string> p(n);
    for (long long int i = 0; i < n; i++) {
      string s;
      cin >> s;
      p[i] = s;
    }
    for (long long int i = 0; i < n; i++) {
      for (long long int j = 0; j < m; j++) v[i][j] = p[i][j];
    }
    for (long long int i = 0; i < n; i++) {
      for (long long int j = 0; j < m; j++) {
        temp = 0;
        vis1.clear();
        vis1.assign(n + 1, vector<int>(m + 1, 0));
        if (!vis[i][j]) {
          temp = dfs(i, j);
        }
        if (temp > ans) {
          ans = temp;
          x0 = i + 1;
          y00 = j + 1;
        }
      }
    }
    cout << x0 << " " << y00 << " " << ans << "\n";
  }
  return 0;
}
