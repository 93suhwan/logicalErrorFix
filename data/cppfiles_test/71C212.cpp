#include <bits/stdc++.h>
using namespace std;
void print(long long t) { cerr << t; }
void print(string t) { cerr << t; }
void print(char t) { cerr << t; }
void print(long double t) { cerr << t; }
void print(double t) { cerr << t; }
void print(unsigned long long t) { cerr << t; }
template <class T, class V>
void print(pair<T, V> p);
template <class T>
void print(vector<T> v);
template <class T>
void print(set<T> v);
template <class T, class V>
void print(map<T, V> v);
template <class T>
void print(multiset<T> v);
template <class T, class V>
void print(pair<T, V> p) {
  cerr << "{";
  print(p.first);
  cerr << ",";
  print(p.second);
  cerr << "}";
}
template <class T>
void print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void print(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void print(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    print(i);
    cerr << " ";
  }
  cerr << "]";
}
const long long inf = 0x3f3f3f3f3f3f3f3f;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void zz() { ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0); }
long long f(long long n, long long k) {
  string s = to_string(n);
  long long m = s.size();
  long long p = 0;
  long long d = 0;
  set<long long> st;
  for (long long i = 0; i < m; i++) {
    st.insert(s[i] - '0');
    if (st.size() > k) break;
    d += 1;
    p = p * 10 + s[i] - '0';
  }
  if (d == m) return p;
  p = p * 10 + s[d] - '0' + 1;
  for (long long i = d + 1; i < m; i++) {
    p *= 10;
  }
  return f(p, k);
}
void slv() {
  long long n, k;
  cin >> n >> k;
  long long ans = f(n, k);
  cout << ans << endl;
}
int32_t main() {
  zz();
  long long t = 1;
  cin >> t;
  while (t--) {
    slv();
  }
}
