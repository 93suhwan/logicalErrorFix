#include <bits/stdc++.h>
using namespace std;
set<long long> leaf(vector<vector<pair<long long, long long>>> grp) {
  queue<long long> q;
  q.push(1);
  vector<long long> res;
  vector<long long> vis(grp.size(), 0);
  set<long long> st;
  while (!q.empty()) {
    long long sz = q.size();
    while (sz--) {
      long long temp = q.front();
      q.pop();
      if (vis[temp] == 0) {
        long long cnt = 0;
        for (long long i = 0; i < grp[temp].size(); i++) {
          if (grp[temp][i].first != 0) {
            q.push(grp[temp][i].first);
            cnt++;
          }
        }
        if (cnt == 1) {
          st.insert(temp);
          continue;
        }
        for (long long i = 0; i < grp[temp].size(); i++) {
          if (vis[grp[temp][i].first] == 0 && grp[temp][i].first != 0) {
            q.push(grp[temp][i].first);
            cnt++;
          }
        }
      }
      vis[temp] = 1;
    }
  }
  return st;
}
vector<long long> djkstra(vector<vector<pair<long long, long long>>> grp,
                          long long start) {
  vector<long long> dist(grp.size() + 1, INT_MAX);
  priority_queue<pair<long long, long long>, vector<pair<long long, long long>>,
                 greater<pair<long long, long long>>>
      pq;
  dist[start] = 0;
  pq.push({0, start});
  while (!pq.empty()) {
    long long u = pq.top().second;
    pq.pop();
    for (long long i = 0; i < grp[u].size(); i++) {
      long long v = grp[u][i].first;
      long long wt = grp[u][i].second;
      if (dist[v] > dist[u] + wt) {
        dist[v] = dist[u] + wt;
        pq.push({dist[v], v});
      }
    }
  }
  return dist;
}
const long long n = 2e5 + 1;
long long dp[n][19];
void slv() {
  for (long long i = 0; i < 19; i++) {
    dp[0][i] = 0;
  }
  long long in = 0;
  long long x;
  for (long long i = 1; i < 2e5 + 1; i++) {
    x = i;
    in = 0;
    while (x > 0) {
      dp[i][in] = x % 2 + dp[i - 1][in];
      x = x / 2;
      in++;
    }
  }
}
void solve() {
  long long n;
  cin >> n;
  long long arr[n];
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
  }
  string st;
  cin >> st;
  vector<pair<long long, long long>> first;
  vector<pair<long long, long long>> second;
  for (long long i = 0; i < n; i++) {
    if (st[i] == '0') {
      first.push_back({arr[i], i});
    } else {
      second.push_back({arr[i], i});
    }
  }
  sort(first.begin(), first.end());
  sort(second.begin(), second.end());
  long long val = 0;
  long long k = 0;
  for (k = 0; k < first.size(); k++) {
    first[k].first = k + 1;
  }
  val = k;
  for (long long i = 0; i < second.size(); i++) {
    second[i].first = val + 1;
    val++;
  }
  map<long long, long long> mp;
  for (long long i = 0; i < second.size(); i++) {
    mp[second[i].second] = second[i].first;
  }
  for (long long i = 0; i < first.size(); i++) {
    mp[first[i].second] = first[i].first;
  }
  for (auto a : mp) {
    cout << a.second << " ";
  }
  cout << "\n";
  return;
}
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
