#include <bits/stdc++.h>
using namespace std;
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '"' << x << '"'; }
void __print(const char *x) { cerr << '"' << x << '"'; }
void __print(const string &x) { cerr << '"' << x << '"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]" << endl; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
const double PI = 3.1415926535897932384626;
const long long oo = 1e18;
long long n, a;
void solution() {
  cin >> n;
  priority_queue<pair<long long, long long> > pq;
  for (long i = 0; i < n; ++i) {
    cin >> a;
    if (a != 0) pq.push({a, i + 1});
  }
  vector<vector<long long> > res;
  while (pq.size() > 1) {
    auto p1 = pq.top();
    pq.pop();
    auto p2 = pq.top();
    pq.pop();
    res.push_back({p1.second, p2.second});
    if (p1.first > 1) pq.push({p1.first - 1, p1.second});
    if (p2.first > 1) pq.push({p2.first - 1, p2.second});
  }
  cout << res.size() << endl;
  for (long i = 0; i < res.size(); ++i)
    cout << res[i][0] << " " << res[i][1] << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(12);
  ;
  long t = 1;
  cin >> t;
  while (t--) solution();
  return 0;
}
