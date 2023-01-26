#include <bits/stdc++.h>
using namespace std;
const int MX = 3e5 + 10;
const int INF = 1e9;
bool vis[MX];
set<int> s;
int cnt[MX], N, M, dp[MX], pre[MX];
vector<pair<int, int> > rg;
vector<int> adj[MX];
void chmax(int& a, int b) {
  if (b > a) a = b;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int x, l, r;
    cin >> x >> l >> r;
    rg.push_back({l, x});
    rg.push_back({r + 1, -x});
  }
  sort(rg.begin(), rg.end());
  set<int>::iterator it;
  s.insert(0);
  s.insert(N + 1);
  for (auto p : rg) {
    int id = p.second > 0 ? p.second : -p.second;
    if (p.second > 0) {
      cnt[id]++;
      if (cnt[id] == 1) {
        s.insert(id);
        it = s.find(id);
        it--;
        adj[id].push_back((*it));
        it++;
        it++;
        adj[(*it)].push_back(id);
      }
    } else {
      cnt[id]--;
      if (cnt[id] == 0) s.erase(id);
    }
  }
  for (int i = 1; i <= N + 1; i++) dp[i] = -INF;
  for (int i = 1; i <= N + 1; i++) {
    for (auto j : adj[i]) {
      if (dp[j] + 1 > dp[i]) {
        dp[i] = dp[j] + 1;
        pre[i] = j;
      }
    }
  }
  cout << N + 1 - dp[N + 1] << '\n';
  int curr = N + 1;
  while (curr != 0) {
    vis[curr] = 1;
    curr = pre[curr];
  }
  for (int i = 1; i <= N; i++)
    if (!vis[i]) cout << i << " ";
  cout << '\n';
}
