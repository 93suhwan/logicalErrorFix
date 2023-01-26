#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, i, j, k, x, p;
    cin >> n;
    vector<pair<int, int>> vec;
    int mi = INT_MAX;
    for (i = 0; i < n; i++) {
      cin >> k;
      x = 0;
      for (j = 0; j < k; j++) {
        cin >> p;
        if (x + j <= p) x = p - j + 1;
      }
      vec.push_back(make_pair(x, k));
    }
    sort(vec.begin(), vec.end());
    priority_queue<pair<int, int>> pq;
    int ans = 0;
    i = 0;
    p = 0;
    pair<int, int> pa;
    while (i < n) {
      if (pq.empty() && ans + p < vec[i].first) {
        ans = vec[i].first - p;
      }
      while (i < n) {
        if (vec[i].first > ans + p) break;
        pq.push(make_pair(vec[i].second, vec[i].first));
        i++;
      }
      pa = pq.top();
      p += pa.first;
      pq.pop();
    }
    cout << ans << "\n";
  }
  return 0;
}
