#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;
const long long int INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e5 + 7;
const int N = 1e6 + 10;
const int M = 1e5 + 10;
int n, m;
vector<int> e[N];
int ans;
int dfs(int x, int fa) {
  int now = 0;
  for (auto it : e[x]) {
    if (it == fa) continue;
    now += dfs(it, x);
  }
  if (now == 0)
    return 1;
  else {
    ans += (now - 1);
    return 0;
  }
}
void run() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    e[x].push_back(y);
    e[y].push_back(x);
  }
  dfs(1, 0);
  printf("%d\n", ans + 1);
  for (int i = 1; i <= n; i++) e[i].clear();
  ans = 0;
}
int main() {
  int T;
  cin >> T;
  while (T--) run();
  return 0;
}
