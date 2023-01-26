#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long N = 6e5 + 10;
int n;
vector<pair<int, int>> t(4 * N), lazy(4 * N);
void push(int v) {
  if (t[v * 2].first < lazy[v].first) {
    t[v * 2] = lazy[v];
  }
  if (lazy[v * 2].first < lazy[v].first) {
    lazy[v * 2] = lazy[v];
  }
  if (t[v * 2 + 1].first < lazy[v].first) {
    t[v * 2 + 1] = lazy[v];
  }
  if (lazy[v * 2 + 1].first < lazy[v].first) {
    lazy[v * 2 + 1] = lazy[v];
  }
  lazy[v] = {0, 0};
}
pair<int, int> maxx(int l, int r, int v = 1, int tl = 0, int tr = n - 1) {
  if (l > r) return {0, 0};
  if (l == tl && r == tr) return t[v];
  push(v);
  int tm = (tl + tr) >> 1;
  pair<int, int> lf = maxx(l, min(r, tm), v * 2, tl, tm);
  pair<int, int> rt = maxx(max(l, tm + 1), r, v * 2 + 1, tm + 1, tr);
  if (lf.first > rt.first) {
    return lf;
  } else {
    return rt;
  }
}
void update(int l, int r, pair<int, int> val, int v = 1, int tl = 0,
            int tr = n - 1) {
  if (l > r) return;
  if (l == tl && r == tr) {
    if (t[v].first < val.first) {
      t[v] = val;
    }
    if (lazy[v].first < val.first) {
      lazy[v] = val;
    }
  } else {
    push(v);
    int tm = (tl + tr) >> 1;
    update(l, min(r, tm), val, v * 2, tl, tm);
    update(max(l, tm + 1), r, val, v * 2 + 1, tm + 1, tr);
    if (t[v * 2].first > t[v * 2 + 1].first) {
      t[v] = t[v * 2];
    } else {
      t[v] = t[v * 2 + 1];
    }
  }
}
void test_case() {
  int nn, m;
  cin >> nn >> m;
  vector<vector<pair<int, int>>> mm(nn + 1);
  map<int, int> zz, id;
  for (int i = 0; i < m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    mm[x].push_back({y, z});
    zz[y]++;
    zz[z]++;
  }
  n = zz.size();
  int curr = 0;
  for (auto u : zz) {
    id[u.first] = curr++;
  }
  vector<int> par(nn + 1, 0);
  for (int i = 1; i <= nn; i++) {
    for (auto u : mm[i]) {
      update(id[u.first], id[u.second], pair<int, int>{1, i});
    }
  }
  for (int i = 1; i <= nn; i++) {
    int mx = 0;
    for (auto u : mm[i]) {
      pair<int, int> q = maxx(id[u.first], id[u.second]);
      if (q.first >= mx) {
        mx = q.first;
        par[i] = q.second;
      }
    }
    for (auto u : mm[i]) {
      update(id[u.first], id[u.second], pair<int, int>{mx + 1, i});
    }
  }
  pair<int, int> ans = maxx(0, n - 1);
  curr = ans.second;
  vector<int> done(nn + 1, 0);
  while (curr != 0) {
    done[curr] = 1;
    if (curr == par[curr]) {
      break;
    }
    curr = par[curr];
  }
  vector<int> res;
  for (int i = 1; i <= nn; i++) {
    if (!done[i]) {
      res.push_back(i);
    }
  }
  cout << res.size() << '\n';
  for (auto u : res) {
    cout << u << ' ';
  }
  cout << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tc = 1;
  while (tc--) test_case();
  return 0;
}
