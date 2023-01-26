#include <bits/stdc++.h>
using namespace std;
const long long maxn = 3e5 + 10;
const long long mod = 1e9 + 7;
const long long m2 = 1e9 + 7;
const long long INF64 = long long(1e18);
const long long max2 = 1e3 + 10;
const long long N = 1000001;
const long long MAXN = 2e5 + 10;
const long long ALPHABET_SIZE = 2;
int cnt = 0;
int vis[maxn];
vector<int> adj[maxn];
vector<int> cyclic_shift(vector<int> v, int k) {
  int ind = (k);
  int n = v.size();
  vector<int> v2(n);
  int i1 = k;
  int i;
  for (i = 0; i < n; ++i, ++i1) {
    v2[i1 % n] = v[i];
  }
  return (v2);
}
void dfs(int p) {
  vis[p] = 1;
  ++cnt;
  for (auto x : adj[p]) {
    if (vis[x] == 0) {
      dfs(x);
    }
  }
}
int find(vector<int> v, vector<int> v2) {
  int i;
  int n = v.size();
  memset(vis, 0, sizeof(vis));
  for (i = 0; i < n; ++i) adj[i].clear();
  for (i = 0; i < n; ++i) {
    adj[v[i]].push_back(v2[i]);
    adj[v2[i]].push_back(v[i]);
  }
  int ans = 0;
  for (i = 0; i < n; ++i) {
    cnt = 0;
    if (vis[i] == 0) {
      dfs(i);
      ans += (cnt - 1);
    }
  }
  return (cnt);
}
vector<vector<int>> vf2;
void printArr(vector<int>& a, int n) {
  vector<int> v;
  for (int i = 0; i < n; i++) v.push_back(a[i]);
  vf2.push_back(v);
}
void heapPermutation(vector<int>& a, int size, int n) {
  if (size == 1) {
    printArr(a, n);
    return;
  }
  for (int i = 0; i < size; i++) {
    heapPermutation(a, size - 1, n);
    if (size % 2 == 1)
      swap(a[0], a[size - 1]);
    else
      swap(a[i], a[size - 1]);
  }
}
int main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(0);
  cout.tie(0);
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    int i;
    int ind[n];
    for (i = 0; i < n; ++i) {
      cin >> v[i];
      --v[i];
      ind[v[i]] = i;
    }
    vector<int> vf(n);
    for (i = 0; i < n; ++i) {
      vf[i] = i;
    }
    int ans[n];
    memset(ans, 0, sizeof(ans));
    for (i = 0; i < n; ++i) {
      int x = ind[i] - i;
      if (x < 0) {
        x += n;
      }
      ans[x]++;
    }
    vector<int> ans2;
    for (i = 0; i < n; ++i) {
      if (n - ans[i] <= k + 1) {
        if (n - ans[i] >= k && n - ans[i] <= k + 5000) {
          vector<int> v2 = cyclic_shift(vf, i);
          int x = find(v, v2);
          if (x <= k) ans2.push_back(i);
        } else {
          ans2.push_back(i);
        }
      }
    }
    cout << ans2.size() << " ";
    for (auto x : ans2) cout << x << " ";
    cout << "\n";
  }
  return (0);
}
