#include <bits/stdc++.h>
using namespace std;
void main0();
int main() {
  clock_t start, end;
  ios::sync_with_stdio(false);
  cin.tie(0);
  main0();
  return 0;
}
const int dx[8] = {0, 1, -1, 0, 1, 1, -1, -1};
const int dy[8] = {1, 0, 0, -1, 1, -1, -1, 1};
const int N = 2e5 + 5;
const int M = 1e5;
const int B = 300;
const int INF = 0x3f3f3f3f;
const long long INFF = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const double eps = 1e-6;
mt19937 rnd(
    (unsigned int)chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
bool chkmin(T &x, T y) {
  return y < x ? x = y, 1 : 0;
}
template <typename T>
bool chkmax(T &x, T y) {
  return y > x ? x = y, 1 : 0;
}
int n, m;
int a[N];
int pre[N], nxt[N];
int preB[N], nxtB[N];
int jump(int type, int u, int k) {
  if (type)
    while (k >= B) u = nxtB[u], k -= B;
  while (k) u = nxt[u], k--;
  return u;
}
void update(int u) {
  int v = jump(0, u, B);
  for (int i = 0; i <= B; ++i, u = pre[u], v = pre[v]) {
    preB[v] = u;
    nxtB[u] = v;
  }
}
void main0() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> nxt[i];
    pre[nxt[i]] = i;
  }
  for (int u = 1; u <= n; ++u) {
    int v = jump(0, u, B);
    preB[v] = u;
    nxtB[u] = v;
  }
  for (int i = 1; i <= m; ++i) {
    int op;
    cin >> op;
    if (op == 1) {
      int u, v;
      cin >> u >> v;
      pre[nxt[u]] = v;
      pre[nxt[v]] = u;
      swap(nxt[u], nxt[v]);
      update(u);
      update(v);
    }
    if (op == 2) {
      int u, k;
      cin >> u >> k;
      cout << jump(1, u, k) << endl;
    }
  }
}
