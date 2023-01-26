#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
vector<vector<int>> adj;
void solve() {
  int n;
  cin >> n;
  vector<vector<int>> adj = vector<vector<int>>(n);
  vector<int> arr(n), ans(n, -1), cnt(n, 0);
  deque<int> dq;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    for (int j = 0; j < arr[i]; j++) {
      int tmp;
      cin >> tmp;
      adj[tmp - 1].push_back(i);
    }
    if (!arr[i]) {
      dq.push_back(i);
      ans[i] = 1;
    }
  }
  while (!dq.empty()) {
    int tmp = dq.front();
    dq.pop_front();
    for (auto it : adj[tmp]) {
      if (it < tmp)
        ans[it] = max(ans[it], ans[tmp] + 1);
      else
        ans[it] = max(ans[it], ans[tmp]);
      cnt[it]++;
      if (cnt[it] == arr[it]) dq.push_back(it);
    }
  }
  for (int i = 0; i < n; i++)
    if (cnt[i] < arr[i]) {
      cout << -1 << '\n';
      return;
    }
  int maxx = -1;
  for (auto it : ans) maxx = max(maxx, it);
  cout << maxx << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
