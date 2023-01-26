#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const int FINF = 0xcccccccc;
int dp[MAXN];
int v[MAXN];
int a[MAXN];
int tree[MAXN];
inline int lowbit(int x) { return x & -x; }
void change(int lo, int x, int n) {
  for (int i = lo; i <= n; i += lowbit(i)) tree[i] = max(tree[i], x);
}
int getmax(int lo) {
  int ret = FINF;
  for (int i = lo; i; i -= lowbit(i)) ret = max(ret, tree[i]);
  return ret;
}
void cal(int ll, int rr) {
  if (ll == rr) return;
  int mid = (ll + rr) / 2;
  cal(ll, mid);
  vector<tuple<int, int, int, int>> l, r;
  vector<int> ids;
  for (int i = ll; i <= mid; i++)
    l.push_back({v[i], a[i], i, dp[i]}), ids.push_back(a[i]);
  for (int i = mid + 1; i <= rr; i++)
    r.push_back({v[i], a[i], i, dp[i]}), ids.push_back(a[i]);
  sort(l.begin(), l.end());
  sort(r.begin(), r.end());
  sort(ids.begin(), ids.end());
  ids.erase(unique(ids.begin(), ids.end()), ids.end());
  int n = ids.size();
  auto getid = [&](int x) {
    return n - (lower_bound(ids.begin(), ids.end(), x) - ids.begin());
  };
  memset(tree, 0xcc, sizeof(int) * (n + 1));
  int aa = 0;
  for (auto x : r) {
    while (aa < l.size() && get<0>(l[aa]) < get<0>(x)) {
      change(getid(get<1>(l[aa])), get<3>(l[aa]), n);
      aa++;
    }
    int i = get<2>(x);
    dp[i] = max(dp[i], getmax(getid(get<1>(x))) + 1);
  }
  cal(mid + 1, rr);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> v[i];
  memset(dp, 0xcc, sizeof dp);
  dp[0] = 0;
  for (int i = 1; i <= n; i++) a[i] = v[i] - i;
  cal(0, n);
  cout << *max_element(dp, dp + 1 + n);
  return 0;
}
