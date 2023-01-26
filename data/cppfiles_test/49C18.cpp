#include <bits/stdc++.h>
using namespace std;
int S[1048576];
void add(int first, int k) {
  if (first == 0) return;
  for (int i = first; i < 1048576; i += i & -i) {
    S[i] += k;
  }
}
int query(int first) {
  int res = 0;
  for (int i = first; i > 0; i -= i & -i) {
    res += S[i];
  }
  return res;
}
int query2(int first) {
  int sum = 0;
  int res = 0;
  for (int i = 19; i >= 0; i--) {
    if (sum + S[res + (1 << i)] < first) {
      res += 1 << i;
      sum += S[res];
    }
  }
  return res + 1;
}
vector<pair<pair<int, int>, int> > qquery[1000005];
int ans[1000005];
int m[1000005];
unordered_set<int> s[1000005];
int a[1000005];
vector<int> v[1000005];
void dfs(int first, int f) {
  add(m[a[first]], -1);
  if (m[a[first]]) s[m[a[first]]].erase(a[first]);
  m[a[first]]++;
  s[m[a[first]]].insert(a[first]);
  add(m[a[first]], 1);
  for (auto it : qquery[first]) {
    int num = it.first.second + query(it.first.first - 1);
    if (num > query(1048575))
      ans[it.second] = -1;
    else
      ans[it.second] = *s[query2(num)].begin();
  }
  for (auto it : v[first]) {
    if (it != f) dfs(it, first);
  }
  s[m[a[first]]].erase(a[first]);
  add(m[a[first]], -1);
  m[a[first]]--;
  add(m[a[first]], 1);
  if (m[a[first]]) {
    s[m[a[first]]].insert(a[first]);
  }
}
void solve() {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; i++) v[i].clear(), qquery[i].clear();
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 2; i <= n; i++) {
    int first;
    scanf("%d", &first);
    v[first].push_back(i);
  }
  for (int i = 1; i <= q; i++) {
    int v, l, k;
    scanf("%d %d %d", &v, &l, &k);
    qquery[v].push_back(make_pair(make_pair(l, k), i));
  }
  dfs(1, 0);
  for (int i = 1; i <= q; i++) printf("%d ", ans[i]);
  printf("\n");
}
int main() {
  int t = 1;
  0000;
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
