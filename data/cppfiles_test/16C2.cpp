#include <bits/stdc++.h>
#pragma GCC optimize("-O2")
using namespace std;
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long mpow(long long base, long long exp) {
  base %= 1000000007;
  long long result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((long long)result * base) % 1000000007;
    base = ((long long)base * base) % 1000000007;
    exp >>= 1;
  }
  return result;
}
void c_p_c() {}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  c_p_c();
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    priority_queue<pair<long long, long long> > p;
    for (long long i = 0; i < n; i++) {
      long long x;
      cin >> x;
      if (x == 0) continue;
      p.push({x, i + 1});
    }
    vector<pair<long long, long long> > sol;
    while (p.size() > 1) {
      auto fi = p.top();
      p.pop();
      auto se = p.top();
      p.pop();
      sol.push_back({fi.second, se.second});
      fi.first--;
      se.first--;
      if (fi.first != 0) p.push(fi);
      if (se.first != 0) p.push(se);
    }
    cout << sol.size() << "\n";
    for (long long i = 0; i < sol.size(); i++) {
      cout << sol[i].first << " " << sol[i].second << "\n";
    }
  }
  return 0;
}
