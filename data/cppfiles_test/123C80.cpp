#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T>
void read(T &x) {
  char ch;
  x = 0;
  int f = 1;
  while (isspace(ch = getchar_unlocked()))
    ;
  if (ch == '-') ch = getchar_unlocked(), f = -1;
  do x = x * 10 + (ch - '0');
  while (isdigit(ch = getchar_unlocked()));
  x *= f;
}
template <class T, class... A>
void read(T &x, A &...args) {
  read(x);
  read(args...);
}
const int N = 200005;
vector<int> G[N];
int len[N];
vector<int> chain;
void DFS(int u, int fa = 0) {
  int son = 0;
  len[u] = 1;
  for (int v : G[u]) {
    if (v == fa) continue;
    DFS(v, u);
    len[u] = max(len[u], len[v] + 1);
    if (!son || len[v] > len[son]) son = v;
  }
  for (int v : G[u])
    if (v != fa && v != son) chain.push_back(len[v]);
}
int main() {
  int n, k;
  read(n, k);
  for (int i = 1; i < n; ++i) {
    int u, v;
    read(u, v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  DFS(1);
  chain.push_back(len[1]);
  sort(begin(chain), end(chain), greater<int>());
  ll ans = -ll(n - n / 2) * (n / 2);
  int fre = n;
  for (int i = 1; i <= k; ++i) {
    if (i <= (int)chain.size()) fre -= chain[i - 1];
    int b = min(n / 2, fre);
    ans = max(ans, ll(i - b) * (n - i - b));
  }
  printf("%lld\n", ans);
  return 0;
}
