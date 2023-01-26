#include <bits/stdc++.h>
using namespace std;
std::mt19937 rnd(
    (int)std::chrono::steady_clock::now().time_since_epoch().count());
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const int MAXN = 300000;
struct E {
  int to, pos, id;
  E(int to, int pos, int id) : to(to), pos(pos), id(id) {}
};
int n;
int a[MAXN];
int ans[MAXN];
bool have[MAXN];
vector<E> adj[MAXN];
bool been[MAXN];
void dfs(int at) {
  if (been[at]) return;
  been[at] = true;
  for (int i = (0); i < (((int)(adj[at]).size())); ++i) {
    int to = adj[at][i].to, pos = adj[at][i].pos;
    if (!have[to]) {
      ans[pos] = to;
      have[to] = true;
    }
    dfs(to);
  }
}
int parid[MAXN];
int dfscycle(int at) {
  if (been[at]) return at;
  been[at] = true;
  for (int i = (0); i < (((int)(adj[at]).size())); ++i) {
    int to = adj[at][i].to, pos = adj[at][i].pos, id = adj[at][i].id;
    if (id == parid[at]) continue;
    parid[to] = id;
    int sub = dfscycle(to);
    if (sub == -1) return -1;
    if (sub >= 0) {
      ans[pos] = to;
      have[to] = true;
      return sub == at ? -1 : sub;
    }
  }
  return -2;
}
void solve() {
  for (int i = (0); i < (n); ++i) have[i] = false;
  for (int i = (0); i < (n - 1); ++i)
    if (a[i] != -1 && a[i + 1] != -1 && a[i + 1] == a[i]) have[a[i]] = true;
  for (int i = (0); i < (n); ++i) ans[i] = a[i];
  int m = 0;
  for (int l = 0, r = l; l < n; l = r) {
    while (r < n && a[r] == -1) ++r;
    int cnt = r - l;
    if (cnt == 0) {
      ++r;
      continue;
    }
    if (cnt % 2 == 0) continue;
    if (l == 0) {
      if (r < n) ans[r - 1] = a[r], have[a[r]] = true;
      continue;
    }
    if (r == n) {
      if (l - 1 >= 0) ans[l] = a[l - 1], have[a[l - 1]] = true;
      continue;
    }
    int x = a[l - 1], y = a[r];
    adj[x].push_back(E(y, r - 1, m));
    adj[y].push_back(E(x, l, m));
    ++m;
  }
  for (int i = (0); i < (n); ++i) been[i] = false;
  for (int i = (0); i < (n); ++i)
    if (!been[i] && have[i]) dfs(i);
  for (int i = (0); i < (n); ++i)
    if (!been[i]) {
      parid[i] = -1;
      dfscycle(i);
    }
  for (int i = (0); i < (n); ++i)
    if (!been[i] && have[i]) dfs(i);
  for (int i = (0); i < (n); ++i)
    if (!been[i]) dfs(i);
  int nxt = 0;
  for (int l = 0, r = l; l < n; l = r) {
    while (r < n && a[r] == -1) ++r;
    int cnt = r - l;
    if (cnt == 0) {
      ++r;
      continue;
    }
    for (int i = (0); i < (cnt / 2); ++i) {
      while (have[nxt]) ++nxt;
      have[nxt] = true;
      ans[l + 2 * i] = ans[l + 2 * i + 1] = nxt;
    }
  }
  for (int i = (0); i < (n); ++i)
    if (ans[i] == -1) ans[i] = n - 1;
}
void run() {
  scanf("%d", &n);
  for (int i = (0); i < (n); ++i) scanf("%d", &a[i]), --a[i];
  solve();
  for (int i = (0); i < (n); ++i) {
    if (i != 0) printf(" ");
    printf("%d", ans[i] + 1);
  }
  puts("");
}
int main() {
  run();
  return 0;
}
