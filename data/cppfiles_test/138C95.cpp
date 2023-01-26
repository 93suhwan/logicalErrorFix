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
long long int p[MAXN], tot[MAXN], ans[MAXN], cur = 0;
int par[MAXN], cnt[MAXN], l[MAXN], r[MAXN];
int find(int x) {
  if (par[x] == x) return x;
  return par[x] = find(par[x]);
}
void merge(int a, int b) {
  a = find(a);
  b = find(b);
  if (a == b) return;
  cnt[a] += cnt[b];
  cur -= tot[a] + tot[b];
  tot[a] = 0;
  l[a] = min(l[a], l[b]);
  r[a] = max(r[a], r[b]);
  int L = r[a] - cnt[a];
  tot[a] = p[r[a]] - (L >= 0 ? p[L] : 0);
  cur += tot[a];
  par[b] = a;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  vector<pair<int, int>> s;
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    s.push_back({v, 1});
  }
  for (int i = n; i < n + m; i++) {
    int v;
    cin >> v;
    s.push_back({v, 0});
  }
  sort(s.begin(), s.end());
  for (int i = 0; i < n + m; i++) {
    par[i] = i;
    p[i] = s[i].first;
    if (s[i].second) {
      cnt[i] = 1;
      tot[i] = p[i];
      cur += p[i];
    }
    l[i] = r[i] = i;
  }
  for (int i = 1; i < n + m; i++) p[i] += p[i - 1];
  vector<pair<int, pair<int, int>>> edge;
  for (int i = 1; i < n + m; i++) {
    edge.push_back({s[i].first - s[i - 1].first, {i, i - 1}});
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
