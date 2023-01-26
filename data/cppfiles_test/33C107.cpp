#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")
using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<long long>;
using vpii = vector<pair<int, int>>;
using vvb = vector<vector<bool>>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<long long>>;
using vvpii = vector<vector<pair<int, int>>>;
using mii = map<int, int>;
using umii = unordered_map<int, int>;
using seti = set<int>;
using useti = unordered_set<int>;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vb res(8200);
  vvi store(8200, vi(1, 0));
  vvb seen(8200, vb(8200));
  res[0] = 1;
  for (int i = 0; i < (8200); i++) seen[i][0] = true;
  for (int i = 0; i < (n); i++) {
    int x;
    cin >> x;
    for (auto d : store[x]) {
      int y = d ^ x;
      res[y] = true;
      for (int j = x + 1; j < 8200; j++)
        if (!seen[j][y]) {
          seen[j][y] = true;
          store[j].push_back(y);
        } else
          break;
    }
    store[x].clear();
  }
  int ans = 0;
  for (int i = 0; i < (8200); i++) ans += res[i];
  cout << ans << "\n";
  for (int i = 0; i < (8200); i++)
    if (res[i]) cout << i << " ";
  cout << "\n";
}
