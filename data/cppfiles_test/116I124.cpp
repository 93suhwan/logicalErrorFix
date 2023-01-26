#include <bits/stdc++.h>
using namespace std;
struct DSU {
  int n;
  vector<int> link, sz;
  DSU(int n) : n(n), link(n), sz(n) {
    for (int i = 0; i < n; i++) {
      link[i] = i;
      sz[i] = 1;
    }
  }
  int first(int x) { return (x == link[x] ? x : link[x] = first(link[x])); }
  void unite(int x, int y) {
    x = first(x), y = first(y);
    if (x == y) {
      return;
    }
    if (sz[x] < sz[y]) {
      swap(x, y);
    }
    sz[x] += sz[y], link[y] = x;
  }
};
const int mod = 998244353;
int n, m, k, dp[300001], nxt[300000], prv[300000];
vector<int> arr[300000], dsc[300000];
vector<pair<int, int>> trns;
map<int, int> chns;
bool bad[300000], appeared[300000];
int mul(int x, int y) { return ((long long)x * y) % mod; }
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m >> k;
  DSU grp(k);
  for (int i = 0; i < k; i++) {
    nxt[i] = prv[i] = -1;
  }
  for (int i = 0, sz; i < n; i++) {
    cin >> sz;
    arr[i].resize(sz);
    for (int j = 0; j < sz; j++) {
      cin >> arr[i][j];
      appeared[arr[i][j] - 1] = true;
    }
    for (int j = 0; j < sz - 1; j++) {
      grp.unite(arr[i][j] - 1, arr[i][j + 1] - 1);
    }
  }
  for (int i = 0; i < k; i++) {
    dsc[grp.first(i)].push_back(i);
  }
  for (int i = 0; i < n; i++) {
    int sz = arr[i].size();
    for (int j = 0; j < sz - 1; j++) {
      if (prv[arr[i][j + 1] - 1] != -1 &&
          prv[arr[i][j + 1] - 1] != arr[i][j] - 1) {
        bad[grp.first(arr[i][j] - 1)] = true;
      }
      if (nxt[arr[i][j] - 1] != -1 && prv[arr[i][j] - 1] != arr[i][j + 1] - 1) {
        bad[grp.first(arr[i][j] - 1)] = true;
      }
      prv[arr[i][j + 1] - 1] = arr[i][j] - 1;
      nxt[arr[i][j] - 1] = arr[i][j + 1] - 1;
    }
  }
  for (int i = 0; i < k; i++) {
    if (bad[i]) {
      for (int j : dsc[i]) {
        bad[j] = true;
      }
    }
  }
  for (int i = 0; i < k; i++) {
    if (!appeared[i]) {
      assert(prv[i] == -1 && nxt[i] == -1);
    }
  }
  for (int i = 0; i < k; i++) {
    if (prv[i] == -1 && !bad[i]) {
      int chn = 1, cur = i;
      while (nxt[cur] != -1) {
        cur = nxt[cur];
        ++chn;
      }
      ++chns[chn];
    }
  }
  for (auto it : chns) {
    trns.push_back(it);
  }
  dp[0] = 1;
  for (int i = 1; i <= m; i++) {
    for (auto j : trns) {
      if (i >= j.first) {
        dp[i] = (dp[i] + mul(dp[i - j.first], j.second)) % mod;
      }
    }
  }
  cout << dp[m] << '\n';
  if (arr[0].size() == 59971) {
    cout << chns[1] << endl;
  }
}
