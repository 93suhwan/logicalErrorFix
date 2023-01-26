#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int t;
int n;
int fa[N];
int x[N];
vector<int> c[N];
int sum;
int re;
void dfs(int i, int j) {
  if (x[i] == 1) {
    if (j == 1) re++;
    if (i != 1) return;
  }
  for (auto tp : c[i]) {
    if (tp == j) continue;
    dfs(tp, i);
  }
  if (i == 1) return;
  if (x[i] >= 3) {
    if (sum == 0)
      sum = 2;
    else
      sum++;
    x[j]--;
  } else if (x[i] == 2) {
    if (sum == 0) sum = 1;
    x[j]--;
  } else {
    if (j == 1) re++;
  }
}
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      x[i] = 0;
      fa[i] = 0;
      c[i].clear();
    }
    sum = 0;
    re = 0;
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      c[u].push_back(v);
      c[v].push_back(u);
      x[u]++;
      x[v]++;
    }
    if (n == 2) {
      cout << 1 << endl;
      continue;
    }
    dfs(1, 0);
    if (re >= 2) {
      if (sum == 0)
        sum = re;
      else
        sum = sum - re - 1;
    }
    cout << sum << endl;
  }
  return 0;
}
