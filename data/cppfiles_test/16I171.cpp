#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e10 + 7;
struct ed {
  long long first, second, z;
};
long long t, n, m, s, e;
long long a[300005], b[300005];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    priority_queue<pair<long long, long long> > pq;
    for (int i = 0; i < n; i++) {
      long long q;
      cin >> q;
      pq.push({q, i});
    }
    vector<pair<long long, long long> > ans;
    while (!pq.empty()) {
      pair<long long, long long> o = pq.top();
      pq.pop();
      if (pq.empty()) break;
      pair<long long, long long> q = pq.top();
      pq.pop();
      for (int i = 0; i < min(o.first, q.first); i++)
        ans.push_back({o.second + 1, q.second + 1});
      if (o.first > q.first)
        pq.push({o.first - q.first, o.second});
      else
        pq.push({q.first - o.first, q.second});
    }
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++)
      cout << ans[i].first << ' ' << ans[i].second << '\n';
  }
}
