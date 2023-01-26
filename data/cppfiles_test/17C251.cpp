#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
template <class T>
bool tmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool tmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
template <typename A>
istream& operator>>(istream& cin, vector<A>& v) {
  for (long long i = 1; i < v.size(); i++) cin >> v[i];
  return cin;
}
template <typename A>
ostream& operator<<(ostream& cout, vector<A> const& v) {
  cout << "[";
  for (long long i = 0; i < v.size(); i++) {
    if (i) cout << ", ";
    cout << v[i];
  }
  return cout << "]";
}
template <typename A, typename B>
ostream& operator<<(ostream& cout, pair<A, B> const& p) {
  return cout << "(" << p.first << ", " << p.second << ")";
}
template <typename A, typename B>
istream& operator>>(istream& cin, pair<A, B>& p) {
  cin >> p.first;
  return cin >> p.second;
}
template <typename T_container, typename T = typename enable_if<
                                    !is_same<T_container, string>::value,
                                    typename T_container::value_type>::type>
ostream& operator<<(ostream& os, const T_container& v) {
  os << '{';
  string sep;
  for (const T& x : v) os << sep << x, sep = ", ";
  return os << '}';
}
void dbg_out() { cerr << '\n'; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
long long logg2(long long n) {
  long long tmp;
  for (long long i = 0; i <= 32; i++) {
    tmp = 1 << i;
    if (tmp == n)
      return i;
    else if (tmp > n)
      return i - 1;
  }
  return 32;
}
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
const long double pi = 3.14159265358979323846;
const long long mod = 1000000007;
long long n, m, k, q, l, r, x, y, z;
vector<long long> a, b, c;
string s, t;
long long ans = 0;
vector<vector<long long> > graph;
vector<bool> visited;
vector<long long> color;
vector<string> vss;
const long long dx[] = {-1, 0, 1, 0};
const long long dy[] = {0, 1, 0, -1};
long long MAXN = 1e6 + 9;
void solve(long long tc = 0) {
  cin >> n;
  graph.resize(n, vector<long long>(5));
  bool found = false;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < 5; j++) cin >> graph[i][j];
  }
  for (long long cur = 0; cur < n; cur++) {
    found = true;
    long long curb = 0;
    for (long long i = cur + 1; i < n; i++) {
      l = 0;
      for (long long j = 0; j < 5; j++) {
        if (graph[cur][j] < graph[i][j]) l++;
      }
      if (l < 3) {
        cur = max(i, cur + 1);
        found = false;
        curb = i;
        break;
      }
    }
    if (found) {
      bool ok = true;
      for (x = 0; x < cur; x++) {
        l = 0;
        for (long long ii = 0; ii < 5; ii++) {
          if (graph[cur][ii] < graph[x][ii]) l++;
        }
        if (l < 3) {
          ok = false;
          break;
        }
      }
      if (ok) {
        cout << cur + 1 << '\n';
        return;
      } else {
        cout << -1 << '\n';
        return;
      }
    } else {
      cur = curb - 1;
    }
  }
  cout << -1 << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  long long tc = 1;
  cin >> tc;
  for (long long tt = 1; tt <= tc; tt++) {
    a.clear(), b.clear(), c.clear();
    graph.clear(), visited.clear(), color.clear();
    s.clear(), t.clear(), vss.clear();
    n = 0, m = 0, k = 0, q = 0, l = 0, r = 0, x = 0, y = 0, z = 0, ans = 0;
    solve(tt);
  }
  return 0;
}
