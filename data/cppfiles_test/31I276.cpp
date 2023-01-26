#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int MOD = 1000000007;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    map<int, vector<int>> pos;
    vector<int> ans(n);
    vector<int> ar(n);
    stack<int> own;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      ar[i] = x;
      if (i > 1)
        pos[x].push_back(i);
      else
        own.push(i);
    }
    for (auto [_, b] : pos) {
      if (b.size() == 1)
        own.push(b[0]);
      else {
        int cnt = b.size() / 2;
        for (int i = 0; i < cnt; i++) ans[b[i]]++;
        for (int i = cnt; i < b.size(); i++) ans[b[i]]--;
        ans[b[0]] += b.size() % 2;
      }
    }
    while (own.size() >= 2 && own.size() - 2 != 1) {
      int x = own.top();
      own.pop();
      int y = own.top();
      own.pop();
      ans[x] = ar[y];
      ans[y] = -ar[x];
    }
    if (own.size()) {
      int x = own.top();
      own.pop();
      int y = own.top();
      own.pop();
      int z = own.top();
      own.pop();
      ans[x] = ar[z];
      ans[y] = ar[z];
      ans[z] = -ar[x] - ar[y];
    }
    for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n - 1];
  }
}
