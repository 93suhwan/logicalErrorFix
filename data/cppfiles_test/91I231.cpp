#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char* x) { cerr << '\"' << x << '\"'; }
void __print(const string& x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V>& x) {
  cerr << '{';
  __print(x.first);
  cerr << ", ";
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T& x) {
  int first = 0;
  cerr << '{';
  for (auto& i : x) cerr << (first++ ? ", " : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100011;
vector<pair<long long, int>> threes[MX];
set<pair<long long, int>> extras[MX];
set<pair<int, pair<long long, long long>>> edges;
long long tri[MX];
set<pair<long long, long long>> tris;
const long long INF = 1e10;
map<pair<int, int>, long long> lens;
void updTri(int p) {
  tris.erase({tri[p], p});
  if ((int)(threes[p]).size() < 3) {
    tri[p] = INF;
  } else {
    tri[p] = 0;
    for (auto& a : threes[p]) tri[p] += a.first;
  }
  tris.insert({tri[p], p});
}
void addEdge(int X, int Y, long long Z) {
  if (X > Y) swap(X, Y);
  lens[make_pair(X, Y)] = Z;
  vector<int> ps = {X, Y};
  for (auto& a : ps) {
    pair<long long, int> cur = {Z, X + Y - a};
    threes[a].push_back(cur);
    sort(threes[a].begin(), threes[a].end());
    if ((int)(threes[a]).size() <= 3 || threes[a][3] != cur) {
      edges.insert({Z, {a, X + Y - a}});
      if ((int)(threes[a]).size() > 3) {
        edges.erase({threes[a][3].first, {a, threes[a][3].second}});
      }
    }
    if ((int)(threes[a]).size() > 3) {
      extras[a].insert({threes[a][3].first, threes[a][3].second});
      threes[a].pop_back();
    }
    updTri(a);
  }
}
void remEdge(int X, int Y) {
  if (X > Y) swap(X, Y);
  long long Z = lens[make_pair(X, Y)];
  vector<int> ps = {X, Y};
  for (auto& a : ps) {
    pair<long long, int> cur = {Z, X + Y - a};
    int p = 0;
    for (auto& b : threes[a]) {
      if (b == cur) {
        threes[a].erase(threes[a].begin() + p);
        edges.erase({cur.first, {a, cur.second}});
      }
      p++;
    }
    if ((int)(threes[a]).size() < 3 && (int)(extras[a]).size()) {
      pair<long long, int> tba = *extras[a].begin();
      extras[a].erase(extras[a].begin());
      threes[a].push_back(tba);
      edges.insert({tba.first, {a, tba.second}});
    }
    updTri(a);
  }
}
long long outAns() {
  long long ans = tris.begin()->first;
  pair<long long, pair<int, int>> firEd = *edges.begin();
  int x = firEd.second.first, y = firEd.second.second;
  for (auto& a : threes[x]) {
    for (auto& b : threes[y]) {
      if (x != b.second && y != a.second && b.second != a.second) {
        ckmin(ans, a.first + b.first);
      }
    }
  }
  for (auto& a : edges) {
    if (a.second.first != x && a.second.first != y && a.second.second != x &&
        a.second.second != y) {
      ckmin(ans, firEd.first + a.first);
      break;
    }
  }
  return ans;
}
void solve() {
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < (N); i++) {
    tri[i] = INF;
    tris.insert({INF, i});
  }
  while (M--) {
    int X, Y;
    long long Z;
    cin >> X >> Y >> Z;
    X--;
    Y--;
    if (X > Y) swap(X, Y);
    addEdge(X, Y, Z);
  }
  int Q;
  cin >> Q;
  cout << outAns() << nl;
  for (int i = 0; i < (Q); i++) {
    int T, X, Y;
    cin >> T >> X >> Y;
    X--;
    Y--;
    if (T) {
      long long Z;
      cin >> Z;
      addEdge(X, Y, Z);
    } else {
      remEdge(X, Y);
    }
    cout << outAns() << nl;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
