#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
const int lim = 1e5;
int n, x, dr[(1 << 14)], ans[(1 << 14)];
vector<int> v[(1 << 14)];
int main() {
  cin >> n;
  for (int i = 0; i < (1 << 13); i++) v[i].push_back(0);
  for (int i = 0; i < (1 << 13); i++) dr[i] = (1 << 13);
  dr[0] = 0;
  ans[0] = 1;
  int j;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    for (auto it : v[x]) {
      if (dr[it ^ x] < x) continue;
      for (j = x + 1; j <= dr[it ^ x]; ++j) v[j].push_back(it ^ x);
      ans[it ^ x] = 1;
      dr[it ^ x] = x;
    }
    v[x].clear();
  }
  int cnt = 0;
  for (int i = 0; i < (1 << 13); i++)
    if (ans[i]) cnt++;
  cout << cnt << "\n";
  for (int i = 0; i < (1 << 13); i++)
    if (ans[i]) cout << i << " ";
  return 0;
}
