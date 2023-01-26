#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const double pi = 3.14159265358979323846;
const long long mxN = 2e5 + 1;
void _print(long long t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(double t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p) {
  cerr << "{";
  _print(p.first);
  cerr << ",";
  _print(p.second);
  cerr << "}";
}
template <class T>
void _print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
map<pair<long long, long long>, long long> id;
map<long long, long long> minn;
map<long long, long long> par;
long long find(long long x) {
  if (par[x] == x) return x;
  return par[x] = find(par[x]);
}
void merge(long long x, long long y) {
  long long fx = find(x);
  long long fy = find(y);
  if (fx == fy) return;
  par[fx] = fy;
  minn[fy] = min(minn[fy], minn[fx]);
}
bool cmp(pair<long long, long long>& a, pair<long long, long long>& b) {
  if (a.first == b.first) return a.second < b.second;
  return a.first < b.first;
}
bool cmp1(pair<long long, long long>& a, pair<long long, long long>& b) {
  if (a.second == b.second) return a.first < b.first;
  return a.second < b.second;
}
void solve() {
  id.clear();
  minn.clear();
  long long n, k;
  cin >> n >> k;
  vector<pair<long long, long long>> hold;
  for (long long i = 1; i <= n; i++) {
    long long x, y, t;
    cin >> x >> y >> t;
    id[{x, y}] = i;
    minn[i] = t;
    par[i] = i;
    hold.push_back({x, y});
  }
  sort(hold.begin(), hold.end(), cmp);
  for (long long i = 1; i < n; i++) {
    if (hold[i].first == hold[i - 1].first &&
        hold[i].second - hold[i - 1].second <= k)
      merge(id[hold[i]], id[hold[i - 1]]);
  }
  sort(hold.begin(), hold.end(), cmp1);
  for (long long i = 1; i < n; i++) {
    if (hold[i].second == hold[i - 1].second &&
        hold[i].first - hold[i - 1].first <= k)
      merge(id[hold[i]], id[hold[i - 1]]);
  }
  set<long long> finalid;
  for (long long i = 1; i <= n; i++) {
    if (par[i] == i) finalid.insert(i);
  }
  vector<pair<long long, long long>> fin;
  for (auto x : finalid) fin.push_back({minn[x], x});
  sort(fin.begin(), fin.end());
  ;
  long long f = 0, e = fin.size() - 1;
  long long time = -1;
  while (f <= e) {
    time++;
    e--;
    while (f < fin.size() && fin[f].first <= time) f++;
  }
  cout << time << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
