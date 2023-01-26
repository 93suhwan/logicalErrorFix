#include <bits/stdc++.h>
using namespace std;
void _print(long long t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
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
long long mpow(long long base, long long exp);
void ipgraph(long long m);
void dfs(long long u, long long par);
const long long mod = 1000000007;
long long par[500000 + 5];
long long rnk[500000 + 5];
void make_set(long long n) {
  for (long long i = 1; i <= n; ++i) {
    par[i] = i;
    rnk[i] = 1;
  }
}
long long find_par(long long a) {
  if (par[a] == a) return a;
  return par[a] = find_par(par[a]);
}
void make_union(long long a, long long b) {
  long long p1 = find_par(a);
  long long p2 = find_par(b);
  if (p1 == p2) {
    return;
  }
  if (rnk[p1] > rnk[p2]) {
    par[p2] = p1;
    rnk[p1] += rnk[p2];
  } else {
    par[p1] = p2;
    rnk[p2] += rnk[p1];
  }
}
void sol() {
  long long n, i, j, k, m, q;
  cin >> n;
  make_set(n);
  std::vector<long long> a(n, 0);
  std::vector<pair<long long, long long> > v, v_index;
  unordered_map<long long, long long> make_pair;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    v.push_back({a[i], i + 1});
  }
  sort(v.begin(), v.end());
  std::vector<long long> b = a;
  sort(b.begin(), b.end());
  if (a == b) {
    cout << "YES" << '\n';
    return;
  }
  for (long long i = 0; i < n; i++) {
    make_union(v[i].second, i + 1);
  }
  std::vector<bool> done(n + 5, false);
  bool pos = false;
  for (long long i = 1; i <= n; i++) {
    long long temp = rnk[find_par(i)];
    if (find_par(i) == i) {
      make_pair[temp]++;
      if (temp >= 3) pos = true;
    }
  }
  if (make_pair[2] == 1 && pos == false) {
    cout << "NO" << '\n';
    return;
  }
  cout << "YES" << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) sol();
  return 0;
}
long long mpow(long long base, long long exp) {
  base %= mod;
  long long result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % mod;
    base = (base * base) % mod;
    exp >>= 1;
  }
  return result;
}
