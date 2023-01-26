#include <bits/stdc++.h>
using namespace std;
const int maxn = 9000;
vector<int> vec[maxn];
int r[maxn], ans[maxn];
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < maxn; i++) vec[i].push_back(0), r[i] = maxn;
  ans[0] = 1;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    for (auto& j : vec[x]) {
      int to = j ^ x;
      ans[to] = 1;
      while (r[to] > x) {
        r[to]--;
        if (r[to] != x) {
          vec[r[to]].push_back(to);
        }
      }
    }
    vec[x].clear();
  }
  int res = 0;
  for (int i = 0; i < maxn; i++)
    if (ans[i]) res++;
  cout << res << '\n';
  for (int i = 0; i < maxn; i++)
    if (ans[i]) cout << i << ' ';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
}
