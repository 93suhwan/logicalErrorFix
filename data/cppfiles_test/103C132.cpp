#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
istream &operator>>(istream &in, vector<T> &v) {
  for (auto &x : v) in >> x;
  return in;
}
template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v) {
  for (auto &x : v) out << x << ' ';
  return out;
}
template <typename T1, typename T2>
istream &operator>>(istream &in, pair<T1, T2> &p) {
  in >> p.first >> p.second;
  return in;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &p) {
  out << p.first << ' ' << p.second;
  return out;
}
map<char, pair<long long, long long> > dir = {
    {'L', {0, -1}}, {'R', {0, 1}}, {'U', {-1, 0}}, {'D', {1, 0}}};
pair<long long, long long> operator+(const pair<long long, long long> &p1,
                                     const pair<long long, long long> &p2) {
  pair<long long, long long> p = p1;
  p.first += p2.first;
  p.second += p2.second;
  return p;
}
long long n, m;
vector<vector<long long> > adj;
inline bool valid(long long i, long long j) {
  return (i >= 0 && i < n && j >= 0 && j < m);
}
inline long long cellNo(long long i, long long j) { return i * m + j + 1; }
const bool tests = 1;
void solve_case() {
  cin >> n >> m;
  vector<string> v(n);
  cin >> v;
  adj.clear();
  adj.resize(n * m + 1);
  vector<long long> indegree(n * m + 1, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      auto p = dir[v[i][j]] + make_pair(i, j);
      if (!valid(p.first, p.second)) continue;
      adj[cellNo(i, j)].push_back(cellNo(p.first, p.second));
      indegree[cellNo(p.first, p.second)]++;
    }
  }
  vector<pair<long long, long long> > arr(n * m + 1);
  for (int i = 1; i <= n * m; i++) {
    arr[i] = {i, 1};
  }
  queue<long long> q;
  for (long long i = 1; i <= n * m; i++) {
    if (indegree[i] == 0) {
      q.push(i);
    }
  }
  while (!q.empty()) {
    long long node = q.front();
    q.pop();
    if (adj[node].empty()) continue;
    indegree[adj[node][0]]--;
    if (indegree[adj[node][0]] == 0) q.push(adj[node][0]);
    arr[adj[node][0]] = {arr[node].first, arr[node].second + 1};
  }
  pair<long long, long long> ans = {0, -1};
  for (int i = 1; i <= n * m; i++) {
    vector<long long> v;
    long long len = 0;
    v.push_back(i);
    if (indegree[i] == 1) {
      indegree[i]--;
      int j = adj[i][0];
      while (indegree[j] == 1) {
        indegree[j] = 0;
        len++;
        v.push_back(j);
        j = adj[j][0];
      }
    }
    for (long long x : v) {
      if (ans.second < arr[x].second + len) {
        ans = arr[x];
        ans.second += len;
      }
    }
  }
  for (int i = 1; i <= n * m; i++) {
    if (indegree[i] != 0) assert(false);
  }
  ans.first--;
  cout << ans.first / m + 1 << ' ' << ans.first % m + 1 << ' ' << ans.second
       << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long testcase = 1;
  if (tests) cin >> testcase;
  cout << fixed << setprecision(10);
  for (long long test = 1; test <= testcase; test++) {
    solve_case();
  }
  return 0;
}
