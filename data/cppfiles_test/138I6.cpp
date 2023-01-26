#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const long long mod = 998244353;
struct tt {
  int p;
  int num;
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
long long s = 1 << 19;
vector<long long> st(s << 1);
void init() {
  for (int i = s - 1; i > 0; i--) st[i] = st[i * 2] + st[i * 2 + 1];
}
long long sum(int l, int r) {
  long long ret = 0;
  for (l += s, r += s; l < r; l >>= 1, r >>= 1) {
    if (l & 1) ret += st[l++];
    if (r & 1) ret += st[--r];
  }
  return ret;
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
  for (int i = 0; i < n + m; i++) st[s + i] = a[i].first;
  init();
  for (int i = 0; i < n + m; i++) {
    t[i].num = a[i].second;
    t[i].p = -1;
  }
  vector<pair<int, pair<int, int>>> g;
  for (int i = 1; i < n + m; i++)
    g.push_back({a[i].first - a[i - 1].first, {i - 1, i}});
  sort(g.begin(), g.end());
  vector<long long> result(q);
  vector<pair<int, int>> kv;
  for (int i = 0; i < q; i++) {
    int tmp;
    cin >> tmp;
    kv.push_back({tmp, i});
  }
  sort(kv.begin(), kv.end());
  int gi = 0;
  for (int i = 0; i < q; i++) {
    while (gi < g.size() && g[gi].first <= kv[i].first) {
      int a = g[gi].second.first, b = g[gi].second.second;
      b = find(b);
      ans -= sum(a, t[a].num);
      ans += sum(b + t[b].num, b + t[b].num + t[a].num);
      t[b].num += t[a].num;
      gi++;
      merge(a, b);
    }
    result[kv[i].second] = ans;
  }
  for (int i = 0; i < q; i++) cout << result[i] << endl;
}
