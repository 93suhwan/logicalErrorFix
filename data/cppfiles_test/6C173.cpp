#include <bits/stdc++.h>
using namespace std;
long long oll = 0;
bool comp(const pair<int, int> &a, const pair<int, int> &b) {
  return a.first < b.first;
}
int degree[200000 + 1], power[200000 + 1];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (long long i = (int)0; i < (int)m; i++) {
    int u, v;
    cin >> u >> v;
    int mx = max(u, v);
    int mn = min(u, v);
    degree[mx]++, degree[mn]++;
    power[mx]++;
  }
  int cnt = 0;
  for (long long i = (int)1; i < (int)n + 1; i++)
    if (degree[i] == power[i]) cnt++;
  int q;
  cin >> q;
  while (q--) {
    int mode;
    cin >> mode;
    if (mode == 1) {
      int u, v;
      cin >> u >> v;
      if (degree[u] == power[u]) cnt--;
      if (degree[v] == power[v]) cnt--;
      degree[u]++, degree[v]++;
      power[max(u, v)]++;
      if (degree[u] == power[u]) cnt++;
      if (degree[v] == power[v]) cnt++;
    } else if (mode == 2) {
      int u, v;
      cin >> u >> v;
      if (degree[u] == power[u]) cnt--;
      if (degree[v] == power[v]) cnt--;
      degree[u]--, degree[v]--;
      power[max(u, v)]--;
      if (degree[u] == power[u]) cnt++;
      if (degree[v] == power[v]) cnt++;
    } else if (mode == 3) {
      cout << cnt << "\n";
    }
  }
  return 0;
}
