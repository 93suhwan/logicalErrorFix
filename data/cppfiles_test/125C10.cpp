#include <bits/stdc++.h>
using namespace std;
std::mt19937 rnd(
    (int)std::chrono::steady_clock::now().time_since_epoch().count());
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
namespace MaxGeneralMatching {
vector<int> solve(int n, vector<pair<int, int>> edges, vector<int> matches) {
  vector<bool> ismatched(((int)(edges).size()), false);
  vector<int> match(n, -1);
  for (int id : matches)
    match[edges[id].first] = match[edges[id].second] = id, ismatched[id] = true;
  vector<vector<int>> adj(n);
  for (int id = (0); id < (((int)(edges).size())); ++id)
    adj[edges[id].first].push_back(id), adj[edges[id].second].push_back(id);
  while (true) {
    vector<int> parid(n, -1);
    vector<int> col(n, -1);
    bool found = false;
    for (int start = (0); start < (n); ++start)
      if (match[start] == -1) {
        parid[start] = -1;
        col[start] = 0;
        vector<pair<int, int>> stck;
        stck.push_back(make_pair(start, 0));
        while (!stck.empty()) {
          int at = stck.back().first, idx = stck.back().second;
          stck.pop_back();
          if (idx >= ((int)(adj[at]).size())) continue;
          stck.push_back(make_pair(at, idx + 1));
          int id = adj[at][idx];
          if (id == match[at]) continue;
          assert(col[at] == 0);
          int to = edges[id].first ^ edges[id].second ^ at;
          if (col[to] == 0) {
            vector<int> pathnodes;
            vector<int> pathedges;
            for (int x = at;;) {
              pathnodes.push_back(x);
              if (x == to) break;
              int xid = parid[x];
              pathedges.push_back(xid);
              x ^= edges[xid].first ^ edges[xid].second;
            }
            pathedges.push_back(id);
            vector<int> mp(n, -1);
            int subn = 1;
            for (int x : pathnodes) mp[x] = 0;
            for (int x = (0); x < (n); ++x)
              if (mp[x] == -1) mp[x] = subn++;
            vector<pair<int, int>> subedges;
            vector<int> edgemp(((int)(edges).size()), -1);
            vector<int> revedgemp;
            for (int i = (0); i < (((int)(edges).size())); ++i)
              if (mp[edges[i].first] != mp[edges[i].second])
                edgemp[i] = ((int)(subedges).size()), revedgemp.push_back(i),
                subedges.push_back(
                    make_pair(mp[edges[i].first], mp[edges[i].second]));
            vector<int> submatches;
            for (int x = (0); x < (n); ++x)
              if (match[x] != -1 && x == edges[match[x]].first &&
                  edgemp[match[x]] != -1)
                submatches.push_back(edgemp[match[x]]);
            submatches = solve(subn, subedges, submatches);
            vector<int> ret;
            for (int x : submatches) ret.push_back(revedgemp[x]);
            for (int x = (0); x < (n); ++x) match[x] = -1;
            for (int x : ret)
              match[edges[x].first] = match[edges[x].second] = x;
            for (int i = (0); i < (((int)(pathnodes).size())); ++i)
              if (match[pathnodes[i]] != -1) {
                rotate(pathnodes.begin(), pathnodes.begin() + i,
                       pathnodes.end());
                rotate(pathedges.begin(), pathedges.begin() + i,
                       pathedges.end());
                break;
              }
            for (int i = 1; i < ((int)(pathedges).size()); i += 2)
              ret.push_back(pathedges[i]);
            return ret;
          }
          if (col[to] == 1) {
            continue;
          }
          col[to] = 1;
          parid[to] = id;
          if (match[to] == -1) {
            vector<int> pathnodes;
            vector<int> pathedges;
            for (int x = to;;) {
              pathnodes.push_back(x);
              int xid = parid[x];
              if (xid == -1) break;
              pathedges.push_back(xid);
              x ^= edges[xid].first ^ edges[xid].second;
            }
            assert(((int)(pathedges).size()) % 2 == 1);
            for (int i = (0); i < (((int)(pathedges).size())); ++i)
              assert(ismatched[pathedges[i]] == (i % 2 == 1));
            for (int id : pathedges) ismatched[id] = !ismatched[id];
            for (int i = 1; i < ((int)(pathedges).size()); i += 2) {
              int x = pathnodes[i], y = pathnodes[i + 1];
              assert(match[x] == pathedges[i] && match[y] == pathedges[i]);
            }
            for (int i = 0; i < ((int)(pathedges).size()); i += 2) {
              int x = pathnodes[i], y = pathnodes[i + 1];
              match[x] = match[y] = pathedges[i];
            }
            found = true;
            break;
          } else {
            int matchid = match[to];
            int nxt = edges[matchid].first ^ edges[matchid].second ^ to;
            assert(col[nxt] == -1);
            col[nxt] = 0;
            parid[nxt] = matchid;
            stck.push_back(make_pair(nxt, 0));
          }
        }
        if (found) break;
      }
    if (!found) {
      vector<int> ret;
      for (int i = (0); i < (((int)(edges).size())); ++i)
        if (ismatched[i]) ret.push_back(i);
      return ret;
    }
  }
}
vector<int> solve(int n, vector<pair<int, int>> edges) {
  vector<int> ret = solve(n, edges, vector<int>());
  return ret;
}
};  // namespace MaxGeneralMatching
struct UF {
  int n;
  vector<int> par, sz;
  void init(int _n) {
    n = _n;
    par = sz = vector<int>(n);
    for (int i = (0); i < (n); ++i) par[i] = i, sz[i] = 1;
  }
  int find(int x) {
    if (par[x] != x) par[x] = find(par[x]);
    return par[x];
  }
  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    if (sz[x] < sz[y]) swap(x, y);
    par[y] = x, sz[x] += sz[y];
    return true;
  }
};
const int MAXN = 300000;
struct Seg {
  int l, r, x, y;
  Seg(int l, int r, int x, int y) : l(l), r(r), x(x), y(y) {}
};
struct OddEdge {
  int to, pos, id;
  OddEdge(int to, int pos, int id) : to(to), pos(pos), id(id) {}
};
int n;
int a[MAXN];
int ans[MAXN];
bool have[MAXN];
vector<OddEdge> oddadj[MAXN];
bool oddbeen[MAXN];
int oddcomp[MAXN];
void dfsodd(int at) {
  if (oddbeen[at])
    return;
  else
    oddbeen[at] = true;
  for (auto e : oddadj[at]) {
    if (!have[e.to]) {
      ans[e.pos] = e.to;
      have[e.to] = true;
    }
    dfsodd(e.to);
  }
}
void dfscomp(int at, int c) {
  if (oddcomp[at] != -1)
    return;
  else
    oddcomp[at] = c;
  for (auto e : oddadj[at]) dfscomp(e.to, c);
}
int dfscycle(int at, int parid) {
  if (oddbeen[at])
    return at;
  else
    oddbeen[at] = true;
  for (auto e : oddadj[at]) {
    if (e.id == parid) continue;
    int sub = dfscycle(e.to, e.id);
    if (sub == -1) return -1;
    if (sub >= 0) {
      ans[e.pos] = e.to;
      have[e.to] = true;
      return sub == at ? -1 : sub;
    }
  }
  return -2;
}
void solve() {
  for (int i = (0); i < (n); ++i) ans[i] = a[i];
  for (int i = (0); i < (n); ++i) have[i] = false;
  for (int i = (0); i < (n - 1); ++i)
    if (a[i] >= 0 && a[i + 1] >= 0 && a[i] == a[i + 1]) have[a[i]] = true;
  vector<Seg> odd, evn;
  for (int l = 0, r = l; l < n; l = r) {
    while (r < n && a[r] == -1) ++r;
    int cnt = r - l;
    if (cnt == 0) {
      ++r;
      continue;
    }
    Seg s(l, r - 1, l == 0 ? -1 : a[l - 1], r == n ? -1 : a[r]);
    if (s.x == -1 && s.y != -1 && cnt % 2 == 1)
      ans[s.r] = s.y, have[s.y] = true, --s.r, --cnt;
    if (s.y == -1 && s.x != -1 && cnt % 2 == 1)
      ans[s.l] = s.x, have[s.x] = true, ++s.l, --cnt;
    if ((s.x == -1 || s.y == -1) && cnt % 2 == 1) {
      assert(s.x == -1 && s.y == -1);
      ans[s.r] = n - 1, --s.r, --cnt;
    }
    if (cnt % 2 == 0)
      evn.push_back(s);
    else
      odd.push_back(s);
  }
  for (int i = (0); i < (n); ++i) oddadj[i].clear();
  for (int i = (0); i < (((int)(odd).size())); ++i) {
    Seg s = odd[i];
    oddadj[s.x].push_back(OddEdge(s.y, s.r, i));
    oddadj[s.y].push_back(OddEdge(s.x, s.l, i));
  }
  for (int i = (0); i < (n); ++i) oddbeen[i] = false;
  for (int i = (0); i < (n); ++i)
    if (have[i]) dfsodd(i);
  for (int i = (0); i < (n); ++i) oddcomp[i] = -1;
  for (int i = (0); i < (n); ++i)
    if (oddcomp[i] == -1) dfscomp(i, i);
  for (int i = (0); i < (n); ++i)
    if (oddcomp[i] == i) dfscycle(i, -1);
  for (int i = (0); i < (n); ++i) oddbeen[i] = false;
  for (int i = (0); i < (n); ++i)
    if (have[i]) dfsodd(i);
  vector<Seg> nodd;
  for (auto s : odd) {
    assert(have[s.x] == have[s.y]);
    if (!have[s.x]) {
      assert(ans[s.l] == -1 && ans[s.r] == -1);
      nodd.push_back(s);
    } else {
      if (s.l == s.r) {
        if (ans[s.l] == -1) ans[s.l] = n - 1;
      } else {
        assert(ans[s.l] == -1 || ans[s.r] == -1);
        if (ans[s.r] != -1)
          --s.r;
        else if (ans[s.l] != -1)
          ++s.l;
        else
          ans[s.r] = n - 1, --s.r;
        evn.push_back(s);
      }
    }
  }
  odd = nodd;
  for (int i = (0); i < (n); ++i) oddadj[i].clear();
  for (int i = (0); i < (((int)(odd).size())); ++i) {
    Seg s = odd[i];
    oddadj[s.x].push_back(OddEdge(s.y, s.r, i));
    oddadj[s.y].push_back(OddEdge(s.x, s.l, i));
  }
  UF uf;
  uf.init(n);
  for (auto s : odd) assert(uf.unite(s.x, s.y));
  vector<Seg> boring, interesting;
  for (auto s : evn) {
    if (s.x == -1 || have[s.x] || s.y == -1 || have[s.y] ||
        uf.find(s.x) == uf.find(s.y))
      boring.push_back(s);
    else
      interesting.push_back(s);
  }
  vector<int> id(n, -1);
  int nid = 0;
  vector<pair<int, int>> evnedges;
  for (auto s : interesting) {
    if (id[uf.find(s.x)] == -1) id[uf.find(s.x)] = nid++;
    if (id[uf.find(s.y)] == -1) id[uf.find(s.y)] = nid++;
    evnedges.push_back(make_pair(id[uf.find(s.x)], id[uf.find(s.y)]));
  }
  assert(nid <= 600);
  vector<int> match = MaxGeneralMatching::solve(nid, evnedges);
  for (int i : match) {
    auto &s = interesting[i];
    assert(!have[s.x] && !have[s.y] && s.x != s.y && s.l != s.r);
    ans[s.l] = s.x, have[s.x] = true, ++s.l;
    ans[s.r] = s.y, have[s.y] = true, --s.r;
  }
  for (auto s : interesting)
    if (s.l <= s.r) boring.push_back(s);
  for (int i = (0); i < (n); ++i)
    if (have[i]) dfsodd(i);
  for (int i = (0); i < (n); ++i)
    if (!have[i]) {
      have[i] = true;
      dfsodd(i);
      have[i] = false;
    }
  for (auto s : odd) {
    if (s.l == s.r) {
      if (ans[s.l] == -1) ans[s.l] = n - 1;
    } else {
      assert(ans[s.l] == -1 || ans[s.r] == -1);
      if (ans[s.r] != -1)
        --s.r;
      else if (ans[s.l] != -1)
        ++s.l;
      else
        ans[s.r] = n - 1, --s.r;
      boring.push_back(s);
    }
  }
  int nxt = 0;
  for (auto s : boring) {
    for (int pos = s.l; pos <= s.r; pos += 2) {
      while (have[nxt]) ++nxt;
      assert(ans[pos] == -1 && ans[pos + 1] == -1);
      ans[pos] = ans[pos + 1] = nxt, have[nxt] = true;
    }
  }
}
void run() {
  scanf("%d", &n);
  for (int i = (0); i < (n); ++i) scanf("%d", &a[i]), --a[i];
  solve();
  for (int i = (0); i < (n); ++i) {
    if (i != 0) printf(" ");
    printf("%d", ans[i] + 1);
  }
  puts("");
}
void stress() {
  std::mt19937 rnd(123213);
  int mxn = 50;
  for (int rep = (0); rep < (1000000); ++rep) {
    n = rnd() % mxn + 1;
    for (int i = (0); i < (n); ++i) a[i] = -1;
    int cnt = rnd() % (n + 1);
    int lim = rnd() % n;
    for (int i = (0); i < (cnt); ++i)
      while (true) {
        int idx = rnd() % n;
        if (a[idx] != -1) continue;
        a[idx] = rnd() % (lim + 1);
        break;
      }
    solve();
    if (rep % 1000 == 999) {
      printf(".");
      fflush(stdout);
    }
  }
}
int main() {
  run();
  return 0;
}
