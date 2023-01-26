#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int t;
int n, k;
vector<int> v[100 + 1];
ll dp[100 + 1][100 + 1];
bool vst[100 + 1];
ll ans;
void dfs(int now, int cnt, int root) {
  vst[now] = true;
  dp[root][now] = cnt;
  for (auto there : v[now]) {
    if (!vst[there]) {
      dfs(there, cnt + 1, root);
    }
  }
}
ll c[128][128];
ll add(ll x, ll y) { return (x + y) % (ll)1000000007; }
ll mul(ll x, ll y) { return x * y % (ll)1000000007; }
ll rundp(vector<int>& arr, int m, int k) {
  memset(c, 0, sizeof c);
  c[0][0] = 1;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j <= k; j++) {
      c[i + 1][j] = add(c[i + 1][j], c[i][j]);
      c[i + 1][j + 1] = add(c[i + 1][j + 1], mul(c[i][j], arr[i]));
    }
  }
  return c[m][k];
}
void solve(int now) {
  if (v[now].size() < k) return;
  memset(vst, false, sizeof vst);
  memset(dp, 0, sizeof dp);
  vst[now] = true;
  for (auto there : v[now]) {
    dfs(there, 1, there);
  }
  map<int, vector<int>> m;
  for (auto there : v[now]) {
    map<int, int> tmp;
    for (int i = 1; i <= n; i++) {
      if (dp[there][i] > 0) tmp[dp[there][i]]++;
    }
    for (auto it = tmp.begin(); it != tmp.end(); it++) {
      m[it->first].push_back(it->second);
    }
  }
  for (auto it = m.begin(); it != m.end(); it++) {
    if (it->second.size() >= k) {
      ans = (ans + rundp(it->second, it->second.size(), k)) % (ll)1000000007;
    }
  }
}
int comb[100 + 1][100 + 1];
int pascal(int i, int j) {
  if (comb[i][j] != 0) {
    return comb[i][j];
  }
  if (j == 0 || j == i) {
    comb[i][j] = 1;
    return comb[i][j];
  }
  return comb[i][j] =
             (pascal(i - 1, j) + pascal(i - 1, j - 1)) % (ll)1000000007;
}
int main(void) {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> k;
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n - 1; i++) {
      int a, b;
      cin >> a >> b;
      v[a].push_back(b);
      v[b].push_back(a);
    }
    ans = 0;
    for (int i = 1; i <= n; i++) {
      solve(i);
    }
    if (k == 2) {
      ans = pascal(n, k);
    }
    cout << ans << "\n";
    for (int i = 1; i <= n; i++) {
      v[i].clear();
      vector<int>().swap(v[i]);
    }
  }
  return 0;
}
