#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long inf = 1e18;
const int inf2 = 1e9;
vector<int> v[200005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int t = 1;
  cin >> t;
  while (t--) {
    int n, i, j, k;
    cin >> n >> k;
    int ans[n], x;
    vector<int> ind;
    memset(ans, 0, sizeof ans);
    for (i = 0; i < n; i++) {
      cin >> x;
      v[x].push_back(i);
    }
    for (i = 1; i <= 200000; i++) {
      if ((int)v[i].size() >= k) {
        int now = 1;
        for (j = 0; j < v[i].size(); j++) {
          ans[v[i][j]] = now;
          now++;
          if (now > k) break;
        }
      } else {
        for (j = 0; j < (int)v[i].size(); j++) {
          ind.push_back(v[i][j]);
        }
      }
      v[i].clear();
    }
    int sz = ind.size();
    j = 0;
    int now = 1;
    for (; j < (int)ind.size(); j++) {
      if (sz < k) break;
      ans[ind[j]] = now;
      now++;
      if (now > k) {
        sz -= k;
        now = 1;
      }
    }
    for (i = 0; i < n; i++) cout << ans[i] << " ";
    cout << '\n';
  }
  return 0;
}
