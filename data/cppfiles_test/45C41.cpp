#include <bits/stdc++.h>
using namespace std;
long long MOD = 1000000007;
template <class T>
T power(T base, T exp) {
  long long res = 1;
  while (exp > 0) {
    if (exp & 1ll) res = res * base;
    exp >>= 1ll;
    base = base * base;
  }
  return res;
}
template <class T>
T modPower(T base, T exp) {
  long long res = 1;
  while (exp > 0) {
    if (exp & 1ll) res = res * base % MOD;
    exp >>= 1ll;
    base = base * base % MOD;
  }
  return res % MOD;
}
template <class T>
T modinverse(T a) {
  return power(a, MOD - 2);
}
const int N = 3e5, M = N;
vector<int> g[N];
int a[N];
void ipgraph(int n, int m) {
  int i, u, v;
  while (m--) {
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
}
void dfs(int u, int par) {
  for (int v : g[u]) {
    if (v == par) continue;
    dfs(v, u);
  }
}
vector<int> pnum;
void addPrimes(long long n) {
  pnum.resize(n + 1, true);
  for (int p = 2; p * p <= n; p++) {
    if (pnum[p] == true)
      for (int i = p * p; i <= n; i += p) pnum[i] = false;
  }
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int minSwapsToSort(vector<int> arr, int n) {
  pair<int, int> arrPos[n];
  for (int i = 0; i < n; i++) {
    arrPos[i].first = arr[i];
    arrPos[i].second = i;
  }
  sort(arrPos, arrPos + n);
  vector<bool> vis(n, false);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (vis[i] || arrPos[i].second == i) continue;
    int cycle_size = 0;
    int j = i;
    while (!vis[j]) {
      vis[j] = 1;
      j = arrPos[j].second;
      cycle_size++;
    }
    ans += (cycle_size - 1);
  }
  return ans;
}
int minSwapToMakeArraySame(vector<int> a, vector<int> b, int n) {
  map<int, int> umap;
  for (int i = 0; i < n; i++) umap[b[i]] = i;
  for (int i = 0; i < n; i++) b[i] = umap[a[i]];
  return minSwapsToSort(b, n);
}
int check(int st, vector<int> a) {
  int cnt0 = 0, cnt1 = 0, ans = 0, i = 0;
  for (i = 0; i < a.size(); i++) {
    if (a[i] != st) {
      if (a[i] == 1) {
        if (cnt0 == 0)
          cnt1++;
        else
          cnt0--;
      }
      if (a[i] == 0) {
        if (cnt1 == 0)
          cnt0++;
        else
          cnt1--;
      }
    }
    ans += abs(cnt0 - cnt1);
    st ^= 1;
  }
  return ans;
}
void solve() {
  long long n, i, j;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  int cnt0 = 0, cnt1 = 0;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    a[i] = a[i] % 2;
    if (a[i] == 0)
      cnt0++;
    else
      cnt1++;
  }
  if (abs(cnt1 - cnt0) > 1) {
    cout << -1;
    return;
  }
  int ans = INT_MAX;
  if (cnt1 >= cnt0) {
    ans = min(ans, check(1, a));
  }
  if (cnt0 >= cnt1) {
    ans = min(ans, check(0, a));
  }
  cout << ans;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  ;
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
  return 0;
}
