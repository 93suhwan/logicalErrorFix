#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int N = 2e6 + 1;
int n, m, q, z;
const int iu = 1e7 + 1;
long long rw[N];
vector<pair<long long, int> > e;
int et[N], eu[N], ev[N], ew[N];
int wu[N], wv[N];
map<pair<int, int>, long long> mp;
multiset<long long> s3;
long long b3[N];
int tsz;
int cnt[iu], lc[iu], rc[iu];
int rt[N];
int upd(int id, int l, int r, int p, int v) {
  if (id == 0) id = ++tsz;
  if (l == r) {
    cnt[id] = v;
    return id;
  }
  int mid = (l + r) / 2;
  if (p <= mid)
    lc[id] = upd(lc[id], l, mid, p, v);
  else
    rc[id] = upd(rc[id], mid + 1, r, p, v);
  cnt[id] = cnt[lc[id]] + cnt[rc[id]];
  return id;
}
long long ans;
int eat(int id0, int idu, int idv, int l, int r, int w) {
  if (l == r) return l;
  int mid = (l + r) / 2;
  if (cnt[lc[idu]] + cnt[lc[idv]] - (l <= w && w <= mid) - cnt[lc[id0]] == 0)
    return eat(rc[id0], rc[idu], rc[idv], mid + 1, r, w);
  else
    return eat(lc[id0], lc[idu], lc[idv], l, mid, w);
}
void rage(int u, int v, int w) {
  if (cnt[rt[0]] == cnt[rt[u]] + cnt[rt[v]] - 1) return;
  int win = eat(rt[0], rt[u], rt[v], 1, z, w);
  ans = min(ans, rw[w] + rw[win]);
}
void hunt(int id, int l, int r, int k) {
  if (l == r) {
    rage(wu[l], wv[l], l);
    return;
  }
  int mid = (l + r) / 2;
  if (cnt[lc[id]] > 0) {
    int z = min(k, cnt[lc[id]]);
    k -= z;
    hunt(lc[id], l, mid, z);
  }
  if (k > 0) {
    hunt(rc[id], mid + 1, r, k);
  }
}
long long love(int id, int l, int r, int k) {
  if (l == r) return rw[l];
  int mid = (l + r) / 2;
  long long res = 0;
  if (cnt[lc[id]] > 0) {
    int z = min(k, cnt[lc[id]]);
    k -= z;
    res += love(lc[id], l, mid, z);
  }
  if (k > 0) {
    res += love(rc[id], mid + 1, r, k);
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i <= n; i++) {
    rt[i] = ++tsz;
    if (i != 0) {
      b3[i] = 2e9;
      s3.insert(b3[i]);
    }
  }
  for (int i = 1; i <= m; i++) {
    et[i] = 1;
    cin >> eu[i] >> ev[i] >> ew[i];
    if (eu[i] > ev[i]) swap(eu[i], ev[i]);
    if (et[i] == 1) {
      e.push_back({ew[i], i});
    }
  }
  cin >> q;
  for (int i = m + 1; i <= m + q; i++) {
    cin >> et[i];
    cin >> eu[i] >> ev[i];
    if (eu[i] > ev[i]) swap(eu[i], ev[i]);
    if (et[i] == 1) cin >> ew[i];
    if (et[i] == 1) {
      e.push_back({ew[i], i});
    }
  }
  sort(e.begin(), e.end());
  z = e.size();
  for (int i = 1; i <= z; i++) {
    rw[i] = e[i - 1].first;
    ew[e[i - 1].second] = i;
    wu[i] = eu[e[i - 1].second];
    wv[i] = ev[e[i - 1].second];
  }
  for (int i = 1; i <= m + q; i++) {
    int t = et[i];
    int u = eu[i], v = ev[i], w = ew[i];
    if (t == 1) {
      mp[{u, v}] = w;
    }
    if (t == 0) {
      w = mp[{u, v}];
    }
    s3.erase(s3.find(b3[u]));
    s3.erase(s3.find(b3[v]));
    if (et[i] == 1) {
      upd(rt[0], 1, z, w, 1);
      upd(rt[u], 1, z, w, 1);
      upd(rt[v], 1, z, w, 1);
    } else {
      upd(rt[0], 1, z, w, 0);
      upd(rt[u], 1, z, w, 0);
      upd(rt[v], 1, z, w, 0);
    }
    b3[u] = b3[v] = 2e9;
    if (cnt[rt[u]] >= 3) b3[u] = love(rt[u], 1, z, 3);
    if (cnt[rt[v]] >= 3) b3[v] = love(rt[v], 1, z, 3);
    s3.insert(b3[u]);
    s3.insert(b3[v]);
    if (i >= m) {
      ans = 2e9;
      hunt(rt[0], 1, z, 3);
      ans = min(ans, *s3.begin());
      cout << ans << '\n';
    }
  }
}
