#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  for (int i = 0, j = 0; i < v.size(); i++, j++)
    if (j >= 5) {
      j = 0;
      puts("");
    } else
      os << v[i] << " ";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& v) {
  for (auto c : v) os << c << " ";
  return os;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& os, const map<T1, T2>& v) {
  for (auto c : v) os << c.first << " " << c.second << '\n';
  return os;
}
template <typename T>
inline void rd(T& a) {
  char c = getchar();
  T x = 0, f = 1;
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 1) + (x << 3) + c - '0';
    c = getchar();
  }
  a = f * x;
}
const int N = 1e5 + 10, M = 1e9 + 7;
long long n, m, _;
int h[N], e[N * 2], ne[N * 2], idx;
int fa[N];
int find(int x) { return x == fa[x] ? fa[x] : fa[x] = find(fa[x]); }
void add(int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; }
void dfs(int u, int fa) {
  for (int i = h[u]; ~i; i = ne[i]) {
    int j = e[i];
    if (j == fa) continue;
    cout << u << " " << j << '\n';
    dfs(j, u);
  }
}
void solve() {
  memset(h, -1, sizeof(h));
  idx = 0;
  int cnt = 0;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) fa[i] = i;
  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (cnt == n - 1) continue;
    int pa = find(a), push_back = find(b), pc = find(c);
    cnt++;
    add(a, c);
    if (pa != pc) {
      fa[pc] = pa;
    }
    if (cnt == n - 1) continue;
    if (pa != push_back) {
      fa[push_back] = pa;
      cnt++;
      add(a, b);
      if (cnt == n - 1) continue;
    }
  }
  dfs(1, -1);
}
int main() {
  cin >> _;
  while (_--) {
    solve();
  }
  return 0;
}
