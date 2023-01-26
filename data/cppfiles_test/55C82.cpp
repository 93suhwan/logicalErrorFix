#include <bits/stdc++.h>
using namespace std;
pair<long long, long long> t[8 * 300009], lazy[8 * 300009];
long long x[300009], l[300009], r[300009], dp[300009], par[300009];
vector<long long> ind[300009];
void push(long long v) {
  if (lazy[v].first == 0) return;
  if (lazy[v].first >= t[v + v].first) t[v + v] = lazy[v + v] = lazy[v];
  if (lazy[v].first >= t[v + v + 1].first)
    t[v + v + 1] = lazy[v + v + 1] = lazy[v];
  lazy[v * 2 + 1] = lazy[v];
  lazy[v] = {0, 0};
}
void update(long long v, long long tl, long long tr, long long l, long long r,
            pair<long long, long long> addend) {
  if (l > r) return;
  if (l == tl && tr == r) {
    if (addend.first >= t[v].first) {
      t[v] = lazy[v] = addend;
    }
  } else {
    push(v);
    long long tm = (tl + tr) / 2;
    update(v * 2, tl, tm, l, min(r, tm), addend);
    update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, addend);
    if (t[v + v].first > t[v + v + 1].first)
      t[v] = t[v * 2];
    else
      t[v] = t[v + v + 1];
  }
}
pair<long long, long long> query(long long v, long long tl, long long tr,
                                 long long l, long long r) {
  if (l > r) return {0, 0};
  if (l <= tl && tr <= r) return t[v];
  push(v);
  long long tm = (tl + tr) / 2;
  pair<long long, long long> a = query(v * 2, tl, tm, l, min(r, tm));
  pair<long long, long long> b =
      query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
  if (a.first >= b.first) return a;
  return b;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  vector<long long> v;
  long long n, m;
  cin >> n >> m;
  long long i = 0;
  while (i < m) {
    cin >> x[i] >> l[i] >> r[i];
    v.push_back(l[i]);
    v.push_back(r[i]);
    ind[x[i]].push_back(i);
    i++;
  }
  sort((v).begin(), (v).end());
  v.resize(unique((v).begin(), (v).end()) - v.begin());
  i = 0;
  long long mx = 0;
  while (i < m) {
    l[i] = 1 + lower_bound(v.begin(), v.end(), l[i]) - v.begin();
    r[i] = 1 + lower_bound(v.begin(), v.end(), r[i]) - v.begin();
    mx = max({mx, l[i], r[i]});
    i++;
  }
  long long op = 0;
  pair<long long, long long> temp;
  i = 1;
  while (i <= n) {
    dp[i] = 1;
    for (auto s : ind[i]) {
      temp = query(1, 1, mx, l[s], r[s]);
      if (1 + temp.first >= dp[i]) {
        dp[i] = 1 + temp.first;
        par[i] = temp.second;
      }
    }
    for (auto s : ind[i]) {
      update(1, 1, mx, l[s], r[s], {dp[i], i});
    }
    if (dp[i] > dp[op]) op = i;
    i++;
  }
  cout << n - dp[op] << "\n";
  set<long long> s;
  while (op) {
    s.insert(op);
    op = par[op];
  }
  i = 1;
  while (i <= n) {
    if (s.find(i) == s.end()) cout << i << " ";
    i++;
  }
}
