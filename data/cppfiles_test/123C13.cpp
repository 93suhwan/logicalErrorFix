#include <bits/stdc++.h>
using namespace std;
template <class T>
bool uin(T &a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
bool uax(T &a, T b) {
  return a < b ? (a = b, true) : false;
}
const int maxn = 210000;
vector<int> e[maxn];
int h[maxn];
void dfsh(int v, int p) {
  h[v] = 0;
  for (int u : e[v]) {
    if (u == p) continue;
    dfsh(u, v);
    uax(h[v], h[u] + 1);
  }
  sort((e[v]).begin(), (e[v]).end(), [&](int u, int w) { return h[u] > h[w]; });
}
vector<int> ord;
void dfsord(int v, int p, int l) {
  bool anyc = false;
  for (int u : e[v]) {
    if (u == p) continue;
    if (!anyc)
      dfsord(u, v, l + 1), anyc = true;
    else
      dfsord(u, v, 1);
  }
  int r = !anyc ? l : 0;
  ord.push_back(r);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(10);
  cout << fixed;
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < (int)(n - 1); ++i) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  dfsh(0, -1);
  dfsord(0, -1, 1);
  sort((ord).rbegin(), (ord).rend());
  long long W = n;
  long long ans = -1LL * (n / 2) * (n - n / 2);
  for (int i = 0; i < (int)(k); ++i) {
    W -= ord[i];
    long long b = n / 2, r = i + 1;
    long long res = 1e18;
    if (b <= W) uin(res, (n - r - b) * (r - b));
    if (b + 1 <= W) uin(res, (n - r - b - 1) * (r - b - 1));
    uin(res, (n - r - W) * (r - W));
    uax(ans, res);
  }
  cout << ans << '\n';
  return 0;
}
