#include <bits/stdc++.h>
using namespace std;
void IO();
void _print(long long t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
void _print(bool t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p) {
  cerr << "(";
  _print(p.first);
  cerr << ",";
  _print(p.second);
  cerr << ")";
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
template <class T, class V>
void _print(map<T, V, greater<T>> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(queue<T> q) {
  cerr << "[ ";
  while (q.size()) {
    _print(q.front());
    cerr << " ";
    q.pop();
  }
  cerr << "]";
}
long long max(long long a, long long b, long long c = -1e18,
              long long d = -1e18, long long e = -1e18) {
  return max({a, b, c, d, e});
}
long long min(long long a, long long b, long long c = 1e18, long long d = 1e18,
              long long e = 1e18) {
  return min({a, b, c, d, e});
}
const long long mod = 1e9 + 7;
long long binPow(long long x, long long y, long long z = mod);
void out(vector<long long> v);
void input(long long &x) { cin >> x; }
void input(long long &x, long long &y) { cin >> x >> y; }
void input(long long &x, long long &y, long long &z) { cin >> x >> y >> z; }
void input(long long &x, long long &y, long long &z, long long &p) {
  cin >> x >> y >> z >> p;
}
bool isPrime(long long x) {
  for (long long i = 2; i * i <= x; i++) {
    if (x % i)
      continue;
    else
      return 0;
  }
  return 1;
}
long long sq(long long x) { return (long long)(sqrt(x)); }
bool comp(pair<long long, long long> &a, pair<long long, long long> &b) {
  return (a.first == b.first) ? (a.second > b.second) : (a.first < b.first);
}
long long dx[4] = {-1, 1, 0, 0};
long long dy[4] = {0, 0, -1, 1};
string str, pat;
long long n, m, d, x, y, t, w, h, k, z, s, l, r, u, q, sum;
const long long N = 1e7 + 1;
const long long M = 5e5 + 1;
long long cal(long long l, long long r, vector<long long> &pcnt,
              vector<long long> &psum) {
  long long cnt = pcnt[r] - (l == 0 ? 0 : pcnt[l - 1]);
  l = r - cnt + 1;
  return psum[r] - (l == 0 ? 0 : psum[l - 1]);
}
void solve() {
  cin >> n >> m >> q;
  vector<pair<long long, long long>> v;
  long long sum = 0;
  for (long long i = 0; i < n; i++) {
    cin >> x;
    v.push_back({x, 0});
    sum += x;
  }
  for (long long j = 0; j < m; j++) {
    cin >> x;
    v.push_back({x, 1});
  }
  sort((v).begin(), (v).end());
  vector<long long> pcnt(v.size()), psum(v.size());
  for (long long i = 0; i < v.size(); i++) {
    psum[i] = v[i].first + (i == 0 ? 0 : psum[i - 1]);
    pcnt[i] = (v[i].second == 0) + (i == 0 ? 0 : pcnt[i - 1]);
  }
  vector<pair<long long, long long>> query;
  vector<long long> ans(q, 0);
  for (long long j = 0; j < q; j++) {
    cin >> x;
    query.push_back({x, j});
  }
  vector<pair<long long, long long>> diff;
  long long z = n + m;
  for (long long i = 0; i < z - 1; i++) {
    diff.push_back({v[i + 1].first - v[i].first, i + 1});
  }
  sort((diff).begin(), (diff).end());
  vector<long long> left(z), right(z);
  for (long long i = 0; i < z; i++) left[i] = right[i] = i;
  long long i = 0;
  for (auto &q : query) {
    while (i < diff.size() && diff[i].first <= q.first) {
      long long t = diff[i].second;
      long long l = left[t - 1];
      long long r = right[t];
      sum -= cal(l, t - 1, pcnt, psum);
      sum -= cal(t, r, pcnt, psum);
      left[r] = l;
      right[l] = r;
      sum += cal(l, r, pcnt, psum);
      i++;
    }
    ans[q.second] = sum;
  }
  for (long long &x : ans) cout << x << "\n";
}
int32_t main() {
  IO();
  long long t = 1;
  while (t--) {
    solve();
  }
}
long long binPow(long long x, long long p, long long mod) {
  if (p == 1LL) return x % mod;
  if (p == 0LL) return 1 % mod;
  if (x == 1LL) return 1 % mod;
  long long ans = 1;
  while (p > 0) {
    if (p % 2) {
      ans = (ans * x) % mod;
      p--;
    } else {
      x = (x * x) % mod;
      p /= 2;
    }
  }
  return ans;
}
void out(vector<long long> v) {
  for (long long x : v) cout << x << " ";
  cout << "\n";
}
void IO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << setprecision(15);
}
