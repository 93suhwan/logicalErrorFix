#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (!b)
    return a;
  else
    return gcd(b, a % b);
}
const int MAXN = 4e5 + 1;
long long int a[MAXN], tot[MAXN], ans[MAXN], cur = 0;
int par[MAXN], cnt[MAXN];
vector<int> comp[MAXN];
int find(int x) {
  if (par[x] == x) return x;
  return par[x] = find(par[x]);
}
void merge(int a, int b) {
  a = find(a);
  b = find(b);
  if (a == b) return;
  int n = (int)(comp[a].size());
  int m = (int)(comp[b].size());
  if (n > m) swap(a, b);
  cnt[b] += cnt[a];
  cur -= tot[a];
  cur -= tot[b];
  tot[b] = 0;
  vector<int> c;
  int p = 0, q = 0;
  while (p < n || q < m) {
    if (p == n || comp[a][p] > comp[b][q]) {
      c.push_back(comp[b][q]);
      q++;
    } else {
      c.push_back(comp[a][p]);
      p++;
    }
    if ((int)(c.size()) > n + m - cnt[b]) tot[b] += c.back();
  }
  cur += tot[b];
  swap(comp[b], c);
  par[a] = b;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  vector<pair<int, int>> s;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    par[i] = i;
    cnt[i] = 1;
    comp[i].push_back(a[i]);
    tot[i] = a[i];
    cur += a[i];
    s.push_back({i, 1});
  }
  for (int i = n; i < n + m; i++) {
    cin >> a[i];
    par[i] = i;
    comp[i].push_back(a[i]);
    s.push_back({i, 0});
  }
  sort(s.begin(), s.end(), [&](pair<int, int> i, pair<int, int> j) {
    return a[i.first] < a[j.first];
  });
  vector<pair<int, pair<int, int>>> edge;
  for (int i = 1; i < n + m; i++) {
    int v = s[i].first;
    int u = s[i - 1].first;
    edge.push_back({a[v] - a[u], {v, u}});
  }
  sort(edge.begin(), edge.end());
  vector<pair<int, int>> que;
  for (int i = 0; i < q; i++) {
    int v;
    cin >> v;
    que.push_back({v, i});
  }
  sort(que.begin(), que.end());
  int pt = -1;
  for (int i = 0; i < q; i++) {
    while (pt + 1 < (int)(edge.size()) && edge[pt + 1].first <= que[i].first) {
      pt++;
      int v = edge[pt].second.first;
      int u = edge[pt].second.second;
      merge(v, u);
    }
    ans[que[i].second] = cur;
  }
  for (int i = 0; i < q; i++) cout << ans[i] << '\n';
}
