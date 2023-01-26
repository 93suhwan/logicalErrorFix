#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
struct tt {
  int p;
  int num;
  vector<long long> pre;
};
vector<tt> t;
int find(int n) {
  if (t[n].p < 0)
    return n;
  else
    return t[n].p = find(t[n].p);
}
void merge(int a, int b) {
  a = find(a);
  b = find(b);
  t[a].p = b;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long ans = 0, n, m, q;
  cin >> n >> m >> q;
  t.resize(n + m);
  vector<pair<int, int>> a(n + m);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = 1;
    ans += a[i].first;
  }
  for (int i = n; i < n + m; i++) cin >> a[i].first;
  sort(a.begin(), a.end());
  for (int i = 0; i < n + m; i++) {
    t[i].num = a[i].second;
    t[i].p = -1;
    t[i].pre.push_back(a[i].first);
  }
  vector<pair<int, pair<int, int>>> g;
  for (int i = 1; i < n + m; i++)
    g.push_back({a[i].first - a[i - 1].first, {i - 1, i}});
  sort(g.begin(), g.end());
  map<int, int> km;
  vector<long long> kv, result(q);
  for (int i = 0; i < q; i++) {
    int tmp;
    cin >> tmp;
    km[tmp] = i;
    kv.push_back(tmp);
  }
  sort(kv.begin(), kv.end());
  int gi = 0;
  for (int i = 0; i < q; i++) {
    while (gi < g.size() && g[gi].first <= kv[i]) {
      int a = g[gi].second.first, b = g[gi].second.second;
      b = find(b);
      long long bef = 0;
      if (t[a].num > 0) bef += t[a].pre[t[a].num - 1];
      if (t[b].num > 0) bef += t[b].pre[t[b].num - 1];
      ans -= bef;
      long long tmp = t[b].pre.back();
      for (int i = 0; i < t[a].pre.size(); i++)
        t[b].pre.push_back(t[a].pre[i] + tmp);
      t[a].pre.clear();
      t[b].num += t[a].num;
      if (t[b].num > 0) ans += t[b].pre[t[b].num - 1];
      gi++;
      merge(a, b);
    }
    result[km[kv[i]]] = ans;
  }
  for (int i = 0; i < q; i++) cout << result[i] << endl;
}
