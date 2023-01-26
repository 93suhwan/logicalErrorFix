#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-9;
const int mod = 1e9 + 7;
const int oo = 1e9 + 7;
const long long lloo = 1e18 + 7;
const int N = 1e6 + 7;
void solve();
int main() {
  int T = 1;
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}
int n;
vector<pair<pair<int, int>, int>> queries[N];
int ans[N];
int freq[N];
int a[N];
set<int> freqto[N];
vector<int> g[N];
const int MAX_VAL = N + 9;
int BITTree[MAX_VAL] = {0};
void add(int idx, int val) {
  idx++;
  while (idx < MAX_VAL) BITTree[idx] += val, idx += (idx & -idx);
}
int getAccum(int idx) {
  idx++;
  int sum = 0;
  while (idx > 0) sum += BITTree[idx], idx -= (idx & -idx);
  return sum;
}
int getrange(int L, int R) {
  int ret = getAccum(R) - getAccum(L - 1);
  return ret;
}
void add(int x) {
  add(freq[x], -1);
  if (freqto[freq[x]].find(x) != freqto[freq[x]].end())
    freqto[freq[x]].erase(x);
  freq[x]++;
  add(freq[x], +1);
  freqto[freq[x]].insert(x);
}
void del(int x) {
  add(freq[x], -1);
  if (freqto[freq[x]].find(x) != freqto[freq[x]].end())
    freqto[freq[x]].erase(x);
  freq[x]--;
  add(freq[x], +1);
  freqto[freq[x]].insert(x);
}
void dfs(int u, int p = -1, int len = 0) {
  add(a[u]);
  for (auto qq : queries[u]) {
    int id = qq.first.first;
    int l = qq.first.second;
    int k = qq.second;
    int L = l, R = len + 7;
    while (L < R) {
      int mid = (L + R) >> 1;
      if (getrange(l, mid) < k)
        L = mid + 1;
      else
        R = mid;
    }
    if (L == len + 7)
      ans[id] = -1;
    else
      ans[id] = *freqto[L].begin();
  }
  for (auto v : g[u]) {
    if (v == p) continue;
    dfs(v, u, len + 1);
  }
  del(a[u]);
}
void solve() {
  int q;
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; i++) {
    g[i].clear();
    queries[i].clear();
  }
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 0; i < n - 1; i++) {
    int pi;
    scanf("%d", &pi);
    g[i + 2].push_back(pi);
    g[pi].push_back(i + 2);
  }
  for (int i = 0; i < q; i++) {
    int u, l, k;
    scanf("%d %d %d", &u, &l, &k);
    queries[u].push_back({{i, l}, k});
  }
  dfs(1);
  for (int i = 0; i < q; i++) printf("%d ", ans[i]);
  puts("");
}
