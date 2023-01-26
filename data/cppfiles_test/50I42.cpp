#include <bits/stdc++.h>
using namespace std;
const int N = (int)5e4 + 500;
vector<pair<long long, long long> > segs, sg, ins[N];
int pr[50 * N];
int sz[50 * N];
long long l[N], r[N];
int n, q;
int tp[N], ans[N];
void div(int bit, long long l, long long r) {
  long long siz = (1ll << (bit + 1)) - 1;
  long long l_s = l & siz;
  long long r_s = r & siz;
  if (!l_s && r_s == siz) {
    segs.push_back({l, r});
    return;
  }
  if (l_s >= (1ll << bit) - 1) {
    div(bit - 1, l, r);
  } else {
    if (r_s < (1ll << bit) - 1) {
      div(bit - 1, l, r);
    } else {
      long long md = l | ((1ll << bit) - 1);
      div(bit - 1, l, md);
      div(bit - 1, md + 1, r);
    }
  }
}
int f(int v) { return (pr[v] == v ? v : pr[v] = f(pr[v])); }
void link(int v, int u) {
  v = f(v);
  u = f(u);
  if (v == u) {
    return;
  }
  if (sz[v] < sz[u]) {
    swap(v, u);
  }
  pr[u] = v;
  sz[v] += sz[u];
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q;
  for (int i = 0; i < q; i++) {
    string s;
    cin >> s >> l[i] >> r[i];
    if (s == "ask") {
      tp[i] = 0;
    } else {
      tp[i] = 1;
      sg.push_back({l[i], r[i]});
    }
  }
  vector<pair<long long, long long> > nsg;
  sort((sg).begin(), (sg).end());
  if ((int)sg.size() == 0) {
    sg.push_back({0, (1ll << n) - 1});
  }
  if (sg[0].first != 0) {
    nsg.push_back({0, sg[0].first - 1});
  }
  for (int i = 0; i < (int)sg.size(); i++) {
    nsg.push_back(sg[i]);
    if (i + 1 < (int)sg.size() && sg[i].second + 1 <= sg[i + 1].first - 1) {
      nsg.push_back({sg[i].second + 1, sg[i + 1].first - 1});
    }
  }
  if (sg.back().second + 1 <= (1ll << n) - 1) {
    nsg.push_back({sg.back().second + 1, (1ll << n) - 1});
  }
  for (auto x : nsg) {
    div(n - 1, x.first, x.second);
  }
  vector<int> tm((int)segs.size());
  for (int i = 0; i < (int)segs.size(); i++) {
    tm[i] = -1;
  }
  for (int i = 0; i < q; i++) {
    if (!tp[i]) {
      continue;
    }
    int L = lower_bound((segs).begin(), (segs).end(), make_pair(l[i], -1ll)) -
            segs.begin();
    int R =
        lower_bound((segs).begin(), (segs).end(), make_pair(r[i] + 1, -1ll)) -
        segs.begin();
    for (int j = L; j < R; j++) {
      tm[j] = i;
    }
  }
  for (int i = 0; i < (int)segs.size(); i++) {
    if (tm[i] == -1) {
      tm[i] = q;
    }
  }
  for (int i = 0; i < n; i++) {
    vector<int> sb[2];
    for (int j = 0; j < (int)segs.size(); j++) {
      auto x = segs[j];
      if ((1ll << i) < x.second - x.first + 1) {
        continue;
      }
      sb[!!(x.first & (1ll << i))].push_back(j);
    }
    for (int b = 0; b < 2; b++) {
      int p = 0;
      for (int j = 0; j < (int)sb[b].size(); j++) {
        int id = sb[b][j];
        long long L = segs[id].first ^ (1ll << i);
        while (segs[p].second < L) {
          p++;
        }
        if (segs[p].second - segs[p].first >=
            segs[id].second - segs[id].first) {
          int tim = min(tm[p], tm[id]);
          ins[tim].push_back({p, id});
        }
      }
    }
  }
  for (int i = 0; i < (int)segs.size(); i++) {
    pr[i] = i;
    sz[i] = 1;
  }
  for (int i = q; i >= 0; i--) {
    for (auto [v, u] : ins[i]) {
      link(v, u);
    }
    if (i < q && !tp[i]) {
      int v =
          upper_bound((segs).begin(), (segs).end(), make_pair(l[i] + 1, -1ll)) -
          segs.begin() - 1;
      int u =
          upper_bound((segs).begin(), (segs).end(), make_pair(r[i] + 1, -1ll)) -
          segs.begin() - 1;
      ans[i] = (f(v) == f(u));
    }
  }
  for (int i = 0; i < q; i++) {
    if (!tp[i]) {
      cout << ans[i] << '\n';
    }
  }
}
