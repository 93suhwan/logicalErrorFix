#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e+16;
const int SMALL_INF = 1998244353;
const int NSIZE = 4 * 1e+5 + 1000;
const long long MOD = 998244353;
const long double EPS = 1e-12;
const int MAX = 1e+6 + 1000;
const long double PI = atan(1) * 4;
const long long HZ = -1692281337;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> xpos(10001, SMALL_INF);
  xpos[0] = -1;
  vector<vector<int> > apos(5001);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    apos[a].push_back(i);
  }
  for (int i = 0; i <= 5000; i++) {
    if (apos[i].empty()) continue;
    for (int j = 0; j <= 10000; j++) {
      if ((i ^ j) <= 10000 && xpos[i ^ j] < apos[i].back()) {
        xpos[j] = min(
            xpos[j], *upper_bound(apos[i].begin(), apos[i].end(), xpos[i ^ j]));
      }
    }
  }
  vector<int> ans;
  for (int i = 0; i <= 10000; i++) {
    if (xpos[i] != SMALL_INF) ans.push_back(i);
  }
  cout << ans.size() << '\n';
  for (auto i : ans) cout << i << " ";
}
