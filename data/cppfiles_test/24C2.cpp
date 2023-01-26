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
unsigned long long qans[MAXQ + 1];
long long d[MAXN];
int par[MAXN];
int pos[MAXN], ord[MAXN], nord;
bool done[MAXN];
int suffpos[MAXN];
unsigned long long ccost[MAXN];
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
unsigned long long calc(const Block& b) {
  int cnt = totcount[b.rpos + 1] - totcount[b.lpos];
  if (cnt == 0) return 0;
  assert(b.best != -1);
  unsigned long long ret = cnt * ccost[b.best];
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
  unsigned long long curans = 0;
  for (const auto& p : blocks) {
    const auto& b = p.second;
    curans += calc(b);
  }
  qans[nq] = curans;
  for (int i = nq - 1; i >= -1; --i) {
    if (i == -1) break;
    int at = qidx[i];
    unsigned long long ocost = ccost[at], ncost = ccost[at] - qdelta[i];
    auto it = prev(blocks.lower_bound(suffpos[at] + 1));
    if (suffpos[at] < n &&
        (it->second.best == at || it->second.best2 == at ||
         it->second.best2 == -1 || ncost < ccost[it->second.best2])) {
      if (it->first != suffpos[at]) {
        Block b = it->second;
        it->second.rpos = suffpos[at] - 1;
        b.lpos = suffpos[at];
        it = blocks.insert(make_pair(suffpos[at], b)).first;
      }
      if (it->second.best == at) {
        auto jt = bestchanges.upper_bound(suffpos[at]);
        int topos = jt == bestchanges.end() ? n : *jt;
        curans -= (unsigned long long)qdelta[i] *
                  bestcount(suffpos[at], topos - 1, at);
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
          b.best2 = b.best, b.best = at;
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
  for (int i = (0); i <= (nq); ++i) printf("%llu\n", qans[i]);
}
unsigned long long qansstupid[MAXQ];
void solvestupid() {
  vector<vector<long long>> d(n, vector<long long>(n, LLONG_MAX));
  for (int i = (0); i < (n); ++i) d[i][i] = 0;
  for (int at = (0); at < (n); ++at)
    for (const auto& e : adj[at]) {
      int to = e.first, len = e.second;
      d[at][to] = d[to][at] = len;
    }
  for (int k = (0); k < (n); ++k)
    for (int i = (0); i < (n); ++i)
      for (int j = (0); j < (n); ++j)
        if (d[i][k] != LLONG_MAX && d[k][j] != LLONG_MAX)
          d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
  for (int i = (0); i < (n); ++i) assert(d[0][i] != LLONG_MAX);
  for (int i = (0); i < (n); ++i) par[i] = -1, done[i] = i == 0;
  for (int at = (0); at < (n); ++at)
    for (const auto& e : adj[at]) {
      int to = e.first, len = e.second;
      if (d[0][to] == d[0][at] + len) {
        if (par[to] == -1)
          par[to] = at;
        else
          done[to] = true;
      }
    }
  for (int i = (0); i < (n); ++i) ccost[i] = scost[i];
  for (int i = (0); i <= (nq); ++i) {
    qansstupid[i] = 0;
    for (int to = (0); to < (n); ++to)
      if (!done[to]) {
        unsigned long long best = ccost[0];
        for (int at = (1); at < (n); ++at)
          if (d[0][at] < d[0][to] && at != par[to]) best = min(best, ccost[at]);
        qansstupid[i] += best;
      }
    if (i == nq) break;
    ccost[qidx[i]] += qdelta[i];
  }
}
void stress() {
  std::mt19937 rnd(1234);
  int nmx = 100, cmx = 4, qmx = 10, costmx = 10;
  for (int rep = (0); rep < (100000); ++rep) {
    n = rnd() % nmx + 1;
    m = n - 1 + rnd() % (n * (n - 1) / 2 - (n - 1) + 1);
    for (int i = (0); i < (n); ++i) scost[i] = rnd() % costmx + 1;
    vector<int> col(n);
    for (int i = (0); i < (n); ++i) col[i] = i;
    set<pair<int, int>> edges;
    for (int i = (0); i < (n - 1); ++i)
      while (true) {
        int a = rnd() % n, b = rnd() % n;
        if (col[a] == col[b]) continue;
        int ocol = col[b];
        for (int j = (0); j < (n); ++j)
          if (col[j] == ocol) col[j] = col[a];
        edges.insert(make_pair(min(a, b), max(a, b)));
        break;
      }
    for (int i = (0); i < (m - (n - 1)); ++i)
      while (true) {
        int a = rnd() % n, b = rnd() % n;
        if (a > b) swap(a, b);
        if (a == b || edges.count(make_pair(a, b))) continue;
        edges.insert(make_pair(a, b));
        break;
      }
    vector<pair<int, int>> elst(edges.begin(), edges.end());
    vector<int> ecost;
    shuffle(elst.begin(), elst.end(), rnd);
    for (int i = (0); i < (n); ++i) adj[i].clear();
    for (const auto& e : elst) {
      int a = e.first, b = e.second, c = rnd() % cmx + 1;
      adj[a].push_back(make_pair(b, c));
      adj[b].push_back(make_pair(a, c));
      ecost.push_back(c);
    }
    nq = rnd() % (qmx + 1);
    for (int i = (0); i < (nq); ++i)
      qidx[i] = rnd() % n, qdelta[i] = rnd() % costmx + 1;
    solve();
    solvestupid();
    bool ok = true;
    for (int i = (0); i <= (nq); ++i)
      if (qans[i] != qansstupid[i]) ok = false;
    if (ok) {
      if (rep % 100 == 99) printf(".");
      continue;
    }
    printf("err rep=%d\n", rep);
    printf("have:");
    for (int i = (0); i <= (nq); ++i) printf(" %llu", qans[i]);
    puts("");
    printf("want:");
    for (int i = (0); i <= (nq); ++i) printf(" %llu", qansstupid[i]);
    puts("");
    printf("%d %d %d\n", n, m, nq);
    for (int i = (0); i < (n); ++i) {
      if (i != 0) printf(" ");
      printf("%d", scost[i]);
    }
    puts("");
    for (int i = (0); i < (((int)(elst).size())); ++i) {
      printf("%d %d %d\n", elst[i].first + 1, elst[i].second + 1, ecost[i]);
    }
    for (int i = (0); i < (nq); ++i) printf("%d %d\n", qidx[i] + 1, qdelta[i]);
    nmx = max(1, n - 1);
    qmx = max(0, nq - 1);
  }
}
int main() {
  run();
  return 0;
}
