#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> result(n, 0);
  map<int, vector<int>> mp;
  for (int i = 0; i < n; i++) {
    mp[a[i]].push_back(i);
  }
  priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>>
      pq;
  for (int i = 1; i <= k; i++) {
    pq.push({0, i});
  }
  for (auto it = mp.begin(); it != mp.end(); it++) {
    vector<int> curr = it->second;
    for (int i = 0; i < min((int)curr.size(), k); i++) {
      auto a = pq.top();
      pq.pop();
      result[curr[i]] = a[1];
      a[0]++;
      pq.push(a);
    }
  }
  map<int, int> colorFreq;
  for (int i = 0; i < n; i++) {
    if (result[i] != 0) {
      colorFreq[result[i]]++;
    }
  }
  int cntReq = INT_MAX;
  for (auto it = colorFreq.begin(); it != colorFreq.end(); it++) {
    cntReq = min(cntReq, it->second);
  }
  map<int, int> diff;
  for (auto it = colorFreq.begin(); it != colorFreq.end(); it++) {
    diff[it->first] = it->second - cntReq;
  }
  for (int i = 0; i < n; i++) {
    if (result[i] != 0) {
      if (diff[result[i]] > 0) {
        diff[result[i]]--;
        result[i] = 0;
      }
    }
  }
  for (int x : result) {
    cout << x << " ";
  }
  cout << "\n";
}
int32_t main() {
  std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
}
