#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long maxn = 1 << 13;
vector<long long> mprime;
vector<long long> arr, brr;
int n, cur;
vector<vector<int>> ps(maxn);
vector<long long> mx(maxn), flag(maxn);
int ans = 0;
void solve() {
  cin >> n;
  for (int i = 0; i < maxn; i++) {
    ps[i].push_back(0);
    mx[i] = maxn;
  }
  flag[0] = 1;
  for (int i = 0; i < n; i++) {
    cin >> cur;
    for (int j : ps[cur]) {
      int k = j ^ cur;
      flag[k] = 1;
      while (mx[k] > cur) {
        mx[k]--;
        if (mx[k] != cur) {
          ps[mx[k]].push_back(k);
        }
      }
    }
    ps[cur].clear();
  }
  for (int i = 0; i < maxn; i++) ans += flag[i];
  cout << ans << endl;
  for (int i = 0; i < maxn; i++)
    if (flag[i]) cout << i << " ";
  cout << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout.precision(10);
  cout << fixed;
  solve();
  return 0;
}
