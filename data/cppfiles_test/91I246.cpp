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
int L = 17;
set<pair<long long, int>> q2[MX];
set<pair<long long, pair<int, int>>> q3;
set<pair<long long, long long>> tris;
long long tri[MX];
map<pair<long long, long long>, int> eds;
pair<int, int> inEd[MX];
pair<long long, int> get(int p, int n) {
  if ((int)(q2[p]).size() < n) return {4e9, -1};
  auto it = q2[p].begin();
  for (int i = 0; i < (n - 1); i++) it++;
  return *it;
}
void updTri(int p) {
  if ((int)(q2[p]).size() < 3) {
    tri[p] = 4e9;
    return;
  }
  auto it = q2[p].begin();
  long long res = 0;
  for (int i = 0; i < (3); i++) {
    res += it->first;
    it++;
  }
  tri[p] = res;
  tris.insert({res, p});
}
void addEdge(int X, int Y, long long Z) {
  if (X < Y) swap(X, Y);
  eds[{X, Y}] = Z;
  vector<int> vals = {X, Y};
  for (auto& a : vals) {
    if (a == Y) continue;
    if ((int)(q2[a]).size() < 3 || get(a, 3) > make_pair(Z, X + Y - a)) {
      q3.insert({Z, {a, X + Y - a}});
      if ((int)(q2[a]).size() >= 3) {
        pair<long long, int> val = get(a, 3);
        q3.erase({val.first, {a, val.second}});
      }
    }
  }
  q2[X].insert({Z, Y});
  q2[Y].insert({Z, X});
  updTri(X);
  updTri(Y);
}
void removeEdge(int X, int Y) {
  if (X < Y) swap(X, Y);
  long long Z = eds[{X, Y}];
  q2[X].erase({Z, Y});
  q2[Y].erase({Z, X});
  vector<int> ps = {X, Y};
  for (auto& a : ps) {
    if (a == Y) continue;
    if ((int)(q2[a]).size() < 3 || make_pair(Z, Y) < get(a, 3)) {
      q3.erase({Z, {a, Y}});
      if ((int)(q2[a]).size() >= 3) {
        pair<long long, int> val = get(a, 3);
        q3.insert({val.first, {a, val.second}});
      }
    }
  }
  updTri(X);
  updTri(Y);
}
long long outAns() {
  while ((int)(tris).size() &&
         tris.begin()->first != tri[tris.begin()->second]) {
    tris.erase(tris.begin());
  }
  long long ans = 4e9;
  if ((int)(tris).size()) {
    ans = tris.begin()->first;
  }
  pair<long long, pair<int, int>> firstEdge = *q3.begin();
  long long d1 = firstEdge.first;
  int x = firstEdge.second.first;
  int y = firstEdge.second.second;
  vector<pair<long long, pair<int, int>>> tbr;
  for (auto& a : q3) {
    if (a.second.first == x || a.second.first == y || a.second.second == x ||
        a.second.second == y)
      continue;
    ckmin(ans, a.first + d1);
    break;
  }
  for (auto& a : tbr) q3.erase(a);
  pair<long long, int> e1 = get(x, 2);
  pair<long long, int> e2 = get(y, 2);
  if (e1.second != e2.second) {
    ckmin(ans, e1.first + e2.first);
  } else {
    pair<long long, int> e3 = get(x, 3);
    pair<long long, int> e4 = get(y, 3);
    ckmin(ans, e1.first + e4.first);
    ckmin(ans, e2.first + e3.first);
  }
  return ans;
}
void solve() {
  int N, M;
  cin >> N >> M;
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
      removeEdge(X, Y);
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
