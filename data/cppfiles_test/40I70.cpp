#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
static inline void amin(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
static inline void amax(T &x, U y) {
  if (x < y) x = y;
}
template <typename T>
static inline void sd(vector<T> &x) {
  sort((x).begin(), (x).end(), greater<T>());
}
long long n, m;
const long long N = 3e5 + 5;
vector<long long> g[N];
vector<long long> dep(N), parent(N), vis(N);
void dfs(long long v, long long par = -1) {
  vis[v] = 1;
  for (long long ch : g[v]) {
    if (ch != par and !vis[ch]) {
      dep[ch] = dep[v] + 1;
      parent[ch] = v;
      dfs(ch, v);
    }
  }
}
void solve() {
  cin >> n >> m;
  for (long long i = 0; i < n + 1; ++i) {
    g[i].clear();
    vis[i] = 0;
  }
  auto path = [&](long long a, long long b) {
    if (dep[a] < dep[b]) swap(a, b);
    vector<long long> v[2];
    while (dep[a] > dep[b]) {
      v[0].push_back(a);
      a = parent[a];
    }
    while (a != b) {
      v[0].push_back(a);
      v[1].push_back(b);
      a = parent[a];
      b = parent[b];
    }
    v[0].push_back(a);
    while (!v[1].empty()) {
      v[0].push_back(v[1].back());
      v[1].pop_back();
    }
    return v[0];
  };
  vector<long long> cnt(n + 1);
  for (long long i = 0; i < m; ++i) {
    long long e, f;
    cin >> e >> f;
    g[e].push_back(f);
    g[f].push_back(e);
  }
  dfs(1);
  vector<vector<long long> > output;
  long long q;
  cin >> q;
  for (long long j = 0; j < q; ++j) {
    long long a, b;
    cin >> a >> b;
    cnt[a]++;
    cnt[b]++;
    output.push_back(path(a, b));
  }
  long long k = 0;
  for (long long i = 1; i < n + 1; ++i) {
    if ((cnt[i] & 1) == 1) {
      k++;
    }
  }
  if (k == 0) {
    cout << "YES\n";
    for (auto &i : output) {
      cout << i.size() << '\n';
      for (long long j : i) {
        cout << j << " ";
      }
      cout << '\n';
    }
  } else {
    cout << "NO\n";
    cout << k / 2 << '\n';
  }
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long testcases = 1;
  while (testcases--) {
    solve();
  }
  return 0;
}
