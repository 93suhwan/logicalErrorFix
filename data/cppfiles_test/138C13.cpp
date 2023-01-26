#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 7;
int n, m, q, pa[N], sz[N];
long long pre[N], Ans, ans[N];
vector<pair<int, int> > edges, v;
pair<int, int> inc[N];
int root(int x) {
  if (x == pa[x]) return x;
  return pa[x] = root(pa[x]);
}
long long f(int r, int len) {
  int l = r - len;
  return pre[r] - pre[l];
}
void solve(int i) {
  int j = i - 1;
  int ri = root(i);
  int rj = root(j);
  Ans -= f(ri, sz[ri]);
  Ans -= f(rj, sz[rj]);
  sz[max(ri, rj)] += sz[min(ri, rj)];
  pa[min(ri, rj)] = pa[max(ri, rj)];
  Ans += f(max(ri, rj), sz[max(ri, rj)]);
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> q;
  for (int i = 1, a; i <= n; i++) {
    cin >> a;
    v.push_back({a, 1});
  }
  for (int i = 1, a; i <= m; i++) {
    cin >> a;
    v.push_back({a, 0});
  }
  sort(v.begin(), v.end());
  for (int i = 1; i <= v.size(); i++) {
    pre[i] = pre[i - 1] + v[i - 1].first;
    sz[i] = v[i - 1].second;
    if (v[i - 1].second) Ans += v[i - 1].first;
    pa[i] = i;
    if (i > 1) edges.push_back({v[i - 1].first - v[i - 2].first, i});
  }
  for (int i = 0; i < q; i++) cin >> inc[i].first, inc[i].second = i;
  sort(inc, inc + q);
  sort(edges.begin(), edges.end());
  int lenEdges = 0;
  for (int i = 0; i < q; i++) {
    while (lenEdges < edges.size() && edges[lenEdges].first <= inc[i].first) {
      solve(edges[lenEdges].second);
      lenEdges++;
    }
    ans[inc[i].second] = Ans;
  }
  for (int i = 0; i < q; i++) cout << ans[i] << '\n';
  return 0;
}
