#include <bits/stdc++.h>
using namespace std;
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
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T& x) {
  int f = 0;
  cerr << '{';
  for (auto& i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
template <typename T>
istream& operator>>(istream& stream, vector<T>& v) {
  for (T& x : v) stream >> x;
  return stream;
}
const long long inf = 1e18;
void solve() {
  long long q;
  cin >> q;
  const long long mxn = 5e5 + 1;
  vector<list<long long>> pos(mxn + 1);
  long long s = 0;
  for (long long i = 0; i < q; i++) {
    long long t;
    cin >> t;
    if (t == 1) {
      s++;
      long long x;
      cin >> x;
      pos[x].push_back(s);
    } else {
      long long x, y;
      cin >> x >> y;
      pos[y].splice(pos[y].end(), pos[x]);
    }
  }
  vector<long long> a(s + 1);
  for (long long i = 1; i < mxn; i++)
    for (long long j : pos[i]) a[j] = i;
  for (long long i = 1; i <= s; i++) cout << a[i] << " ";
  cout << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
