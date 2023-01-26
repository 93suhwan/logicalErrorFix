#include <bits/stdc++.h>
using namespace std;
const long long int inf = 1e12;
const long long int mod = 1e9 + 7;
vector<long long int> adj[100003];
long long int vis[100003];
void dfs(long long int n) {
  vis[n] = 1;
  for (long long int child : adj[n]) {
    if (vis[child] == 0) {
      dfs(child);
    }
  }
}
void solve() {
  long long int n;
  cin >> n;
  vector<pair<long long int, long long int>> a;
  vector<pair<long long int, long long int>> b;
  long long int mx = (-1 * inf), mxi;
  long long int aa;
  for (long long int i = 1; i <= n; i++) {
    cin >> aa;
    a.push_back({aa, i});
    if (aa > mx) {
      mx = aa;
      mxi = i;
    }
  }
  for (long long int i = 1; i <= n; i++) {
    cin >> aa;
    b.push_back({aa, i});
    if (aa > mx) {
      mx = aa;
      mxi = i;
    }
  }
  if (n == 1) {
    cout << "1\n";
    return;
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  for (long long int i = 0; i <= n - 2; i++) {
    adj[a[i + 1].second].push_back(a[i].second);
  }
  for (long long int i = 0; i <= n - 2; i++) {
    adj[b[i + 1].second].push_back(b[i].second);
  }
  dfs(mxi);
  string st = "";
  for (long long int i = 1; i <= n; i++) {
    if (vis[i] == 1) {
      st.push_back('1');
    } else {
      st.push_back('0');
    }
  }
  cout << st << "\n";
  for (long long int i = 0; i <= 100001; i++) {
    vis[i] = 0;
    adj[i].clear();
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
