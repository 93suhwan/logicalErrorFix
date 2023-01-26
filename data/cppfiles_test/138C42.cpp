#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
struct Node {
  int v, p;
  Node(int x, int y) {
    v = x;
    p = y;
  }
};
map<int, long long> ans;
vector<Node> v;
int query[N];
vector<int> sortedQuery;
multiset<pair<pair<int, int>, int> > section;
long long sum[N];
int cnt[N];
void calculatePrefix(int total) {
  sum[0] = 0;
  cnt[0] = 0;
  for (int i = 0; i < total; ++i) {
    sum[i + 1] = sum[i] + v[i].v;
    cnt[i + 1] = cnt[i] + v[i].p;
  }
  sum[total + 1] = sum[total];
  cnt[total + 1] = cnt[total];
}
long long calculateAns(int l, int r) {
  long long num = cnt[r] - cnt[l];
  return sum[r] - sum[r - num];
}
void printAns(int q) {
  for (int i = 0; i < q; ++i) {
    cout << ans[query[i]] << "\n";
  }
}
bool cmp(Node a, Node b) {
  if (a.v == b.v) {
    return a.p < b.p;
  }
  return a.v < b.v;
}
void solve() {
  int n, m, q, x;
  int total;
  cin >> n >> m >> q;
  total = n + m;
  long long _ans = 0;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    v.push_back(Node(x, 1));
    _ans += x;
  }
  for (int i = 0; i < m; ++i) {
    cin >> x;
    v.push_back(Node(x, 0));
  }
  for (int i = 0; i < q; ++i) {
    cin >> x;
    query[i] = x;
    sortedQuery.push_back(x);
  }
  sort(v.begin(), v.end(), cmp);
  ans[0] = _ans;
  sort(sortedQuery.begin(), sortedQuery.end());
  calculatePrefix(total);
  vector<Node> gap;
  for (int i = 1; i < total; ++i) {
    gap.push_back(Node(v[i].v - v[i - 1].v, i));
  }
  sort(gap.begin(), gap.end(), cmp);
  set<int> cc;
  for (int i = 0; i < total; ++i) {
    cc.insert(i);
  }
  cc.insert(total);
  int l = 0;
  for (int i = 0; i < q; ++i) {
    int k = sortedQuery[i];
    if (ans[k]) {
      continue;
    }
    for (; gap[l].v <= k && l < total - 1; l++) {
      auto iter = cc.lower_bound(gap[l].p);
      auto iterl = iter;
      auto iterr = iter;
      iterl--;
      iterr++;
      _ans -= calculateAns(*iterl, *iter);
      _ans -= calculateAns(*iter, *iterr);
      _ans += calculateAns(*iterl, *iterr);
      cc.erase(iter);
    }
    ans[k] = _ans;
  }
  printAns(q);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
