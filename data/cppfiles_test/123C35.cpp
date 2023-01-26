#include <bits/stdc++.h>
using namespace std;
mt19937_64 hua(time(0));
template <typename T>
bool chkmx(T &x, T y) {
  return x < y ? x = y, true : false;
}
template <typename T>
bool chkmn(T &x, T y) {
  return x > y ? x = y, true : false;
}
template <int T>
using A = array<int, T>;
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = 0;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
  return f ? x : -x;
}
const long long inf = 1e18;
const int maxn = 2e5;
int n, k, len[maxn + 5], son[maxn + 5], ans[maxn + 5];
vector<int> G[maxn + 5], s;
void dfs(int u, int par) {
  for (auto v : G[u])
    if (v != par) {
      dfs(v, u);
      if (chkmx(len[u], len[v] + 1)) son[u] = v;
    }
  for (auto v : G[u])
    if (v != par && v != son[u]) s.push_back(len[v] + 1);
}
int main() {
  n = read(), k = read();
  for (int i = (2); i <= int(n); i++) {
    int u = read(), v = read();
    G[u].push_back(v), G[v].push_back(u);
  }
  dfs(1, 1);
  s.push_back(len[1] + 1);
  sort(s.begin(), s.end()), reverse(s.begin(), s.end());
  for (int i = (1); i <= int((int)(s.size())); i++) {
    ans[i] = ans[i - 1] + s[i - 1];
  }
  for (int i = ((int)(s.size()) + 1); i <= int(n); i++) ans[i] = ans[i - 1];
  long long mx = -inf;
  for (int i = (0); i <= int(k); i++) {
    int all = n - i, mxb = n - ans[i];
    if (i - mxb < 0) {
      int mid = all + i >> 1;
      if (mid <= mxb)
        chkmx(mx, 1ll * (all - mid) * (i - mid));
      else
        chkmx(mx, 1ll * (all - mxb) * (i - mxb));
    } else
      chkmx(mx, 1ll * (i - mxb) * (all - mxb));
  }
  cout << mx << '\n';
  return 0;
}
