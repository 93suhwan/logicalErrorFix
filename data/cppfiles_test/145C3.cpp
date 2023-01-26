#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
using pd2 = pair<ld, ld>;
pair<pl2, pl2> arr[200020];
vector<int> adj[200020];
bool chk[200020];
ll res = 1e15;
void dfs(int now) {
  chk[now] = 1;
  res = min(res, arr[now].first.second);
  for (int nxt : adj[now]) {
    if (chk[nxt]) {
      continue;
    }
    dfs(nxt);
  }
}
void Main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    ll k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      cin >> arr[i].second.first >> arr[i].second.second >> arr[i].first.second;
      arr[i].first.first = i;
    }
    sort(arr + 1, arr + n + 1, [](pair<pl2, pl2> a, pair<pl2, pl2> b) {
      if (a.second.first == b.second.first) {
        return a.second.second < b.second.second;
      }
      return a.second.first < b.second.first;
    });
    for (int i = 1; i < n; i++) {
      if (arr[i].second.first != arr[i + 1].second.first) {
        continue;
      }
      ll dis = arr[i + 1].second.second - arr[i].second.second;
      int v1 = arr[i].first.first, v2 = arr[i + 1].first.first;
      if (dis <= k) {
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
      }
    }
    sort(arr + 1, arr + n + 1, [](pair<pl2, pl2> a, pair<pl2, pl2> b) {
      if (a.second.second == b.second.second) {
        return a.second.first < b.second.first;
      }
      return a.second.second < b.second.second;
    });
    for (int i = 1; i < n; i++) {
      if (arr[i].second.second != arr[i + 1].second.second) {
        continue;
      }
      ll dis = arr[i + 1].second.first - arr[i].second.first;
      int v1 = arr[i].first.first, v2 = arr[i + 1].first.first;
      if (dis <= k) {
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
      }
    }
    sort(arr + 1, arr + n + 1);
    vector<ll> v;
    for (int i = 1; i <= n; i++) {
      if (chk[i]) {
        continue;
      }
      res = 1e15;
      dfs(i);
      v.push_back(res);
    }
    int vl = v.size();
    sort(v.begin(), v.end());
    ll ans = 0;
    for (int i = 0; i < vl; i++) {
      ll res = min(v[i], (ll)vl - 1 - i);
      ans = max(ans, res);
    }
    cout << ans << '\n';
    for (int i = 1; i <= n; i++) {
      adj[i].clear();
      arr[i] = {{0, 0}, {0, 0}};
      chk[i] = 0;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.setf(ios::fixed);
  cout.precision(0);
  Main();
}
