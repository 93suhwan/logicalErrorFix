#include <bits/stdc++.h>
constexpr int maxn = 20, maxm = 4e5 + 10, inf = 0x3f3f3f3f;
char str[maxn][maxm];
int n, cnt[maxn][maxm], L[maxn], R[maxn];
void init(const int id) {
  std::stack<char> stk;
  const auto len = (int)std::strlen(str[id] + 1);
  for (auto lim_i = len, i = 1; i <= lim_i; i++) {
    const auto c = str[id][i];
    if (c == '(')
      stk.push(c);
    else if (c == ')') {
      if (!stk.empty() && stk.top() == '(')
        stk.pop();
      else
        stk.push(c);
    }
    if (stk.empty() || stk.top() == ')') cnt[id][stk.size()]++;
  }
  while (!stk.empty()) {
    const auto c = stk.top();
    stk.pop();
    if (c == ')')
      L[id]++;
    else
      R[id]++;
  }
}
struct status {
  int rem = -inf, v;
} f[1 << maxn];
bool vis[1 << maxn];
void solve() {
  std::cin >> n;
  for (auto lim_i = n - 1, i = 0; i <= lim_i; i++)
    std::cin >> (str[i] + 1), init(i);
  for (auto lim_i = n - 1, i = 0; i <= lim_i; i++)
    std::cerr << L[i] << " " << R[i] << "\n";
  std::queue<int> q;
  q.push(0);
  f[0].rem = 0;
  int ans = 0;
  while (!q.empty()) {
    const auto s = q.front();
    q.pop();
    ans = std::max(ans, f[s].v);
    for (auto lim_nxt = n - 1, nxt = 0; nxt <= lim_nxt; nxt++)
      if (!((s >> nxt) & 1)) {
        if (f[s].rem < L[nxt]) {
          const auto t = f[s].v + cnt[nxt][f[s].rem];
          ans = std::max(ans, t);
          continue;
        }
        const auto p = s | (1 << nxt);
        const auto r = f[s].rem - L[nxt] + R[nxt];
        f[p].rem = r;
        const auto t = f[s].v + cnt[nxt][f[s].rem];
        if (t > f[p].v) f[p].v = t;
        if (!vis[p]) {
          q.push(p);
          vis[p] = 1;
        }
      }
  }
  std::cout << ans << "\n";
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t = 1;
  for (auto REPN_lIM = t, REPN = 1; REPN <= REPN_lIM; REPN++) solve();
  return (0 - 0);
}
