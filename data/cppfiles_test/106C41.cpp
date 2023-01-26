#include <bits/stdc++.h>
using namespace std;
std::mt19937 rnd(
    (int)std::chrono::steady_clock::now().time_since_epoch().count());
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
typedef struct MCMF {
  int n, m;
  vector<int> ghead, gnxt, gto, gcap;
  vector<long long> gcost;
  vector<long long> d;
  vector<int> bck;
  vector<long long> pot;
  vector<int> flow;
  void init(int _n) {
    n = _n, m = 0;
    ghead = vector<int>(n, -1);
    gnxt.clear(), gto.clear(), gcap.clear(), gcost.clear();
    d = vector<long long>(n);
    bck = vector<int>(n);
    pot = vector<long long>(n, 0);
    flow = vector<int>(n);
  }
  void addedge(int a, int b, int c, long long d) {
    gnxt.push_back(ghead[a]);
    ghead[a] = m;
    gto.push_back(b);
    gcap.push_back(c);
    gcost.push_back(+d);
    ++m;
    gnxt.push_back(ghead[b]);
    ghead[b] = m;
    gto.push_back(a);
    gcap.push_back(0);
    gcost.push_back(-d);
    ++m;
  }
  pair<int, long long> solve(int s, int t) {
    for (int i = (0); i < (n); ++i) d[i] = LLONG_MAX, bck[i] = -1;
    d[s] = 0, bck[s] = -2;
    while (true) {
      bool change = false;
      for (int at = (0); at < (n); ++at)
        if (d[at] != LLONG_MAX)
          for (int x = ghead[at]; x != -1; x = gnxt[x])
            if (gcap[x] > 0) {
              int to = gto[x];
              if (d[at] + gcost[x] >= d[to]) continue;
              d[to] = d[at] + gcost[x];
              bck[to] = x ^ 1;
              change = true;
            }
      if (!change) break;
    }
    if (d[t] == LLONG_MAX) return make_pair(0, 0);
    for (int i = (0); i < (n); ++i) pot[i] = d[i];
    pair<int, long long> ret = make_pair(0, 0LL);
    while (true) {
      for (int i = (0); i < (n); ++i)
        d[i] = LLONG_MAX, bck[i] = -1, flow[i] = 0;
      d[s] = 0, bck[s] = -2, flow[s] = INT_MAX;
      priority_queue<pair<long long, int>> q;
      q.push(make_pair(-d[s], s));
      while (!q.empty()) {
        long long cost = -q.top().first;
        int at = q.top().second;
        q.pop();
        if (cost > d[at]) continue;
        for (int x = ghead[at]; x != -1; x = gnxt[x])
          if (gcap[x] > 0) {
            int to = gto[x];
            long long rcost = gcost[x] + pot[at] - pot[to];
            if (d[at] + rcost >= d[to]) continue;
            d[to] = d[at] + rcost;
            bck[to] = x ^ 1;
            flow[to] = min(flow[at], gcap[x]);
            q.push(make_pair(-d[to], to));
          }
      }
      if (d[t] == LLONG_MAX) break;
      assert(flow[t] > 0);
      for (int i = (0); i < (n); ++i)
        if (d[i] != LLONG_MAX) pot[i] += d[i];
      ret.first += flow[t], ret.second += pot[t] * flow[t];
      for (int at = t; at != s; at = gto[bck[at]]) {
        gcap[bck[at]] += flow[t];
        gcap[bck[at] ^ 1] -= flow[t];
      }
    }
    return ret;
  }
} MCMF;
const int MAXN = 20;
const int MAXPLAYER = 1 << MAXN;
const int MAXEDGE = MAXPLAYER * MAXN / 2;
const int MAXPAIR = 200;
int n, nplayer, npair;
int gain[MAXPLAYER];
pair<int, pair<int, int>> e[MAXEDGE];
int nedge;
MCMF mcmf;
int solve() {
  nedge = 0;
  for (int i = (0); i < (nplayer); ++i)
    for (int j = (0); j < (n); ++j)
      if ((i & (1 << j)) == 0)
        e[nedge++] =
            make_pair(gain[i] + gain[i ^ (1 << j)], make_pair(i, i ^ (1 << j)));
  sort(e, e + nedge,
       [&](const pair<int, pair<int, int>>& a,
           const pair<int, pair<int, int>>& b) { return a.first > b.first; });
  set<pair<int, int>> useedge;
  set<int> useplayer;
  set<int> needplayer;
  for (int i = (0); i < (nedge); ++i)
    if (((int)(needplayer).size()) < 4 * npair) {
      int a = e[i].second.first, b = e[i].second.second;
      if (needplayer.count(a) || needplayer.count(b)) {
        assert(useplayer.count(a) && useplayer.count(b) &&
               useedge.count(make_pair(min(a, b), max(a, b))));
        continue;
      }
      for (int it = (0); it < (2); ++it) {
        needplayer.insert(a);
        useplayer.insert(a);
        for (int j = (0); j < (n); ++j) {
          int c = a ^ (1 << j);
          useedge.insert(make_pair(min(a, c), max(a, c)));
          useplayer.insert(c);
        }
        swap(a, b);
      }
      assert(useplayer.count(a) && useplayer.count(b) &&
             useedge.count(make_pair(min(a, b), max(a, b))));
    }
  vector<int> playerlst(useplayer.begin(), useplayer.end());
  int k = ((int)(playerlst).size());
  vector<int> side(k);
  for (int i = (0); i < (k); ++i) {
    int cnt = 0;
    for (int j = (0); j < (n); ++j)
      if (playerlst[i] & (1 << j)) ++cnt;
    side[i] = cnt % 2;
  }
  int nid = k;
  int ssid = nid++;
  int sid = nid++;
  int tid = nid++;
  mcmf.init(nid);
  mcmf.addedge(ssid, sid, npair, 0);
  for (int i = (0); i < (k); ++i)
    if (side[i] == 0) mcmf.addedge(sid, i, 1, -gain[playerlst[i]]);
  for (int i = (0); i < (k); ++i)
    if (side[i] == 1) mcmf.addedge(i, tid, 1, -gain[playerlst[i]]);
  for (auto z : useedge) {
    int i = lower_bound(playerlst.begin(), playerlst.end(), z.first) -
            playerlst.begin();
    assert(i < ((int)(playerlst).size()) && playerlst[i] == z.first);
    int j = lower_bound(playerlst.begin(), playerlst.end(), z.second) -
            playerlst.begin();
    assert(j < ((int)(playerlst).size()) && playerlst[j] == z.second);
    if (side[i] != 0) swap(i, j);
    assert(side[i] == 0 && side[j] == 1);
    mcmf.addedge(i, j, 1, 0);
  }
  return -mcmf.solve(ssid, tid).second;
}
void run() {
  scanf("%d%d", &n, &npair);
  nplayer = 1 << n;
  for (int i = (0); i < (nplayer); ++i) scanf("%d", &gain[i]);
  printf("%d\n", solve());
}
int main() {
  run();
  return 0;
}
