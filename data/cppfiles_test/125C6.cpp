#include <bits/stdc++.h>
using namespace std;
void per() { cerr << endl; }
template <typename Head, typename... Tail>
void per(Head H, Tail... T) {
  cerr << H << ' ';
  per(T...);
}
template <class T>
bool uin(T& a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
bool uax(T& a, T b) {
  return a < b ? (a = b, true) : false;
}
template <class U, class V>
ostream& operator<<(ostream& out, const pair<U, V>& a) {
  return out << "(" << a.first << ", " << a.second << ")";
}
template <class U, class V>
istream& operator>>(istream& in, pair<U, V>& a) {
  return in >> a.first >> a.second;
}
template <typename W,
          typename T = typename enable_if<!is_same<W, string>::value,
                                          typename W::value_type>::type>
ostream& operator<<(ostream& out, const W& v) {
  out << "{ ";
  for (const auto& first : v) out << first << ", ";
  return out << '}';
}
template <class T>
void readArr(T from, T to) {
  for (auto i = from; i != to; ++i) cin >> *i;
}
mt19937 mrand(1337);
unsigned int myRand32() { return mrand() & (unsigned int)(-1); }
unsigned long long myRand64() {
  return ((unsigned long long)myRand32() << 32) ^ myRand32();
}
const int mod = 1000000007;
void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}
void dec(int& a, int b) {
  a -= b;
  if (a < 0) a += mod;
}
int mult(int a, int b) { return a * (long long)b % mod; }
int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}
struct Seg {
  int l;
  int r;
  int opposite;
};
vector<vector<Seg> > one;
vector<vector<Seg> > two;
vector<bool> dused;
vector<int> current;
int start;
void dfs(int vertex, int kek) {
  dused[vertex] = 1;
  current.push_back(vertex);
  for (auto e : one[vertex]) {
    int W = e.opposite;
    if (e.l == kek) continue;
    if (dused[W]) {
      start = vertex;
      continue;
    }
    dfs(W, e.l);
  }
}
vector<int> v;
void add_seg(int l, int r, int first) {
  if (v[l - 1] == first)
    v[l] = first;
  else
    v[r] = first;
}
void dfs2(int vertex, int is_start) {
  dused[vertex] = 1;
  for (auto e : one[vertex]) {
    int W = e.opposite;
    if (dused[W]) {
      if (is_start) {
        add_seg(e.l, e.r, vertex);
      }
      continue;
    }
    add_seg(e.l, e.r, W);
    dfs2(W, 0);
  }
}
struct GeneralMatching {
  static const int MAXN = 50000;
  vector<int> g[MAXN];
  int pa[MAXN], match[MAXN], st[MAXN], S[MAXN], v[MAXN];
  int t, Q;
  inline int lca(int first, int second) {
    for (++t;; swap(first, second)) {
      if (first == 0) continue;
      if (v[first] == t) return first;
      v[first] = t;
      first = st[pa[match[first]]];
    }
  }
  void flower(int first, int second, int l, queue<int>& q) {
    while (st[first] != l) {
      pa[first] = second;
      second = match[first];
      if (S[second] == 1) q.push(second), S[second] = 0;
      st[first] = st[second] = l;
      first = pa[second];
    }
  }
  bool bfs(int first) {
    for (int i = 1; i <= Q; ++i) st[i] = i;
    memset(S + 1, -1, sizeof(int) * Q);
    queue<int> q;
    q.push(first), S[first] = 0;
    while (q.size()) {
      first = q.front(), q.pop();
      for (size_t i = 0; i < g[first].size(); ++i) {
        int second = g[first][i];
        if (S[second] == -1) {
          pa[second] = first;
          S[second] = 1;
          if (!match[second]) {
            for (int lst; first; second = lst, first = pa[second]) {
              lst = match[first];
              match[first] = second;
              match[second] = first;
            }
            return 1;
          }
          q.push(match[second]), S[match[second]] = 0;
        } else if (!S[second] && st[second] != st[first]) {
          int l = lca(second, first);
          flower(second, first, l, q);
          flower(first, second, l, q);
        }
      }
    }
    return 0;
  }
  vector<pair<int, int> > blossom() {
    int ans = 0;
    for (int i = 1; i <= Q; ++i)
      if (!match[i] && bfs(i)) ++ans;
    vector<pair<int, int> > res;
    for (int i = 1; i <= Q; ++i) {
      if (match[i] != 0 && i < match[i]) {
        res.push_back({i - 1, match[i] - 1});
      }
    }
    return res;
  }
  GeneralMatching(int n, vector<pair<int, int> > edges) {
    Q = n;
    for (int i = 0; i < edges.size(); ++i) {
      int u = edges[i].first + 1;
      int v = edges[i].second + 1;
      g[u].push_back(v);
      g[v].push_back(u);
    }
  }
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  v.resize(n);
  for (auto& first : v) cin >> first;
  vector<bool> used(n + 1, false);
  one.assign(n + 1, {});
  two.assign(n + 1, {});
  for (int i = 0; i < n; ++i) {
    if (v[i] == 0 && (i == 0 || v[i - 1] > 0)) {
      int j = i + 1;
      while (j < n && v[j] == 0) j++;
      --j;
      if ((j % 2) == (i % 2)) {
        if (i == 0 && j == n - 1) {
          continue;
        }
        if (i == 0) {
          v[j] = v[j + 1];
        } else if (j == n - 1) {
          v[i] = v[i - 1];
        } else {
          int a = v[i - 1], b = v[j + 1];
          one[a].push_back({i, j, b});
          one[b].push_back({i, j, a});
        }
      } else {
        if (i == 0 || j == n - 1) {
          continue;
        }
        int a = v[i - 1], b = v[j + 1];
        two[a].push_back({i, j, b});
        two[b].push_back({i, j, a});
      }
    }
  }
  dused.assign(n + 1, false);
  for (int i = 1; i < n; ++i) {
    if (v[i] == v[i - 1] && v[i] > 0) used[v[i]] = 1;
  }
  vector<vector<int> > bad_compontents;
  for (int i = 1; i <= n && i <= 600; ++i) {
    if (dused[i]) continue;
    current.clear();
    start = -1;
    dfs(i, -1);
    for (auto first : current)
      if (used[first]) start = first;
    if (start == -1) {
      bad_compontents.push_back(current);
    } else {
      for (auto first : current) dused[first] = false;
      dfs2(start, 1);
    }
  }
  vector<int> index(n + 1, -1);
  for (int i = 0; i < bad_compontents.size(); ++i) {
    for (auto first : bad_compontents[i]) index[first] = i;
  }
  int N = bad_compontents.size();
  vector<pair<int, int> > edges;
  map<pair<int, int>, int> ae;
  vector<pair<int, int> > taken;
  vector<pair<int, int> > seg;
  for (int i = 1; i <= n; ++i) {
    for (auto first : two[i]) {
      int W = first.opposite;
      if (index[i] == -1 || index[W] == -1) continue;
      int A = index[i], B = index[W];
      if (A >= B) continue;
      if (ae.count(make_pair(A, B))) continue;
      ae[make_pair(A, B)] = edges.size();
      edges.push_back(make_pair(A, B));
      taken.push_back(make_pair(i, W));
      seg.push_back(make_pair(first.l, first.r));
    }
  }
  GeneralMatching g(N, edges);
  auto res = g.blossom();
  vector<bool> kused(N, false);
  for (auto ee : res) {
    kused[ee.first] = 1;
    kused[ee.second] = 1;
    if (ee.first > ee.second) swap(ee.first, ee.second);
    int R = ae[ee];
    int A = taken[R].first, B = taken[R].second;
    int C = seg[R].first, D = seg[R].second;
    v[C] = v[C - 1];
    v[D] = v[D + 1];
    for (auto first : bad_compontents[ee.first]) dused[first] = 0;
    dfs2(A, 1);
    for (auto first : bad_compontents[ee.second]) dused[first] = 0;
    dfs2(B, 1);
  }
  for (int i = 0; i < bad_compontents.size(); ++i) {
    if (!kused[i]) {
      for (auto first : bad_compontents[i]) dused[first] = 0;
      dfs2(bad_compontents[i][0], 1);
    }
  }
  for (int i = 1; i < n; ++i) {
    if (v[i] == v[i - 1] && v[i] > 0) used[v[i]] = 1;
  }
  vector<int> nn;
  for (int i = 1; i <= n; ++i)
    if (!used[i]) nn.push_back(i);
  int cur = 0;
  while (cur + 1 < n) {
    if (v[cur] == 0 && v[cur + 1] == 0) {
      int W = nn.back();
      v[cur] = W;
      v[cur + 1] = W;
      cur += 2;
      nn.pop_back();
    } else {
      if (v[cur] == 0) v[cur] = 1;
      cur++;
    }
  }
  if (v.back() == 0) v.back() = 1;
  for (auto first : v) cout << first << " ";
}
