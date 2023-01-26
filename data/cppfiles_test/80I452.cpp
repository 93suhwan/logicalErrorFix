#include <bits/stdc++.h>
using namespace std;
using vpii = vector<pair<int, int> >;
using pii = pair<int, int>;
int n, m;
long long mod;
void deykstra(int start) {
  vector<vector<pair<int, int> > > graph;
  vector<int> visit;
  vector<int> dp;
  visit[start] = 1;
  priority_queue<pair<int, int>, vector<pair<int, int> >, std::greater<pii> >
      pq;
  dp[start] = 0;
  for (pii el : graph[start]) {
    int dist = el.first;
    int to = el.second;
    pq.push(make_pair(dist + dp[start], to));
  }
  while (pq.empty() == false) {
    pii top = pq.top();
    pq.pop();
    while (visit[top.second] == 1) {
      if (pq.empty() == true) return;
      top = pq.top();
      pq.pop();
    }
    visit[top.second] = 1;
    dp[top.second] = min(dp[top.second], top.first);
    for (pair<int, int> to : graph[top.second]) {
      if (visit[to.second] == 0) {
        pq.push(make_pair(dp[top.second] + to.first, to.second));
      }
    }
  }
}
vector<int> used;
vector<int> dist;
vector<vector<int> > g, g_travers;
void bfs(int s) {
  queue<int> q;
  q.push(s);
  used[s] = 1;
  dist[s] = 0;
  while (q.empty() == false) {
    int cur = q.front();
    q.pop();
    for (int to : g_travers[cur]) {
      if (used[to] == 0) {
        used[to] = 1;
        q.push(to);
        dist[to] = min(dist[to], dist[cur] + 1);
      }
    }
  }
}
string s;
vector<int> is_simple(120, 1);
int l1, l2, r1, r2;
void print() { cout << l1 << " " << r1 << " " << l2 << " " << r2 << endl; }
void solve() {
  cin >> n;
  string s;
  cin >> s;
  int cnt = n / 2;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      if (i < cnt) {
        l1 = i + 1;
        l2 = i + 2;
        r1 = n;
        r2 = n;
      } else {
        l1 = 1;
        l2 = 1;
        r1 = i + 1;
        r2 = i;
      }
      print();
      return;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  is_simple[1] = 0;
  while (t--) {
    solve();
    cout << endl;
  }
}
