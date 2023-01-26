#include <bits/stdc++.h>
#pragma GCC tarGet("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC tarGet("avx,avx2,fma")
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ldb = long double;
const int N = 1e5;
const int maxN = 1e6 + 1;
const int mod = 998244353;
const ll infty = 1e17;
const ll logn = 18;
const int base = 311;
const int Block_size = 500;
const int ep = 'a';
int cu[] = {0, 0, 1, -1};
int cv[] = {-1, 1, 0, 0};
int du[] = {-1, -1, +1, 1};
int dv[] = {-1, +1, -1, 1};
int cled[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
void InputFile() {
  freopen(".inp", "r", stdin);
  freopen(".out", "w", stdout);
}
void FastInput() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
}
int n, q;
int a[maxN];
int v[maxN], l[maxN], k[maxN];
vector<vector<int>> adj;
vector<set<int>> save;
vector<vector<int>> query;
int cnt[maxN];
int bit[maxN];
int res[maxN];
int all = 0;
void Update(int idx, int val) {
  while (idx <= n) {
    bit[idx] += val;
    idx += (idx & (-idx));
  }
}
int get(int idx) {
  int res = 0;
  while (idx > 0) {
    res += bit[idx];
    idx -= (idx & (-idx));
  }
  return res;
}
int Find(int k) {
  int mini = 1;
  int maxi = n;
  while (mini <= maxi) {
    int mid = (mini + maxi) / 2;
    int pre = get(mid - 1);
    if (pre >= k)
      maxi = mid - 1;
    else
      mini = mid + 1;
  }
  return maxi;
}
void Read() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[i] = 0;
    bit[i] = 0;
  }
  adj.clear();
  adj.resize(n + 1);
  save.clear();
  save.resize(n + 1);
  query.clear();
  query.resize(n + 1);
  for (int i = 2; i <= n; i++) {
    int p;
    cin >> p;
    adj[i].push_back(p);
    adj[p].push_back(i);
  }
  for (int i = 1; i <= q; i++) {
    cin >> v[i] >> l[i] >> k[i];
    query[v[i]].push_back(i);
  }
}
void DFS(int u, int p) {
  if (cnt[a[u]] > 0) {
    Update(cnt[a[u]], -1);
    save[cnt[a[u]]].erase(a[u]);
  } else if (cnt[a[u]] == 0)
    all++;
  cnt[a[u]]++;
  Update(cnt[a[u]], 1);
  save[cnt[a[u]]].insert(a[u]);
  for (int i : query[u]) {
    int pos = get(l[i] - 1) + k[i];
    if (pos > all) {
      res[i] = -1;
      continue;
    }
    int apr = Find(pos);
    res[i] = *save[apr].begin();
  }
  for (int v : adj[u]) {
    if (v == p) continue;
    DFS(v, u);
  }
  save[cnt[a[u]]].erase(a[u]);
  Update(cnt[a[u]], -1);
  cnt[a[u]]--;
  if (cnt[a[u]] == 0)
    all--;
  else {
    Update(cnt[a[u]], 1);
    save[cnt[a[u]]].insert(a[u]);
  }
}
void Solve() {
  DFS(1, 0);
  for (int i = 1; i <= q; i++) cout << res[i] << ' ';
  cout << '\n';
}
void Debug() {}
signed main() {
  FastInput();
  int test;
  cin >> test;
  while (test--) {
    Read();
    Solve();
  }
}
