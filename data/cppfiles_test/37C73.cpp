#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> adjList[300005];
vector<int> visited(300005);
vector<int> a(300005);
vector<long long> f(300005);
vector<long long> twoPowers(300005);
long long mod = 998244353;
vector<long long> ans(300005);
int dfs(int node, int goal) {
  visited[node] = 1;
  int accrued = 0;
  for (int i = 0; i < adjList[node].size(); i++) {
    int child = adjList[node][i];
    if (!visited[child]) {
      int au = dfs(child, goal);
      if (au == -1) return -1;
      accrued += au;
    }
  }
  int toReturn = 1;
  if (accrued % goal == 0)
    toReturn = 1;
  else if ((accrued + 1) % goal == 0)
    toReturn = 0;
  else
    toReturn = -1;
  return toReturn;
}
int main() {
  iostream::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  twoPowers[0] = 1;
  for (int i = 1; i < 300005; i++) {
    twoPowers[i] = (twoPowers[i - 1] * 2) % mod;
  }
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n + 1; i++) {
      vector<int> v;
      adjList[i] = v;
      f[i] = 0;
      ans[i] = 0;
    }
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      adjList[u].push_back(v);
      adjList[v].push_back(u);
    }
    f[1] = twoPowers[n - 1];
    for (int i = 2; i <= n - 1; i++) {
      if ((n - 1) % i == 0) {
        for (int j = 0; j <= n; j++) {
          visited[j] = 0;
          a[j] = 0;
        }
        int res = dfs(0, i);
        if (res == 1) f[i] = 1;
      }
    }
    for (int i = n - 1; i >= 1; i--) {
      ans[i] = f[i];
      for (int j = 2; j * i <= n - 1; j++) ans[i] = ans[i] - ans[j * i];
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << endl;
  }
}
