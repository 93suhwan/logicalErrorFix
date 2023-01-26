#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, arr[N], top;
map<int, int> mp, pos;
vector<pair<int, int> > nodes;
vector<pair<int, int> > adj[N * 32];
pair<int, int> dist[N * 32];
pair<int, pair<int, int> > best = {0, {-1, -1}};
int get(int x) {
  if (!mp.count(x)) {
    nodes.push_back({x, top});
    mp[x] = top++;
  }
  return mp[x];
}
void add(int x) {
  dist[get(x)] = max(dist[get(x)], {0, pos[x]});
  if (!x) return;
  int hi = 31;
  while (!(x & (1 << hi))) --hi;
  int lo = hi;
  while (x & (1 << lo)) --lo;
  int tmp = x;
  int st = get(x);
  for (int i = hi; i > lo; --i) {
    tmp -= (1 << i);
    adj[get(tmp)].push_back({st, (tmp == 0 && hi == lo + 1) ? 1 : 2});
  }
  dist[get(tmp)] = max(
      dist[get(tmp)],
      {dist[st].first + ((tmp == 0 && hi == lo + 1) ? 1 : 2), dist[st].second});
  add(tmp);
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> arr[i], pos[arr[i]] = i, add(arr[i]);
  sort(nodes.begin(), nodes.end());
  reverse(nodes.begin(), nodes.end());
  for (auto [_, v] : nodes) {
    pair<int, int> b1 = dist[v], b2 = {0, pos[v]};
    for (auto [u, d] : adj[v]) {
      pair<int, int> tmp = {dist[u].first + d, dist[u].second};
      int a = arr[dist[u].second], b = arr[dist[v].second];
      a ^= _;
      b ^= _;
      if ((a & 1) && (b & 1)) continue;
      if (tmp != b1 && tmp > b2) b2 = tmp;
    }
    best = max(best, {b1.first + b2.first, {b1.second, b2.second}});
  }
  cout << best.second.first + 1 << ' ' << best.second.second + 1 << ' '
       << best.first << '\n';
}
