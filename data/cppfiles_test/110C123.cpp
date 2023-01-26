#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
void init() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
inline int read() {
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
  return x * f;
}
void write(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
  return;
}
int deep[maxn], k[maxn];
signed main() {
  init();
  int t;
  cin >> t;
  int n;
  while (t--) {
    cin >> n;
    memset(deep, 0, 4 * (n + 1));
    vector<vector<int> > vec(n + 1);
    int x;
    int res = 0;
    queue<int> que;
    for (int i = 1; i <= n; i++) {
      cin >> k[i];
      if (k[i] == 0) {
        que.push(i);
        deep[i] = 1;
        res = 1;
      }
      for (int j = 1; j <= k[i]; j++) {
        cin >> x;
        vec[x].push_back(i);
      }
    }
    while (!que.empty()) {
      int p = que.front();
      que.pop();
      for (int i = 0; i < vec[p].size(); i++) {
        int son = vec[p][i];
        if (k[son] != 0) {
          if (son > p) {
            deep[son] = max(deep[son], deep[p]);
          } else {
            deep[son] = max(deep[son], deep[p] + 1);
          }
          res = max(res, deep[son]);
          k[son]--;
          if (k[son] == 0) {
            que.push(son);
          }
        }
      }
    }
    if (count(k + 1, k + n + 1, 0) != n) {
      cout << -1 << '\n';
    } else {
      cout << res << '\n';
    }
  }
}
