#include <bits/stdc++.h>
using namespace std;
const int N = (1 << 13);
int ne[N + 1];
vector<int> g[N + 1];
bool ans[N + 1];
int main() {
  for (int i = 1; i < N; i++) g[i].push_back(0);
  ans[0] = 1;
  for (int i = 0; i < N; i++) ne[i] = (1 << 13);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    for (auto j : g[x]) {
      int now = (x ^ j);
      ans[now] = true;
      while (ne[now] > now) {
        g[ne[now]].push_back(now);
        ne[now]--;
      }
    }
    g[x] = {};
  }
  int res = 0;
  for (int i = 0; i < N; i++) res += ans[i];
  cout << res << endl;
  for (int i = 0; i < N; i++)
    if (ans[i]) cout << i << " ";
}
