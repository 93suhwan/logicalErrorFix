#include <bits/stdc++.h>
const long long int M = 1e9 + 7;
using namespace std;
bool ulta(long long int& a1, long long int& a2) { return (a1 > a2); }
long long int fastpow(long long int a, long long int n) {
  long long int res = 1;
  while (n) {
    if (n % 2 == 1) res = (res * a) % M;
    a = (a * a) % M;
    n /= 2;
  }
  return res;
}
vector<vector<long long int> > adj;
vector<long long int> vis;
void dfs(long long int node) {
  vis[node] = 1;
  for (auto i : adj[node]) {
    if (!vis[i]) dfs(i);
  }
  return;
}
void run() {
  long long int n;
  cin >> n;
  vector<pair<long long int, long long int> > a(n), b(n);
  adj.clear();
  vis.clear();
  adj.resize(n);
  vis = {0};
  vis.resize(n);
  for (long long int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  for (long long int i = 0; i < n; i++) {
    cin >> b[i].first;
    b[i].second = i;
  }
  sort((a).begin(), (a).end());
  sort((b).begin(), (b).end());
  for (long long int i = 0; i < n - 1; i++) {
    adj[a[i].second].push_back(a[i + 1].second);
    adj[b[i].second].push_back(b[i + 1].second);
  }
  dfs(a[n - 1].second);
  dfs(b[n - 1].second);
  for (long long int i = 0; i < n; i++) cout << vis[i];
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  cin >> t;
  while (t--) {
    run();
  }
  return 0;
}
