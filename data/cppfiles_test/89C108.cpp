#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
using pii = pair<int, int>;
using vec = vector<int>;
using veg = vector<pii>;
int read() {
  int x = 0;
  bool f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = x * 10 + (ch ^ 48), ch = getchar();
  return f ? -x : x;
}
const int N = 2e5 + 10;
int n, tp[N];
vec G[N];
void dfs(int x, int p) {
  bool fl = 0;
  for (int y : G[x])
    if (y ^ p) {
      dfs(y, x);
      fl |= tp[y] == 1;
    }
  if (x == 1)
    tp[x] = 0;
  else {
    if (fl)
      tp[x] = 2;
    else
      tp[x] = 1;
  }
}
void solve() {
  n = read();
  for (int i = (2); i <= (n); i++) {
    int x = read(), y = read();
    G[x].push_back(y), G[y].push_back(x);
  }
  dfs(1, 0);
  bool fl = 0;
  for (auto y : G[1])
    if (tp[y] == 1) fl = true;
  int cnt = 0;
  for (int i = (1); i <= (n); i++) cnt += tp[i] == 2;
  cout << n - cnt * 2 - fl << endl;
  for (int i = (1); i <= (n); i++) vec().swap(G[i]);
}
int main() {
  for (int T = read(); T; T--) solve();
  return 0;
}
