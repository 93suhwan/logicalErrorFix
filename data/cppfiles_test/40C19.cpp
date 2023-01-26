#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
template <typename T>
void read(T &x) {
  x = 0;
  char ch = getchar();
  long long f = 1;
  while (!isdigit(ch)) {
    if (ch == '-') f *= -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  x *= f;
}
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
bool vis[300010];
vector<int> e[300010];
int cnt[300010];
pair<int, int> fk[300010];
int fa[300010], dep[300010];
void dfs(int);
void go(int, int);
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;
  while (m--) {
    int x, y;
    cin >> x >> y;
    e[x].push_back(y);
    e[y].push_back(x);
  }
  int q;
  cin >> q;
  for (int i = 1; i <= q; ++i) {
    int x, y;
    cin >> x >> y;
    fk[i] = {x, y};
    cnt[x] ^= 1;
    cnt[y] ^= 1;
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) ans += cnt[i];
  if (ans) {
    cout << "NO\n";
    cout << ans / 2;
    return 0;
  }
  cout << "YES\n";
  vis[1] = true;
  dfs(1);
  for (int i = 1; i <= q; ++i) {
    auto [x, y] = fk[i];
    go(x, y);
  }
  return 0;
}
void dfs(int x) {
  for (auto v : e[x]) {
    if (vis[v]) continue;
    fa[v] = x;
    dep[v] = dep[x] + 1;
    vis[v] = true;
    dfs(v);
  }
}
void go(int x, int y) {
  vector<int> a, b;
  while (y != x) {
    if (dep[x] > dep[y]) {
      a.push_back(x);
      x = fa[x];
    } else {
      b.push_back(y);
      y = fa[y];
    }
  }
  reverse(b.begin(), b.end());
  cout << a.size() + b.size() + 1 << '\n';
  for (auto v : a) cout << v << ' ';
  cout << x << ' ';
  for (auto v : b) cout << v << ' ';
  cout << '\n';
}
