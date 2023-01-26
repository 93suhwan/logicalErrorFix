#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
template <class T>
void _R(T &x) {
  cin >> x;
}
void _R(int &x) { cin >> x; }
void _R(int64_t &x) { cin >> x; }
void _R(double &x) { cin >> x; }
void _R(long double &x) { cin >> x; }
void _R(char &x) { cin >> x; }
void _R(char *x) { cin >> x; }
void _R(string &x) { cin >> x; }
void R() {}
template <class T, class... U>
void R(T &head, U &...tail) {
  _R(head);
  R(tail...);
}
template <class T>
void _W(const T &x) {
  cout << x;
}
void _W(const int &x) { cout << x; }
void _W(const int64_t &x) { cout << x; }
void _W(const double &x) { cout << fixed << setprecision(8) << x; }
void _W(const long double &x) { cout << fixed << setprecision(16) << x; }
void _W(const char &x) { cout << x; }
void _W(const char *x) { cout << x; }
void _W(const string &x) { cout << x; }
template <class T, class U>
void _W(const pair<T, U> &x) {
  _W(x.first);
  cout << ' ';
  _W(x.second);
}
template <class T>
void _W(const vector<T> &x) {
  for (auto i = x.begin(); i != x.end(); _W(*i++))
    if (i != x.cbegin()) cout << ' ';
}
void W() {}
template <class T, class... U>
void W(const T &head, const U &...tail) {
  _W(head);
  cout << (sizeof...(tail) ? ' ' : '\n');
  W(tail...);
}
void solve_pre() {}
int MULTITEST = 0;
int n;
vector<int> a;
unordered_map<int, set<int>> g;
unordered_map<int, int> visited;
void solve() {
  R(n);
  a.resize(n);
  for (int i = (0); i < (n); i++) {
    R(a[i]);
  }
  for (auto num : a) {
    while (num > 0) {
      if ((num & (num - 1)) == 0) {
        g[0].insert(num);
        g[num].insert(0);
        num = 0;
      } else {
        int k = 8 * sizeof(int) - __builtin_clz(num);
        g[(1 << k) - num].insert(num);
        g[num].insert((1 << k) - num);
        num = (1 << k) - num;
      }
    }
  }
  visited.clear();
  queue<int> q;
  q.push(a[0]);
  visited[a[0]] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto &nv : g[u]) {
      if (visited.find(nv) == visited.end()) {
        q.push(nv);
        visited[nv] = 1 + visited[u];
      }
    }
  }
  int A = a[0];
  for (auto &x : visited) {
    if (g.find(x.first) != g.end() && x.second > visited[A]) {
      A = x.first;
    }
  }
  visited.clear();
  q.push(A);
  visited[A] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto &nv : g[u]) {
      if (visited.find(nv) == visited.end()) {
        q.push(nv);
        visited[nv] = 1 + visited[u];
      }
    }
  }
  int d = 0;
  for (auto &x : visited) {
    d = max(d, x.second);
  }
  int B = -1;
  for (auto &x : visited) {
    if (x.second == d && g.find(x.first) != g.end()) {
      B = x.first;
    }
  }
  int x = -1, y = -1;
  for (int i = 1; i <= n; i++) {
    if (a[i - 1] == A) x = i;
    if (a[i - 1] == B) y = i;
  }
  if (x > y) swap(x, y);
  W(x, y, d);
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve_pre();
  if (MULTITEST) {
    int t;
    R(t);
    for (int testcase = 1; testcase <= t; testcase++) {
      solve();
    }
  } else {
    solve();
  }
  return 0;
}
