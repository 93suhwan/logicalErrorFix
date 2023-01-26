#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<long long int> a(n);
  vector<long long int> mp(n + 1, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mp[a[i]]++;
  }
  vector<long long int> ans(n + 1);
  priority_queue<pair<long long, long long>> pq;
  long long cost = 0;
  for (int i = 0; i < n + 1; i++) {
    ans[i] = mp[i] + cost;
    if (mp[i] == 0) {
      if (pq.empty()) {
        for (int j = i + 1; j < n + 1; j++) ans[j] = -1;
        break;
      }
      auto tp = pq.top();
      pq.pop();
      cost += (long long)(i - tp.first);
      tp.second--;
      if (tp.second > 1) pq.push({tp.first, tp.second});
    }
    if (mp[i] > 1) pq.push({i, mp[i]});
  }
  for (int i = 0; i < n + 1; i++) cout << ans[i] << " ";
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
