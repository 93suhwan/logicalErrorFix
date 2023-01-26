#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
mt19937 rng((int)chrono::steady_clock::now().time_since_epoch().count());
const int MOD = 1e9 + 7;
const int MAXN = 6e6 + 5;
const ll INF = 2e18;
int vis[MAXN];
vector<int> v[MAXN];
map<int, int> mp1, mp2, mp3;
pii dfs(int node, int dist) {
  vis[node] = 1;
  pii ans;
  if (mp3[node])
    ans = {dist, node};
  else
    ans = {0, 0};
  for (int x : v[node]) {
    if (vis[x]) continue;
    ans = max(ans, dfs(x, dist + 1));
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, aux;
  cin >> n;
  vector<int> num(1), pos(n);
  for (int i = 0; i < n; i++) {
    cin >> aux;
    mp1[aux] = i + 1;
    mp2[aux] = 1;
    while (aux) {
      num.push_back(aux);
      int bit = 32 - __builtin_clz(aux);
      if ((1 << bit) == 2 * aux) bit--;
      aux = (1 << bit) - aux;
    }
  }
  sort(num.begin(), num.end());
  num.erase(unique(num.begin(), num.end()), num.end());
  for (int x : num) {
    int pos = lower_bound(num.begin(), num.end(), x) - num.begin();
    if (mp2[x]) mp3[pos] = 1;
    if (!x) continue;
    int bit = 32 - __builtin_clz(x);
    if ((1 << bit) == 2 * x) bit--;
    int pai = lower_bound(num.begin(), num.end(), (1 << bit) - x) - num.begin();
    v[pos].push_back(pai);
    v[pai].push_back(pos);
  }
  pii a1 = dfs(0, 0);
  memset(vis, 0, sizeof(vis));
  pii a2 = dfs(a1.second, 0);
  cout << mp1[num[a1.second]] << ' ' << mp1[num[a2.second]] << ' ' << a2.first
       << '\n';
  return 0;
}
