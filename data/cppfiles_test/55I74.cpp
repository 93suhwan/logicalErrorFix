#include <bits/stdc++.h>
using namespace std;
const int off = 1 << 20, maxn = 3e5;
int n, m, k, l, r;
vector<int> v;
vector<pair<int, int> > inte[maxn];
pair<int, int> tour[2 * off];
pair<int, int> prop[2 * off];
pair<int, int> dp[maxn];
int bio[maxn];
void f(int x, int v, int ind) {
  if (v > tour[x].first) {
    tour[x] = {v, ind};
  }
  if (v > prop[x].first) {
    prop[x] = {v, ind};
  }
}
void push(int x) {
  if (x >= off || prop[x].first == 0) return;
  int v = prop[x].first;
  int ind = prop[x].second;
  prop[x].first = 0;
  f(2 * x, v, ind);
  f(2 * x + 1, v, ind);
}
void update(int x, int lo, int hi, int l, int r, int v, int ind) {
  push(x);
  if (hi <= l || r <= lo) return;
  if (l <= lo && hi <= r) {
    f(x, v, ind);
    return;
  }
  int mid = (lo + hi) / 2;
  update(x * 2, lo, mid, l, r, v, ind);
  update(x * 2 + 1, mid, hi, l, r, v, ind);
  pair<int, int> t1 = tour[x * 2];
  pair<int, int> t2 = tour[x * 2 + 1];
  if (t1.first > t2.first)
    tour[x] = t1;
  else
    tour[x] = t2;
}
pair<int, int> query(int x, int lo, int hi, int l, int r) {
  push(x);
  if (hi <= l || r <= lo) return {0, -1};
  if (l <= lo && hi <= r) return tour[x];
  int mid = (lo + hi) / 2;
  pair<int, int> q1 = query(x * 2, lo, mid, l, r);
  pair<int, int> q2 = query(x * 2 + 1, mid, hi, l, r);
  if (q1.first > q2.first) return q1;
  return q2;
}
void ispis() {
  for (int i = 1; i < 2 * off; i++) {
    if ((i & (i - 1)) == 0) cout << endl;
    cout << "[" << tour[i].first << ' ' << prop[i].first << ' '
         << tour[i].second << "] ";
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> k >> l >> r;
    k--;
    inte[k].push_back({l, r});
    v.push_back(l);
    v.push_back(r);
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < inte[i].size(); j++) {
      inte[i][j].first =
          lower_bound(v.begin(), v.end(), inte[i][j].first) - v.begin();
      inte[i][j].second =
          lower_bound(v.begin(), v.end(), inte[i][j].second) - v.begin();
    }
  }
  for (int i = 1; i < 2 * off; i++) tour[i].second = -1;
  for (int i = 0; i < n; i++) {
    dp[i].second = -1;
    for (int j = 0; j < inte[i].size(); j++) {
      pair<int, int> q =
          query(1, 0, off, inte[i][j].first, inte[i][j].second + 1);
      if (q.first > dp[i].first) dp[i] = q;
    }
    dp[i].first++;
    for (int j = 0; j < inte[i].size(); j++) {
      update(1, 0, off, inte[i][j].first, inte[i][j].second + 1, dp[i].first,
             i);
    }
  }
  int x = n;
  for (int i = 0; i < n; i++) {
    if (dp[i].first > dp[x].first) x = i;
  }
  cout << n - x << "\n";
  while (x != -1) {
    bio[x] = 1;
    x = dp[x].second;
  }
  for (int i = 0; i < n; i++) {
    if (!bio[i]) cout << i + 1 << ' ';
  }
  return 0;
}
