#include <bits/stdc++.h>
using namespace std;
std::mt19937 rnd(
    (int)std::chrono::steady_clock::now().time_since_epoch().count());
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const int MAXN = 200000;
const int MAXQ = 200000;
struct Block {
  int lpos, rpos;
  int best, best2;
};
int n, m, nq;
int scost[MAXN];
vector<pair<int, int>> adj[MAXN];
int qidx[MAXQ], qdelta[MAXQ];
long long qans[MAXQ + 1];
long long d[MAXN];
int par[MAXN];
int pos[MAXN], ord[MAXN], nord;
bool done[MAXN];
int suffpos[MAXN];
long long ccost[MAXN];
map<int, Block> blocks;
set<int> bestchanges;
int totcount[MAXN + 1];
vector<int> ch[MAXN];
int best2count(int lpos, int rpos, int at) {
  if (at == 0) return 0;
  int r = upper_bound(ch[at].begin(), ch[at].end(), rpos) - ch[at].begin();
  int l = lower_bound(ch[at].begin(), ch[at].end(), lpos) - ch[at].begin();
  return r - l;
}
int bestcount(int lpos, int rpos, int at) {
  return totcount[rpos + 1] - totcount[lpos] - best2count(lpos, rpos, at);
}
long long calc(const Block& b) {
  int cnt = totcount[b.rpos + 1] - totcount[b.lpos];
  if (cnt == 0) return 0;
  assert(b.best != -1);
  long long ret = (long long)cnt * ccost[b.best];
  if (b.best != 0) {
    assert(b.best2 != -1);
    ret +=
        (ccost[b.best2] - ccost[b.best]) * best2count(b.lpos, b.rpos, b.best);
  }
  return ret;
}
void solve() {
  for (int i = (0); i < (n); ++i) d[i] = LLONG_MAX;
  priority_queue<pair<long long, int>> pq;
  auto relax = [&](int at, int to, long long val) {
    if (val >= d[to]) return;
    d[to] = val;
    par[to] = at;
    pq.push(make_pair(-val, -to));
  };
  relax(-1, 0, 0);
  nord = 0;
  while (!pq.empty()) {
    int at = -pq.top().second;
    long long val = -pq.top().first;
    pq.pop();
    if (val != d[at]) continue;
    pos[at] = nord, ord[nord] = at, ++nord;
    for (int i = (0); i < (((int)(adj[at]).size())); ++i) {
      int to = adj[at][i].first;
      long long nval = val + adj[at][i].second;
      relax(at, to, nval);
    }
  }
  assert(nord == n);
  for (int at = (0); at < (n); ++at) {
    done[at] = at == 0;
    for (int i = (0); i < (((int)(adj[at]).size())); ++i) {
      int to = adj[at][i].first;
      int len = adj[at][i].second;
      if (to != par[at] && d[to] + len == d[at]) done[at] = true;
    }
  }
  for (int i = (0); i < (n); ++i) {
    int at = ord[i];
    suffpos[at] = i == 0 ? 0 : suffpos[ord[i - 1]];
    while (suffpos[at] < n && d[ord[suffpos[at]]] <= d[at]) ++suffpos[at];
  }
  totcount[0] = 0;
  for (int i = (0); i < (n); ++i)
    totcount[i + 1] = totcount[i] + (!done[ord[i]] ? 1 : 0);
  for (int i = (0); i < (n); ++i) ch[i].clear();
  for (int i = (0); i < (n); ++i) {
    int at = ord[i];
    if (!done[at] && par[at] != -1) ch[par[at]].push_back(i);
  }
  for (int i = (0); i < (n); ++i) ccost[i] = scost[i];
  for (int i = (0); i < (nq); ++i) ccost[qidx[i]] += qdelta[i];
  {
    blocks.clear();
    bestchanges.clear();
    Block b;
    b.lpos = 0, b.best = b.best2 = -1;
    bestchanges.insert(0);
    for (int i = (0); i < (n); ++i) {
      int at = ord[i];
      if (b.best2 != -1 && ccost[at] >= ccost[b.best2]) continue;
      b.rpos = suffpos[at] - 1;
      if (b.lpos <= b.rpos) blocks[b.lpos] = b;
      b.lpos = suffpos[at];
      if (b.best == -1 || ccost[at] < ccost[b.best])
        b.best2 = b.best, b.best = at, bestchanges.insert(b.lpos);
      else
        b.best2 = at;
    }
    b.rpos = n - 1;
    if (b.lpos <= b.rpos) blocks[b.lpos] = b;
  }
  long long curans = 0;
  for (const auto& p : blocks) {
    const auto& b = p.second;
    curans += calc(b);
  }
  qans[nq] = curans;
  for (int i = nq - 1; i >= -1; --i) {
    if (i == -1) break;
    int at = qidx[i];
    long long ocost = ccost[at], ncost = ccost[at] - qdelta[i];
    auto it = prev(blocks.lower_bound(suffpos[at] + 1));
    if (it->second.best == at || it->second.best2 == at ||
        it->second.best2 == -1 || ncost < ccost[it->second.best2]) {
      if (it->first != suffpos[at]) {
        Block b = it->second;
        it->second.rpos = suffpos[at] - 1;
        b.lpos = suffpos[at];
        it = blocks.insert(make_pair(suffpos[at], b)).first;
      }
      if (it->second.best == at) {
        auto jt = bestchanges.upper_bound(suffpos[at]);
        int topos = jt == bestchanges.end() ? n : *jt;
        curans -= (long long)qdelta[i] * bestcount(suffpos[at], topos - 1, at);
        it = topos == n ? blocks.end() : blocks.find(topos);
      }
      auto update = [&](Block& b) {
        assert(b.best != at);
        if (b.best2 == at) {
          if (ncost < ccost[b.best]) swap(b.best, b.best2);
          return true;
        }
        if (b.best2 != -1 && ncost >= ccost[b.best2]) return false;
        if (b.best == -1 || ncost < ccost[b.best])
          b.best = b.best2, b.best = at;
        else
          b.best2 = at;
        return true;
      };
      while (it != blocks.end()) {
        curans -= calc(it->second);
        bool change = update(it->second);
        ccost[at] = ncost;
        curans += calc(it->second);
        ccost[at] = ocost;
        if (!change) break;
        if (it != blocks.begin()) {
          auto pt = prev(it);
          if (pt->second.best == it->second.best)
            bestchanges.erase(it->first);
          else
            bestchanges.insert(it->first);
          if (pt->second.best == it->second.best &&
              pt->second.best2 == it->second.best2) {
            pt->second.rpos = it->second.rpos;
            blocks.erase(it);
            it = pt;
          }
        }
        ++it;
      }
    }
    ccost[at] = ncost;
    qans[i] = curans;
  }
}
void run() {
  scanf("%d%d%d", &n, &m, &nq);
  for (int i = (0); i < (n); ++i) scanf("%d", &scost[i]);
  for (int i = (0); i < (m); ++i) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    --a, --b;
    adj[a].push_back(make_pair(b, c));
    adj[b].push_back(make_pair(a, c));
  }
  for (int i = (0); i < (nq); ++i)
    scanf("%d%d", &qidx[i], &qdelta[i]), --qidx[i];
  solve();
  for (int i = (0); i <= (nq); ++i) printf("%lld\n", qans[i]);
}
int main() {
  run();
  return 0;
}
