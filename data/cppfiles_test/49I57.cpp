#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int n, q;
int color[maxn];
int cnt_color[maxn];
int cnt[maxn];
int suff[maxn];
int ans[maxn];
set<int> first[maxn];
vector<pair<int, pair<int, int> > > queries[maxn];
vector<int> grafo[maxn];
void dfs(int u) {
  cnt_color[color[u]]++;
  cnt[cnt_color[color[u]] - 1]--;
  first[cnt[cnt_color[color[u]] - 1]].erase(u);
  cnt[cnt_color[color[u]]]++;
  suff[cnt_color[color[u]]]++;
  first[cnt[cnt_color[color[u]]]].insert(u);
  for (auto a : queries[u]) {
    int id = a.first, l = a.second.first, k = a.second.second;
    int ini = l, meio, fim = n, anss = -1;
    while (ini <= fim) {
      meio = (ini + fim) >> 1;
      if (suff[meio] >= k) {
        anss = meio;
        ini = meio + 1;
      } else
        fim = meio - 1;
    }
    if (anss == -1)
      ans[id] = -1;
    else
      ans[id] = *first[cnt[anss]].begin();
  }
  for (int v : grafo[u]) dfs(v);
  cnt_color[color[u]]--;
  if (cnt[cnt_color[color[u]]] > 0) first[cnt[cnt_color[color[u]]]].insert(u);
  cnt[cnt_color[color[u]]]++;
  cnt[cnt_color[color[u]] + 1]--;
  suff[cnt_color[color[u]] + 1]--;
  if (cnt[cnt_color[color[u]] + 1] > 0)
    first[cnt[cnt_color[color[u]] + 1]].erase(u);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> color[i];
    for (int i = 2; i <= n; i++) {
      int p;
      cin >> p;
      grafo[p].push_back(i);
    }
    for (int i = 1; i <= q; i++) {
      int v, l, k;
      cin >> v >> l >> k;
      queries[v].push_back({i, {l, k}});
    }
    cnt[0] = 1;
    dfs(1);
    for (int i = 1; i <= q; i++) cout << ans[i] << " ";
    cout << "\n";
    for (int i = 1; i <= n; i++) {
      cnt_color[i] = 0;
      cnt[i] = 0;
      suff[i] = 0;
      first[i].clear();
      grafo[i].clear();
      queries[i].clear();
    }
  }
  return 0;
}
