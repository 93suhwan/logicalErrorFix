#include <bits/stdc++.h>
using namespace std;
const int M = (1 << 13);
int ans[M], ctr[M];
vector<int> g[M];
int main(int argc, char* argv[]) {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  for (int k = 0; k < M; ++k) {
    g[k].clear();
    g[k].push_back(0);
  }
  memset(ans, 0, sizeof(ans));
  for (int k = 0; k < M; ++k) ctr[k] = M - 1;
  int n, v;
  cin >> n;
  ans[0] = 1;
  for (int i = 0; i < n; ++i) {
    cin >> v;
    for (auto& u : g[v]) {
      int o = u xor v;
      ans[o] = 1;
      while (ctr[o] > v) {
        g[ctr[o]].push_back(o);
        ctr[o]--;
      }
    }
    g[v].clear();
  }
  int s = accumulate(ans, ans + M, 0);
  cout << s << endl;
  for (int i = 0; i < M; ++i)
    if (ans[i]) cout << i << ' ';
  cout << endl;
  return 0;
}
