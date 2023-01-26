#include <bits/stdc++.h>
namespace lyc {
using namespace std;
template <typename T>
inline void read(T& res) {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  res = x * f;
  return;
}
template <typename T>
inline void print(T x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) print(x / 10);
  putchar(x % 10 + '0');
}
const int mod = 1e9 + 7;
const int N = 200010;
void sol() {
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int ans = 0;
  function<int(int, int)> dfs = [&](int u, int fa) {
    int s = 0;
    for (int v : g[u]) {
      if (v == fa) {
        continue;
      }
      s += dfs(v, u);
    }
    if (s == 0) return 1;
    ans++;
    return 0;
  };
  int rt = dfs(0, -1);
  if (rt == 0)
    cout << n - 2 * ans + 1 << "\n";
  else
    cout << n - ans * 2 << "\n";
}
signed main() {
  int v_v = 1;
  cin >> v_v;
  while (v_v--) sol();
  return 0;
}
}  // namespace lyc
int main() {
  lyc::main();
  return 0;
}
