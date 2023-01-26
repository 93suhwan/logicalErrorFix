#include <bits/stdc++.h>
using namespace std;
int ans[200005];
void solve() {
  int n, k;
  cin >> n >> k;
  int ar[n];
  map<int, vector<int>> mp;
  memset(ans, 0, sizeof(ans));
  for (int i = 0; i < n; i++) {
    cin >> ar[i];
    if (mp[ar[i]].size() < k) {
      mp[ar[i]].push_back(i);
    }
  }
  int tem = 0;
  for (auto a : mp) {
    tem += a.second.size();
  }
  tem = tem - (tem % k);
  int c = 0;
  bool flag = false;
  for (auto a : mp) {
    for (auto b : a.second) {
      c++;
      ans[b] = c;
      c = c % k;
      tem--;
      if (tem == 0) {
        flag = true;
        break;
      }
    }
    if (flag) break;
  }
  for (int i = 0; i < n; i++) cout << ans[i] << " ";
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
