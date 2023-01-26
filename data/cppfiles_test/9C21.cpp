#include <bits/stdc++.h>
using namespace std;
void FAST() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
long long gcd(long long x, long long y) {
  if (x == 0) return y;
  return gcd(y % x, x);
}
long long powM(long long x, long long y, long long m) {
  long long ans = 1, r = 1;
  x %= m;
  while (r > 0 && r <= y) {
    if (r & y) {
      ans *= x;
      ans %= m;
    }
    r <<= 1;
    x *= x;
    x %= m;
  }
  return ans;
}
template <typename T>
void printarr(vector<T> arr) {
  for (int i = 0; i < arr.size(); i++) cout << arr[i] << " ";
  cout << '\n';
}
template <typename T>
void printarr2d(vector<vector<T>> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    int m = arr[i].size();
    for (int j = 0; j < m; j++) {
      cout << arr[i][j] << " ";
    }
    cout << '\n';
  }
}
map<long long, long long> factorize(long long n) {
  map<long long, long long> ans;
  for (long long i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      ans[i]++;
      n /= i;
    }
  }
  if (n > 1) {
    ans[n]++;
    n = 1;
  }
  return ans;
}
vector<bool> sieve() {
  int n = 1e6;
  vector<bool> prime(n + 1, true);
  for (int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
  return prime;
}
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
void add_edge(vector<vector<int>> &graph, int u, int v) {
  graph[u].push_back(v);
  graph[v].push_back(u);
}
template <typename T>
void printgraph(vector<vector<T>> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    int m = arr[i].size();
    cout << i << ": ";
    for (int j = 0; j < m; j++) {
      cout << arr[i][j] << " ";
    }
    cout << '\n';
  }
}
void dfs(vector<bool> &visited, vector<vector<int>> &adj, int v) {
  visited[v] = true;
  for (int u : adj[v]) {
    if (!visited[u]) dfs(visited, adj, u);
  }
}
void dfsa(vector<bool> &visited, vector<vector<int>> &adj, int v) {
  visited[v] = true;
  for (int i = 0; i < adj[v].size(); i++) {
    if (adj[v][i] && !visited[i]) dfsa(visited, adj, i);
  }
}
void bfs(int u, vector<bool> v, vector<vector<int>> g) {
  queue<int> q;
  q.push(u);
  v[u] = true;
  while (!q.empty()) {
    int f = q.front();
    q.pop();
    for (auto i = g[f].begin(); i != g[f].end(); i++) {
      if (!v[*i]) {
        q.push(*i);
        v[*i] = true;
      }
    }
  }
}
int main() {
  FAST();
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> arr(n, vector<int>(m, 0));
  vector<int> co(m, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
      if (arr[i][j] == 2) co[j]++;
    }
  }
  vector<int> balls(k, 0);
  for (int i = 0; i < k; i++) {
    cin >> balls[i];
    balls[i]--;
  }
  vector<int> ans;
  int b = 0;
  while (b < k) {
    int row = 0;
    int col = balls[b];
    while (row < n && col < m && col >= 0) {
      if (arr[row][col] == 1) {
        arr[row][col] = 2;
        co[col]++;
        col++;
      } else if (arr[row][col] == 2) {
        row++;
      } else if (arr[row][col] == 3) {
        arr[row][col] = 2;
        co[col]++;
        col--;
      }
    }
    if (row == n)
      ans.push_back(col + 1);
    else if (col == m)
      ans.push_back(col);
    else if (col < 0)
      ans.push_back(1);
    b++;
  }
  printarr(ans);
  return 0;
}
