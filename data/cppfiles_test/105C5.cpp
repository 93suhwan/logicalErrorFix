#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int u[N], v[N], m[N], ansu[N], ansv[N], l[N], r[N], n;
set<pair<int, int> > L[N], R[N];
pair<int, int> calc(int u, int v, int m) {
  if (v >= m) {
    return {max(0, u - m), u};
  }
  return {max(0, u - m), u - (m - v)};
}
int calc(set<pair<int, int> > &L, set<pair<int, int> > &R) {
  int ans = 0;
  while (L.size()) {
    ans++;
    int minn = R.begin()->first;
    vector<int> cur;
    auto p = L.begin();
    while (p != L.end() && p->first <= minn) {
      cur.push_back(p->second);
      p++;
    }
    for (auto it : cur) {
      ansu[it] = u[it] - minn, ansv[it] = m[it] - ansu[it];
      L.erase(L.find({l[it], it}));
      R.erase(R.find({r[it], it}));
    }
  }
  return ans;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
      scanf("%d %d %d", &u[i], &v[i], &m[i]);
      pair<int, int> cur = calc(u[i], v[i], m[i]);
      l[i] = cur.first, r[i] = cur.second;
      mp[u[i] + v[i] - m[i]] = 1;
      L[u[i] + v[i] - m[i]].insert({l[i], i});
      R[u[i] + v[i] - m[i]].insert({r[i], i});
    }
    int ans = 0;
    for (auto it : mp) {
      ans += calc(L[it.first], R[it.first]);
    }
    printf("%d\n", ans);
    for (int i = 1; i <= n; i++) {
      printf("%d %d\n", ansu[i], ansv[i]);
    }
  }
  return 0;
}
