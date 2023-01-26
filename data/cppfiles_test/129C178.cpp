#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int MOD = 998244353;
const long long int maxn = 1e5 + 5;
const long long int inf = 1e12;
const double pi = acos(-1);
inline long long int add(long long int x, long long int y) {
  x += y;
  if (x >= mod) x -= mod;
  return x;
}
inline long long int sub(long long int x, long long int y) {
  x -= y;
  if (x < 0) x += mod;
  return x;
}
inline long long int mul(long long int x, long long int y) {
  return (x * 1ll * y) % mod;
}
void _print(long long int t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long int t) { cerr << t; }
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
  _print(p.ff);
  cerr << ",";
  _print(p.ss);
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
long long int n, m, x, y, z, u, minn, maxx;
void solve() {
  cin >> n;
  vector<long long int> arr(n);
  vector<long long int> rem;
  set<long long int> st;
  for (long long int i = 1; i <= n; i++) st.insert(i);
  for (long long int i = 0; i < n; i++) {
    cin >> arr[i];
    if (st.find(arr[i]) != st.end()) {
      st.erase(arr[i]);
    } else {
      rem.push_back(arr[i]);
    }
  }
  sort(rem.begin(), rem.end());
  for (int i = 0; i < rem.size(); i++) {
    long long int curr = *(st.begin());
    if (rem[i] > 2 * curr) {
      st.erase(st.begin());
    } else {
      cout << -1 << endl;
      return;
    }
  }
  cout << rem.size() << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie();
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
